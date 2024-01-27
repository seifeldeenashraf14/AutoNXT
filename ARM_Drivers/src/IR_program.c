/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : HAL                    ***********************/
/***********************            SWC     : IR                     ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 21 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/STK/STK_interface.h"
#include "MCAL/NVIC/NVIC_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "HAL/IR/IR_interface.h"
#include "HAL/IR/IR_private.h"
#include "HAL/IR/IR_config.h"

static volatile u32 Global_u32Arr[33] = {0};
static volatile u8 Global_u8Iterator, Global_u8Start;
static pf Global_pfNotification = NULL;
volatile u8 Global_u8Data;

void IR_voidInit (void)
{
	/* Enable IR Line Peripheral Interrupt */
	NVIC_voidEnablePeripheralInterrupt(IR_NVIC_LINE);
	/* Set Call back for EXTI handler */
	EXTI_voidCallBack(IR_EXTI, &IR_voidReceivedData);
	/* Set IR PORT and PIN Interrupt */
	EXTI_voidSetPortInterrupt(IR_PORT, IR_EXTI);
	/* Set EXTI Trigger */
	EXTI_voidInterruptTrigger(IR_EXTI, EXTI_FALLING);
}

void IR_voidStart (pf pfCallBack)
{
	/* Check if the passes pointer to function is not NULL */
	if (NULL != pfCallBack)
	{
		Global_pfNotification = pfCallBack;
	}
	else
	{
		/* Do Nothing */
	}
	/* Enable Clock for SYSCFG */
	RCC_voidEnablePeripheral(RCC_APB2, RCC_APB2_SYSCFG);
	/* Enable Clock for IR Port */
	RCC_voidEnablePeripheral(RCC_AHB1, IR_PORT);
	/* Set pin to Input Pull up */
	GPIO_voidSetMode(IR_PORT, IR_EXTI, GPIO_INPUT);
	GPIO_voidInputPinMode(IR_PORT, IR_EXTI, GPIO_INPUT_PULL_UP);
	/* Enable Interrupt */
	EXTI_voidInterruptEnableDisable(IR_EXTI, EXTI_ENABLE);
}

void IR_voidStop (void)
{
	/* Disable Clock for SYSCFG */
	RCC_voidDisablePeripheral(RCC_APB2, RCC_APB2_SYSCFG);
	/* Disable Interrupt */
	EXTI_voidInterruptEnableDisable(IR_EXTI, EXTI_DISABLE);
}

static void IR_voidReceivedData (void)
{
	/* Check if it was the start of the signal */
	if (0 == Global_u8Start)
	{
		/* Enable STK interrupt */
		STK_voidEnableInterrupt();
		/* Set Time out value and call back function for STK handler */
		STK_voidSetSingleIntervalMS(IR_TIMEOUT, &ReadData);
		/* Indicate that the start condition is over */
		Global_u8Start = 1;
	}
	else
	{
		/* Calculate the Elapsed time and store it in array */
		STK_voidGetElapsedTime(&Global_u32Arr[Global_u8Iterator]);
		/* Set Time out value and call back function for STK handler */
		STK_voidSetSingleIntervalMS(IR_TIMEOUT, &ReadData);
		/* Increment the counter to save next signal */
		Global_u8Iterator++;
	}
}

static void ReadData (void)
{
	/* Declare a static local variable to save its value even if we finish the function */
	static u8 Local_u8Iterator;
	/* Disable EXTI */
	EXTI_voidInterruptEnableDisable(IR_EXTI, EXTI_DISABLE);
	/* Loop to read the 8 Bits Data */
	for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
	{
		/* Check if the received bit is zero */
		if (Global_u32Arr[17+Local_u8Iterator] < 1300)
		{
			/* Clear bit of Data */
			CLR_BIT(Global_u8Data, Local_u8Iterator);
		}
		/* Check if the received bit is one */
		else if (Global_u32Arr[17+Local_u8Iterator] < 2300)
		{
			/* Set bit of Data */
			SET_BIT(Global_u8Data, Local_u8Iterator);
		}
	}
	/* Check if the Global_pfNotification has valid address */
	if (NULL != Global_pfNotification)
	{
		/* Execute the user function as the data is received  */
		Global_pfNotification ();
	}
	else
	{
		/* Do Nothing */
	}
	/* Reset the Data */
	Global_u8Data = 0;
	/* Reset the Start signal flag */
	Global_u8Start = 0;
	/* Reset the Iterator */
	Global_u8Iterator = 0;
	/* Reset the first array element */
	Global_u32Arr[0] = 0;
	/* Disable STK interrupt */
	STK_voidDisableInterrupt();
	/* Enable EXTI */
	EXTI_voidInterruptEnableDisable(IR_EXTI, EXTI_ENABLE);
}
