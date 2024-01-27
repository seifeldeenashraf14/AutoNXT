/**
 * @file	MGPIO_program.c
 * @author 	Hesham Yasser
 * @version 2.5
 * @date 	10 Oct 2023
 * @brief 	the GPIO source file that conatains defenitions of all function of *GPIO* driver
 */
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/GPIO/MGPIO_interface.h"
#include "MCAL/GPIO/MGPIO_private.h"
#include "MCAL/GPIO/MGPIO_config.h"

/**
 * @fn void MGPIO_voidSetPinMode(u8, u8, u8)
 * @brief this function is responsible for setting any pin mode of STM GPIO pins
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8Mode this is the mode selected for this pin
 * @return none
 */
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
		/*Switch on the Entered port*/
		switch (A_u8Port)
		{
		case GPIO_PORTA:
			/*Set pin mode*/
			GPIOA->MODER &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOA->MODER |= (A_u8Mode<<(A_u8Pin*2));
			break;
		case GPIO_PORTB:
			/*Set pin mode*/
			GPIOB->MODER &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOB->MODER |= (A_u8Mode<<(A_u8Pin*2));
			break;
		case GPIO_PORTC:
			/*Set pin mode*/
			GPIOC->MODER &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOC->MODER |= (A_u8Mode<<(A_u8Pin*2));
			break;
		default :
			break;
		}
	}
}

/**
 * @fn void MGPIO_voidSetPinOutputMode(u8, u8, u8, u8)
 * @brief this function is responsible for setting the output configurations of any selected *GPIO* pin
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8OutputMode this is the output mode selected for this pin
 * @param A_u8Speed this is the speed configured for the selected pin
 * @return none
 */
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
		/*Switch on the Entered port*/
		switch (A_u8Port)
		{
		case GPIO_PORTA:
			GPIOA->OSPEEDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOA->OSPEEDR |= (A_u8Speed<<(A_u8Pin*2));
			/*Set pin output Speed*/
			GPIOA->OTYPER &= ~(ONE_BIT_MASK<<A_u8Pin);
			GPIOA->OTYPER |= (A_u8OutputMode<<A_u8Pin);
			break;
		case GPIO_PORTB:
			/*Set pin output Speed*/
			GPIOB->OSPEEDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOB->OSPEEDR |= (A_u8Speed<<(A_u8Pin*2));
			/*Set pin output mode*/
			GPIOB->OTYPER &= ~(ONE_BIT_MASK<<A_u8Pin);
			GPIOB->OTYPER |= (A_u8OutputMode<<A_u8Pin);
			break;
		case GPIO_PORTC:
			/*Set pin output Speed*/
			GPIOC->OSPEEDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOC->OSPEEDR |= (A_u8Speed<<(A_u8Pin*2));
			/*Set pin output mode*/
			GPIOC->OTYPER &= ~(ONE_BIT_MASK<<A_u8Pin);
			GPIOC->OTYPER |= (A_u8OutputMode<<A_u8Pin);
			break;
		default :
			break;
		}
	}
}

/**
 * @fn void MGPIO_voidSetPinAltrenativeFunction(u8, u8, u8)
 * @brief this function is responsible for setting the alternative function of any selected *GPIO* pins
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8AltFunc this is the alternative function selected for this pin
 * @return none
 */
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

/**
 * @fn void MGPIO_voidSetPinInputMode(u8, u8, u8)
 * @brief this function is responsible for setting the input mode of any selected *GPIO* pins
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8InputMode this is the input mode selected for this pin
 * @return none
 */
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
		/*Switch on the Entered port*/
		switch (A_u8Port)
		{
		case GPIO_PORTA:
			/*Set pin output mode*/
			GPIOA->PUPDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOA->PUPDR |= (A_u8InputMode<<(A_u8Pin*2));
			break;
		case GPIO_PORTB:
			/*Set pin output mode*/
			GPIOB->PUPDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOB->PUPDR |= (A_u8InputMode<<(A_u8Pin*2));
			break;
		case GPIO_PORTC:
			/*Set pin output mode*/
			GPIOC->PUPDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
			GPIOC->PUPDR |= (A_u8InputMode<<(A_u8Pin*2));
			break;
		default :
			break;
		}
	}
}

