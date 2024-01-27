/*
 * MADC_Config.h
 *
 *  Created on: ??�/??�/????
 *      Author: Diaa
 */

#ifndef MADC_CONFIG_H_
#define MADC_CONFIG_H_


#define MADC_RESOLUTION													 	    ADC_8_BIT

#define MADC_PRESCALER												  	     ADC_PRESCALER_4

#define MADC_MODE											        	 ADC_SGL_CHANNEL_SGL_CONVERSION

#define MDAC_DATA_ALIGNMENT												     ADC_RIGHT_ALIGNMENT

#define MADC_EOCS_MODE													    AFTER_ALL_CONVERSIONS

#define MADC_DMA_MODE																DISABLE

#define MADC_DMA_SELECTION													ADC_DMA_SINGLE_COPY

#define MADC_EOC_INTERRUPT														     DISABLE

#define MADC_REGULAR_CHANNELS_SEQUENCE_LENGTH									     	1

#define MADC_CH0_SAMPLE_TIME													ADC_SAMPLE_3_CYCLES
#define MADC_CH1_SAMPLE_TIME													ADC_SAMPLE_3_CYCLES
#define MADC_CH2_SAMPLE_TIME													ADC_SAMPLE_3_CYCLES
#define MADC_CH3_SAMPLE_TIME													ADC_SAMPLE_3_CYCLES
#define MADC_CH4_SAMPLE_TIME													ADC_SAMPLE_3_CYCLES
#define MADC_CH5_SAMPLE_TIME													ADC_SAMPLE_3_CYCLES


#define ADC_REGULAR_SEQ_1 															ADC_CHANNEL0
#define ADC_REGULAR_SEQ_2  															ADC_CHANNEL1
#define ADC_REGULAR_SEQ_3  															ADC_CHANNEL1
#define ADC_REGULAR_SEQ_4  															ADC_CHANNEL1
#define ADC_REGULAR_SEQ_5  															ADC_CHANNEL1
#define ADC_REGULAR_SEQ_6  															ADC_CHANNEL1


#endif /* MADC_CONFIG_H_ */
