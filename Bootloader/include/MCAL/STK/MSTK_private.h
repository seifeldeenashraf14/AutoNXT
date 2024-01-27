/**
 * @file	MSTK_private.h
 * @author 	Hosam Ayoub
 * @version 1.0
 * @date 	5 oct 2023
 * @brief 	The Systick Timer interface header file that has all the addresses of the registers, their base address and any private macros of **STK** driver
 */

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

#define CTRL                                  	(* (volatile u32 *) 0xE000E010)	//!< Systick Control and Status register
#define CTRL_ENABLE								0 			//!< this bit macro enables the counter to reload the value to the load register then counting down to 0
#define CTRL_TICKINT							1			//!< this bit macro indicates to the exception request enable or disable
#define CTRL_CLKSOURCE							2			//!< this bit macro indicates to the clock source of the system either the clock of the bus or prescalered by 8
#define CTRL_COUNTFLAG							16			//!< this bit flag is raised when the timer ends counting or reach to 0

#define LOAD                                  	(* (volatile u32 *) 0xE000E014)		//!< Systick reload value register 
#define VAL	                                  	(* (volatile u32 *) 0xE000E018)		//!< Systick Current value register
#define CALIB                                 	(* (volatile u32 *) 0xE000E01C)		//!< Systick Calibration Value register

#define DIV_BY_8								8									//!< the clock option will be shifted by this macro

#define SINGLE_INTERVAL							0									//!< this bit macro indicates to single interval and single counting and single interrupt
#define PERIODIC_INTERVAL						1									//!< this bit macro indicates to periodic interval and periodic counting and periodic interrupt

#endif
