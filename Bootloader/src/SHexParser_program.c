/**
 * @file SHexParser_program.c
 * @author Hosam Ayoub
 * @version 1.0
 * @date 01 Oct 2023
 * @brief The HexParser C file that has all the the functions body of **HexParser** driver
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/FMI/MFMI_interface.h"
#include "MCAL/UART/MUART_interface.h"
#include "Service/HexParser/SHexParser_interface.h"
#include "Service/HexParser/SHexParser_private.h"
#include "Service/HexParser/SHexParser_config.h"

static u16 Global_u16DataBuffer[100];
static pf Global_pfNotificationFunction = NULL;
u32 Global_u32FlashBaseAddress, Global_u32StartAddress, Global_u32ApplicationAddress;

/**
 * @fn u8 SHexParser_u8AsciiToHex(u8)
 * @brief This to convert an ASCII character representing a hexadecimal digit to its corresponding 4-bit binary value.
 * @param 		Copy_u8Ascii		an ASCII character representing a hexadecimal digit.
 * @return  	u8 	The Value of 4-bit binay.
 * @details		This function convert an ASCII character representing a hexadecimal digit to its corresponding 4-bit binary value
 * -#	Check if the ASCII character is a digit (0-9),If it is a digit, convert it to its binary value.
 * -#	Check if the ASCII character is an uppercase letter (A-F), If it is an uppercase letter, convert it to its binary value.
 */
static u8 SHexParser_u8AsciiToHex (u8 Copy_u8Ascii)
{
	u8 Local_u8Hex = 0;
	if (('0' <= Copy_u8Ascii) && (Copy_u8Ascii <= '9'))
	{
		Local_u8Hex = Copy_u8Ascii - '0';
	}
	else if (('A' <= Copy_u8Ascii) && (Copy_u8Ascii <= 'F'))
	{
		Local_u8Hex = Copy_u8Ascii - ('A' - 10);
	}
	return Local_u8Hex;
}


/**
 * @fn tenumStatus SHexParser_tenumStatusParseData(s8*)
 * @brief This Function responsible for parsing and processing a line of Intel Hexadecimal format data
 * @param 	Pointer_u8Data		contain a data record in Intel HEX format.
 * @return 	tenumStatus	a status indicates whether the Parsing and Writing Were successful (OK) or not (NOK).
 * @details	This function is crucial for parsing data records from an Intel Hex file, converting ASCII to hexadecimal, and writing the data to flash memory while ensuring data integrity through checksum verification.
 * -#	Parses the byte count from the Intel Hex data (index 1 and 2).
 * -#	Combines the parsed digits using bitwise operations.
 * -#	Adding Byte Count to Summation.
 * -#	Parsing and Setting Address:
 *	-	Parses the address bytes (index 3 to 6) from the Intel Hex data.
 * 	-	Combines the parsed digits using bitwise operations.
 * 	-	Checks if the Local_u8Flag is set (indicating the first record), and if true,sets the global start address (Global_u32StartAddress) to Local_u32Address and clears the flag.
 *-#	Adding Address Bytes to Summation:
 *-#	Loop for Data Bytes:
 *	-	Parses and sets four data bytes at a time, converting them from ASCII to hexadecimal.
 *-#	Handling Odd Byte Count:
 *-#	Calculating Checksum:
 *	-	Parses the checksum from the Intel Hex data (index 17 and 18).
 *-#	Checking Record Correctness:
 *	-	Compares the Two's complement of the summation with the calculated checksum.
 *	-	If they match, calls the function MFMI_voidFlashWrite to write the data to flash memory.
 *	-	If not, sets the status to NOK.
 *
 */
