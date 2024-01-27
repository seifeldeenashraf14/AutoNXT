/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : UART                   ***********************/
/***********************            Version : 2.0                    ***********************/
/***********************            Date    : 17 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

typedef struct
{
	u32 SBK : 1;
	u32 RWU : 1;
	u32 RE : 1;
	u32 TE : 1;
	u32 IDLEIE : 1;
	u32 RXNEIE : 1;
	u32 TCIE : 1;
	u32 TXEIE : 1;
	u32 PEIE : 1;
	u32 PS : 1;
	u32 PCE : 1;
	u32 WAKE : 1;
	u32 M : 1;
	u32 UE : 1;
	u32 RESERVED : 1;
	u32 OVER8 : 1;
	u32 RESERVED1 : 16;
}tstrCR1;

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile tstrCR1 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}tstrUART;

#define UART1_ADDRESS_BASE				(0x40011000)
#define UART2_ADDRESS_BASE				(0x40004400)
#define UART6_ADDRESS_BASE				(0x40011400)

#define UART1							((volatile tstrUART *) UART1_ADDRESS_BASE)
#define UART2							((volatile tstrUART *) UART2_ADDRESS_BASE)
#define UART6							((volatile tstrUART *) UART6_ADDRESS_BASE)


/* Equation */
#define EQUATION						(UART_CLK)/(8 * (2-(OVER8)) * BAUD)

/* BRR Bits */
#define BRR_DIV_FRACTION0				0
#define BRR_DIV_MANTISSA0				4

/* CR2 Bits */
#define CR2_STOP0						12

/* SR Bits */
#define SR_RXNE							5
#define SR_TC							6

/* Mask */
#define MASK_2BITS						0b11

#define VALUE 							(((CLK)*1E6)/(8*(2-OVERSAMPLING)*BAUDRATE))

#define BRR_VALUE						((u8)((VALUE-(u8)VALUE) * (8 * (2-OVERSAMPLING))) << BRR_DIV_FRACTION0) | ((u16)VALUE << BRR_DIV_MANTISSA0)

#endif
