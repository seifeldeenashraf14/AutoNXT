/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : RCC                    ***********************/
/***********************            Version : 2.0                    ***********************/
/***********************            Date    : 18 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* Options:
 * 1- RCC_HSI
 * 2- RCC_HSE
 * 3- RCC_PLL
 */
#define SYS_CLK						RCC_HSE


#if SYS_CLK == RCC_HSE

	/* Options:
	 * 1- RCC_HSE_RC
	 * 2- RCC_HSE_CRYSTAL
	 */
	#define HSE_SOURCE				RCC_HSE_CRYSTAL

	/* Options:
	 * 1- RCC_CLK_SECURITY_ENABLE
	 * 2- RCC_CLK_SECURITY_DISABLE
	 */
	#define CLK_SECURITY			RCC_CLK_SECURITY_DISABLE

#elif SYS_CLK == RCC_PLL

	/* Options:
	 * 1- RCC_PLL_HSI
	 * 2- RCC_PLL_HSE
	 */
	#define PLL_SOURCE					RCC_PLL_HSE

	#if PLL_SOURCE == RCC_PLL_HSE
		/* Options:
		 * 1- RCC_HSE_RC
		 * 2- RCC_HSE_CRYSTAL
		 */
		#define HSE_SOURCE				RCC_HSE_CRYSTAL
	#endif

	/* Options:
	 * 1- RCC_PLL_DIV_BY_2
	 * 2- RCC_PLL_DIV_BY_4
	 * 3- RCC_PLL_DIV_BY_6
	 * 4- RCC_PLL_DIV_BY_8
	 */
	#define PLL_PRESCALER				RCC_PLL_DIV_BY_2

	/* Options:
	 * From 2 to 432
	 * */
	#define PLL_MULTIPLICATION_FACTOR	16
#endif

#endif
