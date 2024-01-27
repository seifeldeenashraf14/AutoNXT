/*
 * NVIC_Interface.h
 *
 *  Created on: Sep 11, 2023
 *      Author: Hesham Yasser
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef enum{
	Groups16_NoSub = 3,
	Groups8_Sub2,
	Groups2_Sub8,
	Groups4_Sub4,
	NoGroup_Sub16
}MNVIC_Group_t;

void MNVIC_voidEnablePeripheralInterrupt(u8 A_u8Peripheral);
void MNVIC_voidDisablePeripheralInterrupt(u8 A_u8Peripheral);
void MNVIC_voidSetPeripheralInterruptPending(u8 A_u8Peripheral);
void MNVIC_voidClearPeripheralInterruptPending(u8 A_u8Peripheral);
void MNVIC_voidGetInterruptState(u8 A_u8Peripheral , u8 * p_Read);
void MNVIC_voidSetInterruptGroupMode (MNVIC_Group_t  A_MNVIC_Group_t_Mode);
void MNVIC_voidSetInterruptPriority (u8 A_u8Peripheral , u8 A_u8GroupNumber , u8 A_u8SubNumber);






#endif /* NVIC_INTERFACE_H_ */
