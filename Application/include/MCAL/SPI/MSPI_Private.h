/*
 * MSPI_private.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Hesham Yasser
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_


#define SPI1_BASE_ADDRESS			(0x40013000)
#define SPI2_BASE_ADDRESS			(0x40003800)
#define SPI3_BASE_ADDRESS			(0x40003C00)
#define SPI4_BASE_ADDRESS			(0x40013400)

typedef struct{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}SPI_t;

#define SPI1			((volatile SPI_t *)SPI1_BASE_ADDRESS)
#define SPI2			((volatile SPI_t *)SPI2_BASE_ADDRESS)
#define SPI3			((volatile SPI_t *)SPI3_BASE_ADDRESS)
#define SPI4			((volatile SPI_t *)SPI4_BASE_ADDRESS)



#define SPI_NUMBER						4

#define TWO_BIT_MASK					0b11

#define THREE_BIT_MASK					0b111

#define SPI_BUSY						1

/**************CR1*****************/

#define CR1_DFF							11

#define CR1_SSM							9

#define CR1_SSI							8

#define CR1_LSBFIRST					7

#define CR1_SPE							6

#define CR1_BR							3

#define CR1_MSTR						2

#define CR1_CLK_SELECT					0

/**************CR2*****************/

#define CR2_TXEIE						7

#define CR2_RXNEIE						6

/***************SR******************/

#define SR_TXE							1

#define SR_RXNE							0

#define SR_BSY							7





#endif /* MSPI_PRIVATE_H_ */
