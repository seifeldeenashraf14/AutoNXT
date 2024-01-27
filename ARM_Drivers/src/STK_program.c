/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : STK                    ***********************/
/***********************            Version : 2.0                    ***********************/
/***********************            Date    : 05 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/STK/STK_interface.h"
#include "MCAL/STK/STK_private.h"
#include "MCAL/STK/STK_config.h"

static pf Global_pfNotification = NULL;
static u8 Global_u8IntervalMode;

void STK_voidInit (void)
{
	/* Initialize the configuration of the interrupt and prescaler */
	CTRL = ((INTERRUPT << CTRL_TICKINT) | (PRESCALER << CTRL_CLKSOURCE));
}

void STK_voidStart (void)
{
	/* Start SysTick Timer */
	SET_BIT(CTRL, CTRL_ENABLE);
}

void STK_voidStop (void)
{
	/* Stop SysTick Timer */
	CLR_BIT(CTRL, CTRL_ENABLE);
}

void STK_voidEnableInterrupt (void)
{
	SET_BIT(CTRL, CTRL_TICKINT);
}

void STK_voidDisableInterrupt (void)
{
	CLR_BIT(CTRL, CTRL_TICKINT);
}

void STK_voidGetFlag (u8 *Pointer_u8Value)
{
	/* Get the flag value */
	*Pointer_u8Value = GET_BIT(CTRL, CTRL_COUNTFLAG);
}

void STK_voidSetLoadValue (u32 Copy_u32Ticks)
{
	/* Load the Ticks in its register and make sure the VAL register will start from beginning */
	LOAD = Copy_u32Ticks;
	VAL = 0;
}

void STK_voidSetSingleIntervalMS (u32 Copy_u32MilliSeconds, pf pfCallBack)
{
	/* Load the Ticks in its register and make sure the VAL register will start from beginning */
	LOAD = Copy_u32MilliSeconds * (CLK_FREQ * 1E3);
	VAL = 0;

	/* Enable interrupt */
	SET_BIT(CTRL, CTRL_TICKINT);

	Global_u8IntervalMode = SINGLE_INTERVAL;

	/* Check if the CallBack has valid address */
	if (pfCallBack != NULL)
	{
		/* Store function address in static global pointer to function variable */
		Global_pfNotification = pfCallBack;
	}
	else
	{
		/* Do Nothing */
	}
	/* Start SysTick Timer */
	SET_BIT(CTRL, CTRL_ENABLE);
}

void STK_voidBusyWaiting (u32 Copy_u32Ticks)
{
	/* Load the Ticks in its register and make sure the VAL register will start from beginning */
	LOAD = Copy_u32Ticks;
	VAL = 0;
	/* Start SysTick Timer */
	SET_BIT(CTRL, CTRL_ENABLE);
	/* Polling in the Flag */
	while (!GET_BIT(CTRL, CTRL_COUNTFLAG));
}

void STK_voidDelayUS (u32 Copy_u32MicroSeconds)
{
	/* This is only for 16 MHz Clock */
	/* Load the Ticks in its register and make sure the VAL register will start from beginning */
	LOAD = Copy_u32MicroSeconds * CLK_FREQ;
	VAL = 0;
	/* Start SysTick Timer */
	SET_BIT(CTRL, CTRL_ENABLE);
	/* Polling in the Flag */
	while (!GET_BIT(CTRL, CTRL_COUNTFLAG));
}

void STK_voidDelayMS (u32 Copy_u32MilliSeconds)
{
	/* This is only for 16 MHz Clock */
	/* Load the Ticks in its register and make sure the VAL register will start from beginning */
	LOAD = Copy_u32MilliSeconds * (CLK_FREQ * 1E3);
	VAL = 0;
	/* Start SysTick Timer */
	SET_BIT(CTRL, CTRL_ENABLE);
	/* Polling in the Flag */
	while (!GET_BIT(CTRL, CTRL_COUNTFLAG));
}

void STK_voidGetRemainingTime (u32 *Pointer_u32MicroSecondsBuffer)
{
	/* Calculate the elapsed ticks */
	#if CLK_AHB == PRESCALER
		*Pointer_u32MicroSecondsBuffer = VAL / CLK_FREQ;
	#elif CLK_AHB_BY_8 == PRSCALER
		*Pointer_u32MicroSecondsBuffer = VAL / (CLK_FREQ / DIV_BY_8);
	#endif
}

void STK_voidGetElapsedTime (u32 *Pointer_u32MicroSecondsBuffer)
{
	/* Calculate the remaining ticks */
	#if CLK_AHB == PRESCALER
		*Pointer_u32MicroSecondsBuffer = (LOAD - VAL) / CLK_FREQ;
	#elif CLK_AHB_BY_8 == PRSCALER
		*Pointer_u32MicroSecondsBuffer = (LOAD - VAL) / (CLK_FREQ / DIV_BY_8);
	#endif
}

void STK_voidSetCallBackFunction (pf pfCallBack)
{
	/* Check if the CallBack has valid address */
	if (pfCallBack != NULL)
	{
		/* Store function address in static global pointer to function variable */
		Global_pfNotification = pfCallBack;
	}
	else
	{
		/* Do Nothing */
	}
}

void SysTick_Handler (void)
{
	u8 Local_u8Temp;
	/* Check if the Notification has valid address */
	if (Global_pfNotification != NULL)
	{
		if (SINGLE_INTERVAL == Global_u8IntervalMode)
		{
			/* Disable interrupt */
			CLR_BIT(CTRL, CTRL_TICKINT);
			LOAD = 0;
			VAL = 0;
		}
		/* Execute the function */
		Global_pfNotification();
		/* Clear interrupt flag */
		Local_u8Temp = GET_BIT(CTRL, CTRL_COUNTFLAG);
	}
	else
	{
		/* Do Nothing */
	}
}
