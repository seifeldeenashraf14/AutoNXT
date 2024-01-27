/**
 * @file	MUART_config.h
 * @author 	Hosam Ayoub
 * @version 3.5
 * @date 	10 Nov 2023
 * @brief 	The UART Config Header file that has the configurations of **UART** driver
 */
#ifndef MUART_CONFIG_H_
#define MUART_CONFIG_H_

/*************************************************** 		MUART1			 ***************************************************/
/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
/**
 * @def 	MUART1_TRANSMITTER_ENABLE
 * @brief	It enables the transmitter of UART1
 * @details It has 2 options:
 * - @ref MUART_ENABLE
 * - @ref MUART_DISABLE
 */
#define MUART1_TRANSMITTER_ENABLE					MUART_ENABLE

/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
/**
 * @def 	MUART1_RECEIVER_ENABLE
 * @brief	It enables the receiver of UART1
 * @details It has 2 options:
 * - @ref MUART_ENABLE
 * - @ref MUART_DISABLE
 */
#define MUART1_RECEIVER_ENABLE						MUART_ENABLE

/* Enter The desired Baud rate */
/**
 * @def 	MUART1_BAUDRATE
 * @brief	It determines the baudrate of UART1
 */
#define	MUART1_BAUDRATE								1562500
/* Enter the CPU Clock */
/**
 * @def 	MUART1_CLK
 * @brief	It tells us the CPU clock
 */
#define MUART1_CLK									25

/* options:
 * 1- MUART_OVERSAMPLING_BY_16
 * 2- MUART_OVERSAMPLING_BY_8
 */
/**
 * @def 	MUART1_OVERSAMPLING
 * @brief	It determines the oversampling rate of UART1
 * @details It has 2 options:
 * - @ref MUART_OVERSAMPLING_BY_16
 * - @ref MUART_OVERSAMPLING_BY_8
 */
#define MUART1_OVERSAMPLING							MUART_OVERSAMPLING_BY_8

/* options:
 * 1- MUART_DATA_8BITS
 * 2- MUART_DATA_9BITS
 */
/**
 * @def 	MUART1_DATA_LENGTH
 * @brief	It determines the number of transferred bytes at one time of UART1
 * @details It has 2 options:
 * - @ref   MUART_DATA_8BITS
 * - @ref   MUART_DATA_9BITS
 */
#define MUART1_DATA_LENGTH							MUART_DATA_8BITS

/* options:
 * 1- MUART_PARITY_DISABLE
 * 2- MUART_PARITY_ENABLE
 */
/**
 * @def 	MUART1_PARITY_MODE
 * @brief	It determines if there is a parity bit or not in UART1
 * @details It has 2 options:
 * - @ref   MUART_PARITY_DISABLE
 * - @ref   MUART_PARITY_ENABLE
 */
#define MUART1_PARITY_MODE							MUART_PARITY_DISABLE

#if MUART_PARITY_ENABLE == MUART1_PARITY_MODE
	/* options:
	 * 1- MUART_EVEN_PARITY
	 * 2- MUART_ODD_PARITY
	 */
/**
 * @def 	MUART1_PARITY_SELECTION
 * @brief	It determines if there is a even or odd parity bit in UART1
 * @details It has 2 options:
 * - @ref   MUART_EVEN_PARITY
 * - @ref   MUART_ODD_PARITY
 */
	#define MUART1_PARITY_SELECTION					MUART_EVEN_PARITY
#endif

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
/**
 * @def 	MUART1_TRANSMISSION_COMPELETE_INTERRUPT
 * @brief	It enables the interrupt of transmission data of UART1
 * @details It has 2 options:
 * - @ref   MUART_DISABLE_INTERRUPT
 * - @ref   MUART_ENABLE_INTERRUPT
 */
#define MUART1_TRANSMISSION_COMPELETE_INTERRUPT		MUART_DISABLE_INTERRUPT

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
/**
 * @def 	MUART1_READ_DATA_REGISTER_EMPTY_INTERRUPT
 * @brief	It enables the interrupt of Empty Register  of UART1
 * @details It has 2 options:
 * - @ref   MUART_DISABLE_INTERRUPT
 * - @ref   MUART_ENABLE_INTERRUPT
 */
#define MUART1_READ_DATA_REGISTER_EMPTY_INTERRUPT	MUART_DISABLE_INTERRUPT

/* options
 * 1- MUART_ONE_STOP_BIT
 * 2- MUART_HALF_STOP_BIT
 * 3- MUART_TWO_STOP_BIT
 * 4- MUART_ONE_AND_HALF_STOP_BIT
 */
/**
 * @def 	MUART1_STOP_BITS
 * @brief	It determines the number of stop bits of UART1
 * @details It has 4 options:
 * - @ref   MUART_ONE_STOP_BIT
 * - @ref   MUART_HALF_STOP_BIT
 * - @ref   MUART_TWO_STOP_BIT
 * - @ref   MUART_ONE_AND_HALF_STOP_BIT
 */
