/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : GPIO                   ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 10 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIOA_BASE							(0x40020000)
#define GPIOB_BASE							(0x40020400)
#define GPIOC_BASE							(0x40020800)
#define GPIOD_BASE							(0x40020C00)
#define GPIOE_BASE							(0x40021000)
#define GPIOH_BASE							(0x40021C00)

typedef struct
{
	u32 MODDER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}tstrGPIO;

#define GPIOA				((volatile tstrGPIO *) GPIOA_BASE)
#define GPIOB				((volatile tstrGPIO *) GPIOB_BASE)
#define GPIOC				((volatile tstrGPIO *) GPIOC_BASE)
#define GPIOD				((volatile tstrGPIO *) GPIOD_BASE)
#define GPIOE				((volatile tstrGPIO *) GPIOE_BASE)
#define GPIOH				((volatile tstrGPIO *) GPIOH_BASE)

#define MASK							0b11
#define MASK_FOUR_BITS					0b1111
#define BIT								1


#endif
