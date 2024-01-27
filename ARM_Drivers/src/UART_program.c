/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : UART                   ***********************/
/***********************            Version : 2.0                    ***********************/
/***********************            Date    : 17 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/UART/UART_private.h"
#include "MCAL/UART/UART_config.h"

pf pfGlobalNotificationFunction = NULL;

void UART_voidInit (void)
{
	/* Set Baud rate value */
	UART1->BRR = BRR_VALUE;
	/* Set Oversampling value */
	UART1->CR1.OVER8 = OVERSAMPLING;
	/* Set Data length */
	UART1->CR1.M = DATA_LENGTH;
	/* Parity mode */
	UART1->CR1.PCE = PARITY_MODE;
	#if UART_ENABLE == PARITY_MODE
		UART1->CR1.PS = PARITY_SELECTION;
	#endif
	/* Transmission complete interrupt */
	UART1->CR1.TCIE = TRANSMISSION_COMPELETE_INTERRUPT;
	/* Read data register interrupt */
	UART1->CR1.RXNEIE = READ_DATA_REGISTER_EMPTY_INTERRUPT;
	/* SEt stop bits */
	UART1->CR2 &= ~(MASK_2BITS << CR2_STOP0);
	UART1->CR2 |=  (STOP_BITS << CR2_STOP0);

	UART1->SR = 0;
}

void UART_voidTransmit (s8 *Pointer_s8Data)
{
	u8 Local_u8Iterator = 0;
	while (Pointer_s8Data[Local_u8Iterator] != '\0')
	{
		UART1->DR = Pointer_s8Data[Local_u8Iterator];
		while (!GET_BIT(UART1->SR, SR_TC));
		Local_u8Iterator++;
	}
}

void UART_voidReceive (u8 *Pointer_s8Data)
{
	while (!GET_BIT(UART1->SR, SR_RXNE));
	*Pointer_s8Data = UART1->DR;
}

u8 UART_u8ReceiveWithoutBlocking (s8 *Pointer_s8Data)
{
	u8 Local_u8ErrorStatus = 1;

	if((GET_BIT(UART1->SR, SR_RXNE)) == 1)
	{
		*Pointer_s8Data = UART1->DR;
	}
	else
	{
		Local_u8ErrorStatus=0;
	}
	return Local_u8ErrorStatus;
}

void UART_voidEnable (void)
{
	/* Enable Transmitter */
	UART1->CR1.TE = TRANSMITTER_ENABLE;
	/* Enable Receiver */
	UART1->CR1.RE = RECEIVER_ENABLE;
	/* Enable USART */
	UART1->CR1.UE = UART_ENABLE;
}

void UART_voidDisable (void)
{
	/* Disable USART */
	UART1->CR1.UE = UART_ENABLE;
}

void UART_voidCallBack (pf pfCallBack)
{
	if (NULL != pfCallBack)
	{
		pfGlobalNotificationFunction = pfCallBack;
	}
	else
	{
		/* Do Nothing */
	}
}

void USART1_IRQHandler(void)
{
	if (NULL != pfGlobalNotificationFunction)
	{
		pfGlobalNotificationFunction ();
	}
	else
	{
		/* Do Nothing */
	}
}

void USART2_IRQHandler(void)
{

}

void USART6_IRQHandler(void)
{

}
