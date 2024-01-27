/**
 * @file	MSTK_program.c
 * @author 	Hosam Ayoub
 * @version 1.0
 * @date 	5 oct 2023
 * @brief 	The Systick Timer C file that has all the implementations of the functions **STK** driver
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/STK/MSTK_interface.h"
#include "MCAL/STK/MSTK_private.h"
#include "MCAL/STK/MSTK_config.h"

static pf Global_pfNotification = NULL;		//!< Global pointer to function 
static u8 Global_u8IntervalMode;			//!< Global variable

/**
 * @fn 		void MSTK_voidInit (void)
 * @brief   This funciton used to Control the Clock Source and the interrupt 
 * @param 	none
 * @return 	none
 */
void MSTK_voidInit (void)
{
	/* Initialize the configuration of the interrupt and prescaler */
	CTRL = ((INTERRUPT << CTRL_TICKINT) | (PRESCALER << CTRL_CLKSOURCE));
}

/**
 * @fn 		void MSTK_voidStart (void)
 * @brief   This funciton used to Start the Timer to count down  
 * @param 	none
 * @return 	none
 */
void MSTK_voidStart (void)
{
	/* Start SysTick Timer */
	SET_BIT(CTRL, CTRL_ENABLE);
}

/**
 * @fn 		void MSTK_voidStop (void)
 * @brief   This funciton is used to stop the counting at anytime in the system  
 * @param 	none
 * @return 	none
 */
void MSTK_voidStop (void)
{
	/* Stop SysTick Timer */
	CLR_BIT(CTRL, CTRL_ENABLE);
	LOAD = 0;
	VAL = 0;
}

/**
 * @fn 		void MSTK_voidEnableInterrupt (void)
 * @brief   This funciton is used to enable the interrupt on the countflag bit when reaches to 0
 * @param 	none
 * @return 	none
 */
void MSTK_voidEnableInterrupt (void)
{
	SET_BIT(CTRL, CTRL_TICKINT);
}

/**
 * @fn 		void MSTK_voidDisableInterrupt (void)
 * @brief   This funciton is used to disable the interrupt on the countflag bit when reaches to 0  
 * @param 	none
 * @return 	none
 */
void MSTK_voidDisableInterrupt (void)
{
	CLR_BIT(CTRL, CTRL_TICKINT);
}

/**
 * @fn 		void MSTK_voidGetFlag (u8 *Pointer_u8Value)
 * @brief   This funciton is used to read the flag   
 * @param 	(u8) adress of any variable which will hold the value of the bit flag
 * @return 	none
 */
void MSTK_voidGetFlag (u8 *Pointer_u8Value)
{
	/* Get the flag value */
	*Pointer_u8Value = GET_BIT(CTRL, CTRL_COUNTFLAG);
}

/**
 * @fn 		void MSTK_voidSetLoadValue (u32 Copy_u32Ticks)
 * @brief   This funciton is used to set the value which need to count from to 0
 * @param 	(u32) the number of ticks that will be counted
 * @return 	none
 */
void MSTK_voidSetLoadValue (u32 Copy_u32Ticks)
{
	/* Load the Ticks in its register and make sure the VAL register will start from beginning */
	LOAD = Copy_u32Ticks;
	VAL = 0;
}

/**
 * @fn 		void MSTK_voidSetSingleIntervalMS (u32 Copy_u32MilliSeconds, pf pfCallBack)
 * @brief   This funciton is used to generate an interrupt after period of time
 * @param 	(u32 , pf) the Period of time and the address of the function that will be executed when the interrupt occurs
 * @return 	none
 */
void MSTK_voidSetSingleIntervalMS (u32 Copy_u32MilliSeconds, pf pfCallBack)
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

/**
 * @fn 		void MSTK_voidBusyWaiting (u32 Copy_u32Ticks)
 * @brief   This funciton is used to make the system busy for a period of time
 * @param 	(u32) the number of ticks that will be count from
 * @return 	none
 */
