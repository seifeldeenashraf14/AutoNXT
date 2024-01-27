/**
 * @file	BIT_MATH.h
 * @author 	Hosam Ayoub
 * @version 1.0
 * @date 	2 Aug 2023
 * @brief 	The bit manipulation functions like macro
 */
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT) (REG) |=  (1 << (BIT))					//!< This function set the specified BIT
#define CLR_BIT(REG,BIT) (REG) &= ~(1 << (BIT))                 //!< This function clear the specified BIT
#define TOG_BIT(REG,BIT) (REG) ^=  (1 << (BIT))                 //!< This function toggle the specified BIT
#define GET_BIT(REG,BIT) (((REG) >> (BIT)) & 0x01)              //!< This function get the specified BIT


#endif
