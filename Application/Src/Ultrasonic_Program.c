/*
 * Ultrasonic_Program.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Hesham Yasser
 */


#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/MCAL/GPIO/MGPIO_Interface.h"
#include "../include/MCAL/TIMER/MTIMER_Interface.h"

#include "../include/HAL/Ultrasonic/Ultrasonic_Interface.h""
#include "../include/HAL/Ultrasonic/Ultrasonic_private.h""
#include "../include/HAL/Ultrasonic/Ultrasonic_Configurations.h"

u16 global_u16Distance = 0;

void HUltrasonic_voidInit (void)
{
	MTIMER_voidSetPrescaler(ULTRA_SONIC_TIMER, 15);
	MTIMER_voidSetTimerCountDirection(ULTRA_SONIC_TIMER, UPCOUNT);
	MTIMER_voidSetChannelDirection(ULTRA_SONIC_TIMER, CHANNEL1, CHANNELx_INPUT_TIx);
	MTIMER_voidSetChannelInputPolarity(ULTRA_SONIC_TIMER, CHANNEL1, RISING_EDGE);
	MTIMER_EnableChannelInterrupt(ULTRA_SONIC_TIMER, CHANNEL1);
	MTIMER_voidSetChannelDirection(ULTRA_SONIC_TIMER, CHANNEL2, CHANNELx_INPUT_TIy);
	MTIMER_voidSetChannelInputPolarity(ULTRA_SONIC_TIMER, CHANNEL2, FALLING_EDGE);
	MTIMER_EnableChannelInterrupt(ULTRA_SONIC_TIMER, CHANNEL2);
	MTIMER_voidSetCallBack(ULTRA_SONIC_TIMER, HUltrasonic_voidCallBack);
	MTIMER_voidSetARRValue(ULTRA_SONIC_TIMER, 0xffff);
	MTIMER_voidEnableTimer(ULTRA_SONIC_TIMER);
}


void HUltrasonic_voidTrigger (void)
{
	MGPIO_voidSetResetPin(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, GPIO_SET);
	for (u32 Delay = 0 ; Delay < 100 ; Delay++)
	{
		asm("NOP");
	}
	MGPIO_voidSetResetPin(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, GPIO_RESET);
}


u16 HUltrasonic_u16ReadDistanceNonBlocking (void)
{
	return global_u16Distance;
}


static void HUltrasonic_voidCallBack (void)
{
	u32 local_u32Value = 0;
	if (MTIMER_u8ReadInterruptState(ULTRA_SONIC_TIMER, CHANNEL1) == 1)
	{
		MTIMER_u32ReadChannelValue(ULTRA_SONIC_TIMER, CHANNEL1);
		MTIMER_voidSetCounterValue(ULTRA_SONIC_TIMER, 0);
	}
	else if (MTIMER_u8ReadInterruptState(ULTRA_SONIC_TIMER, CHANNEL2) == 1)
	{
		local_u32Value = MTIMER_u32ReadChannelValue(ULTRA_SONIC_TIMER, CHANNEL2);
		global_u16Distance = local_u32Value/58;
	}
}


u16 HUltrasonic_voidReadDistanceBlocking (void)
{
	/*Send Trigger signal*/
	u32 local_u32Value = 0;
	MGPIO_voidSetResetPin(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, GPIO_SET);
	for (u32 Delay = 0 ; Delay < 100 ; Delay++)
	{
		asm("NOP");
	}
	MGPIO_voidSetResetPin(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, GPIO_RESET);
	/*Wait for rising edge*/
	while(MTIMER_u8ReadInterruptState(ULTRA_SONIC_TIMER, CHANNEL1) == 0);
	MTIMER_u32ReadChannelValue(ULTRA_SONIC_TIMER, CHANNEL1);
	MTIMER_voidSetCounterValue(ULTRA_SONIC_TIMER, 0);
	/*Wait for falling edge*/
	while(MTIMER_u8ReadInterruptState(ULTRA_SONIC_TIMER, CHANNEL2) == 0);
	local_u32Value = MTIMER_u32ReadChannelValue(ULTRA_SONIC_TIMER, CHANNEL2);
	global_u16Distance = local_u32Value/58;
	return global_u16Distance;
}

