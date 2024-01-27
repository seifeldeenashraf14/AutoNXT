/*
 * MTIMER_Program.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Hesham Yasser
 */


#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/MCAL/TIMER/MTIMER_Interface.h"
#include "../include/MCAL/TIMER/MTIMER_private.h"
#include "../include/MCAL/TIMER/MTIMER_Configurations.h"


PtrToFunc_void TIMER_CallBack [4];

void MTIMER_voidEnableTimer (TIMERS_t A_Timer)
{
	switch (A_Timer)
	{
	case TIMER2:
		SET_BIT(TIM2->CR1 , CR1_CEN);
		break;
	case TIMER3:
		SET_BIT(TIM3->CR1 , CR1_CEN);
		break;
	case TIMER4:
		SET_BIT(TIM4->CR1 , CR1_CEN);
		break;
	case TIMER5:
		SET_BIT(TIM5->CR1 , CR1_CEN);
		break;
	}
}

/*
 * UP/Down Count		->	CR1
 * Channels Connection	->	CR2
 * Slave mode 			->	SMCR
 * Interrupt mode		->	DIER
 * CC2 Direction 		->	CCMR1
 * CC1 Direction 		->	CCMR1
 * CC4 Direction 		->	CCMR2
 * CC3 Direction 		->	CCMR2
 * PreScaler			->	PSC
 * Caputre Enable & Polarity	-> CCMR
 */

/*
 * Read Values
 */

/*
 * Outcompare mode1,2		-> CCMR1
 * Outcompare mode3,4		-> CCMR2
 * set ccr registers		-> CCR
 *
 */
void MTIMER_EnableChannelInterrupt (TIMERS_t A_Timer, CHANNELS_t A_Channel)
{
	switch (A_Timer)
	{
	case TIMER2:
		SET_BIT(TIM2->DIER, A_Channel);
		break;
	case TIMER3:
		SET_BIT(TIM3->DIER, A_Channel);
		break;
	case TIMER4:
		SET_BIT(TIM4->DIER, A_Channel);
		break;
	case TIMER5:
		SET_BIT(TIM5->DIER, A_Channel);
		break;
	}
}

void MTIMER_voidSetPrescaler (TIMERS_t A_Timer, u16 A_u16Prescaler)
{
	switch (A_Timer)
	{
	case TIMER2:
		TIM2->PSC = A_u16Prescaler;
		break;
	case TIMER3:
		TIM3->PSC = A_u16Prescaler;
		break;
	case TIMER4:
		TIM4->PSC = A_u16Prescaler;
		break;
	case TIMER5:
		TIM5->PSC = A_u16Prescaler;
		break;
	}
}

void MTIMER_voidSetTimerCountDirection (TIMERS_t A_Timer, CNT_DIR_t A_CNT_Direction)
{
	switch (A_Timer)
	{
	case TIMER2:
		switch (A_CNT_Direction)
		{
		case UPCOUNT:
			CLR_BIT (TIM2->CR1, CR1_DIR);
			break;
		case DOWNCOUNT:
			SET_BIT(TIM2->CR1, CR1_DIR);
			break;
		}
		break;
	case TIMER3:
		switch (A_CNT_Direction)
		{
		case UPCOUNT:
			CLR_BIT (TIM3->CR1, CR1_DIR);
			break;
		case DOWNCOUNT:
			SET_BIT(TIM3->CR1, CR1_DIR);
			break;
		}
		break;
	case TIMER4:
		switch (A_CNT_Direction)
		{
		case UPCOUNT:
			CLR_BIT (TIM4->CR1, CR1_DIR);
			break;
		case DOWNCOUNT:
			SET_BIT(TIM4->CR1, CR1_DIR);
			break;
		}
		break;
	case TIMER5:
		switch (A_CNT_Direction)
		{
		case UPCOUNT:
			CLR_BIT (TIM5->CR1, CR1_DIR);
			break;
		case DOWNCOUNT:
			SET_BIT(TIM5->CR1, CR1_DIR);
			break;
		}
		break;
	}
}

