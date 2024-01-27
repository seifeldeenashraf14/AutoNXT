/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : DMA                    ***********************/
/***********************            Version : 1.5                    ***********************/
/***********************            Date    : 27 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef DMA_CONFIG_H_
#define DMA_CONFIG_H_


/* options:
 * 1- DMA_DBM_DISABLE
 * 2- DMA_DBM_ENABLE
 */
#define DOUBLE_BUFFER_MODE						DMA_DBM_DISABLE

#if DMA_DBM_ENABLE == DOUBLE_BUFFER_MODE
	/* options:
	 * 1- DMA_MEMORY0
	 * 2- DMA_MEMORY1
	 */
	#define FIRST_TARGET_MEMORY					DMA_MEMORY0
#endif

/* options:
 * 1- DMA_PRIORITY_LOW
 * 2- DMA_PRIORITY_MEDIUM
 * 3- DMA_PRIORITY_HIGH
 * 4- DMA_PRIORITY_VERY_HIGH
 */
#define PRIORITY_LEVEL							DMA_PRIORITY_VERY_HIGH

/* options:
 * 1- DMA_FIXED
 * 2- DMA_INCREMENTAL
 */
#define MEMORY_INCREMENT_MODE					DMA_INCREMENTAL

/* options:
 * 1- DMA_FIXED
 * 2- DMA_INCREMENTAL
 */
#define PERIPHERAL_INCREMENT_MODE				DMA_INCREMENTAL

#if DMA_INCREMENTAL == PERIPHERAL_INCREMENT_MODE
	/* options:
	 * 1- DMA_LINKED_TO_PSIZE
	 * 2- DMA_4BYTES_OFFSET
	 */
	#define PERIPHERAL_INCREMENT_OFFSET_SIZE	DMA_LINKED_TO_PSIZE
#endif

/* options:
 * 1- DMA_CIRCULAR_DISABLE
 * 2- DMA_CIRCULAR_ENABLE
 */
#define CIRCULAR_MODE							DMA_CIRCULAR_DISABLE

/* options:
 * 1- DMA_PERIPHERAL_TO_MEMORY
 * 2- DMA_MEMORY_TO_PERIPHERAL
 * 3- DMA_MEMORY_TO_MEMORY
 */
#define DATA_TRANSFER_DIRECTION					DMA_MEMORY_TO_MEMORY

#if DMA_MEMORY_TO_MEMORY != DATA_TRANSFER_DIRECTION
	/* options:
	 * 1- DMA_HAS_FLOW_CONTROLLER
	 * 2- DMA_PERIPHERAL_HAS_FLOW_CONTROLLER
	 */
	#define PERIPHERAL_FLOW_CONTROLLER			DMA_HAS_FLOW_CONTROLLER
#endif

/* options:
 * 1- DMA_INTERRUPT_OFF
 * 2- DMA_INTERRUPT_ON
 */
#define TRANSFER_COMPLETE_INTERRUPT				DMA_INTERRUPT_ON

/* options:
 * 1- DMA_INTERRUPT_OFF
 * 2- DMA_INTERRUPT_ON
 */
#define HALF_TRANSFER_COMPLETE_INTERRUPT		DMA_INTERRUPT_OFF

/* options:
 * 1- DMA_INTERRUPT_OFF
 * 2- DMA_INTERRUPT_ON
 */
#define TRANSFER_ERROR_INTERRUPT				DMA_INTERRUPT_OFF

/* options:
 * 1- DMA_INTERRUPT_OFF
 * 2- DMA_INTERRUPT_ON
 */
#define FIFO_INTERRUPT							DMA_INTERRUPT_OFF

/* options:
 * 1- DMA_DIRECT_MODE_ENABLE
 * 2- DMA_DIRECT_MODE_DISABLE
 */
#define DIRECT_MODE								DMA_DIRECT_MODE_DISABLE


#if DMA_DIRECT_MODE_ENABLE == DIRECT_MODE
	/* options:
	 * 1- DMA_INTERRUPT_OFF
	 * 2- DMA_INTERRUPT_ON
	 */
	#define DIRECT_MODE_ERROR_INTERRUPT			DMA_INTERRUPT_OFF

#elif DMA_DIRECT_MODE_DISABLE == DIRECT_MODE
	/* options:
	 * 1- DMA_SINGLE
	 * 2- DMA_INCR4
	 * 3- DMA_INCR8
	 * 4- DMA_INCR16
	 */
	#define MEMORY_BURST						DMA_SINGLE

	/* options:
	 * 1- DMA_SINGLE
	 * 2- DMA_INCR4
	 * 3- DMA_INCR8
	 * 4- DMA_INCR16
	 */
	#define PERIPHERAL_BURST					DMA_SINGLE

	/* options:
	 * 1- DMA_QUARTER_FIFO
	 * 2- DMA_HALF_FIFO
	 * 3- DMA_THREE_QUARTERS_FIFO
	 * 4- DMA_FULL_FIFO
	 */
	#define FIFO_THRESHOLD						DMA_FULL_FIFO

#endif

#endif
