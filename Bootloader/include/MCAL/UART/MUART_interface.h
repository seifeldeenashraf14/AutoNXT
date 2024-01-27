/**
 * @file	MUART_interface.h
 * @author 	Hosam Ayoub
 * @version 3.5
 * @date 	10 Nov 2023
 * @brief 	The UART Interface  Header file that has all the prototypes and arguments of **UART** driver
 */
#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_
/**
 * @fn 		void MUART1_voidInit (void)
 * @brief 	This function responsible of Initializing UART1
 * @param 	none
 * @return	none
 */
void MUART1_voidInit (void);
/**
 * @fn 		void MUART1_voidTransmit (s8*)
 * @brief 	This function responsible of Transmitting the data from UART1
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be transmitted
 * @return	none
 */
void MUART1_voidTransmit (s8 *Pointer_u8Data);
/**
 * @fn 		void MUART1_voidReceive (s8*)
 * @brief 	This function responsible of Receiving the data from UART1
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by polling
 * @return	none
 */
void MUART1_voidReceive (s8 *Pointer_s8Data);
/**
 * @fn 		u8 MUART1_u8ReceiveWithoutBlocking (s8*)
 * @brief 	This function responsible of Receiving the data from UART1
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by Periodic Check
 * @return	u8 The status if the operation of receiving the past data is finished or not
 */
u8 MUART1_u8ReceiveWithoutBlocking (s8 *Pointer_s8Data);
/**
 * @fn 		void MUART1_voidTransmitCharacter (u8)
 * @brief 	This function responsible of Transmitting the data from UART1
 * @param 	Copy_u8Character Copy of the 8-bit unsigned data which will be transmitted
 * @return	none
 */
void MUART1_voidTransmitCharacter (u8 Copy_u8Character);
/**
 * @fn 		void MUART1_voidEnable (void)
 * @brief 	This function responsible of Enabling the interrupt of UART1
 * @param 	none
 * @return	none
 */
void MUART1_voidEnable (void);
/**
 * @fn 		void MUART1_voidDisable (void)
 * @brief 	This function responsible of Disabling the interrupt of UART1
 * @param 	none
 * @return	none
 */
void MUART1_voidDisable (void);
/**
 * @fn 		void MUART1_voidCallBack(pf)
 * @brief 	This function responsible of assigning the address of the callback function to the pointer which will be called when the interrupt of Uart1 occurred
 * @param 	pfCallBack Copy of the address of the function that will be called when the UART1 interrupt occurred
 * @return	none
 */
void MUART1_voidCallBack (pf pfCallBack);
/**
 * @fn 		void MUART2_voidInit(void)
 * @brief 	This function responsible of Initializing UART2
 * @param 	none
 * @return	none
 */
void MUART2_voidInit (void);
/**
 * @fn 		void MUART2_voidTransmit (s8*)
 * @brief 	This function responsible of Transmitting the data from UART2
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be transmitted
 * @return	none
 */
void MUART2_voidTransmit (s8 *Pointer_u8Data);
/**
 * @fn 		void MUART2_voidReceive (s8*)
 * @brief 	This function responsible of Receiving the data from UART2
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by polling
 * @return	none
 */
void MUART2_voidReceive (s8 *Pointer_s8Data);
/**
 * @fn 		u8 MUART2_u8ReceiveWithoutBlocking (s8*)
 * @brief 	This function responsible of Receiving the data from UART2
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by Periodic Check
 * @return	u8 The status if the operation of receiving the past data is finished or not
 */
u8 MUART2_u8ReceiveWithoutBlocking (s8 *Pointer_s8Data);
/**
* @fn 		void MUART2_voidTransmitCharacter(u8)
* @brief 	This function responsible of Transmitting the data from UART2
* @param 	Copy_u8Character Copy of the 8-bit unsigned data which will be transmitted
* @return	none
*/
void MUART2_voidTransmitCharacter (u8 Copy_u8Character);
/**
 * @fn 		void MUART2_voidEnable (void)
 * @brief 	This function responsible of Enabling the interrupt of UART2
 * @param 	none
 * @return	none
 */
