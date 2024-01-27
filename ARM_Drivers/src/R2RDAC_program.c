/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : HAL                    ***********************/
/***********************            SWC     : R2RDAC                 ***********************/
/***********************            Version : 1.5                    ***********************/
/***********************            Date    : 05 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HAL/R2RDAC/R2RDAC_config.h"
#include "HAL/R2RDAC/R2RDAC_interface.h"
#include "HAL/R2RDAC/R2RDAC_private.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/STK/STK_interface.h"

void R2RDAC_voidInit (void)
{
	/* Set DAC_PORT Mode to be Output */
	GPIO_voidSetMode(DAC_PIN0, GPIO_OUTPUT);
	GPIO_voidSetMode(DAC_PIN1, GPIO_OUTPUT);
	GPIO_voidSetMode(DAC_PIN2, GPIO_OUTPUT);
	GPIO_voidSetMode(DAC_PIN3, GPIO_OUTPUT);
	GPIO_voidSetMode(DAC_PIN4, GPIO_OUTPUT);
	GPIO_voidSetMode(DAC_PIN5, GPIO_OUTPUT);
	GPIO_voidSetMode(DAC_PIN6, GPIO_OUTPUT);
	GPIO_voidSetMode(DAC_PIN7, GPIO_OUTPUT);

	/* Set DAC_PORT OutputMode and Speed to be PushPull and MediumSpeed */
	GPIO_voidOutputPinMode(DAC_PIN0, GPIO_OUTPUT_PUSHPULL, GPIO_MEDIUM_SPEED);
	GPIO_voidOutputPinMode(DAC_PIN1, GPIO_OUTPUT_PUSHPULL, GPIO_MEDIUM_SPEED);
	GPIO_voidOutputPinMode(DAC_PIN2, GPIO_OUTPUT_PUSHPULL, GPIO_MEDIUM_SPEED);
	GPIO_voidOutputPinMode(DAC_PIN3, GPIO_OUTPUT_PUSHPULL, GPIO_MEDIUM_SPEED);
	GPIO_voidOutputPinMode(DAC_PIN4, GPIO_OUTPUT_PUSHPULL, GPIO_MEDIUM_SPEED);
	GPIO_voidOutputPinMode(DAC_PIN5, GPIO_OUTPUT_PUSHPULL, GPIO_MEDIUM_SPEED);
	GPIO_voidOutputPinMode(DAC_PIN6, GPIO_OUTPUT_PUSHPULL, GPIO_MEDIUM_SPEED);
	GPIO_voidOutputPinMode(DAC_PIN7, GPIO_OUTPUT_PUSHPULL, GPIO_MEDIUM_SPEED);
}

void R2RDAC_voidSetData (const u8 *Pointer_u8Arr, u32 Copy_u32ArrSize)
{
	extern u8 Global_u8Break;
	/* Initialize iterator */
	u32 Local_u32Counter = 0;
	for (Local_u32Counter = 0; Local_u32Counter < Copy_u32ArrSize; Local_u32Counter++)
	{
		if (Global_u8Break)
		{
			break;
		}
		else
		{
			/* Set DAC_PORT PINs based on the given Array */
			GPIO_voidSetPinValue(DAC_PIN0, GET_BIT(Pointer_u8Arr[Local_u32Counter], GPIO_PIN0));
			GPIO_voidSetPinValue(DAC_PIN1, GET_BIT(Pointer_u8Arr[Local_u32Counter], GPIO_PIN1));
			GPIO_voidSetPinValue(DAC_PIN2, GET_BIT(Pointer_u8Arr[Local_u32Counter], GPIO_PIN2));
			GPIO_voidSetPinValue(DAC_PIN3, GET_BIT(Pointer_u8Arr[Local_u32Counter], GPIO_PIN3));
			GPIO_voidSetPinValue(DAC_PIN4, GET_BIT(Pointer_u8Arr[Local_u32Counter], GPIO_PIN4));
			GPIO_voidSetPinValue(DAC_PIN5, GET_BIT(Pointer_u8Arr[Local_u32Counter], GPIO_PIN5));
			GPIO_voidSetPinValue(DAC_PIN6, GET_BIT(Pointer_u8Arr[Local_u32Counter], GPIO_PIN6));
			GPIO_voidSetPinValue(DAC_PIN7, GET_BIT(Pointer_u8Arr[Local_u32Counter], GPIO_PIN7));
			/* Make a delay using SysTick to reach 8kHz */
			STK_voidDelayUS(100);
		}
	}
}
