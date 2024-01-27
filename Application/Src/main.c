
#include "../include/LIB/STD_Types.h"

/*************************MCAL Includes*******************************/
#include "../include/MCAL/RCC/MRCC_Interface.h"
#include "../include/MCAL/GPIO/MGPIO_Interface.h"
#include "../include/MCAL/ADC/MADC_Interface.h"
#include "../include/MCAL/NVIC/MNVIC_Interface.h"
#include "../include/MCAL/EXTI/MEXTI_Interface.h"
#include "../include/MCAL/TIMER/MTIMER_Interface.h"
#include "../include/MCAL/UART/MUART_Interface.h"
#include "../include/MCAL/SPI/MSPI_Interface.h"

/*************************HAL Includes*******************************/
#include "../include/HAL/MOTOR/HMotor_Interface.h"
#include "../include/HAL/LDR/HLDR_Interface.h"
#include "../include/HAL/FSR/HFSR_Interface.h"
#include "../include/HAL/Ultrasonic/Ultrasonic_Interface.h"


/************************* OS Includes*******************************/
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "queue.h"
#include "portmacro.h"



/********************* UDS ******************************/
#include "../include/UDS_Services_Interface.h"


TaskHandle_t Move_Handle;
TaskHandle_t Ultrasonic_Handle;
TaskHandle_t LDR_Handle;
TaskHandle_t Airbag_handle;
TaskHandle_t Accident_handle;
TaskHandle_t task2_handle;
TaskHandle_t task3_handle;
TaskHandle_t Button_handle;
xSemaphoreHandle Accident_Key;
xSemaphoreHandle Normal_mode;
xSemaphoreHandle Automatic_mode;
TaskHandle_t NextTask_handle;
QueueHandle_t Q1;

static void Movement_handler(void*parameters)
{
	s8 x=0;
	u32 speed=0;
	while(1)
	{
		x=0;
		//xSemaphoreTake(Normal_mode,portMAX_DELAY);
		MUART2_u8ReceiveWithoutBlocking(&x);
//		MUART2_voidTransmitCharacter(x);
		switch(x)
		{
		case 'F':
			HMotor_VoidCarForword();
			MUART2_voidTransmitCharacter(x);

			//xSemaphoreGive(Normal_mode);
			break;
		case 'B':
			HMotor_VoidCarBackword();
			//xSemaphoreGive(Normal_mode);
			break;
		case 'R':
			HMotor_VoidCarRight();
			//xSemaphoreGive(Normal_mode);
			break;
		case 'L':
			HMotor_VoidCarLeft();
			//xSemaphoreGive(Normal_mode);
			break;
		case 'S':
			speed=speed+100;
			HMotor_VoidCarSpeed(speed);
			//xSemaphoreGive(Normal_mode);
			break;
		case 'H':
			speed=speed-100;
			HMotor_VoidCarSpeed(speed);
			//xSemaphoreGive(Normal_mode);
			break;
		default :
			HMotor_VoidCarStop();
			//	xSemaphoreGive(Normal_mode);
			break;
		}

		vTaskDelay(1);
	}
}

static void Ultrasonic_handler(void*parameters)
{
	static u32 speed=0;
	static s32 Distance = 0;
	while(1)
	{
		//xSemaphoreTake(Automatic_mode,portMAX_DELAY);
		Distance = HUltrasonic_voidReadDistanceBlocking();
		MUART2_voidSendNumbers(Distance);
		//MUART1_voidTransmitCharacter('\n');
		if ((Distance*25) >= 1000 )
		{
			speed = 1000;
		}
		else if (Distance <= 6)
		{
			speed = 0;
		}
		else
		{
			speed = (Distance*25);
		}
		HMotor_VoidCarSpeed(speed);
		HMotor_VoidCarForword();
		//xSemaphoreGive(Automatic_mode);
		vTaskDelay(1);
	}
}


static void LDR_Task(void*parameters)
{
	u32 LDR_Read=0;
	while(1)
	{
		//xSemaphoreTake(Automatic_mode,portMAX_DELAY);
		LDR_Read=HLDR_u32MeasureLightIntensity();
		if(LDR_Read>50000)
		{
			LDR_Read=50000;
		}
		else if (LDR_Read<10000)
		{
			LDR_Read = 0;
		}
		MTIMER_voidSetCCRValue(TIMER3,CHANNEL3,(LDR_Read/50));
		//xSemaphoreGive(Automatic_mode);
		vTaskDelay(10);
	}
}



static void Airbag_Task(void*parameters)
{
	u32 Airbag_Read=0;
	while(1)
	{
		//xSemaphoreTake(Automatic_mode,portMAX_DELAY);
//		MADC_VoidStartChannelConversion(ADC_CHANNEL1);
		Airbag_Read=HFSR_u32MeasureForce();
		if(Airbag_Read<2000000)
		{
			xSemaphoreGive(Accident_Key);
		}
		else
		{

		}
		//xSemaphoreGive(Automatic_mode);
		vTaskDelay(1);
	}
}
static void Accident_Task(void*parameters)
{


	while(1)
	{
		xSemaphoreTake(Accident_Key,portMAX_DELAY);
		MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN8, GPIO_PIN_HIGH);
		vTaskSuspendAll();
	}

}
/*
static void Lane_Keep_Task(void)
{
	u8 Lane_Keep_Data=0;
	while(1)
	{
		Lane_Keep_Data= MSPI2_u16ReadReceivedValue();
		if(Lane_Keep_Data=='L')
		{
			HMotor_VoidCarLeft();
		}
		else if(Lane_Keep_Data=='R')
		{
			HMotor_VoidCarRight();
		}
		else
		{
			HMotor_VoidCarForword();
		}
		vTaskDelay(50);
	}


}

 */

