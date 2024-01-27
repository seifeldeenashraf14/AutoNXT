/**
 * @file	MUART_private.h
 * @author 	Hosam Ayoub
 * @version 3.5
 * @date 	10 Nov 2023
 * @brief 	The UART Private Header file that has all the addresses of the registers, their base address and any private macros of **UART** driver
 */
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


/**
 * @struct 	tstrCR1
 * @brief	This struct has all the CR1 bits
 *
 */
typedef struct
{
	u32 SBK : 1;                   //!<  This bit set is used to send break characters. It can be set and cleared by software. It should be set by software, and will be reset by hardware during the stop bit of break.
	u32 RWU : 1;                   //!<  This bit determines if the USART is in mute mode or not. It is set and cleared by software and can be cleared by hardware when a wakeup sequence is recognized.
	u32 RE : 1;                    //!<  This bit enables the receiver. It is set and cleared by software
	u32 TE : 1;                    //!<  This bit enables the transmitter. It is set and cleared by software.
	u32 IDLEIE : 1;                //!<  This bit is written by software to enable interrupt whenever IDLE=1 in the USART_SR register
	u32 RXNEIE : 1;                //!<  This bit is written by software to enable interrupt whenever ORE=1 or RXNE=1 in the USART_SR
	u32 TCIE : 1;                  //!<  This bit is written by software to enable interrupt whenever  TC=1 in the USART_SR register
	u32 TXEIE : 1;                 //!<  This bit is written by software to enable interrupt whenever TXE=1 in the USART_SR register
	u32 PEIE : 1;                  //!<  This bit is written by software to enable interrupt whenever PE=1 in the USART_SR register
	u32 PS : 1;                    //!<  This bit selects the odd or even parity when the parity generation/detection is enabled (PCE bit set). It is set and cleared by software. The parity will be selected after the current byte
	u32 PCE : 1;                   //!<  This bit selects the hardware parity control (generation and detection). When the parity control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit if M=0) and parity is checked on the received data. This bit is set and cleared by software. Once it is set, PCE is active after the current byte (in reception and in transmission)
	u32 WAKE : 1;                  //!<  This bit determines the USART wakeup method, it is set or cleared by software
	u32 M : 1;                     //!<  This bit determines the word length. It is set or cleared by software
	u32 UE : 1;                    //!<  When this bit is cleared, the USART prescalers and outputs are stopped and the end of the current byte transfer in order to reduce power consumption. This bit is set and cleared by softwar
	u32 RESERVED : 1;              //!<  This bit is Reserved
	u32 OVER8 : 1;                 //!<  This bit determines the oversampling mode
	u32 RESERVED1 : 16;            //!<  This bit is Reserved
}tstrCR1;

/**
 * @struct 	tstrUART
 * @brief	This struct has all the UART registers
 *
 */
typedef struct
{
	volatile u32 SR;      //!< UART Status Register
	volatile u32 DR;      //!< UART Data Register
	volatile u32 BRR;     //!< UART Baud Rate Register
	volatile tstrCR1 CR1; //!< UART  First Control  Register
	volatile u32 CR2;     //!< UART  Second Control  Register
	volatile u32 CR3;     //!< UART  Guard time and prescaler Register
	volatile u32 GTPR;
}tstrUART;

#define UART1_ADDRESS_BASE				(0x40011000)        //!< The **UART1** Base address
#define UART2_ADDRESS_BASE				(0x40004400)        //!< The **UART2** Base address
#define UART6_ADDRESS_BASE				(0x40011400)        //!< The **UART6** Base address

#define UART1							((volatile tstrUART *) UART1_ADDRESS_BASE)     //!< This is a casting the UART1 Base Address to access it by tstrUART Struct
#define UART2							((volatile tstrUART *) UART2_ADDRESS_BASE)     //!< This is a casting the UART2 Base Address to access it by tstrUART Struct
#define UART6							((volatile tstrUART *) UART6_ADDRESS_BASE)     //!< This is a casting the UART6 Base Address to access it by tstrUART Struct


/* Equation */
#define EQUATION						(UART_CLK)/(8 * (2-(OVER8)) * BAUD)

/* BRR Bits */
#define BRR_DIV_FRACTION0				0       //!<  This  bit is the first bit of the bits which define the fraction of UART divider
#define BRR_DIV_MANTISSA0				4       //!<  This  bit is the first bit of the bits which define Mantissa if UART divider


/* CR2 Bits */
#define CR2_STOP0						12      //!<  This is the first bit of the bits which program Stop bit

/* SR Bits */
#define SR_RXNE							5       //!< This bit is set by hardware when the content of the RDR shift register has been transferred to the USART_DR register. An interrupt is generated if RXNEIE=1 in the USART_CR1 register. It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by writing a zero to it. This clearing sequence is recommended only for multibuffer communication
#define SR_TC							6       //!< This bit is set by hardware if the transmission of a frame containing data is complete and if TXE is set. An interrupt is generated if TCIE=1 in the USART_CR1 register. It is cleared by a software sequence (a read from the USART_SR register followed by a write to the USART_DR register). The TC bit can also be cleared by writing a '0' to it. This clearing sequence is recommended only for multibuffer communication

/* Mask */
#define MASK_2BITS						0b11

#define MUART1_VALUE 							(((MUART1_CLK)*1E6)/(8*(2-MUART1_OVERSAMPLING)*MUART1_BAUDRATE))

#define MUART1_BRR_VALUE						((u8)((MUART1_VALUE-(u8)MUART1_VALUE) * (8 * (2-MUART1_OVERSAMPLING))) << BRR_DIV_FRACTION0) | ((u16)MUART1_VALUE << BRR_DIV_MANTISSA0)

#define MUART2_VALUE 							(((MUART2_CLK)*1E6)/(8*(2-MUART2_OVERSAMPLING)*MUART2_BAUDRATE))

#define MUART2_BRR_VALUE						((u8)((MUART2_VALUE-(u8)MUART2_VALUE) * (8 * (2-MUART2_OVERSAMPLING))) << BRR_DIV_FRACTION0) | ((u16)MUART2_VALUE << BRR_DIV_MANTISSA0)

#define MUART6_VALUE 							(((MUART6_CLK)*1E6)/(8*(2-MUART6_OVERSAMPLING)*MUART6_BAUDRATE))

#define MUART6_BRR_VALUE						((u8)((MUART6_VALUE-(u8)MUART6_VALUE) * (8 * (2-MUART6_OVERSAMPLING))) << BRR_DIV_FRACTION0) | ((u16)MUART6_VALUE << BRR_DIV_MANTISSA0)

#endif
