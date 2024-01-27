from firebase_admin import credentials, storage, initialize_app
from cryptography.fernet import Fernet
from os import remove
import serial
import time

Baud = 1562500
UART_Port = "/dev/serial0"
UART = serial.Serial(baudrate = Baud , port = UART_Port , parity="N" , stopbits = 1)

BanksInfo = list()
Lines = list()
DiactivatedBank = "2"

#PATH = "Python/Study/Firebase/"
PATH = "/home/pi/Desktop/Final/"
NAME1 = "Hex1"
NAME2 = "Hex2"
NAME3 = "CriticalUpdate"
CRITICAL_UPDATE_FLAG = 0
VALIDATION_FLAG = 0
UPDATE_FLAG = 0

# Decryption
KEY = "R9jnBFyNZTaiTcObl9Lzzw9ltIxHVaBxqjHPPNNAgoY=".encode()
Encrypt = Fernet(KEY)
# Firebase credentials
cred = credentials.Certificate(PATH + "autonxt-a51b5-firebase-adminsdk-4kl65-1e79ba0cd0.json")
initialize_app(cred, {'storageBucket': 'autonxt-a51b5.appspot.com'})


def ChooseBankForUpdate(Bank):
    global Lines
    if Bank == "1":
        with open(f"Hex1.hex", "r") as FileHex:
            Lines = FileHex.readlines()
    elif Bank == "2":
        with open("Hex2.hex", "r") as FileHex:
            Lines = FileHex.readlines()



def UpdateBanksInfo():
    global UART, BanksInfo, DiactivatedBank
    Temp1 = b'\xff'
    Temp2 = b'\xff'
    while Temp1 == b'\xff':
        Temp1 = UART.read()
    while Temp2 == b'\xff':
        Temp2 = UART.read()
#    print(f"Temp1 = {Temp1} - Temp2 = {Temp2}")
    Info = Temp1.decode() + Temp2.decode()
#    print(Info)
    #Info = UART.read().decode() + UART.read().decode()
    if Info[0] == "1":
        BanksInfo[0] = Info + "\n"
        if Info[1] == "0":
            DiactivatedBank = "1"
        else:
            DiactivatedBank = "2"
    elif Info[0] == "2":
        BanksInfo[1] = Info + "\n"
        if Info[1] == "0":
            DiactivatedBank = "2"
        else:
            DiactivatedBank = "1"
            
    with open("Banks.txt", "w") as Banks:
        Banks.writelines(BanksInfo)

def SendUpdate():
    global UART, Lines
    Iterator = 0
    if (UART.is_open):
        while True:
            try:
                Ack = UART.read()
                if Ack == b'B':
                    print("Burning Code...")
                    while Iterator < len(Lines):
                        for Letter in Lines[Iterator]:
                            UART.write(Letter.encode())
                        Read = UART.read().decode()
                        UART.flushInput()
                        if Read == "K":
                            Iterator += 1
                    UART.flushInput()
                    print("The code has been burned successfully\n")
                    break
            except Exception as exception:
                pass
    else:
        print ("NOK")



def CheckFile(File):
    global VALIDATION_FLAG
    with open (PATH + File, "r") as FileHex:
        Lines = FileHex.read()
        Lines = Lines.splitlines()
    for line in Lines:
        CHECKSUM = 0
        for Byte in range(1, len(line) - 2, 2):
            CHECKSUM += int(line[Byte:Byte+2], 16)
            
        CHECKSUM = hex(CHECKSUM)
        CHECKSUM = CHECKSUM[2:]
        
        if len(CHECKSUM) < 2:
            CHECKSUM = '0' + CHECKSUM
        elif len(CHECKSUM) > 2:
            CHECKSUM = CHECKSUM[-2:]
            
        CHECKSUM = int('FF', 16) - int(CHECKSUM, 16) + 1
        CHECKSUM = hex(CHECKSUM)[2:].upper()
        
        if len(CHECKSUM) < 2:
            CHECKSUM = '0' + CHECKSUM
        elif len(CHECKSUM) > 2:
            CHECKSUM = CHECKSUM[-2:]
        
        if line[-2:] != CHECKSUM:
            # print(f"{line[-2:]} - {CHECKSUM}")
            print("Invalid update")
            VALIDATION_FLAG = 0
            break
        else:
            VALIDATION_FLAG = 1
            
def Decryption(name):
    global PATH
    # Decryption
    Source_File = open(file=f"{PATH}{name}_Enc.hex" , mode="r")
    Dest_File = open(file=f"{PATH}{name}.hex" , mode="w")
    
    for Line in Source_File:
        Dest_File.write(Encrypt.decrypt(Line.encode()).decode())
    
    #print(f"Files Hex1 and Hex2 are decrypted")
    Source_File.close()
    Dest_File.close()
    remove(f"{PATH}{name}_Enc.hex")