void MTIMER_voidSetChannelDirection (TIMERS_t A_Timer, CHANNELS_t A_Channel, CHANNEL_DIR_t A_Direction)
{
	switch (A_Timer)
	{
	case TIMER2:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM2->CCMR1 &= ~(TWO_BIT_MASK << CCMR1_CC1S);
			TIM2->CCMR1 |=  (A_Direction << CCMR1_CC1S);
			break;
		case CHANNEL2:
			TIM2->CCMR1 &= ~(TWO_BIT_MASK << CCMR1_CC2S);
			TIM2->CCMR1 |=  (A_Direction << CCMR1_CC2S);
			break;
		case CHANNEL3:
			TIM2->CCMR2 &= ~(TWO_BIT_MASK << CCMR2_CC3S);
			TIM2->CCMR2 |=  (A_Direction << CCMR2_CC3S);
			break;
		case CHANNEL4:
			TIM2->CCMR2 &= ~(TWO_BIT_MASK << CCMR2_CC4S);
			TIM2->CCMR2 |=  (A_Direction << CCMR2_CC4S);
			break;
		}
		break;
	case TIMER3:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM3->CCMR1 &= ~(TWO_BIT_MASK << CCMR1_CC1S);
			TIM3->CCMR1 |=  (A_Direction << CCMR1_CC1S);
			break;
		case CHANNEL2:
			TIM3->CCMR1 &= ~(TWO_BIT_MASK << CCMR1_CC2S);
			TIM3->CCMR1 |=  (A_Direction << CCMR1_CC2S);
			break;
		case CHANNEL3:
			TIM3->CCMR2 &= ~(TWO_BIT_MASK << CCMR2_CC3S);
			TIM3->CCMR2 |=  (A_Direction << CCMR2_CC3S);
			break;
		case CHANNEL4:
			TIM3->CCMR2 &= ~(TWO_BIT_MASK << CCMR2_CC4S);
			TIM3->CCMR2 |=  (A_Direction << CCMR2_CC4S);
			break;
		}
		break;
	case TIMER4:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM4->CCMR1 &= ~(TWO_BIT_MASK << CCMR1_CC1S);
			TIM4->CCMR1 |=  (A_Direction << CCMR1_CC1S);
			break;
		case CHANNEL2:
			TIM4->CCMR1 &= ~(TWO_BIT_MASK << CCMR1_CC2S);
			TIM4->CCMR1 |=  (A_Direction << CCMR1_CC2S);
			break;
		case CHANNEL3:
			TIM4->CCMR2 &= ~(TWO_BIT_MASK << CCMR2_CC3S);
			TIM4->CCMR2 |=  (A_Direction << CCMR2_CC3S);
			break;
		case CHANNEL4:
			TIM4->CCMR2 &= ~(TWO_BIT_MASK << CCMR2_CC4S);
			TIM4->CCMR2 |=  (A_Direction << CCMR2_CC4S);
			break;
		}
		break;
	case TIMER5:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM5->CCMR1 &= ~(TWO_BIT_MASK << CCMR1_CC1S);
			TIM5->CCMR1 |=  (A_Direction << CCMR1_CC1S);
			break;
		case CHANNEL2:
			TIM5->CCMR1 &= ~(TWO_BIT_MASK << CCMR1_CC2S);
			TIM5->CCMR1 |=  (A_Direction << CCMR1_CC2S);
			break;
		case CHANNEL3:
			TIM5->CCMR2 &= ~(TWO_BIT_MASK << CCMR2_CC3S);
			TIM5->CCMR2 |=  (A_Direction << CCMR2_CC3S);
			break;
		case CHANNEL4:
			TIM5->CCMR2 &= ~(TWO_BIT_MASK << CCMR2_CC4S);
			TIM5->CCMR2 |=  (A_Direction << CCMR2_CC4S);
			break;
		}
		break;
	}
}

