/*
 * MADC_Private.h
 *
 *  Created on: ??�/??�/????
 *      Author: Diaa
 */

#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_

#define MADC_BASE_ADDRESS												(0X40012000)

typedef struct
{
	u32 SR;
	u32 CR1;
	u32 CR2;
	u32 SMPPR1;
	u32 SMPPR2;
	u32 JOFR1;
	u32 JOFR2;
	u32 JOFR3;
	u32 JOFR4;
	u32 HTR;
	u32 LTR;
	u32 SQR1;
	u32 SQR2;
	u32 SQR3;
	u32 JSQR;
	u32 JDR1;
	u32 JDR2;
	u32 JDR3;
	u32 JDR4;
	u32 DR;
}MADC_t;



typedef struct
{
	u32 CSR;
	u32 CCR;
	u32 CDR;
}MADC_COMMON_REG_t;


#define MADC														((volatile	MADC_t*)MADC_BASE_ADDRESS)

#define MADC_COMMON_REG										((volatile	MADC_COMMON_REG_t*)(MADC_BASE_ADDRESS+0x300))



/**********************************************GENERAL_MACROS**************************************************/


#define ENABLE															1
#define DISABLE															0


#define ADC_6_BIT												      	3
#define ADC_8_BIT												      	2
#define ADC_10_BIT												      	1
#define ADC_12_BIT												      	0


#define ADC_PRESCALER_2											      	0
#define ADC_PRESCALER_4											      	1
#define ADC_PRESCALER_6											      	2
#define ADC_PRESCALER_8											      	3

#define ADC_RIGHT_ALIGNMENT												0
#define ADC_LEFT_ALIGNMENT												1

#define AFTER_ALL_CONVERSIONS											0
#define AFTER_EACH_CONVERSION											1

#define ADC_DMA_SINGLE_COPY   											0
#define ADC_DMA_FREE_RUNNING_COPY   									1


#define ADC_SAMPLE_3_CYCLES												0
#define ADC_SAMPLE_15_CYCLES											1
#define ADC_SAMPLE_28_CYCLES											2
#define ADC_SAMPLE_56_CYCLES											3
#define ADC_SAMPLE_84_CYCLES											4
#define ADC_SAMPLE_112_CYCLES											5
#define ADC_SAMPLE_144_CYCLES											6
#define ADC_SAMPLE_480_CYCLES											7



#define ADC_SGL_CHANNEL_SGL_CONVERSION									0
#define ADC_SGL_CHANNEL_CONS_CONVERSION									1
#define ADC_MUL_CHANNEL_SGL_CONVERSION									2
#define ADC_MUL_CHANNEL_CONS_CONVERSION									3
#define ADC_DISCONTINOUS												4




/**********************************************BIT_MACROS**************************************************/

#define CR1_EOCIE														5
#define CR1_JEOCIE														7
#define CR1_SCAN														8
#define CR1_JAUTO														10
#define CR2_ADON														0
#define CR2_SWSTART														30
#define CR2_JSWSTART													22
#define CR2_CONT														1
#define CR2_EOCS														10
#define CR2_ALIGN														11
#define CR2_DMA														    8
#define CR2_DDS															9
#define SR_STRT															4
#define SR_JSTRT														3
#define SR_EOC															1
#define SR_JEOC															2


/**********************************************MASK_MACROS**************************************************/
#define RESOLUTION_MASK													3
#define RESOLUTION_BITS													24

#define PRESCALER_MASK													3
#define PRESCALER_BITS													16

#define SAMPLE_MASK														7
#define SAMPLE_BITS														3

#define LENGTH_MASK														15
#define LENGTH_BITS														20

#define SEQUENCE_MASK													31
#define SEQUENCE_BITS													5

#endif /* MADC_PRIVATE_H_ */
