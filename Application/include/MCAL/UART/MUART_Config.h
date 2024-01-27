/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : UART                   ***********************/
/***********************            Version : 3.5                    ***********************/
/***********************            Date    : 10 Nov 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef MUART_CONFIG_H_
#define MUART_CONFIG_H_

/*************************************************** 		MUART1			 ***************************************************/
/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
#define MUART1_TRANSMITTER_ENABLE					MUART_ENABLE

/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
#define MUART1_RECEIVER_ENABLE						MUART_ENABLE

/* Enter The desired Baud rate */
#define	MUART1_BAUDRATE								1562500
/* Enter the CPU Clock */
#define MUART1_CLK									16

/* options:
 * 1- MUART_OVERSAMPLING_BY_16
 * 2- MUART_OVERSAMPLING_BY_8
 */
#define MUART1_OVERSAMPLING							MUART_OVERSAMPLING_BY_8

/* options:
 * 1- MUART_DATA_8BITS
 * 2- MUART_DATA_9BITS
 */
#define MUART1_DATA_LENGTH							MUART_DATA_8BITS

/* options:
 * 1- MUART_PARITY_DISABLE
 * 2- MUART_PARITY_ENABLE
 */
#define MUART1_PARITY_MODE							MUART_PARITY_DISABLE

#if MUART_PARITY_ENABLE == MUART1_PARITY_MODE
	/* options:
	 * 1- MUART_EVEN_PARITY
	 * 2- MUART_ODD_PARITY
	 */
	#define MUART1_PARITY_SELECTION					MUART_EVEN_PARITY
#endif

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
#define MUART1_TRANSMISSION_COMPELETE_INTERRUPT		MUART_DISABLE_INTERRUPT

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
#define MUART1_READ_DATA_REGISTER_EMPTY_INTERRUPT	MUART_DISABLE_INTERRUPT

/* options
 * 1- MUART_ONE_STOP_BIT
 * 2- MUART_HALF_STOP_BIT
 * 3- MUART_TWO_STOP_BIT
 * 4- MUART_ONE_AND_HALF_STOP_BIT
 */
#define MUART1_STOP_BITS							MUART_ONE_STOP_BIT

/*************************************************** 		MUART2			 ***************************************************/
/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
#define MUART2_TRANSMITTER_ENABLE					MUART_ENABLE

/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
#define MUART2_RECEIVER_ENABLE						MUART_ENABLE

/* Enter The desired Baud rate */
#define	MUART2_BAUDRATE								9600
/* Enter the CPU Clock */
#define MUART2_CLK									16

/* options:
 * 1- MUART_OVERSAMPLING_BY_16
 * 2- MUART_OVERSAMPLING_BY_8
 */
#define MUART2_OVERSAMPLING							MUART_OVERSAMPLING_BY_8

/* options:
 * 1- MUART_DATA_8BITS
 * 2- MUART_DATA_9BITS
 */
#define MUART2_DATA_LENGTH							MUART_DATA_8BITS

/* options:
 * 1- MUART_PARITY_DISABLE
 * 2- MUART_PARITY_ENABLE
 */
#define MUART2_PARITY_MODE							MUART_PARITY_DISABLE

#if MUART_PARITY_ENABLE == MUART2_PARITY_MODE
	/* options:
	 * 1- MUART_EVEN_PARITY
	 * 2- MUART_ODD_PARITY
	 */
	#define MUART2_PARITY_SELECTION					MUART_EVEN_PARITY
#endif

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
#define MUART2_TRANSMISSION_COMPELETE_INTERRUPT		MUART_DISABLE_INTERRUPT

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
#define MUART2_READ_DATA_REGISTER_EMPTY_INTERRUPT	MUART_DISABLE_INTERRUPT

/* options
 * 1- MUART_ONE_STOP_BIT
 * 2- MUART_HALF_STOP_BIT
 * 3- MUART_TWO_STOP_BIT
 * 4- MUART_ONE_AND_HALF_STOP_BIT
 */
#define MUART2_STOP_BITS							MUART_ONE_STOP_BIT

/*************************************************** 		MUART6			 ***************************************************/
/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
#define MUART6_TRANSMITTER_ENABLE					MUART_ENABLE

/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
#define MUART6_RECEIVER_ENABLE						MUART_ENABLE

/* Enter The desired Baud rate */
#define	MUART6_BAUDRATE								1562500
/* Enter the CPU Clock */
#define MUART6_CLK									25

/* options:
 * 1- MUART_OVERSAMPLING_BY_16
 * 2- MUART_OVERSAMPLING_BY_8
 */
#define MUART6_OVERSAMPLING							MUART_OVERSAMPLING_BY_8

/* options:
 * 1- MUART_DATA_8BITS
 * 2- MUART_DATA_9BITS
 */
#define MUART6_DATA_LENGTH							MUART_DATA_8BITS

/* options:
 * 1- MUART_PARITY_DISABLE
 * 2- MUART_PARITY_ENABLE
 */
#define MUART6_PARITY_MODE							MUART_PARITY_DISABLE

#if MUART_PARITY_ENABLE == MUART6_PARITY_MODE
	/* options:
	 * 1- MUART_EVEN_PARITY
	 * 2- MUART_ODD_PARITY
	 */
	#define MUART6_PARITY_SELECTION					MUART_EVEN_PARITY
#endif

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
#define MUART6_TRANSMISSION_COMPELETE_INTERRUPT		MUART_DISABLE_INTERRUPT

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
#define MUART6_READ_DATA_REGISTER_EMPTY_INTERRUPT	MUART_DISABLE_INTERRUPT

/* options
 * 1- MUART_ONE_STOP_BIT
 * 2- MUART_HALF_STOP_BIT
 * 3- MUART_TWO_STOP_BIT
 * 4- MUART_ONE_AND_HALF_STOP_BIT
 */
#define MUART6_STOP_BITS							MUART_ONE_STOP_BIT

#endif
