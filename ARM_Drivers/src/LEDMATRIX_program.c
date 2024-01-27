/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : HAL                    ***********************/
/***********************            SWC     : LEDMATRIX              ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 24 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/STK/STK_interface.h"
#include "HAL/LEDMATRIX/LEDMATRIX_interface.h"
#include "HAL/LEDMATRIX/LEDMATRIX_private.h"
#include "HAL/LEDMATRIX/LEDMATRIX_config.h"

u8 Global_u8Rows[8] = ROWS_PINS;
u8 Global_u8Columns[8] = COLUMNS_PINS;

void LEDMATRIX_voidInit (void)
{
	u8 Local_u8Iterator;
	STK_voidInit();
	RCC_voidInit();
	RCC_voidEnablePeripheral(RCC_AHB1, COLUMNS_PORT);
	RCC_voidEnablePeripheral(RCC_AHB1, ROWS_PORT);

	for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
	{
		GPIO_voidSetMode(COLUMNS_PORT, Global_u8Columns[Local_u8Iterator], GPIO_OUTPUT);
		GPIO_voidOutputPinMode(COLUMNS_PORT, Global_u8Columns[Local_u8Iterator], GPIO_OUTPUT_PUSHPULL, GPIO_MEDIUM_SPEED);
		GPIO_voidSetPinValue(COLUMNS_PORT, Global_u8Columns[Local_u8Iterator], GPIO_PIN_LOW);
	}

	for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
	{
		GPIO_voidSetMode(ROWS_PORT, Global_u8Rows[Local_u8Iterator], GPIO_OUTPUT);
		GPIO_voidOutputPinMode(ROWS_PORT, Global_u8Rows[Local_u8Iterator], GPIO_OUTPUT_PUSHPULL, GPIO_MEDIUM_SPEED);
		GPIO_voidSetPinValue(ROWS_PORT, Global_u8Rows[Local_u8Iterator], GPIO_PIN_LOW);
	}
}

static void LEDMATRIX_voidDisableColumns (void)
{
	u8 Local_u8Iterator;
	for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
	{
		GPIO_voidSetPinValue(COLUMNS_PORT, Global_u8Columns[Local_u8Iterator], GPIO_PIN_HIGH);
	}
}

static void LEDMATRIX_voidSetRowsValue (u8 Copy_u8RowValue)
{
	u8 Local_u8Iterator;
	for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
	{
		GPIO_voidSetPinValue(ROWS_PORT, Global_u8Rows[Local_u8Iterator], GET_BIT(Copy_u8RowValue, Local_u8Iterator));
	}
}

void LEDMATRIX_voidDisplay (u8 *Copy_u8Arr)
{
	u8 Local_u8Iterator;
	LEDMATRIX_voidDisableColumns();
	for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
	{
		LEDMATRIX_voidSetRowsValue (Copy_u8Arr[Local_u8Iterator]);
		GPIO_voidSetPinValue(COLUMNS_PORT, Global_u8Columns[Local_u8Iterator], GPIO_PIN_LOW);
		STK_voidDelayUS(2500);
		GPIO_voidSetPinValue(COLUMNS_PORT, Global_u8Columns[Local_u8Iterator], GPIO_PIN_HIGH);
	}
}
