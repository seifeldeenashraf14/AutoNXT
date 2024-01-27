/*
 * HLDR_Program.c
 *
 *  Created on: ??�/??�/????
 *      Author: Diaa
 */


#include "../include/LIB/STD_Types.h"

#include "../include/HAL/LDR/HLDR_Interface.h"
#include "../include/HAL/LDR/HLDR_Config.h"
#include "../include/HAL/LDR/HLDR_Private.h"
#include "../include/MCAL/ADC/MADC_Interface.h"

void HLDR_voidInit(void)
{
	MADC_VoidInit();
	MADC_VoidEnable();
}

u32 HLDR_u32MeasureLightIntensity(void)
{
	f32 ADC_u32Read=0;
	f32 AnalogValue=0;
//	MADC_VoidStartConversion();
	MADC_VoidStartChannelConversion(ADC_CHANNEL0);
	ADC_u32Read=(f32)MADC_u16ReadSynch();
	AnalogValue=(f32)((ADC_u32Read*3.3)/256UL);
//	return	(	(AnalogValue * FIXED_RESISTANCE)	/	(INPUT_VOLTAGE - AnalogValue)	);


	return((FIXED_RESISTANCE*(INPUT_VOLTAGE-AnalogValue))/AnalogValue);
}










