/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : NVIC                   ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 11 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS						(0xE000E100)

typedef struct
{
	u32 ISER[8];
	u32 RESERVERD1[24];
	u32 ICER[8];
	u32 RESERVERD2[24];
	u32 ISPR[8];
	u32 RESERVERD3[24];
	u32 ICPR[8];
	u32 RESERVERD4[24];
	u32 IABR[8];
	u32 RESERVERD5[56];
	u8 IPR[240];
	u32 RESERVERD6[580];
	u32 STIR;
}tstrNVIC;

#define NVIC									((volatile tstrNVIC *) NVIC_BASE_ADDRESS)
#define SCB_AIRCR								(*(volatile u32 *) 0xE000ED0C)
#define NVIC_VECTKEY							0x05FA0000
#define NVIC_PRIGROUP_SHIFT						8

#endif
