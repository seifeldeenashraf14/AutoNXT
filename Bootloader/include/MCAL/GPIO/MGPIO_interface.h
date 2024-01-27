/**
 * @file	MGPIO_interface.h
 * @author 	Hesham Yasser
 * @version 2.5
 * @date 	10 Oct 2023
 * @brief 	the GPIO interface header file that contains the declarations of *GPIO* driver
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

/*******************PORTS********************/
#define GPIO_PORTA				0				//<! this is the GPIOA Macro
#define GPIO_PORTB				1				//<! this is the GPIOB Macro
#define GPIO_PORTC				2				//<! this is the GPIOC Macro

/********************PINS********************/

#define GPIO_PIN0				0				//<! this is the Pin number 0 macro
#define GPIO_PIN1				1               //<! this is the Pin number 1 macro
#define GPIO_PIN2				2               //<! this is the Pin number 2 macro
#define GPIO_PIN3				3               //<! this is the Pin number 3 macro
#define GPIO_PIN4				4               //<! this is the Pin number 4 macro
#define GPIO_PIN5				5               //<! this is the Pin number 5 macro
#define GPIO_PIN6				6               //<! this is the Pin number 6 macro
#define GPIO_PIN7				7               //<! this is the Pin number 7 macro
#define GPIO_PIN8				8               //<! this is the Pin number 8 macro
#define GPIO_PIN9				9               //<! this is the Pin number 9 macro
#define GPIO_PIN10				10              //<! this is the Pin number 10 macro
#define GPIO_PIN11				11              //<! this is the Pin number 11 macro
#define GPIO_PIN12				12              //<! this is the Pin number 12 macro
#define GPIO_PIN13				13              //<! this is the Pin number 13 macro
#define GPIO_PIN14				14              //<! this is the Pin number 14 macro
#define GPIO_PIN15				15              //<! this is the Pin number 15 macro

/********************PIN_VALUES*******************/

#define GPIO_PIN_LOW			0				//<! this is the macro for low pin value
#define GPIO_PIN_HIGH			1				//<! this is the macro for high pin value

/********************PIN_MODES********************/

#define GPIO_INPUT			0b00				//<! this is the macro for setting the pin input
#define GPIO_OUTPUT			0b01				//<! this is the macro for setting the pin output
#define GPIO_ALT_FUNC		0b10				//<! this is the macro for setting the pin alternative function
#define GPIO_ANALOG			0b11				//<! this is the macro for setting the pin analog

/********************INPUT_MODES********************/

#define GPIO_NOPUPD			0b00				//<! this is the macro of input mode No pull up nor pull down
#define GPIO_PULLUP			0b01				//<! this is the macro of input mode pull up
#define GPIO_PULLDOWN		0b10				//<! this is the macro of input mode pull down

/********************OUTPUT_MODES********************/

#define GPIO_PUSH_PULL		0b0					//<! this is the macro for output mode Push pull
#define GPIO_OPEN_DRAIN		0b1					//<! this is the macro for output mode open drain

/********************OUTPUT_MODE_SPEEDS********************/

#define GPIO_LOW_SPEED		0b00				//<! this is the macro for pin speed mode Low
#define GPIO_MID_SPEED		0b01				//<! this is the macro for pin speed mode Mid
#define GPIO_HIGH_SPEED		0b10				//<! this is the macro for pin speed mode high
#define GPIO_VHIGH_SPEED	0b11				//<! this is the macro for pin speed mode very high

/********************PIN_SET_RESET**********************/

#define GPIO_SET			1					//<! this is the macro for setting selected pin
#define GPIO_RESET			0					//<! this is the macro for resetting selected pin

/*********************Alt_Functions*********************/

