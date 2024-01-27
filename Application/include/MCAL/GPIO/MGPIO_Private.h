/*
 * MGPIO_private.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Hesham Yasser
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS					(0x40020000)
#define GPIOB_BASE_ADDRESS					(0x40020400)
#define GPIOC_BASE_ADDRESS					(0x40020800)
#define GPIOD_BASE_ADDRESS					(0x40020C00)
#define GPIOE_BASE_ADDRESS					(0x40021000)
#define GPIOH_BASE_ADDRESS					(0x40021C00)


typedef struct {
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO_t;




#define GPIOA			((volatile GPIO_t *)GPIOA_BASE_ADDRESS)
#define GPIOB			((volatile GPIO_t *)GPIOB_BASE_ADDRESS)
#define GPIOC			((volatile GPIO_t *)GPIOC_BASE_ADDRESS)
#define GPIOD			((volatile GPIO_t *)GPIOD_BASE_ADDRESS)
#define GPIOE			((volatile GPIO_t *)GPIOE_BASE_ADDRESS)
#define GPIOH			((volatile GPIO_t *)GPIOH_BASE_ADDRESS)


#define FOUR_BIT_MASK		0b1111
#define TWO_BIT_MASK		0b11
#define ONE_BIT_MASK		0b1
#define GPIO_RESET_INDEX	16
#endif /* MGPIO_PRIVATE_H_ */