tenumStatus SHexParser_tenumStatusParseData (s8 *Pointer_s8Data)
{
	u8 Local_u8CC, Local_u8Digit0, Local_u8Digit1, Local_u8Digit2, Local_u8Digit3, Local_u8Iterator, Local_u8CheckSum = 0, Local_u8Summation = 0;
	u32 Local_u32Address;
	tenumStatus Local_u8Status = OK;
	static u8 Local_u8Flag = 1;
	/* Convert character count */
	Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[1]);
	Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[2]);
	Local_u8CC = (Local_u8Digit0 << 4) | (Local_u8Digit1);

	/* Add the previous byte to the summation */
	Local_u8Summation += Local_u8CC;

	/* Convert address */
	Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[3]);
	Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[4]);
	Local_u8Digit2 = SHexParser_u8AsciiToHex(Pointer_s8Data[5]);
	Local_u8Digit3 = SHexParser_u8AsciiToHex(Pointer_s8Data[6]);
	Local_u32Address = (Global_u32FlashBaseAddress) | (Local_u8Digit0 << 12) | (Local_u8Digit1 << 8) | (Local_u8Digit2 << 4) | (Local_u8Digit3);
	if (Local_u8Flag)
	{
		Global_u32StartAddress = Local_u32Address;
		Local_u8Flag = 0;
	}

	/* Add the previous two bytes to the summation */
	Local_u8Summation += (Local_u8Digit0 << 4) | (Local_u8Digit1);
	Local_u8Summation += (Local_u8Digit2 << 4) | (Local_u8Digit3);

	for (Local_u8Iterator = 0; Local_u8Iterator < (Local_u8CC/2); Local_u8Iterator++)
	{
		Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[9  + (Local_u8Iterator * 4)]);
		Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[10 + (Local_u8Iterator * 4)]);
		Local_u8Digit2 = SHexParser_u8AsciiToHex(Pointer_s8Data[11 + (Local_u8Iterator * 4)]);
		Local_u8Digit3 = SHexParser_u8AsciiToHex(Pointer_s8Data[12 + (Local_u8Iterator * 4)]);

		/* Convert big endian to little endian */
		Global_u16DataBuffer[Local_u8Iterator] = (Local_u8Digit2 << 12) | (Local_u8Digit3 << 8) | (Local_u8Digit0 << 4) | (Local_u8Digit1);

		/* Add the previous two bytes to the summation */
		Local_u8Summation += (Local_u8Digit0 << 4) | (Local_u8Digit1);
		Local_u8Summation += (Local_u8Digit2 << 4) | (Local_u8Digit3);
	}

	if (Local_u8CC % 2 == 1)
	{
		/* Add the padding half word to the CC */
		Local_u8CC++;

		Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[9  + (Local_u8Iterator * 4)]);
		Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[10 + (Local_u8Iterator * 4)]);
		Local_u8Digit2 = SHexParser_u8AsciiToHex('0');
		Local_u8Digit3 = SHexParser_u8AsciiToHex('0');

		/* Convert big endian to little endian */
		Global_u16DataBuffer[Local_u8Iterator] = (Local_u8Digit2 << 12) | (Local_u8Digit3 << 8) | (Local_u8Digit0 << 4) | (Local_u8Digit1);
		/* Add the previous two bytes to the summation */
		Local_u8Summation += (Local_u8Digit0 << 4) | (Local_u8Digit1);

		/* Get Checksum */
		Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[11  + (Local_u8Iterator * 4)]);
		Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[12  + (Local_u8Iterator * 4)]);

	}
	else
	{
		/* Get Checksum */
		Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[9  + (Local_u8Iterator * 4)]);
		Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[10 + (Local_u8Iterator * 4)]);
	}

	/* Calculate Checksum  */
	Local_u8CheckSum = (Local_u8Digit0 << 4) | (Local_u8Digit1);

	/* Get the Two's complement of the Summation */
	Local_u8Summation = (0xFF - Local_u8Summation) + 1;

	/* Check if the record is correct or no*/
	if (Local_u8Summation == Local_u8CheckSum)
	{
		MFMI_voidFlashWrite(Local_u32Address, Global_u16DataBuffer, (Local_u8CC/2));
	}
	else
	{
		/* Set error status */
		Local_u8Status = NOK;
	}
	return Local_u8Status;
}

/**
 * @fn tenumStatus SHexParser_tenumStatusSetHighAddress(s8*)
 * @brief	This function  processes a specific type of data record in Intel Hex format
 * @param Pointer_s8Data	A pointer to a character array containing the Intel Hex data record.
 * @return	Returns the status (Local_u8Status), indicating whether the record is correct (OK) or there was an error (NOK).
 * @details	-#The function starts by declaring local variables for digits, checksum, summation, and the status.
 * -#	It converts the character count from ASCII to hexadecimal and adds it to the summation.
 * -#	It converts the address from ASCII to hexadecimal, updates the global flash base address, and adds the address bytes to the summation.
 * -#	It adds 0x04 to the summation as it is the code to set the high address.
 * -#	The function then converts the next set of address bytes from ASCII to hexadecimal, updates the global flash base address, and adds these bytes to the summation.
 * -#	It calculates the two's complement of the summation.
 * -#	The function calculates the checksum from ASCII to hexadecimal.
 * -#	It checks if the calculated checksum matches the two's complement of the summation. If yes, it performs a no-operation (nop).
 * -#	If there is a mismatch, it sets the error status to NOK.
 */
