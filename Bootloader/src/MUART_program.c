/**
 * @file	MUART_program.c
 * @author 	Hosam Ayoub
 * @version 3.5
 * @date 	10 Nov 2023
 * @brief 	The UART Program C file that has the functions body which is responsible for Transmitting and Receiving the data
 */
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/UART/MUART_interface.h"
#include "../include/MCAL/UART/MUART_private.h"
#include "../include/MCAL/UART/MUART_config.h"

pf pfGlobalNotificationFunction_Uart1 = NULL;   //!<  Pointer to function which carries the address of the function which passed to callback function when the UART1 interrupt occurred
pf pfGlobalNotificationFunction_Uart2 = NULL;   //!<  Pointer to function which carries the address of the function which passed to callback function when the UART2 interrupt occurred
pf pfGlobalNotificationFunction_Uart6 = NULL;   //!<  Pointer to function which carries the address of the function which passed to callback function when the UART3 interrupt occurred

/**
 * @fn 		void MUART1_voidInit (void)
 * @brief 	This function responsible of Initializing UART1
 * @param 	none
 * @return	none
 */
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

/**
 * @fn 		void MUART1_voidTransmit (s8*)
 * @brief 	This function responsible of Transmitting the data from UART1
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be transmitted
 * @return	none
 */
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

/**
 * @fn 		void MUART1_voidTransmitCharacter (u8)
 * @brief 	This function responsible of Transmitting the data from UART1
 * @param 	Copy_u8Character Copy of the 8-bit unsigned data which will be transmitted
 * @return	none
 */
void MUART1_voidTransmitCharacter (u8 Copy_u8Character)
{
	UART1->DR = Copy_u8Character;
	while (!GET_BIT(UART1->SR, SR_TC));
}

/**
 * @fn 		void MUART1_voidReceive (s8*)
 * @brief 	This function responsible of Receiving the data from UART1
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by polling
 * @return	none
 */
void MUART1_voidReceive (s8 *Pointer_s8Data)
{
	while (!GET_BIT(UART1->SR, SR_RXNE));
	*Pointer_s8Data = UART1->DR;
}

/**
 * @fn 		u8 MUART1_u8ReceiveWithoutBlocking (s8*)
 * @brief 	This function responsible of Receiving the data from UART1
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by Periodic Check
 * @return	u8 The status if the operation of receiving the past data is finished or not
 */
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


/**
 * @fn 		void MUART1_voidEnable (void)
 * @brief 	This function responsible of Enabling the interrupt of UART1
 * @param 	none
 * @return	none
 */
void MUART1_voidEnable (void)
{
	/* Enable Transmitter */
	UART1->CR1.TE = MUART1_TRANSMITTER_ENABLE;
	/* Enable Receiver */
	UART1->CR1.RE = MUART1_RECEIVER_ENABLE;
	/* Enable USART */
	UART1->CR1.UE = MUART_ENABLE;
}
/**
 * @fn 		void MUART1_voidDisable (void)
 * @brief 	This function responsible of Disabling the interrupt of UART1
 * @param 	none
 * @return	none
 */
void MUART1_voidDisable (void)
{
	/* Disable USART */
	UART1->CR1.UE = MUART_ENABLE;
}

/**
 * @fn 		void MUART1_voidCallBack(pf)
 * @brief 	This function responsible of assigning the address of the callback function to the pointer which will be called when the interrupt of Uart1 occurred
 * @param 	pfCallBack Copy of the address of the function that will be called when the UART1 interrupt occurred
 * @return	none
 */
void MUART1_voidCallBack (pf pfCallBack)
{
	if (NULL != pfCallBack)
	{
		pfGlobalNotificationFunction_Uart6 = pfCallBack;
	}
	else
	{
		/* Do Nothing */
	}
}

/**
 * @fn 		void MUART2_voidInit(void)
 * @brief 	This function responsible of Initializing UART2
 * @param 	none
 * @return	none
 */
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

/**
 * @fn 		void MUART2_voidTransmit (s8*)
 * @brief 	This function responsible of Transmitting the data from UART2
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be transmitted
 * @return	none
 */
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
/**
 * @fn 		void MUART2_voidTransmitCharacter(u8)
 * @brief 	This function responsible of Transmitting the data from UART2
 * @param 	Copy_u8Character Copy of the 8-bit unsigned data which will be transmitted
 * @return	none
 */
void MUART2_voidTransmitCharacter (u8 Copy_u8Character)
{
	UART2->DR = Copy_u8Character;
	while (!GET_BIT(UART2->SR, SR_TC));
}

/**
 * @fn 		void MUART2_voidReceive (s8*)
 * @brief 	This function responsible of Receiving the data from UART2
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by polling
 * @return	none
 */
void MUART2_voidReceive (s8 *Pointer_s8Data)
{
	while (!GET_BIT(UART2->SR, SR_RXNE));
	*Pointer_s8Data = UART2->DR;
}
/**
 * @fn 		u8 MUART2_u8ReceiveWithoutBlocking (s8*)
 * @brief 	This function responsible of Receiving the data from UART2
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by Periodic Check
 * @return	u8 The status if the operation of receiving the past data is finished or not
 */
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
/**
 * @fn 		void MUART2_voidEnable (void)
 * @brief 	This function responsible of Enabling the interrupt of UART2
 * @param 	none
 * @return	none
 */
