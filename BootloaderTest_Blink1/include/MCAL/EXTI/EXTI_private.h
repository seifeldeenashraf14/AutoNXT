/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : EXTI                   ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 12 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESS					(0x40013C00)
#define SYSCFG_BASE_ADDRESS					(0x40013800)

typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}tstrEXTI;

typedef struct
{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 RESERVED1;
	u32 RESERVED2;
	u32 CMPCR;
}tstrSYSCFG;

#define EXTI								((volatile tstrEXTI *) EXTI_BASE_ADDRESS)
#define SYSCFG								((volatile tstrSYSCFG *) SYSCFG_BASE_ADDRESS)
#define MASK								0b1111
#define DIV_FACTOR							4

#endif