tenumStatus SHexParser_tenumStatusSetHighAddress (s8 *Pointer_s8Data)
{
	u8 Local_u8Digit0, Local_u8Digit1, Local_u8Digit2, Local_u8Digit3, Local_u8CheckSum = 0, Local_u8Summation = 0;
	tenumStatus Local_u8Status = OK;
	/* Convert character count */
	Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[1]);
	Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[2]);
	/* Add the previous byte to the summation */
	Local_u8Summation += (Local_u8Digit0 << 4) | (Local_u8Digit1);

	/* Convert address */
	Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[3]);
	Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[4]);
	Local_u8Digit2 = SHexParser_u8AsciiToHex(Pointer_s8Data[5]);
	Local_u8Digit3 = SHexParser_u8AsciiToHex(Pointer_s8Data[6]);
	Global_u32FlashBaseAddress = (Local_u8Digit0 << 12) | (Local_u8Digit1 << 8) | (Local_u8Digit2 << 4) | (Local_u8Digit3);
	/* Add the previous two bytes to the summation */
	Local_u8Summation += (Local_u8Digit0 << 4) | (Local_u8Digit1);
	Local_u8Summation += (Local_u8Digit2 << 4) | (Local_u8Digit3);

	/* Add 0x04 to the summation as it is the code to set High address */
	Local_u8Summation += 0x04;

	Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[9 ]);
	Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[10]);
	Local_u8Digit2 = SHexParser_u8AsciiToHex(Pointer_s8Data[11]);
	Local_u8Digit3 = SHexParser_u8AsciiToHex(Pointer_s8Data[12]);
	Global_u32FlashBaseAddress |= (Local_u8Digit0 << 28) | (Local_u8Digit1 << 24) | (Local_u8Digit2 << 20) | (Local_u8Digit3 << 16);

	/* Add the previous two bytes to the summation */
	Local_u8Summation += (Local_u8Digit0 << 4) | (Local_u8Digit1);
	Local_u8Summation += (Local_u8Digit2 << 4) | (Local_u8Digit3);
	/* Get the Two's complement of the Summation */
	Local_u8Summation = (0xFF - Local_u8Summation) + 1;

	/* Calculate Checksum */
	Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[13]);
	Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[14]);
	Local_u8CheckSum = (Local_u8Digit0 << 4) | (Local_u8Digit1);

	/* Check if the record is correct or no*/
	if (Local_u8Summation == Local_u8CheckSum)
	{
		asm("nop");
	}
	else
	{
		/* Set error status */
		Local_u8Status = NOK;
	}
	return Local_u8Status;
}



/**
 * @fn tenumStatus SHexParser_tenumStatusSetStartAddress(s8*)
 * @brief This function is responsible for setting the start address for the application based on the data provided in an Intel Hex record.
 * @param	 Pointer_s8Data		A pointer to a character array containing Intel Hexadecimal formatted data.
 * @return  tenumStatus   a status (OK or NOK) indicating the success or failure of the operation.
 * @details	This function is specifically designed to handle records in the Intel Hex file format that set the start address of the application.
 * -#	Parsing Character Count:
 * 	-	Parses the character count bytes (index 1 and 2) from the Intel Hex data.
 * 	-	Combines the parsed digits using bitwise operations.
 * -#	Adding Constant to Summation.
 * -#	Parsing Checksum.
 * -#	Calculating Two's Complement of Summation.
 * -#	Checking Record Correctness.
 *
 */
