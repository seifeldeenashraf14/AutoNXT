/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : GPIO                   ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 10 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/GPIO/GPIO_private.h"
#include "MCAL/GPIO/GPIO_config.h"

void GPIO_voidSetMode (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	/* Checking if the Entered PINs are available to use or not */
	if ((Copy_u8Port == GPIO_PORTA) && (Copy_u8Pin == GPIO_PIN13 || Copy_u8Pin == GPIO_PIN14 || Copy_u8Pin == GPIO_PIN15))
	{
		/* Do Nothing */
	}
	else if ((Copy_u8Port == GPIO_PORTB) && (Copy_u8Pin == GPIO_PIN3 || Copy_u8Pin == GPIO_PIN4))
	{
		/* Do Nothing */
	}
	else
	{
		/* Checking which PORT is entered */
		switch (Copy_u8Port)
		{
		/* Set Mode (Output - Input - Alternative - Analog) of PORTA PINx */
		case GPIO_PORTA:
			GPIOA->MODDER &= ~(MASK << (Copy_u8Pin * 2));
			GPIOA->MODDER |= (Copy_u8Mode << (Copy_u8Pin * 2));
			break;
			/* Set Mode (Output - Input - Alternative - Analog) of PORTB PINx */
		case GPIO_PORTB:
			GPIOB->MODDER &= ~(MASK << (Copy_u8Pin * 2));
			GPIOB->MODDER |= (Copy_u8Mode << (Copy_u8Pin * 2));
			break;
			/* Set Mode (Output - Input - Alternative - Analog) of PORTC PINx */
		case GPIO_PORTC:
			GPIOC->MODDER &= ~(MASK << (Copy_u8Pin * 2));
			GPIOC->MODDER |= (Copy_u8Mode << (Copy_u8Pin * 2));
			break;
		default: break;
		}
	}
}

void GPIO_voidOutputPinMode (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OutputMode, u8 Copy_u8Speed)
{
	/* Checking if the Entered PINs are available to use or not */
	if ((Copy_u8Port == GPIO_PORTA) && (Copy_u8Pin == GPIO_PIN13 || Copy_u8Pin == GPIO_PIN14 || Copy_u8Pin == GPIO_PIN15))
	{
		/* Do Nothing */
	}
	else if ((Copy_u8Port == GPIO_PORTB) && (Copy_u8Pin == GPIO_PIN3 || Copy_u8Pin == GPIO_PIN4))
	{
		/* Do Nothing */
	}
	else
	{
		/* Checking which PORT is entered */
		switch (Copy_u8Port)
		{
		/* Set OutputMode (PushPull - OpenDrain) and Speed for PORTA PINx */
		case GPIO_PORTA:
			GPIOA->OTYPER &= ~(BIT << (Copy_u8Pin));
			GPIOA->OTYPER |= (Copy_u8OutputMode << (Copy_u8Pin));
			GPIOA->OSPEEDR &= ~(MASK << (Copy_u8Pin * 2));
			GPIOA->OSPEEDR |= (Copy_u8Speed << (Copy_u8Pin * 2));
			break;
			/* Set OutputMode (PushPull - OpenDrain) and Speed for PORTB PINx */
		case GPIO_PORTB:
			GPIOB->OTYPER &= ~(BIT << (Copy_u8Pin));
			GPIOB->OTYPER |= (Copy_u8OutputMode << (Copy_u8Pin));
			GPIOB->OSPEEDR &= ~(MASK << (Copy_u8Pin * 2));
			GPIOB->OSPEEDR |= (Copy_u8Speed << (Copy_u8Pin * 2));
			break;
			/* Set OutputMode (PushPull - OpenDrain) and Speed for PORTC PINx */
		case GPIO_PORTC:
			GPIOC->OTYPER &= ~(BIT << (Copy_u8Pin));
			GPIOC->OTYPER |= (Copy_u8OutputMode << (Copy_u8Pin));
			GPIOC->OSPEEDR &= ~(MASK << (Copy_u8Pin * 2));
			GPIOC->OSPEEDR |= (Copy_u8Speed << (Copy_u8Pin * 2));
			break;
		default: break;
		}
	}
}

