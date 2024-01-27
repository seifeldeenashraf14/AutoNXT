/**
 * @file	STD_TYPES.h
 * @author 	Hosam Ayoub
 * @version 2.5
 * @date 	17 Oct 2023
 * @brief 	The standard types used in the projects
 */
#ifndef	STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char			u8;						//!< The unsigned char data type
typedef char 					s8;						//!< The signed char data type

typedef unsigned short int 		u16;					//!< The unsigned short int data type
typedef signed short int 		s16;					//!< The signed short int data type


typedef unsigned int 			u32;					//!< The unsigned int data type
typedef signed int 				s32;					//!< The signed int data type

typedef unsigned long long int 	u64;					//!< The unsigned long long int data type
typedef signed long long int 	s64;					//!< The signed long long int data type

typedef float 					f32;					//!< The float data type
typedef double 					f64;					//!< The double data type


#define NULL 					(void *)0				//!< The definition of NULL
#define REG_SIZE				32						//!< The size of register for STM32F401CC

typedef void (* pf) (void);								//!< A pointer to function that its new name is pf

#endif
