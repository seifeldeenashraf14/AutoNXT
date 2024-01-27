/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : HAL                    ***********************/
/***********************            SWC     : STP                    ***********************/
/***********************            Version : 2.0                    ***********************/
/***********************            Date    : 05 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/STK/STK_interface.h"
#include "HAL/STP/STP_interface.h"
#include "HAL/STP/STP_private.h"
#include "HAL/STP/STP_config.h"

void STP_voidInit(void)
{
	/* Enable CLock for STP STP1_SERIAL_DATA_PORT */
	RCC_voidEnablePeripheral(RCC_AHB1, STP1_SERIAL_DATA_PORT);
	/* Enable CLock for STP STP1_SHIFT_CLOCK_PORT */
	RCC_voidEnablePeripheral(RCC_AHB1, STP1_SHIFT_CLOCK_PORT);
	/* Enable CLock for STP STP1_STORAGE_CLOCK_PORT */
	RCC_voidEnablePeripheral(RCC_AHB1, STP1_STORAGE_CLOCK_PORT);

	/* Set STP1_SERIAL_DATA_PIN Direction */
	GPIO_voidSetMode(STP1_SERIAL_DATA_PORT, STP1_SERIAL_DATA_PIN, GPIO_OUTPUT);
	/* Set STP1_SHIFT_CLOCK_PIN Direction */
	GPIO_voidSetMode(STP1_SHIFT_CLOCK_PORT, STP1_SHIFT_CLOCK_PIN, GPIO_OUTPUT);
	/* Set STP1_STORAGE_CLOCK_PIN Direction */
	GPIO_voidSetMode(STP1_STORAGE_CLOCK_PORT, STP1_STORAGE_CLOCK_PIN, GPIO_OUTPUT);

	/* Configure STP1_SERIAL_DATA_PIN */
	GPIO_voidOutputPinMode(STP1_SERIAL_DATA_PORT, STP1_SERIAL_DATA_PIN, GPIO_OUTPUT_PUSHPULL, GPIO_LOW_SPEED);
	/* Configure STP1_SHIFT_CLOCK_PIN */
	GPIO_voidOutputPinMode(STP1_SHIFT_CLOCK_PORT, STP1_SHIFT_CLOCK_PIN, GPIO_OUTPUT_PUSHPULL, GPIO_LOW_SPEED);
	/* Configure STP1_STORAGE_CLOCK_PIN */
	GPIO_voidOutputPinMode(STP1_STORAGE_CLOCK_PORT, STP1_STORAGE_CLOCK_PIN, GPIO_OUTPUT_PUSHPULL, GPIO_LOW_SPEED);

	#if 2 == STP_NUMBER
		/* Enable CLock for STP STP2_SERIAL_DATA_PORT */
		RCC_voidEnablePeripheral(RCC_AHB1, STP2_SERIAL_DATA_PORT);
		/* Enable CLock for STP STP2_SHIFT_CLOCK_PORT */
		RCC_voidEnablePeripheral(RCC_AHB1, STP2_SHIFT_CLOCK_PORT);
		/* Enable CLock for STP STP2_STORAGE_CLOCK_PORT */
		RCC_voidEnablePeripheral(RCC_AHB1, STP2_STORAGE_CLOCK_PORT);

		/* Set STP2_SERIAL_DATA_PIN Direction */
		GPIO_voidSetMode(STP2_SERIAL_DATA_PORT, STP2_SERIAL_DATA_PIN, GPIO_OUTPUT);
		/* Set STP2_SHIFT_CLOCK_PIN Direction */
		GPIO_voidSetMode(STP2_SHIFT_CLOCK_PORT, STP2_SHIFT_CLOCK_PIN, GPIO_OUTPUT);
		/* Set STP2_STORAGE_CLOCK_PIN Direction */
		GPIO_voidSetMode(STP2_STORAGE_CLOCK_PORT, STP2_STORAGE_CLOCK_PIN, GPIO_OUTPUT);

		/* Configure STP2_SERIAL_DATA_PIN */
		GPIO_voidOutputPinMode(STP2_SERIAL_DATA_PORT, STP2_SERIAL_DATA_PIN, GPIO_OUTPUT_PUSHPULL, GPIO_LOW_SPEED);
		/* Configure STP2_SHIFT_CLOCK_PIN */
		GPIO_voidOutputPinMode(STP2_SHIFT_CLOCK_PORT, STP2_SHIFT_CLOCK_PIN, GPIO_OUTPUT_PUSHPULL, GPIO_LOW_SPEED);
		/* Configure STP2_STORAGE_CLOCK_PIN */
		GPIO_voidOutputPinMode(STP2_STORAGE_CLOCK_PORT, STP2_STORAGE_CLOCK_PIN, GPIO_OUTPUT_PUSHPULL, GPIO_LOW_SPEED);
	#endif
}