void MTIMER_voidSetChannelInputPolarity (TIMERS_t A_Timer, CHANNELS_t A_Channel, CHANNEL_POL_t A_Polarity)
{
	switch (A_Timer)
	{
	case TIMER2:
		switch (A_Channel)
		{
		case CHANNEL1:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM2->CCER, CCER_CC1P);
				CLR_BIT(TIM2->CCER, CCER_CC1NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM2->CCER, CCER_CC1P);
				CLR_BIT(TIM2->CCER, CCER_CC1NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM2->CCER, CCER_CC1P);
				SET_BIT(TIM2->CCER, CCER_CC1NP);
				break;
			}
			SET_BIT(TIM2->CCER, CCER_CC1E);
			break;
		case CHANNEL2:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM2->CCER, CCER_CC2P);
				CLR_BIT(TIM2->CCER, CCER_CC2NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM2->CCER, CCER_CC2P);
				CLR_BIT(TIM2->CCER, CCER_CC2NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM2->CCER, CCER_CC2P);
				SET_BIT(TIM2->CCER, CCER_CC2NP);
				break;
			}
			SET_BIT(TIM2->CCER, CCER_CC2E);
			break;
		case CHANNEL3:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM2->CCER, CCER_CC3P);
				CLR_BIT(TIM2->CCER, CCER_CC3NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM2->CCER, CCER_CC3P);
				CLR_BIT(TIM2->CCER, CCER_CC3NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM2->CCER, CCER_CC3P);
				SET_BIT(TIM2->CCER, CCER_CC3NP);
				break;
			}
			SET_BIT(TIM2->CCER, CCER_CC3E);
			break;
		case CHANNEL4:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM2->CCER, CCER_CC4P);
				CLR_BIT(TIM2->CCER, CCER_CC4NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM2->CCER, CCER_CC4P);
				CLR_BIT(TIM2->CCER, CCER_CC4NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM2->CCER, CCER_CC4P);
				SET_BIT(TIM2->CCER, CCER_CC4NP);
				break;
			}
			SET_BIT(TIM2->CCER, CCER_CC4E);
			break;
		}
		break;
	case TIMER3:
		switch (A_Channel)
		{
		case CHANNEL1:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM3->CCER, CCER_CC1P);
				CLR_BIT(TIM3->CCER, CCER_CC1NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM3->CCER, CCER_CC1P);
				CLR_BIT(TIM3->CCER, CCER_CC1NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM3->CCER, CCER_CC1P);
				SET_BIT(TIM3->CCER, CCER_CC1NP);
				break;
			}
			SET_BIT(TIM3->CCER, CCER_CC1E);
			break;
		case CHANNEL2:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM3->CCER, CCER_CC2P);
				CLR_BIT(TIM3->CCER, CCER_CC2NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM3->CCER, CCER_CC2P);
				CLR_BIT(TIM3->CCER, CCER_CC2NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM3->CCER, CCER_CC2P);
				SET_BIT(TIM3->CCER, CCER_CC2NP);
				break;
			}
			SET_BIT(TIM3->CCER, CCER_CC2E);
			break;
		case CHANNEL3:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM3->CCER, CCER_CC3P);
				CLR_BIT(TIM3->CCER, CCER_CC3NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM3->CCER, CCER_CC3P);
				CLR_BIT(TIM3->CCER, CCER_CC3NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM3->CCER, CCER_CC3P);
				SET_BIT(TIM3->CCER, CCER_CC3NP);
				break;
			}
			SET_BIT(TIM3->CCER, CCER_CC3E);
			break;
		case CHANNEL4:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM3->CCER, CCER_CC4P);
				CLR_BIT(TIM3->CCER, CCER_CC4NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM3->CCER, CCER_CC4P);
				CLR_BIT(TIM3->CCER, CCER_CC4NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM3->CCER, CCER_CC4P);
				SET_BIT(TIM3->CCER, CCER_CC4NP);
				break;
			}
			SET_BIT(TIM3->CCER, CCER_CC4E);
			break;
		}
		break;
	case TIMER4:
		switch (A_Channel)
		{
		case CHANNEL1:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM4->CCER, CCER_CC1P);
				CLR_BIT(TIM4->CCER, CCER_CC1NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM4->CCER, CCER_CC1P);
				CLR_BIT(TIM4->CCER, CCER_CC1NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM4->CCER, CCER_CC1P);
				SET_BIT(TIM4->CCER, CCER_CC1NP);
				break;
			}
			SET_BIT(TIM4->CCER, CCER_CC1E);
			break;
		case CHANNEL2:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM4->CCER, CCER_CC2P);
				CLR_BIT(TIM4->CCER, CCER_CC2NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM4->CCER, CCER_CC2P);
				CLR_BIT(TIM4->CCER, CCER_CC2NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM4->CCER, CCER_CC2P);
				SET_BIT(TIM4->CCER, CCER_CC2NP);
				break;
			}
			SET_BIT(TIM4->CCER, CCER_CC2E);
			break;
		case CHANNEL3:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM4->CCER, CCER_CC3P);
				CLR_BIT(TIM4->CCER, CCER_CC3NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM4->CCER, CCER_CC3P);
				CLR_BIT(TIM4->CCER, CCER_CC3NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM4->CCER, CCER_CC3P);
				SET_BIT(TIM4->CCER, CCER_CC3NP);
				break;
			}
			SET_BIT(TIM4->CCER, CCER_CC3E);
			break;
		case CHANNEL4:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM4->CCER, CCER_CC4P);
				CLR_BIT(TIM4->CCER, CCER_CC4NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM4->CCER, CCER_CC4P);
				CLR_BIT(TIM4->CCER, CCER_CC4NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM4->CCER, CCER_CC4P);
				SET_BIT(TIM4->CCER, CCER_CC4NP);
				break;
			}
			SET_BIT(TIM4->CCER, CCER_CC4E);
			break;
		}
		break;
	case TIMER5:
		switch (A_Channel)
		{
		case CHANNEL1:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM5->CCER, CCER_CC1P);
				CLR_BIT(TIM5->CCER, CCER_CC1NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM5->CCER, CCER_CC1P);
				CLR_BIT(TIM5->CCER, CCER_CC1NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM5->CCER, CCER_CC1P);
				SET_BIT(TIM5->CCER, CCER_CC1NP);
				break;
			}
			SET_BIT(TIM5->CCER, CCER_CC1E);
			break;
		case CHANNEL2:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM5->CCER, CCER_CC2P);
				CLR_BIT(TIM5->CCER, CCER_CC2NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM5->CCER, CCER_CC2P);
				CLR_BIT(TIM5->CCER, CCER_CC2NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM5->CCER, CCER_CC2P);
				SET_BIT(TIM5->CCER, CCER_CC2NP);
				break;
			}
			SET_BIT(TIM5->CCER, CCER_CC2E);
			break;
		case CHANNEL3:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM5->CCER, CCER_CC3P);
				CLR_BIT(TIM5->CCER, CCER_CC3NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM5->CCER, CCER_CC3P);
				CLR_BIT(TIM5->CCER, CCER_CC3NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM5->CCER, CCER_CC3P);
				SET_BIT(TIM5->CCER, CCER_CC3NP);
				break;
			}
			SET_BIT(TIM5->CCER, CCER_CC3E);
			break;
		case CHANNEL4:
			switch (A_Polarity)
			{
			case RISING_EDGE:
				CLR_BIT(TIM5->CCER, CCER_CC4P);
				CLR_BIT(TIM5->CCER, CCER_CC4NP);
				break;
			case FALLING_EDGE:
				SET_BIT(TIM5->CCER, CCER_CC4P);
				CLR_BIT(TIM5->CCER, CCER_CC4NP);
				break;
			case BOTH_EDGES:
				SET_BIT(TIM5->CCER, CCER_CC4P);
				SET_BIT(TIM5->CCER, CCER_CC4NP);
				break;
			}
			SET_BIT(TIM5->CCER, CCER_CC4E);
			break;
		}
		break;
	}
}

