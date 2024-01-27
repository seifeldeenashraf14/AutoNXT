/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : SPI                    ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 20 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
/*************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/* Arguments */
#define SPI_DISABLE								0
#define SPI_ENABLE								1

#define SPI_MODE0								0
#define SPI_MODE1                               1
#define SPI_MODE2                               2
#define SPI_MODE3                               3

#define SPI_UNIDIRECTIONAL_TWO_LINES			0
#define SPI_BIDIRECTIONAL_ONE_LINE				1

#define SPI_RECEIVE_ONLY_MODE					0
#define SPI_TRANSMIT_ONLY_MODE					1

#define SPI_FULL_DUPLEX							0
#define SPI_RECEIVE_ONLY						1

#define SPI_CRC_DISABLE							0
#define SPI_CRC_ENABLE							1

#define SPI_8BITS_DATA 							0
#define SPI_16BITS_DATA                         1

#define SPI_MSB									0
#define SPI_LSB									1

#define SPI_HW_MANAGEMENT						0
#define SPI_SW_MANAGEMENT						1

#define SPI_CLK_DIV_BY_2						0
#define SPI_CLK_DIV_BY_4  						1
#define SPI_CLK_DIV_BY_8                        2
#define SPI_CLK_DIV_BY_16                       3
#define SPI_CLK_DIV_BY_32                       4
#define SPI_CLK_DIV_BY_64                       5
#define SPI_CLK_DIV_BY_128                      6
#define SPI_CLK_DIV_BY_256                      7

#define SPI_SLAVE								0
#define SPI_MASER								1

#define SPI_CRC_DISABLE							0
#define SPI_CRC_ENABLE							1

#define SPI_DATA_PHASE							0
#define SPI_CRC_PHASE							1

/* Functions */
void SPI1_voidInit();
void SPI1_voidTransceiveDataByte (u8 Copy_u8Data, u8 *Pointer_u8ReceiveBuffer);
void SPI1_voidSetCallBack (pf PointerToFunction);

#endif