def CheckUpdate():
    global PATH, NAME1, NAME2, NAME3, VALIDATION_FLAG, UPDATE_FLAG, CRITICAL_UPDATE_FLAG

    # Get a reference to the Firebase Cloud Storage bucket
    bucket = storage.bucket()
    # Define the path to the file we want to download from Firebase Storage
    file_path1 = "Files/" + NAME1 + "_Enc.hex"
    file_path2 = "Files/" + NAME2 + "_Enc.hex"
    file_path3 = "Files/" + NAME3 + "_Enc.hex"
    blob1 = bucket.blob(file_path1)
    blob2 = bucket.blob(file_path2)
    blob3 = bucket.blob(file_path3)
    file_versions = list(bucket.list_blobs(prefix=file_path1))

    # Specify the local file path where we want to save the downloaded file
    local_file_path1 = PATH + NAME1 + "_Enc.hex"
    local_file_path2 = PATH + NAME2 + "_Enc.hex"
    local_file_path3 = PATH + NAME3 + "_Enc.hex"
        
    with open (PATH + "Versions.txt", "r") as version:
        current_generation = int(version.read())
        
    # Get file version from firebase
    file_versions = list(bucket.list_blobs(prefix=file_path1))
    new_generation = int(str(file_versions).split(" ")[-1][:-2])
    
    # Compare with the previous metadata
    if current_generation != new_generation:
        UPDATE_FLAG = 1
        #print("There is an update")
        blob1.download_to_filename(local_file_path1)
        blob2.download_to_filename(local_file_path2)
        if blob3.exists():
            blob3.download_to_filename(local_file_path3)
            blob3.delete()
            Decryption(NAME3)
            with open (f"{PATH}{NAME3}.hex", "r") as State:
                Password = State.read()
            if Password == ")QhPjjGbp=/;>P9Cxp8<neP92p1#V5n|,5.3V:\"zpD`L":
                CRITICAL_UPDATE_FLAG = 1
            else:
                CRITICAL_UPDATE_FLAG = 0
            remove(f"{PATH}{NAME3}.hex")
        else:
            CRITICAL_UPDATE_FLAG = 0
        
        Decryption(NAME1)
        Decryption(NAME2)
        
            
        #print("Checking file 1")
        CheckFile("Hex1.hex")
        if not VALIDATION_FLAG:
            #print("The file 1 is not valid")
            remove(f"{PATH}{NAME1}.hex")
                
        #print("Checking file 2")
        CheckFile("Hex2.hex")
            
        if not VALIDATION_FLAG:
            #print("The file 2 is not valid")
            remove(f"{PATH}{NAME2}.hex")
        
        #with open (PATH + NAME3, "r") as State:
         #   Temp = State.read().title()
         #   print(Temp)
          #  if Temp == "Critical":
          #      UPDATE_STATE = 1
            
        # Update version
        current_generation = new_generation
        with open (PATH + "Versions.txt", "w") as version:
            version.write(str(current_generation))
    else:
        print("No update")
        UPDATE_FLAG = 0


if __name__ == "__main__":
    UpdateAck = str()
    Info = str()
    #ChooseBankForUpdate(DiactivatedBank)
    #SendUpdate()
    while True:
        with open("Banks.txt", "r") as Banks:
            BanksInfo = Banks.readlines()
            
        UpdateAck = ""
        CheckUpdate()
        #print(f"UPDATE_FLAG = {UPDATE_FLAG} - VALIDATION_FLAG = {VALIDATION_FLAG}")
        if UPDATE_FLAG and VALIDATION_FLAG:
            UPDATE_FLAG = 0
            VALIDATION_FLAG = 0
            UART.flushInput()
            while UpdateAck != 'K':
                UART.flushOutput()
                if CRITICAL_UPDATE_FLAG == 1:
                    print("There is a critical update")
                    UART.write('C'.encode())
                else:
                    print("There is an update press the top switch to accept it or the bottom switch")
                    UART.write('U'.encode())
                UpdateAck = UART.read().decode()
                if UpdateAck == 'R':
                    print("The update has been rejected")
                    break
                else:
                    UpdateBanksInfo()
            else:
                print("Downloading the update...")
                print(f"The code has been downloaded press the middle switch to install it in bank {DiactivatedBank}")
                ChooseBankForUpdate(DiactivatedBank)
                UART.flushInput()
                SendUpdate()
                UpdateBanksInfo()
        time.sleep(10)
