/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : UART                   ***********************/
/***********************            Version : 3.5                    ***********************/
/***********************            Date    : 10 Nov 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/UART/MUART_Interface.h"
#include "../include/MCAL/UART/MUART_Private.h"
#include "../include/MCAL/UART/MUART_Config.h"

pf pfGlobalNotificationFunction = NULL;

void MUART1_voidInit (void)
{
	/* Set Baud rate value */
	UART1->BRR = MUART1_BRR_VALUE;
	/* Set Oversampling value */
	UART1->CR1.OVER8 = MUART1_OVERSAMPLING;
	/* Set Data length */
	UART1->CR1.M = MUART1_DATA_LENGTH;
	/* Parity mode */
	UART1->CR1.PCE = MUART1_PARITY_MODE;
#if MUART_ENABLE == MUART1_PARITY_MODE
	UART1->CR1.PS = MUART1_PARITY_SELECTION;
#endif
	/* Transmission complete interrupt */
	UART1->CR1.TCIE = MUART1_TRANSMISSION_COMPELETE_INTERRUPT;
	/* Read data register interrupt */
	UART1->CR1.RXNEIE = MUART1_READ_DATA_REGISTER_EMPTY_INTERRUPT;
	/* SEt stop bits */
	UART1->CR2 &= ~(MASK_2BITS << CR2_STOP0);
	UART1->CR2 |=  (MUART1_STOP_BITS << CR2_STOP0);

	UART1->SR = 0;
}

void MUART1_voidTransmit (s8 *Pointer_s8Data)
{
	u8 Local_u8Iterator = 0;
	while (Pointer_s8Data[Local_u8Iterator] != '\0')
	{
		UART1->DR = Pointer_s8Data[Local_u8Iterator];
		while (!GET_BIT(UART1->SR, SR_TC));
		Local_u8Iterator++;
	}
}

void MUART1_voidTransmitCharacter (u8 Copy_u8Character)
{
	UART1->DR = Copy_u8Character;
	while (!GET_BIT(UART1->SR, SR_TC));
}

void MUART1_voidReceive (s8 *Pointer_s8Data)
{
	while (!GET_BIT(UART1->SR, SR_RXNE));
	*Pointer_s8Data = UART1->DR;
}

u8 MUART1_u8ReceiveWithoutBlocking (s8 *Pointer_s8Data)
{
	u8 Local_u8ErrorStatus = 1;

	if((GET_BIT(UART1->SR, SR_RXNE)) == 1)
	{
		*Pointer_s8Data = UART1->DR;
	}
	else
	{
		Local_u8ErrorStatus = 0;
	}
	return Local_u8ErrorStatus;
}

void MUART1_voidEnable (void)
{
	/* Enable Transmitter */
	UART1->CR1.TE = MUART1_TRANSMITTER_ENABLE;
	/* Enable Receiver */
	UART1->CR1.RE = MUART1_RECEIVER_ENABLE;
	/* Enable USART */
	UART1->CR1.UE = MUART_ENABLE;
}

void MUART1_voidDisable (void)
{
	/* Disable USART */
	UART1->CR1.UE = MUART_ENABLE;
}

void MUART1_voidCallBack (pf pfCallBack)
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

void MUART2_voidInit (void)
{
	/* Set Baud rate value */
	UART2->BRR = MUART2_BRR_VALUE;
	/* Set Oversampling value */
	UART2->CR1.OVER8 = MUART2_OVERSAMPLING;
	/* Set Data length */
	UART2->CR1.M = MUART2_DATA_LENGTH;
	/* Parity mode */
	UART2->CR1.PCE = MUART2_PARITY_MODE;
#if MUART_ENABLE == MUART2_PARITY_MODE
	UART2->CR1.PS = MUART2_PARITY_SELECTION;
#endif
	/* Transmission complete interrupt */
	UART2->CR1.TCIE = MUART2_TRANSMISSION_COMPELETE_INTERRUPT;
	/* Read data register interrupt */
	UART2->CR1.RXNEIE = MUART2_READ_DATA_REGISTER_EMPTY_INTERRUPT;
	/* SEt stop bits */
	UART2->CR2 &= ~(MASK_2BITS << CR2_STOP0);
	UART2->CR2 |=  (MUART2_STOP_BITS << CR2_STOP0);

	UART2->SR = 0;
}

void MUART2_voidTransmit (s8 *Pointer_s8Data)
{
	u8 Local_u8Iterator = 0;
	while (Pointer_s8Data[Local_u8Iterator] != '\0')
	{
		UART2->DR = Pointer_s8Data[Local_u8Iterator];
		while (!GET_BIT(UART2->SR, SR_TC));
		Local_u8Iterator++;
	}
}

