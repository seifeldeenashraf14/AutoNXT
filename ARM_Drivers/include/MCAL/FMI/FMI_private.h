/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : FMI                    ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 10 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef FMI_PRIVATE_H_
#define FMI_PRIVATE_H_

#define FMI_BASE_ADDRESS						(0x40023C00)

typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 OPTCR;
}tstrFMI;

#define FMI										((volatile tstrFMI *) FMI_BASE_ADDRESS)

/* KEYR bits */
#define ACR_KEY1								0
#define ACR_KEY2								16

/* SR bits */
#define SR_BSY                              	16
#define SR_RDERR                            	8
#define SR_PGSERR                           	7
#define SR_PGPERR                           	6
#define SR_PGAERR                           	5
#define SR_WRPERR                           	4
#define SR_OPERR                            	1
#define SR_EOP                              	0

/* CR bits */
#define CR_LOCK                             	31
#define CR_ERRIE                            	25
#define CR_EOPIE                          		24
#define CR_STRT                           		16
#define CR_PSIZE                           		8
#define CR_SNB		                           	3
#define CR_MER	                            	2
#define CR_SER                              	1
#define CR_PG	                            	0


/* Keys */
#define FMI_KEY1								0x45670123
#define FMI_KEY2								0xCDEF89AB

/* Masks */
#define MASK_2BIT								0b11
#define MASK_4BIT								0b1111

#endif
