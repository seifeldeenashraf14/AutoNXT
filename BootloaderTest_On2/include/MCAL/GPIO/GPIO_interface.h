/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : GPIO                   ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 10 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
/*************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/* GPIO PORTs */
#define GPIO_PORTA								0
#define GPIO_PORTB								1
#define GPIO_PORTC								2

/* GPIO PINs */
#define GPIO_PIN0								0
#define GPIO_PIN1								1
#define GPIO_PIN2								2
#define GPIO_PIN3								3
#define GPIO_PIN4								4
#define GPIO_PIN5								5
#define GPIO_PIN6								6
#define GPIO_PIN7								7
#define GPIO_PIN8								8
#define GPIO_PIN9								9
#define GPIO_PIN10								10
#define GPIO_PIN11								11
#define GPIO_PIN12								12
#define GPIO_PIN13								13
#define GPIO_PIN14								14
#define GPIO_PIN15								15

void GPIO_voidSetMode (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void GPIO_voidOutputPinMode (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OutputMode, u8 Copy_u8Speed);
void GPIO_voidInputPinMode (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8InputMode);
void GPIO_voidGetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Pointer_u8Data);
void GPIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Data);
void GPIO_voidSetResetValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
void GPIO_voidSetAlternativeLine (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Alternative);
void GPIO_voidSetPortValue (u8 Copy_u8Port, u32 Copy_u32Value);

/* Pin modes */
#define GPIO_INPUT								0
#define GPIO_OUTPUT                           	1
#define GPIO_ALTERNATE                          2
#define GPIO_ANALOG                             3

/* Output modes */
#define GPIO_OUTPUT_PUSHPULL					0
#define GPIO_OUTPUT_OPENDRAIN					1

/* Output speed */
#define GPIO_LOW_SPEED							0
#define GPIO_MEDIUM_SPEED                       1
#define GPIO_HIGH_SPEED                         2
#define GPIO_VERY_HIGH_SPEED                    3

/* Input modes */
#define GPIO_INPUT_NORMAL						0
#define GPIO_INPUT_PULL_UP						1
#define GPIO_INPUT_PULL_DOWN					2

/* Output value */
#define GPIO_PIN_LOW							0
#define GPIO_PIN_HIGH							1


#define GPIO_AF0_SYSTEM							0
#define GPIO_AF1_TIM_1_2						1
#define GPIO_AF2_TIM_3_5						2
#define GPIO_AF3_TIM_9_11                       3
#define GPIO_AF4_I2C_1_3                        4
#define GPIO_AF5_SPI_1_4                        5
#define GPIO_AF6_SPI_3                          6
#define GPIO_AF7_USART_1_2                      7
#define GPIO_AF8_USART_6                        8
#define GPIO_AF9_I2C_2_3                        9
#define GPIO_AF10_OTG_FS                        10
#define GPIO_AF11                               11
#define GPIO_AF12_SDIO                          12
#define GPIO_AF13                               13
#define GPIO_AF14                               14
#define GPIO_AF15_EVENTOUT                      15


#endif
