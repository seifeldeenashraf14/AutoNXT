/**
 * @file MSCB_private.h
 * @author Hosam Ayoub
 * @version 1.0
 * @date 08 Nov 2023
 * @brief The System Control Block C file that has all the addresses of the registers, their base address and any private macros of the **SCB** driver
 */
#ifndef MSCB_PRIVATE_H_
#define MSCB_PRIVATE_H_

#define SCB_VTOR       					(*(volatile u32*)0xE000ED08)		//!< The System control block vector table offset register
#define SCB_AIRCR						(*(volatile u32*)0xE000ED0C)		//!< The System control block application interrupt reset control register
#define SCB_AIRCR_SYSRESETREQ			2									//!< The System Reset Request bit of the System control block application interrupt reset control register
#define RESET_VALUE						0x05FA0000							//!< The reset value of SCB_AIRCR

#endif