void GPIO_voidInputPinMode (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8InputMode)
{
	/* Checking if the Entered PINs are available to use or not */
	if ((Copy_u8Port == GPIO_PORTA) && (Copy_u8Pin == GPIO_PIN13 || Copy_u8Pin == GPIO_PIN14 || Copy_u8Pin == GPIO_PIN15))
	{
		/* Do Nothing */
	}
	else if ((Copy_u8Port == GPIO_PORTB) && (Copy_u8Pin == GPIO_PIN3 || Copy_u8Pin == GPIO_PIN4))
	{
		/* Do Nothing */
	}
	else
	{
		/* Checking which PORT is entered */
		switch (Copy_u8Port)
		{
		/* Set InputMode (Normal - PullUp - PullDown) of PORTA PINx */
		case GPIO_PORTA:
			GPIOA->PUPDR &= ~(MASK << (Copy_u8Pin * 2));
			GPIOA->PUPDR |= (Copy_u8InputMode << (Copy_u8Pin * 2));
			break;
			/* Set InputMode (Normal - PullUp - PullDown) of PORTB PINx */
		case GPIO_PORTB:
			GPIOB->PUPDR &= ~(MASK << (Copy_u8Pin * 2));
			GPIOB->PUPDR |= (Copy_u8InputMode << (Copy_u8Pin * 2));
			break;
			/* Set InputMode (Normal - PullUp - PullDown) of PORTC PINx */
		case GPIO_PORTC:
			GPIOC->PUPDR &= ~(MASK << (Copy_u8Pin * 2));
			GPIOC->PUPDR |= (Copy_u8InputMode << (Copy_u8Pin * 2));
			break;
		default: break;
		}
	}
}

void GPIO_voidGetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Pointer_u8Data)
{
	/* Checking if the Entered PINs are available to use or not */
	if ((Copy_u8Port == GPIO_PORTA) && (Copy_u8Pin == GPIO_PIN13 || Copy_u8Pin == GPIO_PIN14 || Copy_u8Pin == GPIO_PIN15))
	{
		/* Do Nothing */
	}
	else if ((Copy_u8Port == GPIO_PORTB) && (Copy_u8Pin == GPIO_PIN3 || Copy_u8Pin == GPIO_PIN4))
	{
		/* Do Nothing */
	}
	else
	{
		/* Checking which PORT is entered */
		switch (Copy_u8Port)
		{
		/* Get reading of PORTA PINx */
		case GPIO_PORTA:
			*Pointer_u8Data = GET_BIT(GPIOA->IDR, Copy_u8Pin);
			break;
			/* Get reading of PORTB PINx */
		case GPIO_PORTB:
			*Pointer_u8Data = GET_BIT(GPIOB->IDR, Copy_u8Pin);
			break;
			/* Get reading of PORTC PINx */
		case GPIO_PORTC:
			*Pointer_u8Data = GET_BIT(GPIOC->IDR, Copy_u8Pin);
			break;
		default: break;
		}
	}
}

void GPIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Data)
{
	/* Checking if the Entered PINs are available to use or not */
	if ((Copy_u8Port == GPIO_PORTA) && (Copy_u8Pin == GPIO_PIN13 || Copy_u8Pin == GPIO_PIN14 || Copy_u8Pin == GPIO_PIN15))
	{
		/* Do Nothing */
	}
	else if ((Copy_u8Port == GPIO_PORTB) && (Copy_u8Pin == GPIO_PIN3 || Copy_u8Pin == GPIO_PIN4))
	{
		/* Do Nothing */
	}
	else
	{
		/* Checking which PORT is entered */
		switch (Copy_u8Port)
		{
		/* Set PinValue (High - Low) of PORTA PINx */
		case GPIO_PORTA:
			GPIOA->ODR &= ~(BIT << (Copy_u8Pin));
			GPIOA->ODR |= (Copy_u8Data << (Copy_u8Pin));
			break;
			/* Set PinValue (High - Low) of PORTB PINx */
		case GPIO_PORTB:
			GPIOB->ODR &= ~(BIT << (Copy_u8Pin));
			GPIOB->ODR |= (Copy_u8Data << (Copy_u8Pin));
			break;
			/* Set PinValue (High - Low) of PORTC PINx */
		case GPIO_PORTC:
			GPIOC->ODR &= ~(BIT << (Copy_u8Pin));
			GPIOC->ODR |= (Copy_u8Data << (Copy_u8Pin));
			break;
		default: break;
		}
	}
}

