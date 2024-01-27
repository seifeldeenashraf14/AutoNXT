/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : HAL                    ***********************/
/***********************            SWC     : IR                     ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 21 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef IR_CONFIG_H_
#define IR_CONFIG_H_

/* options:
 * From NVIC_PERIPHERAL_EXTI0 to NVIC_PERIPHERAL_EXTI15
 */
#define IR_NVIC_LINE							NVIC_PERIPHERAL_EXTI0

/* options:
 * From EXTI_LINE0 to EXTI_LINE15
 */
#define IR_EXTI									EXTI_LINE0

/* options:
 * 1- EXTI_PORTA
 * 2- EXTI_PORTB
 * 3- EXTI_PORTC
 */
#define IR_PORT									EXTI_PORTA

/* depend on the maximum period for signal */
#define IR_TIMEOUT								20

#endif
