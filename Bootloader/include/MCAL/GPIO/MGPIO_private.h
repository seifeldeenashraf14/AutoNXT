/**
 * @file	MGPIO_private.h
 * @author 	Hesham Yasser
 * @version 2.5
 * @date 	10 Oct 2023
 * @brief 	the GPIO private header file that contains private declarations
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS					(0x40020000)		//<!this is GPIOA base address
#define GPIOB_BASE_ADDRESS					(0x40020400)		//<!this is GPIOB base address
#define GPIOC_BASE_ADDRESS					(0x40020800)		//<!this is GPIOC base address
#define GPIOD_BASE_ADDRESS					(0x40020C00)		//<!this is GPIOD base address
#define GPIOE_BASE_ADDRESS					(0x40021000)		//<!this is GPIOE base address
#define GPIOH_BASE_ADDRESS					(0x40021C00)		//<!this is GPIOF base address


/**
 * @struct GPIO_t
 * @brief this struct contains the GPIO registers
 */
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




#define GPIOA			((volatile GPIO_t *)GPIOA_BASE_ADDRESS)		//<! this is a pointer to GPIOA registers
#define GPIOB			((volatile GPIO_t *)GPIOB_BASE_ADDRESS)		//<! this is a pointer to GPIOB registers
#define GPIOC			((volatile GPIO_t *)GPIOC_BASE_ADDRESS)		//<! this is a pointer to GPIOC registers
#define GPIOD			((volatile GPIO_t *)GPIOD_BASE_ADDRESS)		//<! this is a pointer to GPIOD registers
#define GPIOE			((volatile GPIO_t *)GPIOE_BASE_ADDRESS)		//<! this is a pointer to GPIOE registers
#define GPIOH			((volatile GPIO_t *)GPIOH_BASE_ADDRESS)		//<! this is a pointer to GPIOF registers

#define TWO_BIT_MASK		0b11					//<! this is used in masking two bits
#define FOUR_BIT_MASK		0b1111					//<! this is used in masking Four bits
#define ONE_BIT_MASK		0b1						//<! this is used in masking one bit
#define GPIO_RESET_INDEX	16						//<! this is the reset index of GPIO_BSSR register
#endif /* MGPIO_PRIVATE_H_ */
