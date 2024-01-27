/*
 * MGPIO_Program.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Hesham Yasser
 */
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/MCAL/GPIO/MGPIO_Interface.h"
#include "../include/MCAL/GPIO/MGPIO_Private.h"
#include "../include/MCAL/GPIO/MGPIO_Config.h"


void MGPIO_voidSetPinMode (u8 A_u8Port , u8 A_u8Pin , u8 A_u8Mode)
{
	if ((A_u8Port == GPIO_PORTA) && ((A_u8Pin == GPIO_PIN13) || (A_u8Pin == GPIO_PIN14) || (A_u8Pin == GPIO_PIN15)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else if ((A_u8Port == GPIO_PORTB) && ((A_u8Pin == GPIO_PIN3) || (A_u8Pin == GPIO_PIN4)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else
	{
		switch (A_u8Port)
		{
		case GPIO_PORTA:
			GPIOA->MODER &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOA->MODER |= (A_u8Mode<<(A_u8Pin*2));
			break;
		case GPIO_PORTB:
			GPIOB->MODER &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOB->MODER |= (A_u8Mode<<(A_u8Pin*2));
			break;
		case GPIO_PORTC:
			GPIOC->MODER &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOC->MODER |= (A_u8Mode<<(A_u8Pin*2));
			break;
		default :
			break;
		}
	}
}
void MGPIO_voidSetPinOutputMode (u8 A_u8Port , u8 A_u8Pin , u8 A_u8OutputMode , u8 A_u8Speed)
{
	if ((A_u8Port == GPIO_PORTA) && ((A_u8Pin == GPIO_PIN13) || (A_u8Pin == GPIO_PIN14) || (A_u8Pin == GPIO_PIN15)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else if ((A_u8Port == GPIO_PORTB) && ((A_u8Pin == GPIO_PIN3) || (A_u8Pin == GPIO_PIN4)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else
	{
		switch (A_u8Port)
		{
		case GPIO_PORTA:
			GPIOA->OSPEEDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOA->OSPEEDR |= (A_u8Speed<<(A_u8Pin*2));
			GPIOA->OTYPER &= ~(ONE_BIT_MASK<<A_u8Pin);
			GPIOA->OTYPER |= (A_u8OutputMode<<A_u8Pin);
			break;
		case GPIO_PORTB:
			GPIOB->OSPEEDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOB->OSPEEDR |= (A_u8Speed<<(A_u8Pin*2));
			GPIOB->OTYPER &= ~(ONE_BIT_MASK<<A_u8Pin);
			GPIOB->OTYPER |= (A_u8OutputMode<<A_u8Pin);
			break;
		case GPIO_PORTC:
			GPIOC->OSPEEDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOC->OSPEEDR |= (A_u8Speed<<(A_u8Pin*2));
			GPIOC->OTYPER &= ~(ONE_BIT_MASK<<A_u8Pin);
			GPIOC->OTYPER |= (A_u8OutputMode<<A_u8Pin);
			break;
		default :
			break;
		}
	}
}
void MGPIO_voidSetPinInputMode (u8 A_u8Port , u8 A_u8Pin , u8 A_u8InputMode)
{
	if ((A_u8Port == GPIO_PORTA) && ((A_u8Pin == GPIO_PIN13) || (A_u8Pin == GPIO_PIN14) || (A_u8Pin == GPIO_PIN15)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else if ((A_u8Port == GPIO_PORTB) && ((A_u8Pin == GPIO_PIN3) || (A_u8Pin == GPIO_PIN4)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else
	{
		switch (A_u8Port)
		{
		case GPIO_PORTA:
			GPIOA->PUPDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOA->PUPDR |= (A_u8InputMode<<(A_u8Pin*2));
			break;
		case GPIO_PORTB:
			GPIOB->PUPDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOB->PUPDR |= (A_u8InputMode<<(A_u8Pin*2));
			break;
		case GPIO_PORTC:
			GPIOC->PUPDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOC->PUPDR |= (A_u8InputMode<<(A_u8Pin*2));
			break;
		default :
			break;
		}
	}
}

void MGPIO_voidSetPinValue (u8 A_u8Port , u8 A_u8Pin , u8 A_u8Output)
{
	if ((A_u8Port == GPIO_PORTA) && ((A_u8Pin == GPIO_PIN13) || (A_u8Pin == GPIO_PIN14) || (A_u8Pin == GPIO_PIN15)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else if ((A_u8Port == GPIO_PORTB) && ((A_u8Pin == GPIO_PIN3) || (A_u8Pin == GPIO_PIN4)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else
	{
		switch (A_u8Port)
		{
		case GPIO_PORTA:
			switch (A_u8Output)
			{
			case GPIO_PIN_HIGH:
				SET_BIT(GPIOA->ODR , A_u8Pin);
				break;
			case GPIO_PIN_LOW:
				CLR_BIT(GPIOA->ODR , A_u8Pin);
				break;
			}
			break;
		case GPIO_PORTB:
			switch (A_u8Output)
			{
			case GPIO_PIN_HIGH:
				SET_BIT(GPIOB->ODR , A_u8Pin);
				break;
			case GPIO_PIN_LOW:
				CLR_BIT(GPIOB->ODR , A_u8Pin);
				break;
			}
			break;
		case GPIO_PORTC:
			switch (A_u8Output)
			{
			case GPIO_PIN_HIGH:
				SET_BIT(GPIOC->ODR , A_u8Pin);
				break;
			case GPIO_PIN_LOW:
				CLR_BIT(GPIOC->ODR , A_u8Pin);
				break;
			}
				break;
		default :
			break;
		}
	}
}
void MGPIO_voidGetPinValue (u8 A_u8Port , u8 A_u8Pin , u8 * pu8Return)
{
	if (pu8Return != NULL)
	{
		if ((A_u8Port == GPIO_PORTA) && ((A_u8Pin == GPIO_PIN13) || (A_u8Pin == GPIO_PIN14) || (A_u8Pin == GPIO_PIN15)))
		{
			/*Do Nothing (Reserved Pins For Debugger)*/
		}
		else if ((A_u8Port == GPIO_PORTB) && ((A_u8Pin == GPIO_PIN3) || (A_u8Pin == GPIO_PIN4)))
		{
			/*Do Nothing (Reserved Pins For Debugger)*/
		}
		else
		{
			switch (A_u8Port)
			{
			case GPIO_PORTA:
				*pu8Return = GET_BIT(GPIOA->IDR , A_u8Pin);
				break;
			case GPIO_PORTB:
				*pu8Return = GET_BIT(GPIOB->IDR , A_u8Pin);
				break;
			case GPIO_PORTC:
				*pu8Return = GET_BIT(GPIOC->IDR , A_u8Pin);
				break;
			default :
				break;
			}
		}
	}

}
void MGPIO_voidSetResetPin (u8 A_u8Port , u8 A_u8Pin , u8 A_u8SetResetValue)
{
	if ((A_u8Port == GPIO_PORTA) && ((A_u8Pin == GPIO_PIN13) || (A_u8Pin == GPIO_PIN14) || (A_u8Pin == GPIO_PIN15)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else if ((A_u8Port == GPIO_PORTB) && ((A_u8Pin == GPIO_PIN3) || (A_u8Pin == GPIO_PIN4)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else
	{
		switch (A_u8Port)
		{
		case GPIO_PORTA:
			switch (A_u8SetResetValue)
			{
			case GPIO_SET:
				SET_BIT(GPIOA->BSRR , A_u8Pin);
				break;
			case GPIO_RESET:
				SET_BIT(GPIOA->BSRR , (A_u8Pin+GPIO_RESET_INDEX));
				break;
			}
			break;
		case GPIO_PORTB:
			switch (A_u8SetResetValue)
			{
			case GPIO_SET:
				SET_BIT(GPIOB->BSRR , A_u8Pin);
				break;
			case GPIO_RESET:
				SET_BIT(GPIOB->BSRR , (A_u8Pin+GPIO_RESET_INDEX));
				break;
			}
			break;
		case GPIO_PORTC:
			switch (A_u8SetResetValue)
			{
			case GPIO_SET:
				SET_BIT(GPIOC->BSRR , A_u8Pin);
				break;
			case GPIO_RESET:
				SET_BIT(GPIOC->BSRR , (A_u8Pin+GPIO_RESET_INDEX));
				break;
			}
				break;
		default :
			break;
		}
	}
}

void MGPIO_voidSetPinAltrenativeFunction (u8 A_u8Port , u8 A_u8Pin , u8 A_u8AltFunc)
{
	if ((A_u8Port == GPIO_PORTA) && ((A_u8Pin == GPIO_PIN13) || (A_u8Pin == GPIO_PIN14) || (A_u8Pin == GPIO_PIN15)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else if ((A_u8Port == GPIO_PORTB) && ((A_u8Pin == GPIO_PIN3) || (A_u8Pin == GPIO_PIN4)))
	{
		/*Do Nothing (Reserved Pins For Debugger)*/
	}
	else
	{
		/*Switch on the Entered port*/
		switch (A_u8Port)
		{
		case GPIO_PORTA:
			if (A_u8Pin < 8)
			{
				GPIOA->AFRL &= ~(FOUR_BIT_MASK<<(A_u8Pin*4));
				GPIOA->AFRL |= (A_u8AltFunc<<(A_u8Pin*4));
			}
			else
			{
				GPIOA->AFRH &= ~(FOUR_BIT_MASK<<((A_u8Pin-8)*4));
				GPIOA->AFRH |= (A_u8AltFunc<<((A_u8Pin-8)*4));
			}
			break;
		case GPIO_PORTB:
			if (A_u8Pin < 8)
			{
				GPIOB->AFRL &= ~(FOUR_BIT_MASK<<(A_u8Pin*4));
				GPIOB->AFRL |= (A_u8AltFunc<<(A_u8Pin*4));
			}
			else
			{
				GPIOB->AFRH &= ~(FOUR_BIT_MASK<<((A_u8Pin-8)*4));
				GPIOB->AFRH |= (A_u8AltFunc<<((A_u8Pin-8)*4));
			}
			break;
		case GPIO_PORTC:
			if (A_u8Pin < 8)
			{
				GPIOC->AFRL &= ~(FOUR_BIT_MASK<<(A_u8Pin*4));
				GPIOC->AFRL |= (A_u8AltFunc<<(A_u8Pin*4));
			}
			else
			{
				GPIOB->AFRH &= ~(FOUR_BIT_MASK<<((A_u8Pin-8)*4));
				GPIOB->AFRH |= (A_u8AltFunc<<((A_u8Pin-8)*4));
			}
			break;
		default :
			break;
		}
	}
}