void STP_voidSendDataSynchronouseTwoSTP (u8 Copy_u8Data1, u8 Copy_u8Data2)
{
	s8 Local_s8Iterator;
	for (Local_s8Iterator = 7; Local_s8Iterator > -1; Local_s8Iterator--)
	{
		/* Send Data From MSB to LSB bit by bit */
		GPIO_voidSetPinValue(STP1_SERIAL_DATA_PORT, STP1_SERIAL_DATA_PIN, GET_BIT(Copy_u8Data1, Local_s8Iterator));
		GPIO_voidSetPinValue(STP1_SERIAL_DATA_PORT, STP1_SERIAL_DATA_PIN, GET_BIT(Copy_u8Data2, Local_s8Iterator));
		/* Send Pulse to Shift clock */
		GPIO_voidSetPinValue(STP1_SHIFT_CLOCK_PORT, STP1_SHIFT_CLOCK_PIN, GPIO_PIN_HIGH);
		GPIO_voidSetPinValue(STP1_SHIFT_CLOCK_PORT, STP2_SHIFT_CLOCK_PIN, GPIO_PIN_HIGH);
		STK_voidDelayUS(1);
		GPIO_voidSetPinValue(STP1_SHIFT_CLOCK_PORT, STP1_SHIFT_CLOCK_PIN, GPIO_PIN_LOW);
		GPIO_voidSetPinValue(STP1_SHIFT_CLOCK_PORT, STP2_SHIFT_CLOCK_PIN, GPIO_PIN_LOW);
		STK_voidDelayUS(1);
	}
	/* Send Pulse to storage clock */
	GPIO_voidSetPinValue(STP1_STORAGE_CLOCK_PORT, STP1_STORAGE_CLOCK_PIN, GPIO_PIN_HIGH);
	GPIO_voidSetPinValue(STP1_STORAGE_CLOCK_PORT, STP2_STORAGE_CLOCK_PIN, GPIO_PIN_HIGH);
	STK_voidDelayUS(1);
	GPIO_voidSetPinValue(STP1_STORAGE_CLOCK_PORT, STP1_STORAGE_CLOCK_PIN, GPIO_PIN_LOW);
	GPIO_voidSetPinValue(STP1_STORAGE_CLOCK_PORT, STP2_STORAGE_CLOCK_PIN, GPIO_PIN_LOW);
	STK_voidDelayUS(1);
}

void STP_voidSendDataSynchronouseOneSTP (u8 Copy_u8Index, u8 Copy_u8Data)
{
	s8 Local_s8Iterator;
	if (STP1 == Copy_u8Index)
	{
		for (Local_s8Iterator = 7; Local_s8Iterator > -1; Local_s8Iterator--)
		{
			/* Send Data From MSB to LSB bit by bit */
			GPIO_voidSetPinValue(STP1_SERIAL_DATA_PORT, STP1_SERIAL_DATA_PIN, GET_BIT(Copy_u8Data, Local_s8Iterator));
			/* Send Pulse to Shift clock */
			GPIO_voidSetPinValue(STP1_SHIFT_CLOCK_PORT, STP1_SHIFT_CLOCK_PIN, GPIO_PIN_HIGH);
			STK_voidDelayUS(1);
			GPIO_voidSetPinValue(STP1_SHIFT_CLOCK_PORT, STP1_SHIFT_CLOCK_PIN, GPIO_PIN_LOW);
			STK_voidDelayUS(1);
		}
		/* Send Pulse to storage clock */
		GPIO_voidSetPinValue(STP1_STORAGE_CLOCK_PORT, STP1_STORAGE_CLOCK_PIN, GPIO_PIN_HIGH);
		STK_voidDelayUS(1);
		GPIO_voidSetPinValue(STP1_STORAGE_CLOCK_PORT, STP1_STORAGE_CLOCK_PIN, GPIO_PIN_LOW);
		STK_voidDelayUS(1);
	}
	else if (STP2 == Copy_u8Index)
	{
		for (Local_s8Iterator = 7; Local_s8Iterator > -1; Local_s8Iterator--)
		{
			/* Send Data From MSB to LSB bit by bit */
			GPIO_voidSetPinValue(STP2_SERIAL_DATA_PORT, STP2_SERIAL_DATA_PIN, GET_BIT(Copy_u8Data, Local_s8Iterator));
			/* Send Pulse to Shift clock */
			GPIO_voidSetPinValue(STP2_SHIFT_CLOCK_PORT, STP2_SHIFT_CLOCK_PIN, GPIO_PIN_HIGH);
			STK_voidDelayUS(1);
			GPIO_voidSetPinValue(STP2_SHIFT_CLOCK_PORT, STP2_SHIFT_CLOCK_PIN, GPIO_PIN_LOW);
			STK_voidDelayUS(1);
		}
		/* Send Pulse to storage clock */
		GPIO_voidSetPinValue(STP2_STORAGE_CLOCK_PORT, STP2_STORAGE_CLOCK_PIN, GPIO_PIN_HIGH);
		STK_voidDelayUS(1);
		GPIO_voidSetPinValue(STP2_STORAGE_CLOCK_PORT, STP2_STORAGE_CLOCK_PIN, GPIO_PIN_LOW);
		STK_voidDelayUS(1);
	}
	else
	{
		/* Do nothing */
	}
}