void GPIO_voidSetResetValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	/* Checking if the Entered PINs are available to use or not */
	if ((Copy_u8Port == GPIO_PORTA) && (Copy_u8Pin == GPIO_PIN13 || Copy_u8Pin == GPIO_PIN14 || Copy_u8Pin == GPIO_PIN15))
	{
		/* Do Nothing */
	}
	else if ((Copy_u8Port == GPIO_PORTB) && (Copy_u8Pin == GPIO_PIN3 || Copy_u8Pin == GPIO_PIN4))
	{
		/* Do Nothing */
	}
	else
	{
		/* Checking which value is entered */
		if (Copy_u8Value)
		{
			/* Checking which PORT is entered */
			switch (Copy_u8Port)
			{
			/* Set PinValue of PORTA PINx using BSRR register */
			case GPIO_PORTA:
				SET_BIT(GPIOA->BSRR, Copy_u8Pin);
				break;
				/* Set PinValue of PORTB PINx using BSRR register */
			case GPIO_PORTB:
				SET_BIT(GPIOB->BSRR, Copy_u8Pin);
				break;
				/* Set PinValue of PORTC PINx using BSRR register */
			case GPIO_PORTC:
				SET_BIT(GPIOC->BSRR, Copy_u8Pin);
				break;
			default: break;
			}
		}
		/* Checking which value is entered */
		else if (!Copy_u8Value)
		{
			/* Checking which PORT is entered */
			switch (Copy_u8Port)
			{
			/* Reset PinValue of PORTA PINx using BSRR register */
			case GPIO_PORTA:
				SET_BIT(GPIOA->BSRR, (Copy_u8Pin + 16));
				break;
				/* Reset PinValue of PORTB PINx using BSRR register */
			case GPIO_PORTB:
				SET_BIT(GPIOB->BSRR, (Copy_u8Pin + 16));
				break;
				/* Reset PinValue of PORTC PINx using BSRR register */
			case GPIO_PORTC:
				SET_BIT(GPIOC->BSRR, (Copy_u8Pin + 16));
				break;
			default: break;
			}
		}
	}
}

void GPIO_voidSetAlternativeLine (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Alternative)
{
	switch (Copy_u8Port)
	{
	case GPIO_PORTA:
		if (Copy_u8Pin < 8)
		{
			GPIOA->AFRL &=  ~(MASK_FOUR_BITS << (4 * (Copy_u8Pin % 8)));
			GPIOA->AFRL |=  (Copy_u8Alternative << (4 * (Copy_u8Pin % 8)));
		}
		else
		{
			GPIOA->AFRH &=  ~(MASK_FOUR_BITS << (4 * (Copy_u8Pin % 8)));
			GPIOA->AFRH |=  (Copy_u8Alternative << (4 * (Copy_u8Pin % 8)));
		}
		break;
	case GPIO_PORTB:
		if (Copy_u8Pin < 8)
		{
			GPIOB->AFRL &=  ~(MASK_FOUR_BITS << (4 * (Copy_u8Pin % 8)));
			GPIOB->AFRL |=  (Copy_u8Alternative << (4 * (Copy_u8Pin % 8)));
		}
		else
		{
			GPIOB->AFRH &=  ~(MASK_FOUR_BITS << (4 * (Copy_u8Pin % 8)));
			GPIOB->AFRH |=  (Copy_u8Alternative << (4 * (Copy_u8Pin % 8)));
		}
		break;
	case GPIO_PORTC:
		if (Copy_u8Pin < 8)
		{
			GPIOC->AFRL &=  ~(MASK_FOUR_BITS << (4 * (Copy_u8Pin % 8)));
			GPIOC->AFRL |=  (Copy_u8Alternative << (4 * (Copy_u8Pin % 8)));
		}
		else
		{
			GPIOC->AFRH &=  ~(MASK_FOUR_BITS << (4 * (Copy_u8Pin % 8)));
			GPIOC->AFRH |=  (Copy_u8Alternative << (4 * (Copy_u8Pin % 8)));
		}
		break;
	}
}

void GPIO_voidSetPortValue (u8 Copy_u8Port, u32 Copy_u32Value)
{
	/* Checking which PORT is entered */
	switch (Copy_u8Port)
	{
	/* Set PinValue (High - Low) of PORTA PINx */
	case GPIO_PORTA:
		GPIOA->ODR = Copy_u32Value;
		break;
	/* Set PinValue (High - Low) of PORTB PINx */
	case GPIO_PORTB:
		GPIOB->ODR = Copy_u32Value;
		break;
	/* Set PinValue (High - Low) of PORTC PINx */
	case GPIO_PORTC:
		GPIOC->ODR = Copy_u32Value;
		break;
	default: break;
	}
}
