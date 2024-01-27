/**
 * @file MRCC_Config.h
 * @author Hosam Ayoub
 * @version 2.0
 * @date 18 Sep 2023
 * @brief The Reset Clock Control header file that has all the configurations of the **RCC** driver
 */
#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_

/* Options:
 * 1- MRCC_HSI
 * 2- MRCC_HSE
 * 3- MRCC_PLL
 */
/**
 * @def 	SYS_CLK
 * @brief	It determines the source of the CPU clock
 * @details It has 3 options:
 * - @ref   MRCC_HSI
 * - @ref   MRCC_HSE
 * - @ref   MRCC_PLL
 */
#define SYS_CLK						MRCC_HSE


#if SYS_CLK == MRCC_HSE

	/* Options:
	 * 1- MRCC_HSE_RC
	 * 2- MRCC_HSE_CRYSTAL
	 */
/**
 * @def 	HSE_SOURCE
 * @brief	It determines the source of the HSE clock
 * @details It has 2 options:
 * - @ref   MRCC_HSE_RC
 * - @ref   MRCC_HSE_CRYSTAL
 */
	#define HSE_SOURCE				MRCC_HSE_CRYSTAL

	/* Options:
	 * 1- MRCC_CLK_SECURITY_ENABLE
	 * 2- MRCC_CLK_SECURITY_DISABLE
	 */
/**
 * @def 	CLK_SECURITY
 * @brief	It enables the clock security or disable it
 * @details It has 2 options:
 * - @ref   MRCC_CLK_SECURITY_ENABLE
 * - @ref   MRCC_CLK_SECURITY_DISABLE
 */
	#define CLK_SECURITY			MRCC_CLK_SECURITY_DISABLE
#endif

#if SYS_CLK == MRCC_PLL

	/* Options:
	 * 1- MRCC_PLL_HSI
	 * 2- MRCC_PLL_HSE
	 */
/**
 * @def 	PLL_SOURCE
 * @brief	It determines the source of the PLL clock
 * @details It has 2 options:
 * - @ref   MRCC_PLL_HSI
 * - @ref   MRCC_PLL_HSE
 */
	#define PLL_SOURCE					MRCC_PLL_HSE

	#if PLL_SOURCE == MRCC_PLL_HSE
		/* Options:
		 * 1- MRCC_HSE_RC
		 * 2- MRCC_HSE_CRYSTAL
		 */
/**
 * @def 	HSE_SOURCE
 * @brief	It determines the source of the HSE clock
 * @details It has 2 options:
 * - @ref   MRCC_HSE_RC
 * - @ref   MRCC_HSE_CRYSTAL
 */
		#define HSE_SOURCE				MRCC_HSE_CRYSTAL
	#endif

	/* Options:
	 * 1- MRCC_PLL_DIV_BY_2
	 * 2- MRCC_PLL_DIV_BY_4
	 * 3- MRCC_PLL_DIV_BY_6
	 * 4- MRCC_PLL_DIV_BY_8
	 */
/**
 * @def 	PLL_PRESCALER
 * @brief	It determines the prescaler of the PLL clock
 * @details It has 4 options:
 * - @ref   MRCC_PLL_DIV_BY_2
 * - @ref   MRCC_PLL_DIV_BY_4
 * - @ref   MRCC_PLL_DIV_BY_4
 * - @ref   MRCC_PLL_DIV_BY_4
 */
	#define PLL_PRESCALER				MRCC_PLL_DIV_BY_2

	/* Options:
	 * From 2 to 432
	 * */
/**
 * @def 	PLL_MULTIPLICATION_FACTOR
 * @brief	It determines the Multiplication factor of the PLL clock
 */
	#define PLL_MULTIPLICATION_FACTOR	16
#endif

#endif