u32 MTIMER_u32ReadChannelValue (TIMERS_t A_Timer, CHANNELS_t A_Channel)
{
	u32 local_ReturnValue = 0;
	switch (A_Timer)
	{
	case TIMER2:
		switch (A_Channel)
		{
		case CHANNEL1:
			local_ReturnValue = TIM2->CCR1;
			break;
		case CHANNEL2:
			local_ReturnValue = TIM2->CCR2;
			break;
		case CHANNEL3:
			local_ReturnValue = TIM2->CCR3;
			break;
		case CHANNEL4:
			local_ReturnValue = TIM2->CCR4;
			break;
		}
		break;
	case TIMER3:
		switch (A_Channel)
		{
		case CHANNEL1:
			local_ReturnValue = TIM3->CCR1;
			break;
		case CHANNEL2:
			local_ReturnValue = TIM3->CCR2;
			break;
		case CHANNEL3:
			local_ReturnValue = TIM3->CCR3;
			break;
		case CHANNEL4:
			local_ReturnValue = TIM3->CCR4;
			break;
		}
		break;
	case TIMER4:
		switch (A_Channel)
		{
		case CHANNEL1:
			local_ReturnValue = TIM4->CCR1;
			break;
		case CHANNEL2:
			local_ReturnValue = TIM4->CCR2;
			break;
		case CHANNEL3:
			local_ReturnValue = TIM4->CCR3;
			break;
		case CHANNEL4:
			local_ReturnValue = TIM4->CCR4;
			break;
		}
		break;
	case TIMER5:
		switch (A_Channel)
		{
		case CHANNEL1:
			local_ReturnValue = TIM5->CCR1;
			break;
		case CHANNEL2:
			local_ReturnValue = TIM5->CCR2;
			break;
		case CHANNEL3:
			local_ReturnValue = TIM5->CCR3;
			break;
		case CHANNEL4:
			local_ReturnValue = TIM5->CCR4;
			break;
		}
		break;
	}
	return local_ReturnValue;
}

