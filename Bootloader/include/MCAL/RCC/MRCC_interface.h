/**
 * @file MRCC_Interface.h
 * @author Hosam Ayoub
 * @version 2.0
 * @date 18 Sep 2023
 * @brief The Reset Clock Control header file that has all the functions prototypes and arguments of the **RCC** driver
 */
#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_
/**
 * @fn 		void MRCC_voidInit (void)
 * @brief   This function is responsible of Initializing Reset Clock Control
 * @param 	none
 * @return 	none
 * @details This function initialize the system clock:
 * -# Check that the system clock is External or PLL or Internal then wait for the Ready flag then switch to to chosen Clock
 * -# if The chosen Clock is external ,Function will check if it's source is Crystal or RC then Check if Clock Security Enabl or Disable
 * -# if The chosen Clock is PLL ,Function will check if PLL's source is HSI or HSE then set PLL Multiplication Factor and  PLL Prescaler
 * -# Wait for the ready flag in Chosen Clock then Switch to chosen clock
 */

void MRCC_voidInit (void);
/**
 * @fn 		void MRCC_voidDisablePeripheral (u32,u32)
 * @brief 	This function responsible of Disabling the peripheral Clock From RCC
 * @param 	Copy_u32BusID Copy of the Bus id in which the Peripheral Located
 * @param 	Copy_u32PeripheralID Copy of the Peripheral Id to access it in its bus
 * @return	none
 */
void MRCC_voidDisablePeripheral (u32 Copy_u32BusID, u32 Copy_u32PeripheralID);
/**
 * @fn 		void MRCC_voidEnablePeripheral (u32,u32)
 * @brief 	This function responsible of Enabling the peripheral Clock From RCC
 * @param 	Copy_u32BusID Copy of the Bus id in which the Peripheral Located
 * @param 	Copy_u32PeripheralID Copy of the Peripheral Id to access it in its bus
 * @return	none
 */
void MRCC_voidEnablePeripheral (u32 Copy_u32BusID, u32 Copy_u32PeripheralID);
/**
 * @fn 		void MRCC_voidSetAPB2Prescaler (u8)
 * @brief 	This function responsible of Determining the APB2 Bus Prescaler
 * @param 	Copy_u8Prescaler Copy of the prescaler value that will be assigned to APB2 Bus
 * @return	none
 */
void MRCC_voidSetAPB2Prescaler (u8 Copy_u8Prescaler);
/**
 * @fn 		void MRCC_voidSetAPB1Prescaler (u8)
 * @brief 	This function responsible of Determining the APB1 Bus Prescaler
 * @param 	Copy_u8Prescaler Copy of the prescaler value that will be assigned to APB1 Bus
 * @return	none
 */
void MRCC_voidSetAPB1Prescaler (u8 Copy_u8Prescaler);
/**
 * @fn 		void MRCC_voidSetAHB1Prescaler (u8)
 * @brief 	This function responsible of Determining the AHB1 Bus Prescaler
 * @param 	Copy_u8Prescaler Copy of the prescaler value that will be assigned to AHB1 Bus
 * @return	none
 */
void MRCC_voidSetAHB1Prescaler (u8 Copy_u8Prescaler);

#define MRCC_APB1							 0       //!<  APP1 Bus is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral
#define MRCC_APB2                            1       //!<  APB2 Bus is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral
#define MRCC_AHB1                            2       //!<  AHB1 Bus is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral
#define MRCC_AHB2                            3       //!<  AHB2 Bus is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral

/***********************            APB1            ***********************/
#define MRCC_APB1_TIM2						0       //!<  TIMER2 Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1
#define MRCC_APB1_TIM3						1       //!<  TIMER3 Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1
#define MRCC_APB1_TIM4						2       //!<  TIMER4 Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1
#define MRCC_APB1_TIM5						3       //!<  TIMER5 Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1
#define MRCC_APB1_WWDG						11      //!<  Watch dog Timer Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1
#define MRCC_APB1_SPI2						14      //!<  SPI2 Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1
#define MRCC_APB1_SPI3						15      //!<  SPI3 Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1
#define MRCC_APB1_USART2					17      //!<  USART2 Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1
#define MRCC_APB1_I2C1						21      //!<  I2C1 Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1
#define MRCC_APB1_I2C2						22      //!<  I2C2 Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1
#define MRCC_APB1_I2C3						23      //!<  I2C3 Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1
#define MRCC_APB1_PWR						28      //!<  PWR Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB1

/***********************            APB2            ***********************/
#define MRCC_APB2_TIM1						 0       //!<  TIMER1 Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB2
#define MRCC_APB2_USART1                     4       //!<  USART1  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB2
#define MRCC_APB2_USART6                     5       //!<  USART6  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB2
#define MRCC_APB2_ADC1                       8       //!<  ADC1  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB2
#define MRCC_APB2_SDIO                       11      //!<  SDIO  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB2
#define MRCC_APB2_SPI1                       12      //!<  SPI1  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB2
#define MRCC_APB2_SPI4                       13      //!<  SPI4  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB2
#define MRCC_APB2_SYSCFG                     14      //!<  SYSCFG  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB2
#define MRCC_APB2_TIM9                       16      //!<  TIMER9  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB2
#define MRCC_APB2_TIM10                      17      //!<  TIMER10  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB2
#define MRCC_APB2_TIM11                      18      //!<  TIMER11  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_APB2

