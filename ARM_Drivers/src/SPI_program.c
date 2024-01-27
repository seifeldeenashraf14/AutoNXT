/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : SPI                    ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 20 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/SPI/SPI_private.h"
#include "MCAL/SPI/SPI_config.h"

void SPI1_voidInit()
{
	/* Mask CR1 register*/
	SPI->CR1 = 0x0000;
	/* Set bidirectional data mode */
	SPI->CR1 |= SPI1_DATA_LINES << CR1_BIDIMODE;
	#if SPI_BIDIRECTIONAL_ONE_LINE == SPI1_DATA_LINES
		/* Set the data direction */
		SPI->CR1 |= SPI1_DATA_DIRECTION << CR1_BIDIOE;
	#elif SPI_UNIDIRECTIONAL_TWO_LINES == SPI1_DATA_LINES
		/* Set the Transmit Receive relationship */
		SPI->CR1 |= SPI1_RECEIVE_ONLY << CR1_RXONLY;
	#endif
	/* Set CRC State */
	SPI->CR1 |= SPI1_CRC_STATE << CR1_CRCEN;
	#if SPI_CRC_ENABLE == SPI1_CRC_STATE
		/* CRC transfer next */
		SPI->CR1 |= SPI1_CRC_PHASE << CR1_CRCNEXT;
	#endif
	/* Data frame format */
	SPI->CR1 |= SPI1_DATA_SIZE << CR1_DFF;
	/* Software slave management */
	SPI->CR1 |= SPI1_SS_MANAGE << CR1_SSM;
	/* Set SW Management */
	#if SPI_SW_MANAGEMENT == SPI1_SS_MANAGE
		SPI->CR1 |= INTERNAL_SLAVE_SELECT << CR1_SSI;
	#endif
	/* Frame format */
	SPI->CR1 |= SPI1_DATA_ORDER << CR1_LSBFIRST;
	/* Baud rate control */
	SPI->CR1 |= SPI1_PRESCALER << CR1_BR0;
	/* Master selection */
	SPI->CR1 |= SPI1_MASTER_SLAVE << CR1_MSTR;
	/* Set clock mode */
	SPI->CR1 |= SPI1_CLOCK_MODE << CR1_CPHA;
	/* SPI enable */
	SPI->CR1 |= SPI1_STATUS << CR1_SPE;
}

void SPI1_voidTransceiveDataByte (u8 Copy_u8Data, u8 *Pointer_u8ReceiveBuffer)
{
	SPI->DR = Copy_u8Data;
	while (GET_BIT(SPI->SR, SR_BSY));
	*Pointer_u8ReceiveBuffer = SPI->DR;
}

void SPI1_voidSetCallBack (pf PointerToFunction)
{

}