/**
 * @fn void MGPIO_voidSetPinValue(u8, u8, u8)
 * @brief this function is responsible for setting the value of any output *GPIO* pin
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8Output this is the value selected for this pin
 * @return none
 */
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
		/*Switch on the Entered port*/
		switch (A_u8Port)
		{
		case GPIO_PORTA:
			switch (A_u8Output)
			{
			/*Set pin output value*/
			case GPIO_PIN_HIGH:
				SET_BIT(GPIOA->ODR , A_u8Pin);
				break;
			case GPIO_PIN_LOW:
				CLR_BIT(GPIOA->ODR , A_u8Pin);
				break;
			}
			break;
		case GPIO_PORTB:
			/*Set pin output value*/
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
			/*Set pin output value*/
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

/**
 * @fn void MGPIO_voidGetPinValue(u8, u8, u8*)
 * @brief this function is responsible for getting the current value of any input *GPIO* pin
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to check its value
 * @param pu8Return this is the pointer to variable to save the value of pin in
 * @return none
 */
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
			/*Switch on the Entered port*/
			switch (A_u8Port)
			{
			case GPIO_PORTA:
				/*read pin value*/
				*pu8Return = GET_BIT(GPIOA->IDR , A_u8Pin);
				break;
			case GPIO_PORTB:
				/*read pin value*/
				*pu8Return = GET_BIT(GPIOB->IDR , A_u8Pin);
				break;
			case GPIO_PORTC:
				/*read pin value*/
				*pu8Return = GET_BIT(GPIOC->IDR , A_u8Pin);
				break;
			default :
				break;
			}
		}
	}

}

/**
 * @fn void MGPIO_voidSetResetPin(u8, u8, u8)
 * @brief this function is responsible for setting the value of any output *GPIO* pin (but in one clk cycle)
 * @param A_u8Port this is the port of selected pin
 * @param A_u8Pin this is the number of pin to be configured
 * @param A_u8SetResetValue this is the value to be setted for the selected pin
 * @return none
 */
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
		/*Switch on the Entered port*/
		switch (A_u8Port)
		{
		case GPIO_PORTA:
			/*Set pin output value*/
			switch (A_u8SetResetValue)
			{
			case GPIO_SET:
				GPIOA->BSRR = 1<<A_u8Pin;
				break;
			case GPIO_RESET:
				GPIOA->BSRR = 1<<(A_u8Pin+GPIO_RESET_INDEX);
				break;
			}
			break;
		case GPIO_PORTB:
			/*Set pin output value*/
			switch (A_u8SetResetValue)
			{
			case GPIO_SET:
				GPIOB->BSRR = 1<<A_u8Pin;
				break;
			case GPIO_RESET:
				GPIOB->BSRR = 1<<(A_u8Pin+GPIO_RESET_INDEX);
				break;
			}
			break;
		case GPIO_PORTC:
			/*Set pin output value*/
			switch (A_u8SetResetValue)
			{
			case GPIO_SET:
				GPIOC->BSRR = 1<<A_u8Pin;
				break;
			case GPIO_RESET:
				GPIOC->BSRR = 1<<(A_u8Pin+GPIO_RESET_INDEX);
				break;
			}
				break;
		default :
			break;
		}
	}
}

/**
 * @fn void MGPIO_voidSetPortValue(u8, u16)
 * @brief this function is responsible for setting the whole port value
 * @param A_u8Port this is the selected port
 * @param A_u16Data this is the value of the port
 * @return none
 */
void MGPIO_voidSetPortValue (u8 A_u8Port , u16 A_u16Data)
{
	/*Switch on the Entered port*/
	switch (A_u8Port)
	{
	case GPIO_PORTA :
		/*Set port value*/
		GPIOA->ODR = A_u16Data;
		break;
	case GPIO_PORTB :
		/*Set port value*/
		GPIOB->ODR = A_u16Data;
		break;
	case GPIO_PORTC :
		/*Set port value*/
		GPIOC->ODR = A_u16Data;
		break;
	default :
		break;
	}
}