void MUART2_voidTransmitCharacter (u8 Copy_u8Character)
{
	UART2->DR = Copy_u8Character;
	while (!GET_BIT(UART2->SR, SR_TC));
}

void MUART2_voidReceive (s8 *Pointer_s8Data)
{
	while (!GET_BIT(UART2->SR, SR_RXNE));
	*Pointer_s8Data = UART2->DR;
}

u8 MUART2_u8ReceiveWithoutBlocking (s8 *Pointer_s8Data)
{
	u8 Local_u8ErrorStatus = 1;

	if((GET_BIT(UART2->SR, SR_RXNE)) == 1)
	{
		*Pointer_s8Data = UART2->DR;
	}
	else
	{
		Local_u8ErrorStatus = 0;
	}
	return Local_u8ErrorStatus;
}

void MUART2_voidEnable (void)
{
	/* Enable Transmitter */
	UART2->CR1.TE = MUART2_TRANSMITTER_ENABLE;
	/* Enable Receiver */
	UART2->CR1.RE = MUART2_RECEIVER_ENABLE;
	/* Enable USART */
	UART2->CR1.UE = MUART_ENABLE;
}

void MUART2_voidDisable (void)
{
	/* Disable USART */
	UART2->CR1.UE = MUART_ENABLE;
}

void MUART2_voidCallBack (pf pfCallBack)
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

void MUART6_voidInit (void)
{
	/* Set Baud rate value */
	UART6->BRR = MUART6_BRR_VALUE;
	/* Set Oversampling value */
	UART6->CR1.OVER8 = MUART6_OVERSAMPLING;
	/* Set Data length */
	UART6->CR1.M = MUART6_DATA_LENGTH;
	/* Parity mode */
	UART6->CR1.PCE = MUART6_PARITY_MODE;
	#if MUART_ENABLE == MUART6_PARITY_MODE
		UART6->CR1.PS = MUART6_PARITY_SELECTION;
	#endif
	/* Transmission complete interrupt */
	UART6->CR1.TCIE = MUART6_TRANSMISSION_COMPELETE_INTERRUPT;
	/* Read data register interrupt */
	UART6->CR1.RXNEIE = MUART6_READ_DATA_REGISTER_EMPTY_INTERRUPT;
	/* SEt stop bits */
	UART6->CR2 &= ~(MASK_2BITS << CR2_STOP0);
	UART6->CR2 |=  (MUART6_STOP_BITS << CR2_STOP0);

	UART6->SR = 0;
}

void MUART6_voidTransmit (s8 *Pointer_s8Data)
{
	u8 Local_u8Iterator = 0;
	while (Pointer_s8Data[Local_u8Iterator] != '\0')
	{
		UART6->DR = Pointer_s8Data[Local_u8Iterator];
		while (!GET_BIT(UART6->SR, SR_TC));
		Local_u8Iterator++;
	}
}

void MUART6_voidTransmitCharacter (u8 Copy_u8Character)
{
	UART6->DR = Copy_u8Character;
	while (!GET_BIT(UART6->SR, SR_TC));
}

void MUART6_voidReceive (s8 *Pointer_s8Data)
{
	while (!GET_BIT(UART6->SR, SR_RXNE));
	*Pointer_s8Data = UART6->DR;
}

u8 MUART6_u8ReceiveWithoutBlocking (s8 *Pointer_s8Data)
{
	u8 Local_u8ErrorStatus = 1;

	if((GET_BIT(UART6->SR, SR_RXNE)) == 1)
	{
		*Pointer_s8Data = UART6->DR;
	}
	else
	{
		Local_u8ErrorStatus = 0;
	}
	return Local_u8ErrorStatus;
}

void MUART6_voidEnable (void)
{
	/* Enable Transmitter */
	UART6->CR1.TE = MUART6_TRANSMITTER_ENABLE;
	/* Enable Receiver */
	UART6->CR1.RE = MUART6_RECEIVER_ENABLE;
	/* Enable USART */
	UART6->CR1.UE = MUART_ENABLE;
}

void MUART6_voidDisable (void)
{
	/* Disable USART */
	UART6->CR1.UE = MUART_ENABLE;
}

void MUART6_voidCallBack (pf pfCallBack)
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


void MUART2_voidSendNumbers (u32 A_u32Number)
{
	u32 local_u32Temp = 1;
	while (A_u32Number != 0)
	{
		local_u32Temp = local_u32Temp*10 + (A_u32Number%10);
		A_u32Number /= 10;
	}
	while (local_u32Temp != 1)
	{
		MUART2_voidTransmitCharacter((local_u32Temp%10)+'0');
		local_u32Temp /= 10;
	}
}
