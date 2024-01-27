/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : RCC                    ***********************/
/***********************            Version : 2.0                    ***********************/
/***********************            Date    : 18 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

void RCC_voidInit (void);
void RCC_voidEnablePeripheral (u32 Copy_u32BusID, u32 Copy_u32PeripheralID);
void RCC_voidDisablePeripheral (u32 Copy_u32BusID, u32 Copy_u32PeripheralID);
void RCC_voidSetAPB2Prescaler (u8 Copy_u8Prescaler);
void RCC_voidSetAPB1Prescaler (u8 Copy_u8Prescaler);
void RCC_voidSetAHB1Prescaler (u8 Copy_u8Prescaler);

#define RCC_APB1							0
#define RCC_APB2                            1
#define RCC_AHB1                            2
#define RCC_AHB2                            3

/***********************            APB1            ***********************/
#define RCC_APB1_TIM2						0
#define RCC_APB1_TIM3						1
#define RCC_APB1_TIM4						2
#define RCC_APB1_TIM5						3
#define RCC_APB1_WWDG						11
#define RCC_APB1_SPI2						14
#define RCC_APB1_SPI3						15
#define RCC_APB1_USART2						17
#define RCC_APB1_I2C1						21
#define RCC_APB1_I2C2						22
#define RCC_APB1_I2C3						23
#define RCC_APB1_PWR						28

/***********************            APB2            ***********************/
#define RCC_APB2_TIM1						0
#define RCC_APB2_USART1                     4
#define RCC_APB2_USART6                     5
#define RCC_APB2_ADC1                       8
#define RCC_APB2_SDIO                       11
#define RCC_APB2_SPI1                       12
#define RCC_APB2_SPI4                       13
#define RCC_APB2_SYSCFG                     14
#define RCC_APB2_TIM9                       16
#define RCC_APB2_TIM10                      17
#define RCC_APB2_TIM11                      18

/***********************            AHB1            ***********************/
#define RCC_AHB1_GPIOA						0
#define RCC_AHB1_GPIOB	                    1
#define RCC_AHB1_GPIOC	                    2
#define RCC_AHB1_GPIOD	                    3
#define RCC_AHB1_GPIOE	                    4
#define RCC_AHB1_GPIOH	                    7
#define RCC_AHB1_CRC	                    12
#define RCC_AHB1_FLITF	                    15
#define RCC_AHB1_SRAM1	                    16
#define RCC_AHB1_DMA1	                    21
#define RCC_AHB1_DMA2	                    22

/***********************            AHB2            ***********************/
#define RCC_AHB2_OTGFS						7

/* Configurations  */
#define RCC_HSI                             0
#define RCC_HSE								1
#define RCC_PLL                             2

#define RCC_CLK_SECURITY_DISABLE			0
#define RCC_CLK_SECURITY_ENABLE				1

#define RCC_HSE_RC							0
#define RCC_HSE_CRYSTAL						1

#define RCC_PLL_HSI							0
#define RCC_PLL_HSE							1

#define RCC_PLL_DIV_BY_2					0
#define RCC_PLL_DIV_BY_4					1
#define RCC_PLL_DIV_BY_6					2
#define RCC_PLL_DIV_BY_8					3

#define RCC_APB_1_PRESCALER					3
#define RCC_APB_2_PRESCALER					4
#define RCC_APB_4_PRESCALER					5
#define RCC_APB_8_PRESCALER					6
#define RCC_APB_16_PRESCALER				7

#define RCC_AHB_1_PRESCALER					7
#define RCC_AHB_2_PRESCALER					8
#define RCC_AHB_4_PRESCALER					9
#define RCC_AHB_8_PRESCALER					10
#define RCC_AHB_16_PRESCALER				11
#define RCC_AHB_64_PRESCALER				12
#define RCC_AHB_128_PRESCALER				13
#define RCC_AHB_256_PRESCALER				14
#define RCC_AHB_512_PRESCALER				15


#endif
