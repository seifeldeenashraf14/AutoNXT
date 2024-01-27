/**
 * @file SHexParser_private.h
 * @author Hosam Ayoub
 * @version 1.0
 * @date 01 Oct 2023
 * @brief The HexParser Header file that has all the private Functions and any private macros of **HexParser** driver.
 *
 */


#ifndef SHexParser_PRIVATE_H_
#define SHexParser_PRIVATE_H_

/**
 * @fn u8 SHexParser_u8AsciiToHex(u8)
 * @brief This to convert an ASCII character representing a hexadecimal digit to its corresponding 4-bit binary value.
 *
 * @param 		Copy_u8Ascii		an ASCII character representing a hexadecimal digit.
 * @return  	u8 	The Value of 4-bit binay.
 */

static u8 SHexParser_u8AsciiToHex (u8 Copy_u8Data);

#endif