void MTIMER_voidSetCallBack (TIMERS_t A_Timer, PtrToFunc_void A_CallBack)
{
	TIMER_CallBack[A_Timer] = A_CallBack;
}


void MTIMER_voidSetCounterValue (TIMERS_t A_Timer, u32 A_u32CNTValue)
{
	switch (A_Timer)
	{
	case TIMER2:
		TIM2->CNT = A_u32CNTValue;
		break;
	case TIMER3:
		TIM3->CNT = A_u32CNTValue;
		break;
	case TIMER4:
		TIM4->CNT = A_u32CNTValue;
		break;
	case TIMER5:
		TIM5->CNT = A_u32CNTValue;
		break;
	}
}

void MTIMER_voidSetARRValue (TIMERS_t A_Timer, u32 A_u32ARRValue)
{
	switch (A_Timer)
	{
	case TIMER2:
		TIM2->ARR = A_u32ARRValue;
		break;
	case TIMER3:
		TIM3->ARR = A_u32ARRValue;
		break;
	case TIMER4:
		TIM4->ARR = A_u32ARRValue;
		break;
	case TIMER5:
		TIM5->ARR = A_u32ARRValue;
		break;
	}
}
void MTIMER_voidSetCCRValue (TIMERS_t A_Timer, CHANNELS_t A_Channel, u32 A_u32CCRValue)
{
	switch (A_Timer)
	{
	case TIMER2:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM2->CCR1 = A_u32CCRValue;
			break;
		case CHANNEL2:
			TIM2->CCR2 = A_u32CCRValue;
			break;
		case CHANNEL3:
			TIM2->CCR3 = A_u32CCRValue;
			break;
		case CHANNEL4:
			TIM2->CCR4 = A_u32CCRValue;
			break;
		}
		break;
	case TIMER3:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM3->CCR1 = A_u32CCRValue;
			break;
		case CHANNEL2:
			TIM3->CCR2 = A_u32CCRValue;
			break;
		case CHANNEL3:
			TIM3->CCR3 = A_u32CCRValue;
			break;
		case CHANNEL4:
			TIM3->CCR4 = A_u32CCRValue;
			break;
		}
		break;
	case TIMER4:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM4->CCR1 = A_u32CCRValue;
			break;
		case CHANNEL2:
			TIM4->CCR2 = A_u32CCRValue;
			break;
		case CHANNEL3:
			TIM4->CCR3 = A_u32CCRValue;
			break;
		case CHANNEL4:
			TIM4->CCR4 = A_u32CCRValue;
			break;
		}
		break;
	case TIMER5:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM5->CCR1 = A_u32CCRValue;
			break;
		case CHANNEL2:
			TIM5->CCR2 = A_u32CCRValue;
			break;
		case CHANNEL3:
			TIM5->CCR3 = A_u32CCRValue;
			break;
		case CHANNEL4:
			TIM5->CCR4 = A_u32CCRValue;
			break;
		}
		break;
	}
}


