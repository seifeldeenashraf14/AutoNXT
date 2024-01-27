/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : SPI                    ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 20 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI1_BASE_ADDRESS						(0x40013000)

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}tstrSPI;

#define SPI										((volatile tstrSPI *) SPI1_BASE_ADDRESS)

/* CR1 bits */
#define CR1_BIDIMODE							15
#define CR1_BIDIOE                              14
#define CR1_CRCEN                               13
#define CR1_CRCNEXT                             12
#define CR1_DFF                                 11
#define CR1_RXONLY                              10
#define CR1_SSM                                 9
#define CR1_SSI                                 8
#define CR1_LSBFIRST                            7
#define CR1_SPE                                 6
#define CR1_BR0                                 3
#define CR1_MSTR                                2
#define CR1_CPOL                                1
#define CR1_CPHA								0

/* SR bits */
#define SR_BSY									7
#define SR_RXNE									0


#define RESET_VALUE								0x0000

#define INTERNAL_SLAVE_SELECT					1

#endif
