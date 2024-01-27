/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : RCC                    ***********************/
/***********************            Version : 2.0                    ***********************/
/***********************            Date    : 18 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define RCC_BASE_ADDRESS				0x40023800

typedef struct
{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 RESERVED1;
	u32 RESERVED2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 RESERVED3;
	u32 RESERVED4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 RESERVED5;
	u32 RESERVED6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 RESERVED7;
	u32 RESERVED8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 RESERVED9;
	u32 RESERVED10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 RESERVED11;
	u32 RESERVED12;
	u32 BDCR;
	u32 CSR;
	u32 RESERVED13;
	u32 RESERVED14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 RESERVED15;
	u32 DCKCFGR;
}tstrRCC;

#define RCC 							((volatile tstrRCC *)RCC_BASE_ADDRESS)


/* CFGR */
#define CFGR_SW0						0
#define CFGR_PPRE2						13
#define CFGR_PPRE1						10
#define CFGR_HPRE						4


/* CR */
#define CR_HSI_ON						0
#define CR_HSI_RDY						1
#define CR_HSITRIM0						3
#define CR_HSE_ON						16
#define CR_HSE_RDY						17
#define CR_HSE_BYP						18
#define CR_CSS_ON						19
#define CR_PLL_ON						24
#define CR_PLL_RDY						25

/* PLLCFGR */
#define PLLCFGR_PLLCFGR					22
#define PLLCFGR_PLLP0					16
#define PLLCFGR_PLLN					6

#define TWO_BITS_MASK					0b11
#define THREE_BITS_MASK					0b111
#define FOUR_BITS_MASK					0b1111
#define NINE_BITS_MASK					0b111111111

/* System Clock Switch */
#define SW_HSI							0
#define SW_HSE							1
#define SW_PLL							2

#define HSITRIM_MASK					0x00000080

#endif
