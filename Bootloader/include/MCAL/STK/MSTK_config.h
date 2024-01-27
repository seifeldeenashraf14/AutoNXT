/**
 * @file	MSTK_config.h
 * @author 	Hosam Ayoub
 * @version 1.0
 * @date 	5 oct 2023
 * @brief 	The Systick Timer interface header file that has all the configurations and the modes and the options of the **STK** driver
 */
#ifndef STK_CONFIG_H_
#define STK_CONFIG_H_

/* Options:
 * 1- CLK_AHB_BY_8
 * 2- CLK_AHB
 */
#define PRESCALER								CLK_AHB_BY_8	//!< this bit macro will select the clock source

/* Options:
 * 1- INTERRUPT_OFF
 * 2- INTERRUPT_ON
 */
#define INTERRUPT								INTERRUPT_OFF	//!< this bit macro will select the interrupt enable or disable 


#define CLK_FREQ								3.125			//!< this bit macro will select the frequency of the clock

#endif