#define MUART1_STOP_BITS							MUART_ONE_STOP_BIT

/*************************************************** 		MUART2			 ***************************************************/
/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
/**
 * @def 	MUART2_TRANSMITTER_ENABLE
 * @brief	It enables the transmitter
 * @details It has 2 options:
 * - @ref MUART_ENABLE
 * - @ref MUART_DISABLE
 */
#define MUART2_TRANSMITTER_ENABLE					MUART_ENABLE

/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
/**
 * @def 	MUART2_RECEIVER_ENABLE
 * @brief	It enables the receiver
 * @details It has 2 options:
 * - @ref MUART_ENABLE
 * - @ref MUART_DISABLE
 */
#define MUART2_RECEIVER_ENABLE						MUART_ENABLE

/* Enter The desired Baud rate */
/**
 * @def 	MUART2_BAUDRATE
 * @brief	It determines the baudrate of UART2
 */
#define	MUART2_BAUDRATE								1562500
/* Enter the CPU Clock */
/**
 * @def 	MUART2_CLK
 * @brief	It tells us the CPU clock
 */
#define MUART2_CLK									25

/* options:
 * 1- MUART_OVERSAMPLING_BY_16
 * 2- MUART_OVERSAMPLING_BY_8
 */
/**
 * @def 	MUART2_OVERSAMPLING
 * @brief	It determines the oversampling rate of UART2
 * @details It has 2 options:
 * - @ref MUART_OVERSAMPLING_BY_16
 * - @ref MUART_OVERSAMPLING_BY_8
 */
#define MUART2_OVERSAMPLING							MUART_OVERSAMPLING_BY_8

/* options:
 * 1- MUART_DATA_8BITS
 * 2- MUART_DATA_9BITS
 */
/**
 * @def 	MUART2_DATA_LENGTH
 * @brief	It determines the number of transferred bytes at one time of UART2
 * @details It has 2 options:
 * - @ref   MUART_DATA_8BITS
 * - @ref   MUART_DATA_9BITS
 */
#define MUART2_DATA_LENGTH							MUART_DATA_8BITS

/* options:
 * 1- MUART_PARITY_DISABLE
 * 2- MUART_PARITY_ENABLE
 */
/**
 * @def 	MUART2_PARITY_MODE
 * @brief	It determines if there is a parity bit or not in UART2
 * @details It has 2 options:
 * - @ref   MUART_PARITY_DISABLE
 * - @ref   MUART_PARITY_ENABLE
 */
#define MUART2_PARITY_MODE							MUART_PARITY_DISABLE

#if MUART_PARITY_ENABLE == MUART2_PARITY_MODE
	/* options:
	 * 1- MUART_EVEN_PARITY
	 * 2- MUART_ODD_PARITY
	 */
/**
 * @def 	MUART2_PARITY_SELECTION
 * @brief	It determines if there is a even or odd parity bit in UART2
 * @details It has 2 options:
 * - @ref   MUART_EVEN_PARITY
 * - @ref   MUART_ODD_PARITY
 */
	#define MUART2_PARITY_SELECTION					MUART_EVEN_PARITY
#endif

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
/**
 * @def 	MUART2_TRANSMISSION_COMPELETE_INTERRUPT
 * @brief	It enables the interrupt of transmission data of UART2
 * @details It has 2 options:
 * - @ref   MUART_DISABLE_INTERRUPT
 * - @ref   MUART_ENABLE_INTERRUPT
 */
#define MUART2_TRANSMISSION_COMPELETE_INTERRUPT		MUART_DISABLE_INTERRUPT

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
/**
 * @def 	MUART2_READ_DATA_REGISTER_EMPTY_INTERRUPT
 * @brief	It enables the interrupt of Empty Register  of UART2
 * @details It has 2 options:
 * - @ref   MUART_DISABLE_INTERRUPT
 * - @ref   MUART_ENABLE_INTERRUPT
 */
#define MUART2_READ_DATA_REGISTER_EMPTY_INTERRUPT	MUART_DISABLE_INTERRUPT

/* options
 * 1- MUART_ONE_STOP_BIT
 * 2- MUART_HALF_STOP_BIT
 * 3- MUART_TWO_STOP_BIT
 * 4- MUART_ONE_AND_HALF_STOP_BIT
 */
/**
 * @def 	MUART2_STOP_BITS
 * @brief	It determines the number of stop bits of UART2
 * @details It has 4 options:
 * - @ref   MUART_ONE_STOP_BIT
 * - @ref   MUART_HALF_STOP_BIT
 * - @ref   MUART_TWO_STOP_BIT
 * - @ref   MUART_ONE_AND_HALF_STOP_BIT
 */
#define MUART2_STOP_BITS							MUART_ONE_STOP_BIT