#define GPIO_AF0			0b0000				//<! this is the macro for alternative function no. 0
#define GPIO_AF1			0b0001              //<! this is the macro for alternative function no. 1
#define GPIO_AF2			0b0010              //<! this is the macro for alternative function no. 2
#define GPIO_AF3			0b0011              //<! this is the macro for alternative function no. 3
#define GPIO_AF4			0b0100              //<! this is the macro for alternative function no. 4
#define GPIO_AF5			0b0101              //<! this is the macro for alternative function no. 5
#define GPIO_AF6			0b0110              //<! this is the macro for alternative function no. 6
#define GPIO_AF7			0b0111              //<! this is the macro for alternative function no. 7
#define GPIO_AF8			0b1000              //<! this is the macro for alternative function no. 8
#define GPIO_AF9			0b1001              //<! this is the macro for alternative function no. 9
#define GPIO_AF10			0b1010              //<! this is the macro for alternative function no. 10
#define GPIO_AF11			0b1011              //<! this is the macro for alternative function no. 11
#define GPIO_AF12			0b1100              //<! this is the macro for alternative function no. 12
#define GPIO_AF13			0b1101              //<! this is the macro for alternative function no. 13
#define GPIO_AF14			0b1110              //<! this is the macro for alternative function no. 14
#define GPIO_AF15			0b1111              //<! this is the macro for alternative function no. 15

/********************APIs********************/


/**
 * @fn void MGPIO_voidSetPinMode(u8, u8, u8)
 * @brief this function is responsible for setting any pin mode of STM GPIO pins
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8Mode this is the mode selected for this pin
 * @return none
 */
void MGPIO_voidSetPinMode (u8 A_u8Port , u8 A_u8Pin , u8 A_u8Mode);

/**
 * @fn void MGPIO_voidSetPinOutputMode(u8, u8, u8, u8)
 * @brief this function is responsible for setting the output configurations of any selected *GPIO* pin
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8OutputMode this is the output mode selected for this pin
 * @param A_u8Speed this is the speed configured for the selected pin
 * @return none
 */
void MGPIO_voidSetPinOutputMode (u8 A_u8Port , u8 A_u8Pin , u8 A_u8OutputMode , u8 A_u8Speed);

/**
 * @fn void MGPIO_voidSetPinAltrenativeFunction(u8, u8, u8)
 * @brief this function is responsible for setting the alternative function of any selected *GPIO* pins
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8AltFunc this is the alternative function selected for this pin
 * @return none
 */
void MGPIO_voidSetPinAltrenativeFunction (u8 A_u8Port , u8 A_u8Pin , u8 A_u8AltFunc);

/**
 * @fn void MGPIO_voidSetPinInputMode(u8, u8, u8)
 * @brief this function is responsible for setting the input mode of any selected *GPIO* pins
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8InputMode this is the input mode selected for this pin
 * @return none
 */
void MGPIO_voidSetPinInputMode (u8 A_u8Port , u8 A_u8Pin , u8 A_u8InputMode);

/**
 * @fn void MGPIO_voidSetPinValue(u8, u8, u8)
 * @brief this function is responsible for setting the value of any output *GPIO* pin
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8Output this is the value selected for this pin
 * @return none
 */
void MGPIO_voidSetPinValue (u8 A_u8Port , u8 A_u8Pin , u8 A_u8Output);

/**
 * @fn void MGPIO_voidGetPinValue(u8, u8, u8*)
 * @brief this function is responsible for getting the current value of any input *GPIO* pin
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to check its value
 * @param pu8Return this is the pointer to variable to save the value of pin in
 * @return none
 */
void MGPIO_voidGetPinValue (u8 A_u8Port , u8 A_u8Pin , u8 * pu8Return);

/**
 * @fn void MGPIO_voidSetResetPin(u8, u8, u8)
 * @brief this function is responsible for setting the value of any output *GPIO* pin (but in one clk cycle)
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8SetResetValue this is the value to be setted for the selected pin
 * @return none
 */
void MGPIO_voidSetResetPin (u8 A_u8Port , u8 A_u8Pin , u8 A_u8SetResetValue);

/**
 * @fn void MGPIO_voidSetPortValue(u8, u16)
 * @brief this function is responsible for setting the whole port value
 * @param A_u8Port this is the selected port
 * @param A_u16Data this is the value of the port
 * @return none
 */
void MGPIO_voidSetPortValue (u8 A_u8Port , u16 A_u16Data);


#endif /* MGPIO_INTERFACE_H_ */







