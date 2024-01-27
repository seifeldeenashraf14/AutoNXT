/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: LIB					*********************************/
/********************			Version: 2.50				*********************************/
/********************			Date: 17 Oct 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef	STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char			u8;
typedef char 					s8;

typedef unsigned short int 		u16;
typedef signed short int 		s16;


typedef unsigned int 			u32;
typedef signed int 				s32;

typedef unsigned long long int 	u64;
typedef signed long long int 	s64;

typedef float 					f32;
typedef double 					f64;


#define NULL 					(void *)0
#define REG_SIZE				32

typedef void (* pf) (void);

#endif
