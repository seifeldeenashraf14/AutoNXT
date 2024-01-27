/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : HAL                    ***********************/
/***********************            SWC     : TFT                    ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 24 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/STK/STK_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "HAL/TFT/TFT_interface.h"
#include "HAL/TFT/TFT_private.h"
#include "HAL/TFT/TFT_config.h"

u8 Global_u8Temp;

void TFT_voidWriteCommand (u8 Copy_u8Command)
{
	GPIO_voidSetPinValue(TFT_CONTROL_PORT, TFT_CONTROL_PIN, GPIO_PIN_LOW);
	SPI1_voidTransceiveDataByte(Copy_u8Command, &Global_u8Temp);
}

void TFT_voidWriteData (u8 Copy_u8Data)
{
	GPIO_voidSetPinValue(TFT_CONTROL_PORT, TFT_CONTROL_PIN, GPIO_PIN_HIGH);
	SPI1_voidTransceiveDataByte(Copy_u8Data, &Global_u8Temp);
}

void TFT_voidReset (void)
{
	/* Reset Sequence */
	GPIO_voidSetPinValue(TFT_RESET_PORT, TFT_RESET_PIN, GPIO_PIN_HIGH);
	STK_voidDelayUS (100);
	GPIO_voidSetPinValue(TFT_RESET_PORT, TFT_RESET_PIN, GPIO_PIN_LOW);
	STK_voidDelayUS (1);
	GPIO_voidSetPinValue(TFT_RESET_PORT, TFT_RESET_PIN, GPIO_PIN_HIGH);
	STK_voidDelayUS (100);
	GPIO_voidSetPinValue(TFT_RESET_PORT, TFT_RESET_PIN, GPIO_PIN_LOW);
	STK_voidDelayUS (100);
	GPIO_voidSetPinValue(TFT_RESET_PORT, TFT_RESET_PIN, GPIO_PIN_HIGH);
	STK_voidDelayMS (120);
}

void TFT_voidInit (void)
{
	RCC_voidEnablePeripheral(RCC_AHB1, TFT_RESET_PORT);
	RCC_voidEnablePeripheral(RCC_APB2, RCC_APB2_SPI1);

	GPIO_voidSetMode(TFT_RESET_PORT, TFT_RESET_PIN, GPIO_OUTPUT);
	GPIO_voidOutputPinMode(TFT_RESET_PORT, TFT_RESET_PIN, GPIO_OUTPUT_PUSHPULL, GPIO_LOW_SPEED);

	GPIO_voidSetMode(TFT_CONTROL_PORT, TFT_CONTROL_PIN, GPIO_OUTPUT);
	GPIO_voidOutputPinMode(TFT_CONTROL_PORT, TFT_CONTROL_PIN, GPIO_OUTPUT_PUSHPULL, GPIO_LOW_SPEED);

	GPIO_voidSetMode(TFT_DATA_PORT, TFT_DATA_PIN, GPIO_ALTERNATE);
	GPIO_voidSetAlternativeLine(TFT_DATA_PORT, TFT_DATA_PIN, GPIO_AF5_SPI_1_4);

	GPIO_voidSetMode(TFT_CLOCK_PORT, TFT_CLOCK_PIN, GPIO_ALTERNATE);
	GPIO_voidSetAlternativeLine(TFT_CLOCK_PORT, TFT_CLOCK_PIN, GPIO_AF5_SPI_1_4);

	SPI1_voidInit();

	TFT_voidReset();
	TFT_voidWriteCommand(0x11); // Sleep out
	STK_voidDelayMS (150);
	/* Set color code */
	TFT_voidWriteCommand(0x3A); // command to select color mode
	TFT_voidWriteData(0x05); //RGB565
	/* Display On */
	TFT_voidWriteCommand(0x29);
	STK_voidDelayMS(1);
}

void TFT_voidDisplay (const u16 *Pointer_u16Array)
{
	u8 Local_u8TempLow, Local_u8TempHigh;
	/* Set x y */
	TFT_voidWriteCommand(0x2A); // set x
	/* Start x from (0, 0) */
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	/* End of x to (0, 127) */
	TFT_voidWriteData(0);
	TFT_voidWriteData(127);

	TFT_voidWriteCommand(0x2B); // set y
	/* Start y from (0, 0) */
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	/* End of y to (0, 159) */
	TFT_voidWriteData(0);
	TFT_voidWriteData(159);
	/* Access RAM */
	TFT_voidWriteCommand(0x2C);
	/* Send Data */
	for (u16 i = 0; i < 20480; i++)
	{
		Local_u8TempHigh = (u8)(Pointer_u16Array[i] >> 8);
		Local_u8TempLow = (u8)Pointer_u16Array[i];
		TFT_voidWriteData(Local_u8TempHigh);
		TFT_voidWriteData(Local_u8TempLow);
	}
}


void TFT_voidDisplayColor (u16 Copy_u16Color)
{
	u8 Local_u8TempLow, Local_u8TempHigh;
	/* Set x y */
	TFT_voidWriteCommand(0x2A); // set x
	/* Start x from (0, 0) */
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	/* End of x to (0, 127) */
	TFT_voidWriteData(0);
	TFT_voidWriteData(127);

	TFT_voidWriteCommand(0x2B); // set y
	/* Start y from (0, 0) */
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	/* End of y to (0, 159) */
	TFT_voidWriteData(0);
	TFT_voidWriteData(159);
	/* Access RAM */
	TFT_voidWriteCommand(0x2C);
	/* Send Data */
	for (u16 i = 0; i < 20480; i++)
	{
		Local_u8TempHigh = (u8)(Copy_u16Color >> 8);
		Local_u8TempLow = (u8)Copy_u16Color;
		TFT_voidWriteData(Local_u8TempHigh);
		TFT_voidWriteData(Local_u8TempLow);
	}
}
