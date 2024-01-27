/*
 * MSPI_Interface.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Hesham Yasser
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

/*********************MACROs***********************/

#define MSPI_ENABLED			1
#define MSPI_DISABLED			0


#define MSPI_CLK_MODE_0			0
#define MSPI_CLK_MODE_1			1
#define MSPI_CLK_MODE_2			2
#define MSPI_CLK_MODE_3			3


#define MSPI_MASTER				1
#define MSPI_SLAVE				0


#define MSPI_PRESCALER_BY2 		0b000
#define MSPI_PRESCALER_BY4		0b001
#define MSPI_PRESCALER_BY8 		0b010
#define MSPI_PRESCALER_BY16		0b011
#define MSPI_PRESCALER_BY32 	0b100
#define MSPI_PRESCALER_BY64		0b101
#define MSPI_PRESCALER_BY128 	0b110
#define MSPI_PRESCALER_BY256 	0b111


#define MSPI_MSB_FIRST			1
#define MSPI_LSB_FIRST			0


#define MSPI_HW_SLAVE_MANAGEMENT		1
#define MSPI_SW_SLAVE_MANAGEMENT		0


#define MSPI_8BIT_DATA					0
#define MSPI_16BIT_DATA					1

#define MSPI_INTERRUPT_ENABLE			1
#define MSPI_INTERRUPT_DISABLE			0

/**********************APIs*******************/

void MSPI1_voidInit(void);

u16 MSPI1_voidSendReceiveData (u16 A_u16Data);

void MSPI1_voidSetCallBack (PtrToFunc_void p_CallBackFunc);


void MSPI2_voidInit(void);

u16 MSPI2_voidSendReceiveData (u16 A_u16Data);

void MSPI2_voidSetCallBack (PtrToFunc_void p_CallBackFunc);

u16 MSPI2_u16ReadReceivedValue(void);


#endif /* MSPI_INTERFACE_H_ */