tenumStatus SHexParser_tenumStatusSetStartAddress (s8 *Pointer_s8Data)
{
	u8 Local_u8Digit0, Local_u8Digit1, Local_u8Digit2, Local_u8Digit3, Local_u8CheckSum = 0, Local_u8Summation = 0;
	tenumStatus Local_u8Status = OK;
	/* Convert character count */
	Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[1]);
	Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[2]);
	/* Add the previous byte to the summation */
	Local_u8Summation += (Local_u8Digit0 << 4) | (Local_u8Digit1);

	/* Add 0x05 to the summation as it is the code to set High address */
	Local_u8Summation += 0x05;

	Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[9 ]);
	Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[10]);
	Local_u8Digit2 = SHexParser_u8AsciiToHex(Pointer_s8Data[11]);
	Local_u8Digit3 = SHexParser_u8AsciiToHex(Pointer_s8Data[12]);
	Global_u32ApplicationAddress |= (Local_u8Digit0 << 28) | (Local_u8Digit1 << 24) | (Local_u8Digit2 << 20) | (Local_u8Digit3 << 16);
	/* Add the previous two bytes to the summation */
	Local_u8Summation += (Local_u8Digit0 << 4) | (Local_u8Digit1);
	Local_u8Summation += (Local_u8Digit2 << 4) | (Local_u8Digit3);

	Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[13]);
	Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[14]);
	Local_u8Digit2 = SHexParser_u8AsciiToHex(Pointer_s8Data[15]);
	Local_u8Digit3 = SHexParser_u8AsciiToHex(Pointer_s8Data[16]);
	Global_u32ApplicationAddress |= (Local_u8Digit0 << 12) | (Local_u8Digit1 << 8) | (Local_u8Digit2 << 4) | (Local_u8Digit3 << 0);
	/* Add the previous two bytes to the summation */
	Local_u8Summation += (Local_u8Digit0 << 4) | (Local_u8Digit1);
	Local_u8Summation += (Local_u8Digit2 << 4) | (Local_u8Digit3);

	/* Get the Two's complement of the Summation */
	Local_u8Summation = (0xFF - Local_u8Summation) + 1;

	/* Calculate Checksum */
	Local_u8Digit0 = SHexParser_u8AsciiToHex(Pointer_s8Data[17]);
	Local_u8Digit1 = SHexParser_u8AsciiToHex(Pointer_s8Data[18]);
	Local_u8CheckSum = (Local_u8Digit0 << 4) | (Local_u8Digit1);

	/* Check if the record is correct or no*/
	if (Local_u8Summation == Local_u8CheckSum)
	{
		asm("nop");
	}
	else
	{
		/* Set error status */
		Local_u8Status = NOK;
	}
	return Local_u8Status;

}

/**
 * @fn tenumStatus SHexParser_tenumStatusParseRecord(s8*)
 * @brief This function is responsible for parsing different types of Intel Hex records and taking appropriate actions based on the record type.
 * @param Pointer_u8Data	A pointer to a character array containing Intel Hexadecimal formatted data.
 * @return tenumStatus	a status indicating the success or failure of the parsing process.
 * @details	This function serves as a record parser, determining the type of record based on the value at a specific index in the input data. It then calls corresponding functions to process or set relevant information based on the record type.
 */
tenumStatus SHexParser_tenumStatusParseRecord (s8 *Pointer_s8Data)
{
	tenumStatus Local_u8Status = OK;
	switch (Pointer_s8Data[8])
	{
	case '0':
		Local_u8Status = SHexParser_tenumStatusParseData(Pointer_s8Data);
		break;
	case '4':
		/* Set high address */
		Local_u8Status = SHexParser_tenumStatusSetHighAddress(Pointer_s8Data);
		break;
	case '1':
		/* End of file */
		if (Pointer_s8Data[11] == '\n')
		{
			/*Send ok to tool to send the next Record */
//			MMUART11_voidTransmit("K");
			MUART1_voidTransmit("K");
			Global_pfNotificationFunction();
		}
		else
		{
			/*Send ok to tool to send the next Record */
			Local_u8Status = SHexParser_tenumStatusParseData(Pointer_s8Data);
		}
		break;
	case '5':
		/* Set high address */
		Local_u8Status = SHexParser_tenumStatusSetStartAddress (Pointer_s8Data);
		//		MUART1_voidTransmit("K");
		break;
	default:
		break;
	}
	return Local_u8Status;
}


/**
 * @fn tenumStatus SHexParser_tenumStatusSetCallBack(pf)
 * @brief  This function to set a callback function that can be executed in response to specific conditions.
 * @param 	PointerToFunction	A pointer to a function (callback).
 * @return 	tenumStatus 	a status (OK or NOK) indicating the success or failure of setting the callback.
 * @details	This function is to allow external code to set a callback function by providing a function pointer. It performs a basic check to ensure that the provided function pointer is not NULL. If the pointer is valid, it sets a global function pointer to the provided function, indicating success (OK). If the pointer is NULL, it sets the status to indicate an error (NOK).
 */
tenumStatus SHexParser_tenumStatusSetCallBack(pf PointerToFunction)
{
	tenumStatus Local_u8Status = OK;
	if (PointerToFunction != NULL)
	{
		Global_pfNotificationFunction = PointerToFunction;
	}
	else
	{
		Local_u8Status = NOK;
	}
	return Local_u8Status;
}
