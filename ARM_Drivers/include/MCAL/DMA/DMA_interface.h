/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : DMA                    ***********************/
/***********************            Version : 1.5                    ***********************/
/***********************            Date    : 27 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

void DMA1_voidSetStreamConfigurations (u8 Copy_u8StreamID, u8 Copy_u8ChannelID, u32 *Pointer_u32SourceAddress, u32 *Pointer_u32DestinationAddress, u8 Copy_u8ElementSize, u16 Copy_u16BlockSize);
void DMA1_voidSetCallBack (u8 Copy_u8StreamID, pf pfCallBackFunctions);
void DMA1_voidEnableStream (u8 Copy_u8StreamID);
void DMA1_voidDisableStream (u8 Copy_u8StreamID);

void DMA2_voidSetStreamConfigurations (u8 Copy_u8StreamID, u8 Copy_u8ChannelID, u32 *Pointer_u32SourceAddress, u32 *Pointer_u32DestinationAddress, u8 Copy_u8ElementSize, u16 Copy_u16BlockSize);
void DMA2_voidSetCallBack (u8 Copy_u8StreamID, pf pfCallBackFunctions);
void DMA2_voidEnableStream (u8 Copy_u8StreamID);
void DMA2_voidDisableStream (u8 Copy_u8StreamID);

/* DMA Streams */
#define DMA_STREAM0									0
#define DMA_STREAM1									1
#define DMA_STREAM2									2
#define DMA_STREAM3                                	3
#define DMA_STREAM4                                	4
#define DMA_STREAM5                                	5
#define DMA_STREAM6                                	6
#define DMA_STREAM7                                	7


/* DMA Channels */
#define DMA_CHANNEL0								0
#define DMA_CHANNEL1								1
#define DMA_CHANNEL2								2
#define DMA_CHANNEL3                                3
#define DMA_CHANNEL4                                4
#define DMA_CHANNEL5                                5
#define DMA_CHANNEL6                                6
#define DMA_CHANNEL7                                7

/* Memory & Peripheral Burst */
#define DMA_SINGLE                            		0
#define DMA_INCR4                            		1
#define DMA_INCR8                            		2
#define DMA_INCR16                            		3

/* Double Buffer Mode */
#define DMA_DBM_DISABLE                             0
#define DMA_DBM_ENABLE                              1

/* Target Memory */
#define DMA_MEMORY0                                 0
#define DMA_MEMORY1                                 1

/* Priority Levels */
#define DMA_PRIORITY_LOW                            0
#define DMA_PRIORITY_MEDIUM                         1
#define DMA_PRIORITY_HIGH                           2
#define DMA_PRIORITY_VERY_HIGH                      3

/* Increment Mode for Memory and Peripheral */
#define DMA_FIXED									0
#define DMA_INCREMENTAL								1

/* Peripheral increment offset size */
#define DMA_LINKED_TO_PSIZE							0
#define DMA_4BYTES_OFFSET							1

/* Memory and Peripheral data size */
#define DMA_ELEMENT_BYTE							0
#define DMA_ELEMENT_HALF_WORD						1
#define DMA_ELEMENT_WORD							2

/* Circular mode */
#define DMA_CIRCULAR_DISABLE						0
#define DMA_CIRCULAR_ENABLE							1

/* Data transfer direction */
#define DMA_PERIPHERAL_TO_MEMORY					0
#define DMA_MEMORY_TO_PERIPHERAL					1
#define DMA_MEMORY_TO_MEMORY						2

/* Interrupt */
#define DMA_INTERRUPT_OFF							0
#define DMA_INTERRUPT_ON							1

/* Peripheral flow controller */
#define DMA_HAS_FLOW_CONTROLLER						0
#define DMA_PERIPHERAL_HAS_FLOW_CONTROLLER			1

/* Direct mode */
#define DMA_DIRECT_MODE_ENABLE						0
#define DMA_DIRECT_MODE_DISABLE						1

/* FIFO threshold selection */
#define DMA_QUARTER_FIFO							0
#define DMA_HALF_FIFO								1
#define DMA_THREE_QUARTERS_FIFO						2
#define DMA_FULL_FIFO								3

#endif
