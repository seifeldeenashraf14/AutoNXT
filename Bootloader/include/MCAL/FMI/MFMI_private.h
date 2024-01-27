/**
 * @file	MFMI_private.h
 * @author 	Hosam Ayoub
 * @version 1.0
 * @date 	10 Oct 2023
 * @brief 	The Flash Memory Interface Header file that has all the addresses of the registers, their base address and any private macros of **FMI** driver
 */
#ifndef FMI_PRIVATE_H_
#define FMI_PRIVATE_H_

#define FMI_BASE_ADDRESS						(0x40023C00)									//!< The **FMI** Base address

/**
 * @struct 	tstrFMI
 * @brief	This struct has all the FMI register
 *
 */
typedef struct
{
	volatile u32 ACR;			//!< Flash access control register
	volatile u32 KEYR;          //!< Flash key register
	volatile u32 OPTKEYR;       //!< Flash option key register
	volatile u32 SR;            //!< Flash status register
	volatile u32 CR;            //!< Flash control register
	volatile u32 OPTCR;         //!< Flash option control register
}tstrFMI;

#define FMI										((volatile tstrFMI *) FMI_BASE_ADDRESS)			//!< The base address of the **FMI** peripheral

/* SR bits */
#define SR_BSY                              	16	                                            //!< Busy, this bit indicates that a Flash memory operation is in progress.
#define SR_RDERR                            	8	                                            //!< Read Protection Error, set by hardware when an address to be read through the DBus belongs to a read protected part of the flash.
#define SR_PGSERR                           	7	                                            //!< Programming sequence error, set by hardware when a write access to the Flash memory is performed by the code while the control register has not been correctly configured.
#define SR_PGPERR                           	6                                               //!< Programming parallelism error, set by hardware when the size of the access (byte, half-word, word, double word) during the program sequence does not correspond to the parallelism configuration @ref MFMI_PSIZE (@ref MFMI_PSIZE_BYTE - @ref MFMI_PSIZE_HALF_WORD - @ref MFMI_PSIZE_WORD - @ref MFMI_PSIZE_DOUBLE_WORD)
#define SR_PGAERR                           	5                                               //!< Programming alignment error, set by hardware when the data to program cannot be contained in the same 128-bit Flash memory row.
#define SR_WRPERR                           	4                                               //!< Write protection error, set by hardware when an address to be erased/programmed belongs to a write-protected part of the Flash memory.
#define SR_OPERR                            	1                                               //!< Operation error, set by hardware when a flash operation (programming / erase /read) request is detected and can not be run because of parallelism, alignment, or write protection error. This bit is set only if error interrupts are enabled
#define SR_EOP                              	0                                               //!< End of operation, set by hardware when one or more Flash memory operations (program/erase) has/have completed successfully. It is set only if the end of operation interrupts are enabled

/* CR bits */
#define CR_LOCK                             	31                                              //!< Lock, write to 1 only. When it is set, this bit indicates that the FLASH_CR register is locked. It is cleared by hardware after detecting the unlock sequence
#define CR_ERRIE                            	25                                              //!< Error interrupt enable, this bit enables the interrupt generation when the OPERR bit in the FLASH_SR register is set to 1
#define CR_EOPIE                          		24                                              //!< End of operation interrupt enable, this bit enables the interrupt generation when the EOP bit in the FLASH_SR register goes to 1
#define CR_STRT                           		16                                              //!< Start, this bit triggers an erase operation when set. It is set only by software and cleared when the BSY bit is cleared
#define CR_PSIZE                           		8                                               //!< Program size, these bits select the program parallelism and its options (@ref MFMI_PSIZE_BYTE - @ref MFMI_PSIZE_HALF_WORD - @ref MFMI_PSIZE_WORD - @ref MFMI_PSIZE_DOUBLE_WORD)
#define CR_SNB		                           	3                                               //!< Sector number, these bits select the sector to erase and its options (@ref MFMI_SECTOR0 - @ref MFMI_SECTOR1 - @ref MFMI_SECTOR2 - @ref MFMI_SECTOR3 - @ref MFMI_SECTOR4 - @ref MFMI_SECTOR5)
#define CR_MER	                            	2                                               //!< Mass Erase, erase activated for all user sectors
#define CR_SER                              	1                                               //!< Sector Erase, sector Erase activated
#define CR_PG	                            	0                                               //!< Programming, Flash programming activated


/* Keys */
#define FMI_KEY1								0x45670123                                      //!< The first flash key register **KEYR**
#define FMI_KEY2								0xCDEF89AB                                      //!< The second flash key register **KEYR**

/* Masks */
#define MASK_2BIT								0b11        									//!< Mask for 2 Bits
#define MASK_4BIT								0b1111      									//!< Mask for 4 Bits

#endif
