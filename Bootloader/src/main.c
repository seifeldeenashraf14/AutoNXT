/**
 * @file	 main.c
 * @author 	 Hosam Ayoub
 * @version  1.0
 * @date 	 1 Oct 2023
 * @brief 	 The bootloader logic <BR>
 * 			 **Target** STM32F401CC (Black Pill)
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/FMI/MFMI_interface.h"
#include "MCAL/RCC/MRCC_interface.h"
#include "MCAL/STK/MSTK_interface.h"
#include "MCAL/GPIO/MGPIO_interface.h"
#include "MCAL/UART/MUART_interface.h"
#include "MCAL/SCB/MSCB_interface.h"
#include "Service/HexParser/SHexParser_interface.h"

#define TX_PIN							GPIO_PIN9						//!< The Transmitter PIN of USART1
#define RX_PIN							GPIO_PIN10						//!< The Receiver PIN of USART1


s8 ReceiveBuffer[100];                                                  //!< This array will receive the new update records
volatile u8 u8RecCounter = 0;                                           //!< The record counter
volatile u8 TimeOutFlag = 0;                                            //!< The time out flag which indicated that the bootloader has finished it task
volatile u8 u8WriteReq = 1;                                             //!< This flag indicated for the start of writing in a bank
pf EntryPoint = NULL;													//!< The entry point of the application which will be jumped to it after the bootloader finish

/**
 * @fn 		void main(void)
 * @param 	none
 * @return 	none
 * @brief 	The sequence of the bootloader
 * @details The main logic of the bootloader which is waiting 10 ms to check if there was update or not
 * - If there wasn't a new update it will check which bank has a valid application then jump to it
 * - If there was a new update it will receive each record byte by byte and it will continue receiving bytes until it finish the record then check if it was valid it will send **K** not valid will send **N** then it will repeat the sequence of receiving
 * - If there wasn't update or there wasn't a valid application it will wait again for any update
 */
void main (void)

{
	u8 Local_u8MUART11Status = 0;
	tenumStatus Local_u8RecordStatus = OK;
	MRCC_voidEnablePeripheral(MRCC_APB2, MRCC_APB2_USART1);
	MRCC_voidEnablePeripheral(MRCC_AHB1, MRCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(MRCC_AHB1, MRCC_AHB1_GPIOB);
	MRCC_voidInit();

	MGPIO_voidSetPinMode(GPIO_PORTA, TX_PIN, GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA, RX_PIN, GPIO_ALT_FUNC);

	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA, TX_PIN, GPIO_AF7);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA, RX_PIN, GPIO_AF7);

	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN2, GPIO_PUSH_PULL, GPIO_MID_SPEED);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_HIGH);

//	MMUART11_voidInit();
//	MMUART11_voidEnable();
	MUART1_voidInit();
	MUART1_voidEnable();

	MSTK_voidInit();

	MSTK_voidSetSingleIntervalMS(10, &APP_voidStartApplication);

	SHexParser_tenumStatusSetCallBack(&APP_voidStartApplication);

//	MMUART11_voidTransmit("B");
	MUART1_voidTransmit("B");
	while (!TimeOutFlag)
	{
//		Local_u8MUART11Status = MMUART11_u8ReceiveWithoutBlocking(&ReceiveBuffer[u8RecCounter]) ;
		Local_u8MUART11Status = MUART1_u8ReceiveWithoutBlocking(&ReceiveBuffer[u8RecCounter]);

		if(Local_u8MUART11Status == 1)
		{
			/*indicate The end Of the Record*/
			if(ReceiveBuffer[u8RecCounter] == '\n')
			{
				/*Parse The Record and Write it to flash*/
				Local_u8RecordStatus = SHexParser_tenumStatusParseRecord(ReceiveBuffer);
				if(u8WriteReq == 1)
				{
					/* Stop Timer Because Application Code In Processing*/
					MSTK_voidStop();
					//					/*Erase The Application Code*/
					//					if (Global_u32FlashBaseAddress == 0x08000000)
					//						MFMI_voidEraseAppArea(MFMI_BANK1);
					//					else if (Global_u32FlashBaseAddress == 0x08020000)
					//						MFMI_voidEraseAppArea(MFMI_BANK2);
					/* Clear Write request */
					u8WriteReq = 0 ;
				}
				if (Local_u8RecordStatus == OK)
				{
					/*Send ok to tool to send the next Record */
//					MMUART11_voidTransmit("K");
					MUART1_voidTransmit("K");
					/*Reset Buffer Counter*/
					u8RecCounter = 0;
				}
				else if (Local_u8RecordStatus == NOK)
				{
					/*Send NOK to tool to resend the Record */
//					MMUART11_voidTransmit("N");
					MUART1_voidTransmit("N");
					/*Reset Buffer Counter*/
					u8RecCounter = 0;
				}
			}
			else
			{
				u8RecCounter++ ;
			}

		}
		else
		{
			// Do Nothing
		}
	}
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_LOW);
	EntryPoint();
}