/***********************            AHB1            ***********************/
#define MRCC_AHB1_GPIOA						0         //!<  GPIOA  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB1
#define MRCC_AHB1_GPIOB	                    1         //!<  GPIOB  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB1
#define MRCC_AHB1_GPIOC	                    2         //!<  GPIOC  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB1
#define MRCC_AHB1_GPIOD	                    3         //!<  GPIOD  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB1
#define MRCC_AHB1_GPIOE	                    4         //!<  GPIOE  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB1
#define MRCC_AHB1_GPIOH	                    7         //!<  GPIOH  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB1
#define MRCC_AHB1_CRC	                    12        //!<  CRC  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB1
#define MRCC_AHB1_FLITF	                    15        //!<  FLTTF  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB1
#define MRCC_AHB1_SRAM1	                    16        //!<  SRAM1  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB1
#define MRCC_AHB1_DMA1	                    21        //!<  DMA1  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB1
#define MRCC_AHB1_DMA2	                    22        //!<  DMA2  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB1

/***********************            AHB2            ***********************/
#define MRCC_AHB2_OTGFS						7       //!<  OTFGS  Peripheral is argument of the @ref MRCC_voidDisablePeripheral @ref MRCC_voidEnablePeripheral come only with @ref MRCC_AHB2

/* Configurations  */
#define MRCC_HSI                            0         //!< HSI CLOCK is  an option for @ref SYS_CLK
#define MRCC_HSE						    1         //!< HSE CLOCK is  an option for @ref SYS_CLK
#define MRCC_PLL                            2         //!< PLL CLOCK is  an option for @ref SYS_CLK

#define MRCC_CLK_SECURITY_DISABLE			0         //!< Clock Security is an option for @ref CLK_SECURITY
#define MRCC_CLK_SECURITY_ENABLE		    1         //!< Clock Security is an option for @ref CLK_SECURITY

#define MRCC_HSE_RC							0         //!< RC Clock is an option for @ref HSE_SOURCE
#define MRCC_HSE_CRYSTAL				    1         //!< CRYSTAL Clock is an option for @ref HSE_SOURCE

#define MRCC_PLL_HSI						0         //!< PLL HSI Source Clock is an option for @ref PLL_SOURCE
#define MRCC_PLL_HSE						1         //!< PLL HSE Source is an option for @ref PLL_SOURCE

#define MRCC_PLL_DIV_BY_2					0        //!< PLL divided by factor 2 is an option for @ref PLL_PRESCALER
#define MRCC_PLL_DIV_BY_4					1        //!< PLL divided by factor 4 is an option for @ref PLL_PRESCALER
#define MRCC_PLL_DIV_BY_6					2        //!< PLL divided by factor 6 is an option for @ref PLL_PRESCALER
#define MRCC_PLL_DIV_BY_8					3        //!< PLL divided by factor 8 is an option for @ref PLL_PRESCALER

#define MRCC_APB_1_PRESCALER				3        //!< Prescaler 1 is an argument of the @ref MRCC_voidSetAPB1Prescaler @ref  MRCC_voidSetAPB2Prescaler
#define MRCC_APB_2_PRESCALER				4        //!< Prescaler 2 is an argument of the @ref MRCC_voidSetAPB1Prescaler @ref  MRCC_voidSetAPB2Prescaler
#define MRCC_APB_4_PRESCALER				5        //!< Prescaler 4 is an argument of the @ref MRCC_voidSetAPB1Prescaler @ref  MRCC_voidSetAPB2Prescaler
#define MRCC_APB_8_PRESCALER				6        //!< Prescaler 8 is an argument of the @ref MRCC_voidSetAPB1Prescaler @ref  MRCC_voidSetAPB2Prescaler
#define MRCC_APB_16_PRESCALER				7        //!< Prescaler 16 is an argument of the @ref MRCC_voidSetAPB1Prescaler @ref  MRCC_voidSetAPB2Prescaler

#define MRCC_AHB_1_PRESCALER				7       //!< Prescaler 1 is an argument of the @ref MRCC_voidSetAHB1Prescaler
#define MRCC_AHB_2_PRESCALER				8       //!< Prescaler 2 is an argument of the @ref MRCC_voidSetAHB1Prescaler
#define MRCC_AHB_4_PRESCALER				9       //!< Prescaler 4 is an argument of the @ref MRCC_voidSetAHB1Prescaler
#define MRCC_AHB_8_PRESCALER				10      //!< Prescaler 8 is an argument of the @ref MRCC_voidSetAHB1Prescaler
#define MRCC_AHB_16_PRESCALER				11      //!< Prescaler 16 is an argument of the @ref MRCC_voidSetAHB1Prescaler
#define MRCC_AHB_64_PRESCALER				12      //!< Prescaler 64 is an argument of the @ref MRCC_voidSetAHB1Prescaler
#define MRCC_AHB_128_PRESCALER				13      //!< Prescaler 128 is an argument of the @ref MRCC_voidSetAHB1Prescaler
#define MRCC_AHB_256_PRESCALER				14      //!< Prescaler 256 is an argument of the @ref MRCC_voidSetAHB1Prescaler
#define MRCC_AHB_512_PRESCALER				15      //!< Prescaler 512 is an argument of the @ref MRCC_voidSetAHB1Prescaler


#endif