u8 MTIMER_u8ReadInterruptState (TIMERS_t A_Timer, CHANNELS_t A_Channel)
{
	u8 local_ReturnValue = 0;
	switch (A_Timer)
	{
	case TIMER2:
		local_ReturnValue = GET_BIT(TIM2->SR, A_Channel);
		break;
	case TIMER3:
		local_ReturnValue = GET_BIT(TIM3->SR, A_Channel);
		break;
	case TIMER4:
		local_ReturnValue = GET_BIT(TIM4->SR, A_Channel);
		break;
	case TIMER5:
		local_ReturnValue = GET_BIT(TIM5->SR, A_Channel);
		break;
	}
	return local_ReturnValue;
}

void MTIMER_voidSetOutputMode (TIMERS_t A_Timer, CHANNELS_t A_Channel, OUT_MODES_t A_Mode)
{
	switch (A_Timer)
	{
	case TIMER2:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM2->CCMR1 &= ~(THREE_BIT_MASK << CCMR1_OC1M);
			TIM2->CCMR1 |=  (A_Mode << CCMR1_OC1M);
			break;
		case CHANNEL2:
			TIM2->CCMR1 &= ~(THREE_BIT_MASK << CCMR1_OC2M);
			TIM2->CCMR1 |=  (A_Mode << CCMR1_OC2M);
			break;
		case CHANNEL3:
			TIM2->CCMR2 &= ~(THREE_BIT_MASK << CCMR2_OC3M);
			TIM2->CCMR2 |=  (A_Mode << CCMR2_OC3M);
			break;
		case CHANNEL4:
			TIM2->CCMR2 &= ~(THREE_BIT_MASK << CCMR2_OC4M);
			TIM2->CCMR2 |=  (A_Mode << CCMR2_OC4M);
			break;
		}
		break;
	case TIMER3:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM3->CCMR1 &= ~(THREE_BIT_MASK << CCMR1_OC1M);
			TIM3->CCMR1 |=  (A_Mode << CCMR1_OC1M);
			break;
		case CHANNEL2:
			TIM3->CCMR1 &= ~(THREE_BIT_MASK << CCMR1_OC2M);
			TIM3->CCMR1 |=  (A_Mode << CCMR1_OC2M);
			break;
		case CHANNEL3:
			TIM3->CCMR2 &= ~(THREE_BIT_MASK << CCMR2_OC3M);
			TIM3->CCMR2 |=  (A_Mode << CCMR2_OC3M);
			break;
		case CHANNEL4:
			TIM3->CCMR2 &= ~(THREE_BIT_MASK << CCMR2_OC4M);
			TIM3->CCMR2 |=  (A_Mode << CCMR2_OC4M);
			break;
		}
		break;
	case TIMER4:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM4->CCMR1 &= ~(THREE_BIT_MASK << CCMR1_OC1M);
			TIM4->CCMR1 |=  (A_Mode << CCMR1_OC1M);
			break;
		case CHANNEL2:
			TIM4->CCMR1 &= ~(THREE_BIT_MASK << CCMR1_OC2M);
			TIM4->CCMR1 |=  (A_Mode << CCMR1_OC2M);
			break;
		case CHANNEL3:
			TIM4->CCMR2 &= ~(THREE_BIT_MASK << CCMR2_OC3M);
			TIM4->CCMR2 |=  (A_Mode << CCMR2_OC3M);
			break;
		case CHANNEL4:
			TIM4->CCMR2 &= ~(THREE_BIT_MASK << CCMR2_OC4M);
			TIM4->CCMR2 |=  (A_Mode << CCMR2_OC4M);
			break;
		}
		break;
	case TIMER5:
		switch (A_Channel)
		{
		case CHANNEL1:
			TIM5->CCMR1 &= ~(THREE_BIT_MASK << CCMR1_OC1M);
			TIM5->CCMR1 |=  (A_Mode << CCMR1_OC1M);
			break;
		case CHANNEL2:
			TIM5->CCMR1 &= ~(THREE_BIT_MASK << CCMR1_OC2M);
			TIM5->CCMR1 |=  (A_Mode << CCMR1_OC2M);
			break;
		case CHANNEL3:
			TIM5->CCMR2 &= ~(THREE_BIT_MASK << CCMR2_OC3M);
			TIM5->CCMR2 |=  (A_Mode << CCMR2_OC3M);
			break;
		case CHANNEL4:
			TIM5->CCMR2 &= ~(THREE_BIT_MASK << CCMR2_OC4M);
			TIM5->CCMR2 |=  (A_Mode << CCMR2_OC4M);
			break;
		}
		break;
	}
}