void MSTK_voidBusyWaiting (u32 Copy_u32Ticks)
{
	/* Load the Ticks in its register and make sure the VAL register will start from beginning */
	LOAD = Copy_u32Ticks;
	VAL = 0;
	/* Start SysTick Timer */
	SET_BIT(CTRL, CTRL_ENABLE);
	/* Polling in the Flag */
	while (!GET_BIT(CTRL, CTRL_COUNTFLAG));
}

/**
 * @fn 		void MSTK_voidDelayUS (u32 Copy_u32MicroSeconds)
 * @brief   This funciton is used to delay the system by a period of time in microseconds
 * @param 	(u32) the period of time in microseconds
 * @return 	none
 */
void MSTK_voidDelayUS (u32 Copy_u32MicroSeconds)
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

/**
 * @fn 		void MSTK_voidDelayMS (u32 Copy_u32MilliSeconds)
 * @brief   This funciton is used to delay the system by a period of time in millisecond
 * @param 	(u32) the period of time in millisecond
 * @return 	none
 */
void MSTK_voidDelayMS (u32 Copy_u32MilliSeconds)
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

/**
 * @fn 		void MSTK_voidGetRemainingTime (u32 *Pointer_u32MicroSecondsBuffer);
 * @brief   This funciton is used to calculate the remaining time untill it reaches to 0
 * @param 	(u32) address which is assign to a pointer and will assign the remaining time to this variable in millisecond
 * @return 	none
 */
void MSTK_voidGetRemainingTime (u32 *Pointer_u32MicroSecondsBuffer)
{
	/* Calculate the elapsed ticks */
	#if CLK_AHB == PRESCALER
		*Pointer_u32MicroSecondsBuffer = VAL / CLK_FREQ;
	#elif CLK_AHB_BY_8 == PRSCALER
		*Pointer_u32MicroSecondsBuffer = VAL / (CLK_FREQ / DIV_BY_8);
	#endif
}

/**
 * @fn 		void MSTK_voidGetElapsedTime (u32 *Pointer_u32MicroSecondsBuffer);
 * @brief   This funciton is used to calculate the elapsed time from it starts to count
 * @param 	(u32) address which is assign to a pointer and will assign the remaining time to this variable in microseconds
 * @return 	none
 */
void MSTK_voidGetElapsedTime (u32 *Pointer_u32MicroSecondsBuffer)
{
	/* Calculate the remaining ticks */
	#if CLK_AHB == PRESCALER
		*Pointer_u32MicroSecondsBuffer = (LOAD - VAL) / CLK_FREQ;
	#elif CLK_AHB_BY_8 == PRSCALER
		*Pointer_u32MicroSecondsBuffer = (LOAD - VAL) / (CLK_FREQ / DIV_BY_8);
	#endif
}

/**
 * @fn 		void MSTK_voidSetCallBackFunction (pf pfCallBack);
 * @brief   This funciton is used to calculate the elapsed time from it starts to count
 * @param 	pointer to funciton which holds the address of the specific funciton that will be executed when interrupt occurs
 * @return 	none
 */
void MSTK_voidSetCallBackFunction (pf pfCallBack)
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
/**
 * @fn 		void SysTick_Handler (void)
 * @brief   This funciton will be executed when the interrupt occurs then the specific funciton will be executed when global pointer funciton is called
 * @param 	none
 * @return 	none
 */
void SysTick_Handler (void)
{
	u8 Local_u8Temp;
	/* Check if the Notification has valid address */
	if (Global_pfNotification != NULL)
	{
		/* Execute the function */
		Global_pfNotification();
		/* Clear interrupt flag */
		Local_u8Temp = GET_BIT(CTRL, CTRL_COUNTFLAG);
		/* Check if it was single interval or periodic */
		if (SINGLE_INTERVAL == Global_u8IntervalMode)
		{
			/* Disable interrupt */
			CLR_BIT(CTRL, CTRL_TICKINT);
			LOAD = 0;
			VAL = 0;
		}
	}
	else
	{
		/* Do Nothing */
	}
}
