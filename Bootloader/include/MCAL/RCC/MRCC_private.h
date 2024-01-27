/**
 * @file MRCC_private.h
 * @author Hosam Ayoub
 * @version 2.0
 * @date 18 Sep 2023
 * @brief The Reset Clock Control header file that has all the addresses of the registers, their base address and any private macros of the **RCC** driver
 */
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define RCC_BASE_ADDRESS				0x40023800         //!< The *RCC** Base address
/**
 * @struct 	tstrRCC
 * @brief	This struct has all the RCC registers
 *
 */
typedef struct
{
	u32 CR;                 //!< RCC clock control register
	u32 PLLCFGR;            //!< RCC PLL configuration register
	u32 CFGR;               //!< RCC clock configuration register
	u32 CIR;                //!< RCC clock interrupt register
	u32 AHB1RSTR;           //!< RCC AHB1 peripheral reset register
	u32 AHB2RSTR;           //!< RCC AHB2 peripheral reset register
	u32 RESERVED1;          //!< RCC Reserved Register
	u32 RESERVED2;          //!< RCC Reserved Register
	u32 APB1RSTR;           //!< RCC APB1 peripheral reset register
	u32 APB2RSTR;           //!< RCC APB2 peripheral reset register
	u32 RESERVED3;          //!< RCC Reserved Register
	u32 RESERVED4;          //!< RCC Reserved Register
	u32 AHB1ENR;            //!< RCC AHB1 peripheral reset register
	u32 AHB2ENR;            //!< RCC AHB1 peripheral clock enable register
	u32 RESERVED5;          //!< RCC Reserved Register
	u32 RESERVED6;          //!< RCC Reserved Register
	u32 APB1ENR;            //!< RCC AHB2 peripheral clock enable register
	u32 APB2ENR;            //!< RCC APB1 peripheral clock enable register
	u32 RESERVED7;          //!< RCC Reserved Register
	u32 RESERVED8;          //!< RCC Reserved Register
	u32 AHB1LPENR;          //!< RCC AHB1 peripheral reset register
	u32 AHB2LPENR;          //!< RCC APB2 peripheral clock enable register
	u32 RESERVED9;          //!< RCC Reserved Register
	u32 RESERVED10;         //!< RCC Reserved Register
	u32 APB1LPENR;          //!< RCC AHB1 peripheral clock enable in low power mode register
	u32 APB2LPENR;          //!< RCC AHB2 peripheral clock enable in low power mode register
	u32 RESERVED11;         //!< RCC Reserved Register
	u32 RESERVED12;         //!< RCC Reserved Register
	u32 BDCR;               //!< RCC Backup domain control register
	u32 CSR;                //!< RCC clock control & status register
	u32 RESERVED13;         //!< RCC Reserved Register
	u32 RESERVED14;         //!< RCC Reserved Register
	u32 SSCGR;              //!< RCC spread spectrum clock generation register
	u32 PLLI2SCFGR;         //!< RCC PLLI2S configuration register
	u32 RESERVED15;         //!< RCC Reserved Register
	u32 DCKCFGR;            //!<RCC Dedicated Clocks Configuration Register
}tstrRCC;

#define RCC 							((volatile tstrRCC *)RCC_BASE_ADDRESS)         //!< This is a casting the RCC Base Address to access it by tstrRCC Struct


/* CFGR */
#define CFGR_SW0						0    //!< This bit is the first bit of the bits which Set and cleared by software to select the system clock source andSet by hardware to force the HSI selection when leaving the Stop or Standby mode or in case of failure of the HSE oscillator used directly or indirectly as the system clock

#define CFGR_PPRE2						13   //!< This bit is the first bit of the bits which Set and cleared by software to control APB high-speed clock division factor.
#define CFGR_PPRE1						10   //!< This bit is the first bit of the bits which Set and cleared by software to control APB low-speed clock division factor.
#define CFGR_HPRE						4    //!< This bit is the first bit of the bits whichSet and cleared by software to control AHB clock division factor


/* CR */
#define CR_HSI_ON						0    //!< This bit is Set and cleared by software ,This bit is Set by hardware to force the HSI oscillator ON when leaving the Stop or Standby mode or in case of a failure of the HSE oscillator used directly or indirectly as the system clock. This bit cannot be cleared if the HSI is used directly or indirectly as the system clock
#define CR_HSI_RDY						1    //!< This bit is Set by hardware to indicate that the HSI oscillator is stable. After the HSION bit is cleared
#define CR_HSITRIM0						3    //!< This bit is the first bit of the bits which provide an additional user-programmable trimming value that is added to the HSICAL[7:0] bits. It can be programmed to adjust to variations in voltage and temperature that influence the frequency of the internal HSI RC
#define CR_HSE_ON						16   //!< This bit is Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode. This bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock
#define CR_HSE_RDY						17   //!< This bit is Set by hardware to indicate that the HSE oscillator is stable. After the HSEON bit is cleared, HSERDY goes low after 6 HSE oscillator clock cycles
#define CR_HSE_BYP						18   //!< This bit is Set and cleared by software to bypass the oscillator with an external clock. The external clock must be enabled with the HSEON bit, to be used by the device
#define CR_CSS_ON						19   //!< This bit is Set and cleared by software to enable the clock security system. When CSSON is set, the clock detector is enabled by hardware when the HSE oscillator is ready, and disabled by hardware if an oscillator failure is detected
#define CR_PLL_ON						24   //!< This bit is Set and cleared by software to enable PLL andCleared by hardware when entering Stop or Standby mode. This bit cannot be reset if PLL clock is used as the system clock
#define CR_PLL_RDY						25   //!< This bit is Set by hardware to indicate that PLL is locked

/* PLLCFGR */
#define PLLCFGR_PLLCFGR					22   //!< This bit is Set and cleared by software to select PLL and PLLI2S clock source. This bit can be written only when PLL and PLLI2S are disabled
#define PLLCFGR_PLLP0					16   //!< This bit is the first bit of the bits which is Set and cleared by software to control the frequency of the general PLL output clock. These bits can be written only if PLL is disabled
#define PLLCFGR_PLLN					6    //!< This bit is the first bit of the bits which is Set and cleared by software to control the multiplication factor of the VCO. These bits can be written only when PLL is disabled. Only half-word and word accesses are allowed to write these bits

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
