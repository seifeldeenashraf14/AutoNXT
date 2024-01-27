/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : APP                    ***********************/
/***********************            SWC     : ARM_DRIVERS            ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 11 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/STK/STK_interface.h"
#include "MCAL/NVIC/NVIC_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"

#define SCB_VTOR       					(*(volatile u32*)0xE000ED08)
#define START_ADDRESS					0x08020000

volatile u8 TimeOutFlag = 1;
pf EntryPoint = NULL;


void APP_voidStartApplication (void)
{
	TimeOutFlag = 0;
	SCB_VTOR = START_ADDRESS;
	EntryPoint  = (*(pf *) (START_ADDRESS | 0x4));
}

void main (void)
{
	u8 Local_u8State = 1;
	RCC_voidEnablePeripheral(RCC_AHB1, RCC_AHB1_GPIOA);
	RCC_voidInit();
	STK_voidInit();

//	GPIO_voidSetMode(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT);
//	GPIO_voidOutputPinMode(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_PUSHPULL, GPIO_HIGH_SPEED);
//	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_PIN_HIGH);

	GPIO_voidSetMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
	GPIO_voidOutputPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_PUSHPULL, GPIO_HIGH_SPEED);
	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_LOW);

	GPIO_voidSetMode(GPIO_PORTA, GPIO_PIN7, GPIO_INPUT);
	GPIO_voidInputPinMode(GPIO_PORTA, GPIO_PIN7, GPIO_INPUT_PULL_UP);

	EXTI_voidCallBack(7, &APP_voidStartApplication);
	EXTI_voidSetPortInterrupt(EXTI_PORTA, EXTI_LINE7);
	EXTI_voidInterruptTrigger(EXTI_LINE7, EXTI_FALLING);
	EXTI_voidInterruptEnableDisable(EXTI_LINE7, EXTI_ENABLE);

	NVIC_voidEnablePeripheralInterrupt(NVIC_PERIPHERAL_EXTI9_5);

	while(TimeOutFlag)
	{
		GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, Local_u8State);
		TOG_BIT(Local_u8State, 0);
		STK_voidDelayMS(500);
	}
//	GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_PIN_LOW);
	EntryPoint();
}
