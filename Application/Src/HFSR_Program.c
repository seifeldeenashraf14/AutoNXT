/*
 * HFSR_Program.c
 *
 *  Created on: ??�/??�/????
 *      Author: Diaa
 */



#include "../include/LIB/STD_Types.h"

#include "../include/HAL/FSR/HFSR_Interface.h"
#include "../include/HAL/FSR/HFSR_Config.h"
#include "../include/HAL/FSR/HFSR_Private.h"
#include "../include/MCAL/ADC/MADC_Interface.h"

void HFSR_voidInit(void)
{
	MADC_VoidInit();
	MADC_VoidEnable();
}

u32 HFSR_u32MeasureForce(void)
{
	f32 ADC_u32Read=0;
	MADC_VoidStartChannelConversion(ADC_CHANNEL1);
	ADC_u32Read=MADC_u16ReadSynch();
	f32 AnalogValue=(f32)((ADC_u32Read*3.3)/256UL);

//	return	(	(AnalogValue * FIXED_RESISTANCE)	/	(INPUT_VOLTAGE - AnalogValue)	);
	return((FIXED_RESISTANCE*(INPUT_VOLTAGE-AnalogValue))/AnalogValue);
}













