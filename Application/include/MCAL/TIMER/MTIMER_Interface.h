/*
 * MTIMER_Interface.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Hesham Yasser
 */

#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_


/****************Timers****************/
typedef enum
{
	TIMER2,
	TIMER3,
	TIMER4,
	TIMER5
}TIMERS_t;

/**************Channels****************/
typedef enum
{
	CHANNEL1 = 1,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4
}CHANNELS_t;

/************Channel Directions*********/

typedef enum
{
	CHANNEL_OUTPUT,
	CHANNELx_INPUT_TIx,
	CHANNELx_INPUT_TIy,
	CHANNEL_INPUT_TRC,

}CHANNEL_DIR_t;

/**************Count Directions*********/

typedef enum
{
	UPCOUNT,
	DOWNCOUNT
}CNT_DIR_t;

/************Channel input polarity********/

typedef enum
{
	RISING_EDGE,
	FALLING_EDGE,
	BOTH_EDGES = 3
}CHANNEL_POL_t;

/*************Output Modes***************/

typedef enum
{
	FROZEN,
	ACTIVE_ON_MATCH,
	INACTIVE_ON_MATCH,
	TOGGLE,
	FORCE_INACTIVE,
	FORCE_ACTIVE,
	PWM_MODE_1,
	PWM_MODE_2
}OUT_MODES_t;



/******************APIs****************/
void MTIMER_voidEnableTimer (TIMERS_t A_Timer);

void MTIMER_EnableChannelInterrupt (TIMERS_t A_Timer, CHANNELS_t A_Channel);

void MTIMER_voidSetPrescaler (TIMERS_t A_Timer, u16 A_u16Prescaler);

void MTIMER_voidSetTimerCountDirection (TIMERS_t A_Timer, CNT_DIR_t A_CNT_Direction);

void MTIMER_voidSetChannelInputPolarity (TIMERS_t A_Timer, CHANNELS_t A_Channel, CHANNEL_POL_t A_Polarity);

void MTIMER_voidSetChannelDirection (TIMERS_t A_Timer, CHANNELS_t A_Channel, CHANNEL_DIR_t A_Direction);

u32 MTIMER_u32ReadChannelValue (TIMERS_t A_Timer, CHANNELS_t A_Channel);

void MTIMER_voidSetCallBack (TIMERS_t A_Timer, PtrToFunc_void A_CallBack);

void MTIMER_voidSetCounterValue (TIMERS_t A_Timer, u32 A_u32CNTValue);

void MTIMER_voidSetARRValue (TIMERS_t A_Timer, u32 A_u32ARRValue);

u8 MTIMER_u8ReadInterruptState (TIMERS_t A_Timer, CHANNELS_t A_Channel);

void MTIMER_voidSetOutputMode (TIMERS_t A_Timer, CHANNELS_t A_Channel, OUT_MODES_t A_Mode);

void MTIMER_voidSetCCRValue (TIMERS_t A_Timer, CHANNELS_t A_Channel, u32 A_u32CCRValue);

void MTIMER_voidEnableOutputPin (TIMERS_t A_Timer, CHANNELS_t A_Channel);

void MTIMER_voidSetPWMOption (TIMERS_t A_Timer, CHANNELS_t A_Channel, u32 A_ARRValue, u32 A_CRRValue, u16 A_u16Prescaler);


#endif /* MTIMER_INTERFACE_H_ */
