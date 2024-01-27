/**
 * @file MRCC_config.h
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
#define SYS_CLK						MRCC_HSI


#if SYS_CLK == MRCC_HSE

	/* Options:
	 * 1- MRCC_HSE_RC
	 * 2- MRCC_HSE_CRYSTAL
	 */
	#define HSE_SOURCE				MRCC_HSE_CRYSTAL

	/* Options:
	 * 1- MRCC_CLK_SECURITY_ENABLE
	 * 2- MRCC_CLK_SECURITY_DISABLE
	 */
	#define CLK_SECURITY			MRCC_CLK_SECURITY_DISABLE
#endif

#if SYS_CLK == MRCC_PLL

	/* Options:
	 * 1- MRCC_PLL_HSI
	 * 2- MRCC_PLL_HSE
	 */
	#define PLL_SOURCE					MRCC_PLL_HSE

	#if PLL_SOURCE == MRCC_PLL_HSE
		/* Options:
		 * 1- MRCC_HSE_RC
		 * 2- MRCC_HSE_CRYSTAL
		 */
		#define HSE_SOURCE				MRCC_HSE_CRYSTAL
	#endif

	/* Options:
	 * 1- MRCC_PLL_DIV_BY_2
	 * 2- MRCC_PLL_DIV_BY_4
	 * 3- MRCC_PLL_DIV_BY_6
	 * 4- MRCC_PLL_DIV_BY_8
	 */
	#define PLL_PRESCALER				MRCC_PLL_DIV_BY_2

	/* Options:
	 * From 2 to 432
	 * */
	#define PLL_MULTIPLICATION_FACTOR	16
#endif

#endif
