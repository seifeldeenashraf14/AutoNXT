/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : SPI                    ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 20 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_
/* options:
 * 1- SPI_ENABLE
 * 2- SPI_DISABLE
 */
#define SPI1_STATUS							SPI_ENABLE
/* options:
 * 1- SPI_MODE0
 * 2- SPI_MODE1
 * 3- SPI_MODE2
 * 4- SPI_MODE3
 */
#define SPI1_CLOCK_MODE						SPI_MODE3
/* options:
 * 1- SPI_MASTER
 * 2- SPI_SLAVE
 */
#define SPI1_MASTER_SLAVE					SPI_MASER
/* options:
 * 1- SPI_UNIDIRECTIONAL_TWO_LINES
 * 2- SPI_BIDIRECTIONAL_ONE_LINE
 */
#define SPI1_DATA_LINES						SPI_UNIDIRECTIONAL_TWO_LINES

#if SPI_BIDIRECTIONAL_ONE_LINE == SPI1_DATA_LINES
	/* options:
	 * 1- SPI_RECEIVE_ONLY_MODE
	 * 2- SPI_TRANSMIT_ONLY_MODE
	 */
	#define SPI1_DATA_DIRECTION				SPI_RECEIVE_ONLY_MODE
#elif SPI_UNIDIRECTIONAL_TWO_LINES == SPI1_DATA_LINES
	/* options:
	 * 1- SPI_FULL_DUPLEX
	 * 2- SPI_RECEIVE_ONLY
	 */
	#define SPI1_RECEIVE_ONLY				SPI_FULL_DUPLEX
#endif
/* options:
 * 1- SPI_CLK_DIV_BY_2
 * 2- SPI_CLK_DIV_BY_4
 * 3- SPI_CLK_DIV_BY_8
 * 4- SPI_CLK_DIV_BY_16
 * 5- SPI_CLK_DIV_BY_32
 * 6- SPI_CLK_DIV_BY_64
 * 7- SPI_CLK_DIV_BY_128
 * 8- SPI_CLK_DIV_BY_256
 */
#define SPI1_PRESCALER						SPI_CLK_DIV_BY_2
/* options:
 * 1- MSB
 * 2- LSB
 */
#define SPI1_DATA_ORDER						SPI_MSB
/* options:
 * 1- SPI_HW_MANAGEMENT
 * 2- SPI_SW_MANAGEMENT
 */
#define SPI1_SS_MANAGE						SPI_SW_MANAGEMENT

/* options:
 * 1- SPI_8BITS_DATA
 * 2- SPI_16BITS_DATA
 */
#define SPI1_DATA_SIZE						SPI_8BITS_DATA

/* options:
 * 1- SPI_INTERRUPT_DISABLE
 * 2- SPI_INTERRUPT_ENABLE
 */
#define SPI1_INTERRUPT_STATUS				SPI_INTERRUPT_DISABLE
/* options:
 * 1- SPI_PORTA
 * 2- SPI_PORTB
 * 3- SPI_PORTC
 */
#define SPI1_SS_PORT						SPI_PORTA
/* options:
 * from SPI_PIN0 to SPI_PIN15
 */
#define SPI1_SS_PIN							SPI_PIN0

/* options:
 * 1- SPI_CRC_DISABLE
 * 2- SPI_CRC_ENABLE
 */
#define SPI1_CRC_STATE						SPI_CRC_DISABLE

/* options:
 * 1- SPI_DATA_PHASE
 * 2- SPI_CRC_PHASE
 */
#define SPI1_CRC_PHASE						SPI_DATA_PHASE

#endif
