/*
 * NVIC_Program.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Hesham Yasser
 */
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/MCAL/NVIC/MNVIC_Interface.h"
#include "../include/MCAL/NVIC/MNVIC_Private.h"
#include "../include/MCAL/NVIC/MNVIC_Config.h"

// ENABLE SYSCFG IN RCC BEFORE STARTING
static MNVIC_Group_t sglobal_MNVIC_Group_t_Mode ;

void MNVIC_voidEnablePeripheralInterrupt(u8 A_u8Peripheral)
{
	/*Set the corresponding bit to enable peripheral interrupt*/
	SET_BIT(NVIC->ISER[(A_u8Peripheral/BITS_IN_REGISTER)] , (A_u8Peripheral%BITS_IN_REGISTER));
}
void MNVIC_voidDisablePeripheralInterrupt(u8 A_u8Peripheral)
{
	/*Set the corresponding bit to Disable peripheral interrupt*/
	SET_BIT(NVIC->ICER[(A_u8Peripheral/BITS_IN_REGISTER)] , (A_u8Peripheral%BITS_IN_REGISTER));

}
void MNVIC_voidSetPeripheralInterruptPending(u8 A_u8Peripheral)
{
	/*Set the corresponding bit to set peripheral pending flag*/
	SET_BIT(NVIC->ISPR[(A_u8Peripheral/BITS_IN_REGISTER)] , (A_u8Peripheral%BITS_IN_REGISTER));

}
void MNVIC_voidClearPeripheralInterruptPending(u8 A_u8Peripheral)
{
	/*Set the corresponding bit to clear peripheral pending falg*/
	SET_BIT(NVIC->ICPR[(A_u8Peripheral/BITS_IN_REGISTER)] , (A_u8Peripheral%BITS_IN_REGISTER));

}
void MNVIC_voidGetInterruptState(u8 A_u8Peripheral , u8 * p_Read)
{
	/*Get the state of peripheral interrput*/
	*p_Read = GET_BIT(NVIC->IABR[(A_u8Peripheral/BITS_IN_REGISTER)] , (A_u8Peripheral%BITS_IN_REGISTER));
}
void MNVIC_voidSetInterruptGroupMode (MNVIC_Group_t  A_MNVIC_Group_t_Mode)
{
	/*Save the group mode in a static global variable*/
	sglobal_MNVIC_Group_t_Mode = A_MNVIC_Group_t_Mode;
	SCB_AIRCR = (SCB_AIRCR_VECT_KEY | A_MNVIC_Group_t_Mode<<AICIR_PRIGROUP_b0);
}


void MNVIC_voidSetInterruptPriority (u8 A_u8Peripheral , u8 A_u8GroupNumber , u8 A_u8SubNumber)
{
	/*Switch on the entered mode*/
	switch (sglobal_MNVIC_Group_t_Mode)
	{
	case Groups16_NoSub :
		/*Set group and sub priority based on the mode*/
		NVIC->IPR[A_u8Peripheral] = (A_u8GroupNumber<<4);
		break;
	case Groups8_Sub2 :
		/*Set group and sub priority based on the mode*/
		NVIC->IPR[A_u8Peripheral] = (A_u8GroupNumber<<5|A_u8SubNumber<<4);
		break;
	case Groups4_Sub4 :
		/*Set group and sub priority based on the mode*/
		NVIC->IPR[A_u8Peripheral] = (A_u8GroupNumber<<6|A_u8SubNumber<<4);
		break;
	case Groups2_Sub8 :
		/*Set group and sub priority based on the mode*/
		NVIC->IPR[A_u8Peripheral] = (A_u8GroupNumber<<7|A_u8SubNumber<<4);
		break;
	case NoGroup_Sub16 :
		/*Set group and sub priority based on the mode*/
		NVIC->IPR[A_u8Peripheral] = (A_u8SubNumber<<4);
		break;
	}
}
