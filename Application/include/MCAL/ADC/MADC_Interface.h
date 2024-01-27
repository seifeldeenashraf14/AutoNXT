/*
 * MADC_Interface.h
 *
 *  Created on: ??�/??�/????
 *      Author: Diaa
 */

#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_


/****************Channels******************/
#define ADC_CHANNEL0													0
#define ADC_CHANNEL1													1
#define ADC_CHANNEL2													2
#define ADC_CHANNEL3													3
#define ADC_CHANNEL4													4
#define ADC_CHANNEL5													5

/******************APIs********************/

void MADC_VoidInit(void);

void MADC_VoidEnable(void);

void MADC_VoidDisable(void);

void MADC_VoidStartConversion(void);

void MADC_VoidStopConversion(void);

u32 MADC_u16ReadSynch(void);

void MADC_SetCallBack(pf ADC_CallBack);

void MADC_VoidStartChannelConversion(u8 A_u8Channel);

#endif /* MADC_INTERFACE_H_ */