/*************************************************** 		MUART6			 ***************************************************/
/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
/**
 * @def 	MUART6_TRANSMITTER_ENABLE
 * @brief	It enables the transmitter
 * @details It has 2 options:
 * - @ref MUART_ENABLE
 * - @ref MUART_DISABLE
 */
#define MUART6_TRANSMITTER_ENABLE					MUART_ENABLE

/* options:
 * 1- MUART_DISABLE
 * 2- MUART_ENABLE
 */
/**
 * @def 	MUART6_RECEIVER_ENABLE
 * @brief	It enables the receiver
 * @details It has 2 options:
 * - @ref MUART_ENABLE
 * - @ref MUART_DISABLE
 */
#define MUART6_RECEIVER_ENABLE						MUART_ENABLE

/* Enter The desired Baud rate */
/**
 * @def 	MUART6_BAUDRATE
 * @brief	It determines the baudrate of UART6
 */
#define	MUART6_BAUDRATE								1562500
/* Enter the CPU Clock */

/**
 * @def 	MUART6_CLK
 * @brief	It tells us the CPU clock
 */
#define MUART6_CLK									25

/* options:
 * 1- MUART_OVERSAMPLING_BY_16
 * 2- MUART_OVERSAMPLING_BY_8
 */
/**
 * @def 	MUART6_OVERSAMPLING
 * @brief	It determines the oversampling rate of UART6
 * @details It has 2 options:
 * - @ref MUART_OVERSAMPLING_BY_16
 * - @ref MUART_OVERSAMPLING_BY_8
 */
#define MUART6_OVERSAMPLING							MUART_OVERSAMPLING_BY_8

/* options:
 * 1- MUART_DATA_8BITS
 * 2- MUART_DATA_9BITS
 */
/**
 * @def 	MUART6_DATA_LENGTH
 * @brief	It determines the number of transferred bytes at one time of UART6
 * @details It has 2 options:
 * - @ref   MUART_DATA_8BITS
 * - @ref   MUART_DATA_9BITS
 */
#define MUART6_DATA_LENGTH							MUART_DATA_8BITS

/* options:
 * 1- MUART_PARITY_DISABLE
 * 2- MUART_PARITY_ENABLE
 */
/**
 * @def 	MUART6_PARITY_MODE
 * @brief	It determines if there is a parity bit or not in UART6
 * @details It has 2 options:
 * - @ref   MUART_PARITY_DISABLE
 * - @ref   MUART_PARITY_ENABLE
 */
#define MUART6_PARITY_MODE							MUART_PARITY_DISABLE

#if MUART_PARITY_ENABLE == MUART6_PARITY_MODE
	/* options:
	 * 1- MUART_EVEN_PARITY
	 * 2- MUART_ODD_PARITY
	 */
/**
 * @def 	MUART6_PARITY_SELECTION
 * @brief	It determines if there is a even or odd parity bit in UART6
 * @details It has 2 options:
 * - @ref   MUART_EVEN_PARITY
 * - @ref   MUART_ODD_PARITY
 */
	#define MUART6_PARITY_SELECTION					MUART_EVEN_PARITY
#endif

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
/**
 * @def 	MUAR6_TRANSMISSION_COMPELETE_INTERRUPT
 * @brief	It enables the interrupt of transmission data of UART6
 * @details It has 2 options:
 * - @ref   MUART_DISABLE_INTERRUPT
 * - @ref   MUART_ENABLE_INTERRUPT
 */
#define MUART6_TRANSMISSION_COMPELETE_INTERRUPT		MUART_DISABLE_INTERRUPT

/* options:
 * 1- MUART_DISABLE_INTERRUPT
 * 2- MUART_ENABLE_INTERRUPT
 */
/**
 * @def 	MUART6_READ_DATA_REGISTER_EMPTY_INTERRUPT
 * @brief	It enables the interrupt of Empty Register  of UART6
 * @details It has 2 options:
 * - @ref   MUART_DISABLE_INTERRUPT
 * - @ref   MUART_ENABLE_INTERRUPT
 */
#define MUART6_READ_DATA_REGISTER_EMPTY_INTERRUPT	MUART_DISABLE_INTERRUPT

/* options
 * 1- MUART_ONE_STOP_BIT
 * 2- MUART_HALF_STOP_BIT
 * 3- MUART_TWO_STOP_BIT
 * 4- MUART_ONE_AND_HALF_STOP_BIT
 */
/**
 * @def 	MUART6_STOP_BITS
 * @brief	It determines the number of stop bits of UART6
 * @details It has 4 options:
 * - @ref   MUART_ONE_STOP_BIT
 * - @ref   MUART_HALF_STOP_BIT
 * - @ref   MUART_TWO_STOP_BIT
 * - @ref   MUART_ONE_AND_HALF_STOP_BIT
 */
#define MUART6_STOP_BITS							MUART_ONE_STOP_BIT

#endif
