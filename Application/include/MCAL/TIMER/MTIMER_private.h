/*
 * MTIMER_private.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Hesham Yasser
 */

#ifndef MTIMER_PRIVATE_H_
#define MTIMER_PRIVATE_H_

#define TIMER2_BASE_ADDRESS				(0x40000000)
#define TIMER3_BASE_ADDRESS				(0x40000400)
#define TIMER4_BASE_ADDRESS				(0x40000800)
#define TIMER5_BASE_ADDRESS				(0x40000C00)

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SMCR;
	u32 DIER;
	u32 SR;
	u32 EGR;
	u32 CCMR1;
	u32 CCMR2;
	u32 CCER;
	u32 CNT;
	u32 PSC;
	u32 ARR;
	u32 RESERVED1;
	u32 CCR1;
	u32 CCR2;
	u32 CCR3;
	u32 CCR4;
	u32 RESERVED2;
	u32 DCR;
	u32 DMAR;
}TIMER_t;


#define TIM2			((volatile TIMER_t *)TIMER2_BASE_ADDRESS)
#define TIM3			((volatile TIMER_t *)TIMER3_BASE_ADDRESS)
#define TIM4			((volatile TIMER_t *)TIMER4_BASE_ADDRESS)
#define TIM5			((volatile TIMER_t *)TIMER5_BASE_ADDRESS)


/*****************MACROs****************/

#define CR1_CEN					0
#define CR1_DIR					4

#define CCMR1_CC1S				0
#define CCMR1_CC2S				8
#define CCMR2_CC3S				0
#define CCMR2_CC4S				8

#define CCMR1_OC1M				4
#define CCMR1_OC2M				12

#define CCMR2_OC3M				4
#define CCMR2_OC4M				12

#define CCER_CC1E				0
#define CCER_CC1P				1
#define CCER_CC1NP				3

#define CCER_CC2E				4
#define CCER_CC2P				5
#define CCER_CC2NP				7

#define CCER_CC3E				8
#define CCER_CC3P				9
#define CCER_CC3NP				11

#define CCER_CC4E				12
#define CCER_CC4P				13
#define CCER_CC4NP				15

#define TWO_BIT_MASK			0b11
#define THREE_BIT_MASK			0b111
#endif /* MTIMER_PRIVATE_H_ */
