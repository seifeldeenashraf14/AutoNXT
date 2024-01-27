/*
 * MGPIO_Interface.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Hesham Yasser
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

/*******************PORTS********************/
#define GPIO_PORTA				0
#define GPIO_PORTB				1
#define GPIO_PORTC				2

/********************PINS********************/

#define GPIO_PIN0				0
#define GPIO_PIN1				1
#define GPIO_PIN2				2
#define GPIO_PIN3				3
#define GPIO_PIN4				4
#define GPIO_PIN5				5
#define GPIO_PIN6				6
#define GPIO_PIN7				7
#define GPIO_PIN8				8
#define GPIO_PIN9				9
#define GPIO_PIN10				10
#define GPIO_PIN11				11
#define GPIO_PIN12				12
#define GPIO_PIN13				13
#define GPIO_PIN14				14
#define GPIO_PIN15				15

/********************PIN_VALUES*******************/

#define GPIO_PIN_LOW			0
#define GPIO_PIN_HIGH			1

/********************PIN_MODES********************/

#define GPIO_INPUT			0b00
#define GPIO_OUTPUT			0b01
#define GPIO_ALT_FUNC		0b10
#define GPIO_ANALOG			0b11

/********************INPUT_MODES********************/

#define GPIO_NOPUPD			0b00
#define GPIO_PULLUP			0b01
#define GPIO_PULLDOWN		0b10

/********************OUTPUT_MODES********************/

#define GPIO_PUSH_PULL		0b0
#define GPIO_OPEN_DRAIN		0b1

/********************OUTPUT_MODE_SPEEDS********************/

#define GPIO_LOW_SPEED		0b00
#define GPIO_MID_SPEED		0b01
#define GPIO_HIGH_SPEED		0b10
#define GPIO_VHIGH_SPEED	0b11

/********************PIN_SET_RESET**********************/

#define GPIO_SET			1
#define GPIO_RESET			0

/*********************Alt_Functions*********************/
#define GPIO_AF0			0b0000
#define GPIO_AF1			0b0001
#define GPIO_AF2			0b0010
#define GPIO_AF3			0b0011
#define GPIO_AF4			0b0100
#define GPIO_AF5			0b0101
#define GPIO_AF6			0b0110
#define GPIO_AF7			0b0111
#define GPIO_AF8			0b1000
#define GPIO_AF9			0b1001
#define GPIO_AF10			0b1010
#define GPIO_AF11			0b1011
#define GPIO_AF12			0b1100
#define GPIO_AF13			0b1101
#define GPIO_AF14			0b1110
#define GPIO_AF15			0b1111
/********************APIs********************/

void MGPIO_voidSetPinMode (u8 A_u8Port , u8 A_u8Pin , u8 A_u8Mode);
void MGPIO_voidSetPinOutputMode (u8 A_u8Port , u8 A_u8Pin , u8 A_u8OutputMode , u8 A_u8Speed);
void MGPIO_voidSetPinInputMode (u8 A_u8Port , u8 A_u8Pin , u8 A_u8InputMode);
void MGPIO_voidSetPinValue (u8 A_u8Port , u8 A_u8Pin , u8 A_u8Output);
void MGPIO_voidGetPinValue (u8 A_u8Port , u8 A_u8Pin , u8 * pu8Return);
void MGPIO_voidSetResetPin (u8 A_u8Port , u8 A_u8Pin , u8 A_u8SetResetValue);
void MGPIO_voidSetPinAltrenativeFunction (u8 A_u8Port , u8 A_u8Pin , u8 A_u8AltFunc);

#endif /* MGPIO_INTERFACE_H_ */