void MTIMER_voidEnableOutputPin (TIMERS_t A_Timer, CHANNELS_t A_Channel)
{
	switch (A_Timer)
	{
	case TIMER2:
		switch (A_Channel)
		{
		case CHANNEL1:
			SET_BIT (TIM2->CCER, CCER_CC1E);
			break;
		case CHANNEL2:
			SET_BIT (TIM2->CCER, CCER_CC2E);
			break;
		case CHANNEL3:
			SET_BIT (TIM2->CCER, CCER_CC3E);
			break;
		case CHANNEL4:
			SET_BIT (TIM2->CCER, CCER_CC4E);
			break;
		}
		break;
	case TIMER3:
		switch (A_Channel)
		{
		case CHANNEL1:
			SET_BIT (TIM3->CCER, CCER_CC1E);
			break;
		case CHANNEL2:
			SET_BIT (TIM3->CCER, CCER_CC2E);
			break;
		case CHANNEL3:
			SET_BIT (TIM3->CCER, CCER_CC3E);
			break;
		case CHANNEL4:
			SET_BIT (TIM3->CCER, CCER_CC4E);
			break;
		}
		break;
	case TIMER4:
		switch (A_Channel)
		{
		case CHANNEL1:
			SET_BIT (TIM4->CCER, CCER_CC1E);
			break;
		case CHANNEL2:
			SET_BIT (TIM4->CCER, CCER_CC2E);
			break;
		case CHANNEL3:
			SET_BIT (TIM4->CCER, CCER_CC3E);
			break;
		case CHANNEL4:
			SET_BIT (TIM4->CCER, CCER_CC4E);
			break;
		}
		break;
	case TIMER5:
		switch (A_Channel)
		{
		case CHANNEL1:
			SET_BIT (TIM5->CCER, CCER_CC1E);
			break;
		case CHANNEL2:
			SET_BIT (TIM5->CCER, CCER_CC2E);
			break;
		case CHANNEL3:
			SET_BIT (TIM5->CCER, CCER_CC3E);
			break;
		case CHANNEL4:
			SET_BIT (TIM5->CCER, CCER_CC4E);
			break;
		}
		break;
	}
}

void MTIMER_voidSetPWMOption (TIMERS_t A_Timer, CHANNELS_t A_Channel, u32 A_ARRValue, u32 A_CRRValue, u16 A_u16Prescaler)
{
	MTIMER_voidSetPrescaler(A_Timer, A_u16Prescaler);
	MTIMER_voidSetTimerCountDirection(A_Timer, UPCOUNT);
	MTIMER_voidSetChannelDirection(A_Timer, A_Channel, CHANNEL_OUTPUT);
	MTIMER_voidSetOutputMode(A_Timer, A_Channel,PWM_MODE_1);
	MTIMER_voidSetARRValue(A_Timer,A_ARRValue);
	MTIMER_voidSetCCRValue(A_Timer,A_Channel,A_CRRValue);
	MTIMER_voidEnableOutputPin(A_Timer,A_Channel);
	MTIMER_voidEnableTimer(A_Timer);
}


void TIM2_IRQHandler (void)
{
	if (TIMER_CallBack[TIMER2] != NULL)
	{
		TIMER_CallBack[TIMER2]();
	}
}
void TIM3_IRQHandler (void)
{
	if (TIMER_CallBack[TIMER3] != NULL)
	{
		TIMER_CallBack[TIMER3]();
	}
}
void TIM4_IRQHandler (void)
{
	if (TIMER_CallBack[TIMER4] != NULL)
	{
		TIMER_CallBack[TIMER4]();
	}
}
void TIM5_IRQHandler (void)
{
	if (TIMER_CallBack[TIMER5] != NULL)
	{
		TIMER_CallBack[TIMER5]();
	}
}
