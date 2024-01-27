/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : NVIC                   ***********************/
/***********************            Version : 1.5                    ***********************/
/***********************            Date    : 11 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
/*************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


#define NVIC_GROUP16SUB0						3
#define NVIC_GROUP8SUB2							4
#define NVIC_GROUP4SUB4							5
#define NVIC_GROUP2SUB8							6
#define NVIC_GROUP0SUB16						7



#define NVIC_PERIPHERAL_WWDG					0
#define NVIC_PERIPHERAL_EXTI16_PVD				1
#define NVIC_PERIPHERAL_EXTI21_TAMP_STAMP       2
#define NVIC_PERIPHERAL_EXTI22_RTC_WKUP         3
#define NVIC_PERIPHERAL_FLASH                   4
#define NVIC_PERIPHERAL_RCC                     5
#define NVIC_PERIPHERAL_EXTI0                   6
#define NVIC_PERIPHERAL_EXTI1                   7
#define NVIC_PERIPHERAL_EXTI2                   8
#define NVIC_PERIPHERAL_EXTI3                   9
#define NVIC_PERIPHERAL_EXTI4                   10
#define NVIC_PERIPHERAL_DMA1_STREAM0            11
#define NVIC_PERIPHERAL_DMA1_STREAM1            12
#define NVIC_PERIPHERAL_DMA1_STREAM2            13
#define NVIC_PERIPHERAL_DMA1_STREAM3            14
#define NVIC_PERIPHERAL_DMA1_STREAM4            15
#define NVIC_PERIPHERAL_DMA1_STREAM5            16
#define NVIC_PERIPHERAL_DMA1_STREAM6            17
#define NVIC_PERIPHERAL_ADC                     18
#define NVIC_PERIPHERAL_EXTI9_5	             	23
#define NVIC_PERIPHERAL_TIM1_BRK_TIM9           24
#define NVIC_PERIPHERAL_TIM1_UP_TIM10           25
#define NVIC_PERIPHERAL_TIM1_TRG_COM_TIM11      26
#define NVIC_PERIPHERAL_TIM1_CC                 27
#define NVIC_PERIPHERAL_TIM2                    28
#define NVIC_PERIPHERAL_TIM3                    29
#define NVIC_PERIPHERAL_TIM4                    30
#define NVIC_PERIPHERAL_I2C1_EV                 31
#define NVIC_PERIPHERAL_I2C1_ER                 32
#define NVIC_PERIPHERAL_I2C2_EV                 33
#define NVIC_PERIPHERAL_I2C2_ER                 34
#define NVIC_PERIPHERAL_SPI1                    35
#define NVIC_PERIPHERAL_SPI2                    36
#define NVIC_PERIPHERAL_USART1                  37
#define NVIC_PERIPHERAL_USART2                  38
#define NVIC_PERIPHERAL_EXTI15_10  		        40
#define NVIC_PERIPHERAL_EXTI17_RTC_ALARM        41
#define NVIC_PERIPHERAL_EXTI18_OTG_FS_WKUP      42
#define NVIC_PERIPHERAL_DMA1_Stream7            47
#define NVIC_PERIPHERAL_SDIO                  	49
#define NVIC_PERIPHERAL_TIM5                    50
#define NVIC_PERIPHERAL_SPI3                    51
#define NVIC_PERIPHERAL_DMA2_STREAM0	        56
#define NVIC_PERIPHERAL_DMA2_STREAM1            57
#define NVIC_PERIPHERAL_DMA2_STREAM2            58
#define NVIC_PERIPHERAL_DMA2_STREAM3            59
#define NVIC_PERIPHERAL_DMA2_STREAM4            60
#define NVIC_PERIPHERAL_OTG_FS  				67
#define NVIC_PERIPHERAL_DMA2_STREAM5            68
#define NVIC_PERIPHERAL_DMA2_STREAM6            69
#define NVIC_PERIPHERAL_DMA2_STREAM7            70
#define NVIC_PERIPHERAL_USART6                  71
#define NVIC_PERIPHERAL_I2C3_EV                 72
#define NVIC_PERIPHERAL_I2C3_ER                 73
#define NVIC_PERIPHERAL_FPU	                 	81
#define NVIC_PERIPHERAL_SPI4	                84


void NVIC_voidEnablePeripheralInterrupt (u8 Copy_u8Peripheral);
void NVIC_voidDisablePeripheralInterrupt (u8 Copy_u8Peripheral);
void NVIC_voidEnablePeripheralInterruptPending (u8 Copy_u8Peripheral);
void NVIC_voidDisablePeripheralInterruptPending (u8 Copy_u8Peripheral);
void NVIC_voidIsPeripheralInterruptActive (u8 Copy_tenumPeriphera, u8 *Pointer_u8Read);
void NVIC_voidSetInterruptGroupMode (u8 Copy_u8GroupMode);
void NVIC_voidSetInterruptPriority (u8 Copy_u8Peripheral, u8 Copy_u8Group, u8 Copy_u8SubGroup);

#endif
