/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : UART                   ***********************/
/***********************            Version : 2.0                    ***********************/
/***********************            Date    : 17 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
/*************************/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit (void);
void UART_voidTransmit (s8 *Pointer_s8Data);
void UART_voidReceive (s8 *Pointer_s8Data);
u8 UART_u8ReceiveWithoutBlocking (s8 *Pointer_s8Data);
void UART_voidEnable (void);
void UART_voidDisable (void);
void UART_voidCallBack (pf pfCallBack);

/* Oversampling mode */
#define UART_OVERSAMPLING_BY_16					0
#define UART_OVERSAMPLING_BY_8 					1

/* Data length */
#define UART_DATA_8BITS							0
#define UART_DATA_9BITS							1

/* Parity mode */
#define UART_PARITY_DISABLE						0
#define UART_PARITY_ENABLE						1

/* Parity selection */
#define UART_EVEN_PARITY						0
#define UART_ODD_PARITY							1

/* Interrupt state */
#define UART_DISABLE_INTERRUPT					0
#define UART_ENABLE_INTERRUPT					1

/* Transmitter & Receiver enable */
#define UART_DISABLE							0
#define UART_ENABLE								1

/* Stop bits */
#define UART_ONE_STOP_BIT		                0
#define UART_HALF_STOP_BIT                      1
#define UART_TWO_STOP_BIT						2
#define UART_ONE_AND_HALF_STOP_BIT				3

#endif