void MUART2_voidEnable (void);
/**
 * @fn 		void MUART2_voidDisable (void)
 * @brief 	This function responsible of Disabling the interrupt of UART2
 * @param 	none
 * @return	none
 */
void MUART2_voidDisable (void);
/**
 * @fn 		void MUART2_voidCallBack (pf)
 * @brief 	This function responsible of assigning the address of the callback function to the pointer which will be called when the interrupt of Uart2 occurred
 * @param 	pfCallBack Copy of the address of the function that will be called when the UART2 interrupt occurred
 * @return	none
 */
void MUART2_voidCallBack (pf pfCallBack);
/**
 * @fn 		void MUART6_voidInit(void)
 * @brief 	This function responsible of Initializing UART6
 * @param 	none
 * @return	none
 */
void MUART6_voidInit (void);
/**
 * @fn 		void MUART6_voidTransmit (s8*)
 * @brief 	This function responsible of Transmitting the data from UART6
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be transmitted
 * @return	none
 */
void MUART6_voidTransmit (s8 *Pointer_u8Data);
/**
 * @fn 		void MUART6_voidReceive (s8*)
 * @brief 	This function responsible of Receiving the data from UART6
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by polling
 * @return	none
 */
void MUART6_voidReceive (s8 *Pointer_s8Data);
/**
 * @fn 		u8 MUART6_u8ReceiveWithoutBlocking (s8*)
 * @brief 	This function responsible of Receiving the data from UART6
 * @param 	Pointer_s8Data pointer to 8-Bit Signed data which will be Received by Periodic Check
 * @return	u8 The status if the operation of receiving the past data is finished or not
 */
u8 MUART6_u8ReceiveWithoutBlocking (s8 *Pointer_s8Data);
/**
 * @fn 		void MUART6_voidTransmitCharacter (u8)
 * @brief 	This function responsible of Transmitting the data from UART6
 * @param 	Copy_u8Character Copy of the 8-bit unsigned data which will be transmitted
 * @return	none
 */
void MUART6_voidTransmitCharacter (u8 Copy_u8Character);
/**
 * @fn 		void MUART6_voidEnable (void)
 * @brief 	This function responsible of Enabling the interrupt of UART6
 * @param 	none
 * @return	none
 */
void MUART6_voidEnable (void);
/**
 * @fn 		void MUART6_voidDisable (void)
 * @brief 	This function responsible of Disabling the interrupt of UART6
 * @param 	none
 * @return	none
 */
void MUART6_voidDisable (void);
/**
 * @fn 		void MUART6_voidCallBack (pf)
 * @brief 	This function responsible of assigning the address of the callback function to the pointer which will be called when the interrupt of Uart6 occurred
 * @param 	pfCallBack Copy of the address of the function that will be called when the UART6 interrupt occurred
 * @return	none
 */
void MUART6_voidCallBack (pf pfCallBack);




/* Oversampling mode */
#define MUART_OVERSAMPLING_BY_16					0           //!< Oversampling is 16 bit an option for @ref MUART1_OVERSAMPLING @ref MUART2_OVERSAMPLING @ref MUART6_OVERSAMPLING
#define MUART_OVERSAMPLING_BY_8 					1           //!< Oversampling is 8 bit an option for @ref MUART1_OVERSAMPLING @ref MUART2_OVERSAMPLING @ref MUART6_OVERSAMPLING

/* Data length */
#define MUART_DATA_8BITS							0           //!< The size of Transferring data at one time is 8 bit an option for @ref MUART1_DATA_LENGTH @ref MUART2_DATA_LENGTH @ref MUART3_DATA_LENGTH
#define MUART_DATA_9BITS							1           //!< The size of Transferring data at one time is 8 bit an option for @ref MUART1_DATA_LENGTH @ref MUART2_DATA_LENGTH @ref MUART6_DATA_LENGTH