void MUART2_voidEnable (void)
{
	/* Enable Transmitter */
	UART2->CR1.TE = MUART2_TRANSMITTER_ENABLE;
	/* Enable Receiver */
	UART2->CR1.RE = MUART2_RECEIVER_ENABLE;
	/* Enable USART */
	UART2->CR1.UE = MUART_ENABLE;
}
/**
 * @fn 		void MUART2_voidDisable (void)
 * @brief 	This function responsible of Disabling the interrupt of UART2
 * @param 	none
 * @return	none
 */
void MUART2_voidDisable (void)
{
	/* Disable USART */
	UART2->CR1.UE = MUART_ENABLE;
}
/**
 * @fn 		void MUART2_voidCallBack (pf)
 * @brief 	This function responsible of assigning the address of the callback function to the pointer which will be called when the interrupt of Uart2 occurred
 * @param 	pfCallBack Copy of the address of the function that will be called when the UART2 interrupt occurred
 * @return	none
 */
void MUART2_voidCallBack (pf pfCallBack)
{
	if (NULL != pfCallBack)
	{
		pfGlobalNotificationFunction_Uart2 = pfCallBack;
	}
	else
	{
		/* Do Nothing */
	}
}

/**
 * @fn 		void MUART6_voidInit(void)
 * @brief 	This function responsible of Initializing UART6
 * @param 	none
 * @return	none
 */
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

/**
 * @fn 		void MUART6_voidTransmit (s8*)
 * @brief 	This function responsible of Transmitting the data from UART6
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be transmitted
 * @return	none
 */
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

/**
 * @fn 		void MUART6_voidTransmitCharacter (u8)
 * @brief 	This function responsible of Transmitting the data from UART6
 * @param 	Copy_u8Character Copy of the 8-bit unsigned data which will be transmitted
 * @return	none
 */
void MUART6_voidTransmitCharacter (u8 Copy_u8Character)
{
	UART6->DR = Copy_u8Character;
	while (!GET_BIT(UART6->SR, SR_TC));
}

/**
 * @fn 		void MUART6_voidReceive (s8*)
 * @brief 	This function responsible of Receiving the data from UART6
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by polling
 * @return	none
 */
void MUART6_voidReceive (s8 *Pointer_s8Data)
{
	while (!GET_BIT(UART6->SR, SR_RXNE));
	*Pointer_s8Data = UART6->DR;
}


/**
 * @fn 		u8 MUART6_u8ReceiveWithoutBlocking (s8*)
 * @brief 	This function responsible of Receiving the data from UART6
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by Periodic Check
 * @return	u8 The status if the operation of receiving the past data is finished or not
 */
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
/**
 * @fn 		void MUART6_voidEnable (void)
 * @brief 	This function responsible of Enabling the interrupt of UART6
 * @param 	none
 * @return	none
 */
void MUART6_voidEnable (void)
{
	/* Enable Transmitter */
	UART6->CR1.TE = MUART6_TRANSMITTER_ENABLE;
	/* Enable Receiver */
	UART6->CR1.RE = MUART6_RECEIVER_ENABLE;
	/* Enable USART */
	UART6->CR1.UE = MUART_ENABLE;
}
/**
 * @fn 		void MUART6_voidDisable (void)
 * @brief 	This function responsible of Disabling the interrupt of UART6
 * @param 	none
 * @return	none
 */
void MUART6_voidDisable (void)
{
	/* Disable USART */
	UART6->CR1.UE = MUART_ENABLE;
}
/**
 * @fn 		void MUART6_voidCallBack (pf)
 * @brief 	This function responsible of assigning the address of the callback function to the pointer which will be called when the interrupt of Uart6 occurred
 * @param 	pfCallBack Copy of the address of the function that will be called when the UART6 interrupt occurred
 * @return	none
 */
void MUART6_voidCallBack (pf pfCallBack)
{
	if (NULL != pfCallBack)
	{
		pfGlobalNotificationFunction_Uart6 = pfCallBack;
	}
	else
	{
		/* Do Nothing */
	}
}
/**
 * @fn 		void USART1_IRQHandler(void)
 * @brief 	This handler will be called when the interrupt of UART1 occurred
 * @param 	none
 * @return	none
 */
void USART1_IRQHandler(void)
{
	if (NULL != pfGlobalNotificationFunction_Uart1)
	{
		pfGlobalNotificationFunction_Uart1 ();
	}
	else
	{
		/* Do Nothing */
	}
}

/**
 * @fn 		void USART2_IRQHandler(void)
 * @brief 	This handler will be called when the interrupt of UART2 occurred
 * @param 	none
 * @return	none
 */
void USART2_IRQHandler(void)
{
	if (NULL != pfGlobalNotificationFunction_Uart2)
	{
		pfGlobalNotificationFunction_Uart2 ();
	}
	else
	{
		/* Do Nothing */
	}
}
/**
 * @fn 		void USART6_IRQHandler(void)
 * @brief 	This handler will be called when the interrupt of UART6 occurred
 * @param 	none
 * @return	none
 */
void USART6_IRQHandler(void)
{
	if (NULL != pfGlobalNotificationFunction_Uart6)
		{
			pfGlobalNotificationFunction_Uart6 ();
		}
		else
		{
			/* Do Nothing */
		}
}