int main(void)
{

	BaseType_t status;
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(MRCC_AHB1, MRCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(MRCC_AHB1, MRCC_AHB1_GPIOB);
	MRCC_voidEnablePeripheral(MRCC_APB2, MRCC_APB2_USART1);
	MRCC_voidEnablePeripheral(MRCC_APB1, MRCC_APB1_USART2);
	MRCC_voidEnablePeripheral(MRCC_APB1, MRCC_APB1_TIM4);
	MRCC_voidEnablePeripheral(MRCC_APB1, MRCC_APB1_TIM3);
	MRCC_voidEnablePeripheral(MRCC_APB1, MRCC_APB1_TIM2);
	MRCC_voidEnablePeripheral(MRCC_APB2, MRCC_APB2_ADC1);
	MRCC_voidEnablePeripheral(MRCC_APB1, MRCC_APB1_SPI2);

	/******************ADC**********************/
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_ANALOG);
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN1, GPIO_ANALOG);

	/******************HC-05 pins*****************/
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA, GPIO_PIN2, GPIO_AF7);
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN3, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA, GPIO_PIN3, GPIO_AF7);
	/***************Ultrasonic Trig***************/
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN4, GPIO_PUSH_PULL,GPIO_MID_SPEED );
	MGPIO_voidSetResetPin(GPIO_PORTA, GPIO_PIN4, GPIO_RESET);

	/*****************Ultrasonic echo*************/
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN5, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA, GPIO_PIN5, GPIO_AF1);

	/*******************Motor Init pins*********************/
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN6, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA, GPIO_PIN6, GPIO_AF2);
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN7, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA, GPIO_PIN7, GPIO_AF2);
	/*********************** FSR LED ***************************/
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN8, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN8, GPIO_PUSH_PULL,GPIO_MID_SPEED );
	MGPIO_voidSetResetPin(GPIO_PORTA, GPIO_PIN8, GPIO_RESET);

	/****************Uart1******************/
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN9, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA, GPIO_PIN9, GPIO_AF7);
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN10, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA, GPIO_PIN10, GPIO_AF7);
	/*****************Testing Pin*****************/
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN11, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN11, GPIO_PUSH_PULL,GPIO_MID_SPEED );
	MGPIO_voidSetResetPin(GPIO_PORTA, GPIO_PIN11, GPIO_SET);

	/*********Light control led***************/
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN0, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTB, GPIO_PIN0, GPIO_AF2);
	MTIMER_voidSetPWMOption(TIMER3, CHANNEL3, 1000, 0, 15);
	/*************SPI pins init****************/
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN12, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTB, GPIO_PIN12, GPIO_AF5);
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN13, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTB, GPIO_PIN13, GPIO_AF5);
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN14, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTB, GPIO_PIN14, GPIO_AF5);
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN15, GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTB, GPIO_PIN15, GPIO_AF5);

	/***********Some inits**************/

	MUART1_voidInit();
	MUART1_voidEnable();
	MUART2_voidInit();
	MUART2_voidEnable();
	MSPI2_voidInit();
	HUltrasonic_voidInit();
	MADC_VoidInit();
	MADC_VoidEnable();
	HMotor_VoidCarInit();
	//	HLDR_voidInit();
	//	HFSR_voidInit();

	/******************Bluetooth**********************/
	//status=xTaskCreate(Movement_handler,"RC Car",150,0,1,&Move_Handle);
	//configASSERT(status==pdPASS);
	/*******************LDR Task***********************/
	status=xTaskCreate(LDR_Task,"LDR",150,0,1,&LDR_Handle);
	configASSERT(status==pdPASS);

	/******************  Adaptive cruise control ***********************/
	status=xTaskCreate(Ultrasonic_handler,"Ultrasonic",150,0,3,&Ultrasonic_Handle);
	configASSERT(status==pdPASS);

	/**************** Air Bag***************************/
	status=xTaskCreate(Airbag_Task,"Airbag",150,0,4,&Airbag_handle);
	configASSERT(status==pdPASS);

	status=xTaskCreate(Accident_Task,"Accident",150,0,6,&Accident_handle);
	configASSERT(status==pdPASS);
	/*********** Create Accident Key************/
	Accident_Key=xSemaphoreCreateBinary();
	Normal_mode=xSemaphoreCreateBinary();

	/*Q1=xQueueCreate(3,sizeof(unsigned char));
	if(Q1==NULL)
	{

	}*/

	vTaskStartScheduler();

	while(1)
	{

	}
}
