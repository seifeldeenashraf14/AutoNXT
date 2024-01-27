/**
 * @file	MFMI_config.h
 * @author 	Hosam Ayoub
 * @version 1.0
 * @date 	10 Oct 2023
 * @brief 	The flash memory interface header file that has the configurations of **FMI** driver
 */
#ifndef FMI_CONFIG_H_
#define FMI_CONFIG_H_

/* options:
 * 1- MFMI_PSIZE_BYTE
 * 2- MFMI_PSIZE_HALF_WORD
 * 3- MFMI_PSIZE_WORD
 * 4- MFMI_PSIZE_DOUBLE_WORD
 */
/**
 * @def 	MFMI_PSIZE
 * @brief	It sets the size of programming
 * @details It has 4 options:
 * - @ref MFMI_PSIZE_BYTE
 * - @ref MFMI_PSIZE_HALF_WORD
 * - @ref MFMI_PSIZE_WORD
 * - @ref MFMI_PSIZE_DOUBLE_WORD
 */
#define MFMI_PSIZE							MFMI_PSIZE_HALF_WORD

#endif
