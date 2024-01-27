/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : EXTI                   ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 12 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/EXTI/EXTI_private.h"
#include "MCAL/EXTI/EXTI_config.h"


/* static global array of pointer to function to avoid defining 15 global variable pointer to function */
static pf Global_pfNotification[15] = {NULL};

void EXTI_voidSetPortInterrupt (u8 Copy_u8PORT, u8 Copy_u8Line)
{
	/* Reset the bits of the Line in its register */
	SYSCFG->EXTICR[Copy_u8Line / DIV_FACTOR] &= ~(MASK << (DIV_FACTOR * (Copy_u8Line % DIV_FACTOR)));
	/* Set the bits of the Line in its register */
	SYSCFG->EXTICR[Copy_u8Line / DIV_FACTOR] |=  (Copy_u8PORT << (DIV_FACTOR * (Copy_u8Line % DIV_FACTOR)));
}

void EXTI_voidInterruptEnableDisable(u8 Copy_u8Line , u8 Copy_tstrState)
{
	/* Check the entered State if it was Enable */
	if (EXTI_ENABLE == Copy_tstrState)
	{
		/* Enable THe interrupt for the Line */
		SET_BIT(EXTI->IMR , Copy_u8Line);
	}
	/* Check the entered State if it was Disable */
	else if (EXTI_DISABLE == Copy_tstrState)
	{
		/* Disable THe interrupt for the Line */
		CLR_BIT(EXTI->IMR , Copy_u8Line);
	}
}

void EXTI_voidInterruptTrigger(u8 Copy_u8Line,u8 Copy_u8Trigger)
{
	/* Check if the entered Trigger is RisingEdge */
	if (EXTI_RISING == Copy_u8Trigger)
	{
		/* Set configurations of the Trigger to RisingEdge */
		CLR_BIT(EXTI->FTSR , Copy_u8Line);
		SET_BIT(EXTI->RTSR , Copy_u8Line);
	}
	/* Check if the entered Trigger is FallingEdge */
	else if (EXTI_FALLING == Copy_u8Trigger)
	{
		/* Set configurations of the Trigger to FallingEdge */
		CLR_BIT(EXTI->RTSR , Copy_u8Line);
		SET_BIT(EXTI->FTSR , Copy_u8Line);
	}
	/* Check if the entered Trigger is OnChange */
	else if (EXTI_ONCHANGE == Copy_u8Trigger)
	{
		/* Set configurations of the Trigger to OnChange */
		SET_BIT(EXTI->RTSR , Copy_u8Line);
		SET_BIT(EXTI->FTSR , Copy_u8Line);
	}
	else
	{
		/* Do Nothing */
	}
}

void EXTI_voidSetSWInterrupt (u8 Copy_u8Line)
{
	SET_BIT(EXTI->SWIER, Copy_u8Line);
}

void EXTI_voidCallBack(u8 Copy_u8Index, pf pfCallBack)
{
	/* Check if the pfCallBack has valid address or not */
	if (NULL != pfCallBack)
	{
		/* Store the address of function in static global array of pointer to function */
		Global_pfNotification[Copy_u8Index] = pfCallBack;
	}
	else
	{
		/* Do Nothing */
	}
}

/***********************            ISR for all Lines                    ***********************/

void EXTI0_IRQHandler(void)
{
	if (NULL != Global_pfNotification[0])
	{
		Global_pfNotification[0]();
	}
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, 0);
}

void EXTI1_IRQHandler(void)
{
	if (NULL != Global_pfNotification[1])
	{
		Global_pfNotification[1]();
	}
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, 1);
}

void EXTI2_IRQHandler(void)
{
	if (NULL != Global_pfNotification[2])
	{
		Global_pfNotification[2]();
	}
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, 2);
}

void EXTI3_IRQHandler(void)
{
	if (NULL != Global_pfNotification[3])
	{
		Global_pfNotification[3]();
	}
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, 3);
}

void EXTI4_IRQHandler(void)
{
	if (NULL != Global_pfNotification[4])
	{
		Global_pfNotification[4]();
	}
	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, 4);
}

void EXTI9_5_IRQHandler (void)
{
	u8 Local_u8Iterator;
	for (Local_u8Iterator = 5; Local_u8Iterator < 10; Local_u8Iterator++)
	{
		if (NULL != Global_pfNotification[Local_u8Iterator])
		{
			Global_pfNotification[Local_u8Iterator]();
		}
		else
		{
			/* Do Nothing */
		}
		SET_BIT(EXTI->PR, Local_u8Iterator);
	}
}

void EXTI15_10_IRQHandler(void)
{
	u8 Local_u8Iterator;
	for (Local_u8Iterator = 10; Local_u8Iterator <= 15; Local_u8Iterator++)
	{
		if (NULL != Global_pfNotification[Local_u8Iterator])
		{
			Global_pfNotification[Local_u8Iterator]();
		}
		else
		{
			/* Do Nothing */
		}
		SET_BIT(EXTI->PR, Local_u8Iterator);
	}
}
