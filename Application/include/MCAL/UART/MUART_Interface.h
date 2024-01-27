/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : UART                   ***********************/
/***********************            Version : 3.5                    ***********************/
/***********************            Date    : 10 Nov 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
/*************************/
#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_

void MUART1_voidInit (void);
void MUART1_voidTransmit (s8 *Pointer_u8Data);
void MUART1_voidReceive (s8 *Pointer_s8Data);
u8 MUART1_u8ReceiveWithoutBlocking (s8 *Pointer_s8Data);
void MUART1_voidTransmitCharacter (u8 Copy_u8Character);
void MUART1_voidEnable (void);
void MUART1_voidDisable (void);
void MUART1_voidCallBack (pf pfCallBack);

void MUART2_voidInit (void);
void MUART2_voidTransmit (s8 *Pointer_u8Data);
void MUART2_voidReceive (s8 *Pointer_s8Data);
u8 MUART2_u8ReceiveWithoutBlocking (s8 *Pointer_s8Data);
void MUART2_voidTransmitCharacter (u8 Copy_u8Character);
void MUART2_voidEnable (void);
void MUART2_voidDisable (void);
void MUART2_voidCallBack (pf pfCallBack);
void MUART2_voidSendNumbers (u32 A_u32Number);

void MUART6_voidInit (void);
void MUART6_voidTransmit (s8 *Pointer_u8Data);
void MUART6_voidReceive (s8 *Pointer_s8Data);
u8 MUART6_u8ReceiveWithoutBlocking (s8 *Pointer_s8Data);
void MUART6_voidTransmitCharacter (u8 Copy_u8Character);
void MUART6_voidEnable (void);
void MUART6_voidDisable (void);
void MUART6_voidCallBack (pf pfCallBack);

/* Oversampling mode */
#define MUART_OVERSAMPLING_BY_16					0
#define MUART_OVERSAMPLING_BY_8 					1

/* Data length */
#define MUART_DATA_8BITS							0
#define MUART_DATA_9BITS							1

/* Parity mode */
#define MUART_PARITY_DISABLE						0
#define MUART_PARITY_ENABLE							1

/* Parity selection */
#define MUART_EVEN_PARITY							0
#define MUART_ODD_PARITY							1

/* Interrupt state */
#define MUART_DISABLE_INTERRUPT						0
#define MUART_ENABLE_INTERRUPT						1

/* Transmitter & Receiver enable */
#define MUART_DISABLE								0
#define MUART_ENABLE								1

/* Stop bits */
#define MUART_ONE_STOP_BIT		                	0
#define MUART_HALF_STOP_BIT                      	1
#define MUART_TWO_STOP_BIT							2
#define MUART_ONE_AND_HALF_STOP_BIT					3

#endif
