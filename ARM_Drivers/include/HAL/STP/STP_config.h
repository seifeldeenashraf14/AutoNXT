/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : HAL                    ***********************/
/***********************            SWC     : STP                    ***********************/
/***********************            Version : 2.0                    ***********************/
/***********************            Date    : 05 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef STP_CONFIG_H_
#define STP_CONFIG_H_

#define STP_NUMBER								2

#define STP1_SERIAL_DATA_PIN					GPIO_PIN8
#define STP1_STORAGE_CLOCK_PIN					GPIO_PIN9
#define STP1_SHIFT_CLOCK_PIN					GPIO_PIN10

#define STP1_SERIAL_DATA_PORT					GPIO_PORTB
#define STP1_STORAGE_CLOCK_PORT					GPIO_PORTB
#define STP1_SHIFT_CLOCK_PORT					GPIO_PORTB

#if 2 == STP_NUMBER

	#define STP2_SERIAL_DATA_PIN				GPIO_PIN12
	#define STP2_STORAGE_CLOCK_PIN				GPIO_PIN13
	#define STP2_SHIFT_CLOCK_PIN				GPIO_PIN14

	#define STP2_SERIAL_DATA_PORT				GPIO_PORTB
	#define STP2_STORAGE_CLOCK_PORT				GPIO_PORTB
	#define STP2_SHIFT_CLOCK_PORT				GPIO_PORTB

#endif

#endif