/* Parity mode */
#define MUART_PARITY_DISABLE						0           //!< Disabling the Parity Check is an option for @ref MUART1_PARITY_MODE @ref MUART2_PARITY_MODE @ref MUART6_PARITY_MODE
#define MUART_PARITY_ENABLE							1           //!< Enabling the Parity Check  is an option for @ref MUART1_PARITY_MODE @ref MUART2_PARITY_MODE @ref MUART6_PARITY_MODE

/* Parity selection */
#define MUART_EVEN_PARITY							0           //!< Checking for even  Parity Check is an option for @ref MUART1_PARITY_SELECTION @ref MUART2_PARITY_SELECTION @ref MUART6_PARITY_SELECTION
#define MUART_ODD_PARITY							1           //!< Checking for odd  Parity Check is an option for @ref MUART1_PARITY_SELECTION @ref MUART2_PARITY_SELECTION @ref MUART6_PARITY_SELECTION

/* Interrupt state */
#define MUART_DISABLE_INTERRUPT						0           //!< Disabling the Interrupt of Transferring data is an option for @ref MUART1_TRANSMISSION_COMPELETE_INTERRUPT @ref MUART2_TRANSMISSION_COMPELETE_INTERRUPT @ref MUART6_TRANSMISSION_COMPELETE_INTERRUPT @ref MUART1_READ_DATA_REGISTER_EMPTY_INTERRUPT @ref MUART2_READ_DATA_REGISTER_EMPTY_INTERRUPT @ref MUART6_READ_DATA_REGISTER_EMPTY_INTERRUPT
#define MUART_ENABLE_INTERRUPT						1           //!< Enabling the Interrupt of Transferring data is an option for @ref MUART1_TRANSMISSION_COMPELETE_INTERRUPT @ref MUART2_TRANSMISSION_COMPELETE_INTERRUPT @ref MUART6_TRANSMISSION_COMPELETE_INTERRUPT @ref MUART1_READ_DATA_REGISTER_EMPTY_INTERRUPT @ref MUART2_READ_DATA_REGISTER_EMPTY_INTERRUPT @ref MUART6_READ_DATA_REGISTER_EMPTY_INTERRUPT

/* Transmitter & Receiver enable */
#define MUART_DISABLE								0           //!< Disabling The transmitter or receiver is an option for @ref MUART1_TRANSMITTER_ENABLE	 @ref MUART2_TRANSMITTER_ENABLE	 @ref MUART6_TRANSMITTER_ENABLE	@ref MUART1_RECEIVER_ENABLE @ref MUART2_TRECEIVER_ENABLE @ref MUART6_RECEIVER_ENABLE
#define MUART_ENABLE								1           //!< Enabling The transmitter or receiver is an option for @ref MUART1_TRANSMITTER_ENABLE	 @ref MUART2_TRANSMITTER_ENABLE	 @ref MUART6_TRANSMITTER_ENABLE	@ref MUART1_RECEIVER_ENABLE @ref MUART2_TRECEIVER_ENABLE @ref MUART6_RECEIVER_ENABLE

/* Stop bits */
#define MUART_ONE_STOP_BIT		                	0            //!< TheNumber of Stop bits  is 1 bit an option for @ref MUART1_STOP_BITS@ref MUART2_STOP_BITS @ref MUART6_STOP_BITS
#define MUART_HALF_STOP_BIT                      	1            //!< TheNumber of Stop bits  is Half bit an option for @ref MUART1_STOP_BITS@ref MUART2_STOP_BITS @ref MUART6_STOP_BITS
#define MUART_TWO_STOP_BIT							2            //!< TheNumber of Stop bits  is 2 bits an option for @ref MUART1_STOP_BITS@ref MUART2_STOP_BITS @ref MUART6_STOP_BITS
#define MUART_ONE_AND_HALF_STOP_BIT					3            //!< TheNumber of Stop bits  is one and half  bits an option for @ref MUART1_STOP_BITS@ref MUART2_STOP_BITS @ref MUART6_STOP_BITS

#endif
