/*
 * EXTI_Program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Hesham Yasser
 */


#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/MCAL/EXTI/MEXTI_Interface.h"
#include "../include/MCAL/EXTI/MEXTI_Private.h"
#include "../include/MCAL/EXTI/MEXTI_Config.h"

extern MEXTI_Configuartions MEXTI_Config[MEXTI_NUMBER];

static pf MEXTI_CallBack[MEXTI_TOTAL_NUMBER];

void MEXTI_voidInit (void)
{
	/*initialize an iterator to iterate on the EXTIs in configuration source file*/
	u8 local_u8Iterator = 0;
	for (local_u8Iterator = 0 ; local_u8Iterator < MEXTI_NUMBER ; local_u8Iterator++)
	{
		/*Set the EXTI port*/
		SYSCFG->EXTICR[((MEXTI_Config[local_u8Iterator].Line)/4)] &= ~(FOUR_BIT_MASK << (((MEXTI_Config[local_u8Iterator].Line)%4)*4));
		SYSCFG->EXTICR[((MEXTI_Config[local_u8Iterator].Line)/4)] |=  (MEXTI_Config[local_u8Iterator].Port << (((MEXTI_Config[local_u8Iterator].Line)%4)*4));
		/*Set the EXTI mode*/
		if (MEXTI_Config[local_u8Iterator].Mode == MEXTI_FALLING_EDGE)
		{
			SET_BIT(EXTI->FTSR , MEXTI_Config[local_u8Iterator].Line);
		}
		else if (MEXTI_Config[local_u8Iterator].Mode == MEXTI_RISING_EDGE)
		{
			SET_BIT(EXTI->RTSR , MEXTI_Config[local_u8Iterator].Line);
		}
		else
		{
			SET_BIT(EXTI->FTSR , MEXTI_Config[local_u8Iterator].Line);
			SET_BIT(EXTI->RTSR , MEXTI_Config[local_u8Iterator].Line);
		}
		/*Set state of EXTI based on the given Intial Value*/
		if (MEXTI_Config[local_u8Iterator].InitialValue == MEXTI_ENABLED)
		{
			SET_BIT(EXTI->IMR , MEXTI_Config[local_u8Iterator].Line);
		}
		else
		{
			CLR_BIT(EXTI->IMR , MEXTI_Config[local_u8Iterator].Line);
		}
	}

}

void MEXTI_voidEnableEXTILine (MEXTI_Line A_MEXTI_Line)
{
	/*Set the corresponding bit to enable the entered EXTI*/
	SET_BIT(EXTI->IMR , A_MEXTI_Line);
}

void MEXTI_voidDisableEXTILine (MEXTI_Line A_MEXTI_Line)
{
	/*Clear the corresponding bit to disable the entered EXTI*/
	CLR_BIT(EXTI->IMR , A_MEXTI_Line);
}

void MEXTI_voidSetCallBack (MEXTI_Line A_MEXTI_Line , pf A_CallBackFunc)
{
	/*Set the entered function to the entered EXTI Callback function pointer*/
	MEXTI_CallBack[A_MEXTI_Line] = A_CallBackFunc;
}

void MEXTI_voidSoftwareInterrputRequest (MEXTI_Line A_MEXTI_Line)
{
	/*Set the corresponding bit to trigger an interrupt request*/
	SET_BIT(EXTI->SWIER , A_MEXTI_Line);
}

void MEXTI_voidClearPendingFlag (MEXTI_Line A_MEXTI_Line)
{
	/*Set the corresponding bit to clear the pending flag*/
	SET_BIT(EXTI->PR , A_MEXTI_Line);
}

void MEXTI_voidSelectPort (MEXTI_Line A_MEXTI_Line , MEXTI_Port A_MEXTI_Port)
{
	/*Set those bits based on the entered port and EXTI*/
	SYSCFG->EXTICR[(A_MEXTI_Line/4)] &= ~(FOUR_BIT_MASK << ((A_MEXTI_Line%4)*4));
	SYSCFG->EXTICR[(A_MEXTI_Line/4)] |=  (A_MEXTI_Port << ((A_MEXTI_Line%4)*4));
}

void MEXTI_voidSetMode (MEXTI_Line A_MEXTI_Line , MEXTI_Mode A_MEXTI_Mode)
{
	/*Set those bits based on the entered mode and EXTI*/
	if (A_MEXTI_Mode == MEXTI_FALLING_EDGE)
	{
		SET_BIT(EXTI->FTSR , A_MEXTI_Line);
	}
	else if (A_MEXTI_Mode == MEXTI_RISING_EDGE)
	{
		SET_BIT(EXTI->RTSR , A_MEXTI_Line);
	}
	else
	{
		SET_BIT(EXTI->FTSR , A_MEXTI_Line);
		SET_BIT(EXTI->RTSR , A_MEXTI_Line);
	}
}


void EXTI0_IRQHandler (void)
{
	SET_BIT(EXTI->PR , MEXTI_LINE0);
	if (MEXTI_CallBack[MEXTI_LINE0] != NULL)
	{
		MEXTI_CallBack[MEXTI_LINE0]();
	}
}
void EXTI1_IRQHandler (void)
{
	SET_BIT(EXTI->PR , MEXTI_LINE1);
	if (MEXTI_CallBack[MEXTI_LINE1] != NULL)
	{
		MEXTI_CallBack[MEXTI_LINE1]();
	}
}
