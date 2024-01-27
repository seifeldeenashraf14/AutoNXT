/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : DMA                    ***********************/
/***********************            Version : 1.5                    ***********************/
/***********************            Date    : 27 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DMA/DMA_interface.h"
#include "MCAL/DMA/DMA_private.h"
#include "MCAL/DMA/DMA_config.h"

pf Global_pfNotificationFunctionDMA1[8] = {NULL}, Global_pfNotificationFunctionDMA2[8] = {NULL};

void DMA1_voidSetStreamConfigurations (u8 Copy_u8StreamID, u8 Copy_u8ChannelID, u32 *Pointer_u32SourceAddress, u32 *Pointer_u32DestinationAddress, u8 Copy_u8ElementSize, u16 Copy_u16BlockSize)
{
	if (Copy_u8StreamID < 8)
	{
		if (Copy_u8ChannelID < 8)
		{
			/* Clear low interrupt flags */
			DMA1->LIFCR = INTERRUPT_FLAGS_RESET_VALUE;
			/* Clear high interrupt flags */
			DMA1->HIFCR = INTERRUPT_FLAGS_RESET_VALUE;

			/* Reset SxCR register */
			DMA1->tstrStream[Copy_u8StreamID].SxCR = SxCR_RESET_VALUE;
			/* Channel selection */
			DMA1->tstrStream[Copy_u8StreamID].SxCR |= (Copy_u8ChannelID << SxCR_CHSEL0);

			/* Select Double buffer mode */
			DMA1->tstrStream[Copy_u8StreamID].SxCR |= (DOUBLE_BUFFER_MODE << SxCR_DBM);

			#if DMA_DBM_ENABLE == DOUBLE_BUFFER_MODE
				/* Select Current Memory Target */
				DMA1->tstrStream[Copy_u8StreamID].SxCR |= (FIRST_TARGET_MEMORY << SxCR_CT);
			#endif

			/* Set Priority Level */
			DMA1->tstrStream[Copy_u8StreamID].SxCR |= (PRIORITY_LEVEL << SxCR_PL0);
			/* Peripheral increment offset size */
			DMA1->tstrStream[Copy_u8StreamID].SxCR |= (PERIPHERAL_INCREMENT_MODE << SxCR_PINC);

			#if DMA_INCREMENTAL == PERIPHERAL_INCREMENT_MODE
				/* Set increment step size */
				DMA1->tstrStream[Copy_u8StreamID].SxCR |= (PERIPHERAL_INCREMENT_OFFSET_SIZE << SxCR_PINCOS);
			#endif

			/* Memory increment mode */
			DMA1->tstrStream[Copy_u8StreamID].SxCR |= (MEMORY_INCREMENT_MODE << SxCR_MINC);
			/* Circular mode */
			DMA1->tstrStream[Copy_u8StreamID].SxCR |= (CIRCULAR_MODE << SxCR_CIRC);
			/* Data transfer direction */
			DMA1->tstrStream[Copy_u8StreamID].SxCR |= (DATA_TRANSFER_DIRECTION << SxCR_DIR0);
			#if DMA_MEMORY_TO_MEMORY != DATA_TRANSFER_DIRECTION
				/* Peripheral flow controller */
				DMA1->tstrStream[Copy_u8StreamID].SxCR |= (PERIPHERAL_FLOW_CONTROLLER << SxCR_PFCTRL);
			#endif
			/* Transfer complete interrupt */
			DMA1->tstrStream[Copy_u8StreamID].SxCR |= (TRANSFER_COMPLETE_INTERRUPT << SxCR_TCIE);
			/* Half Transfer complete interrupt */
			DMA1->tstrStream[Copy_u8StreamID].SxCR |= (HALF_TRANSFER_COMPLETE_INTERRUPT << SxCR_HTIE);
			/* Transfer error interrupt */
			DMA1->tstrStream[Copy_u8StreamID].SxCR |= (TRANSFER_ERROR_INTERRUPT << SxCR_TEIE);

			/* Set The block size for the corresponding StreamID */
			DMA1->tstrStream[Copy_u8StreamID].SxNDTR = Copy_u16BlockSize;

			#if DMA_PERIPHERAL_TO_MEMORY == DATA_TRANSFER_DIRECTION
				/* Set the Source address */
				DMA1->tstrStream[Copy_u8StreamID].SxPAR = Pointer_u32SourceAddress;
				/* Set the destination address */
				DMA1->tstrStream[Copy_u8StreamID].SxM0AR = Pointer_u32DestinationAddress;
			#elif DMA_MEMORY_TO_PERIPHERAL == DATA_TRANSFER_DIRECTION
				/* Set the Source address */
				DMA1->tstrStream[Copy_u8StreamID].SxPAR = Pointer_u32DestinationAddress;
				/* Set the destination address */
				DMA1->tstrStream[Copy_u8StreamID].SxM0AR = Pointer_u32SourceAddress;
			#elif DMA_MEMORY_TO_MEMORY == DATA_TRANSFER_DIRECTION
				/* Set the Source address */
				DMA1->tstrStream[Copy_u8StreamID].SxPAR = Pointer_u32SourceAddress;
				/* Set the destination address */
				DMA1->tstrStream[Copy_u8StreamID].SxM0AR = Pointer_u32DestinationAddress;
			#else
				#error "Wrong configurations.\nCheck DATA_TRANSFER_DIRECTION in MCAL/DMA/DMA_config"
			#endif

			/* Reset SxFCR register */
			DMA1->tstrStream[Copy_u8StreamID].SxFCR = SxFCR_RESET_VALUE;
			/* FIFO error interrupt */
			DMA1->tstrStream[Copy_u8StreamID].SxFCR |= (FIFO_INTERRUPT << SxFCR_FEIE);
			#if DMA_DIRECT_MODE_ENABLE == DIRECT_MODE
				/* Direct mode error interrupt */
				DMA1->tstrStream[Copy_u8StreamID].SxCR |= (DIRECT_MODE_ERROR_INTERRUPT << SxCR_DMEIE);
				/* Direct mode */
				DMA1->tstrStream[Copy_u8StreamID].SxFCR |= (DIRECT_MODE << SxFCR_DMDIS);
			#elif DMA_DIRECT_MODE_DISABLE == DIRECT_MODE
				/* Memory burst transfer configuration */
				DMA1->tstrStream[Copy_u8StreamID].SxCR |= (MEMORY_BURST << SxCR_MBURST0);
				/* Peripheral burst transfer configuration */
				DMA1->tstrStream[Copy_u8StreamID].SxCR |= (PERIPHERAL_BURST << SxCR_PBURST0);
				/* Set Memory data size */
				DMA1->tstrStream[Copy_u8StreamID].SxCR |= (Copy_u8ElementSize << SxCR_MSIZE0);
				/* Set Peripheral data size */
				DMA1->tstrStream[Copy_u8StreamID].SxCR |= (Copy_u8ElementSize << SxCR_PSIZE0);
				/* FIFO threshold selection */
				DMA1->tstrStream[Copy_u8StreamID].SxFCR |= (FIFO_THRESHOLD << SxFCR_FTH);
			#else
				#error "Wrong configurations.\nCheck DIRECT_MODE in MCAL/DMA/DMA_config"
			#endif
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}
}

void DMA1_voidSetCallBack (u8 Copy_u8StreamID, pf pfCallBackFunctions)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != pfCallBackFunctions)
	{
		/* Store the Call back function in the corresponding StreamID */
		Global_pfNotificationFunctionDMA1[Copy_u8StreamID] = pfCallBackFunctions;
	}
	else
	{
		/* Do Nothing */
	}
}

void DMA1_voidEnableStream (u8 Copy_u8StreamID)
{
	/* Stream Enable */
	SET_BIT(DMA1->tstrStream[Copy_u8StreamID].SxCR, SxCR_EN);
}

void DMA1_voidDisableStream (u8 Copy_u8StreamID)
{
	/* Stream Disable */
	SET_BIT(DMA1->tstrStream[Copy_u8StreamID].SxCR, SxCR_EN);
}

void DMA2_voidSetStreamConfigurations (u8 Copy_u8StreamID, u8 Copy_u8ChannelID, u32 *Pointer_u32SourceAddress, u32 *Pointer_u32DestinationAddress, u8 Copy_u8ElementSize, u16 Copy_u16BlockSize)
{
	if (Copy_u8StreamID < 8)
	{
		if (Copy_u8ChannelID < 8)
		{
			/* Clear low interrupt flags */
			DMA2->LIFCR = INTERRUPT_FLAGS_RESET_VALUE;
			/* Clear high interrupt flags */
			DMA2->HIFCR = INTERRUPT_FLAGS_RESET_VALUE;

			/* Reset SxCR register */
			DMA2->tstrStream[Copy_u8StreamID].SxCR = SxCR_RESET_VALUE;
			/* Channel selection */
			DMA2->tstrStream[Copy_u8StreamID].SxCR |= (Copy_u8ChannelID << SxCR_CHSEL0);

			/* Select Double buffer mode */
			DMA2->tstrStream[Copy_u8StreamID].SxCR |= (DOUBLE_BUFFER_MODE << SxCR_DBM);

			#if DMA_DBM_ENABLE == DOUBLE_BUFFER_MODE
				/* Select Current Memory Target */
				DMA2->tstrStream[Copy_u8StreamID].SxCR |= (FIRST_TARGET_MEMORY << SxCR_CT);
			#endif

			/* Set Priority Level */
			DMA2->tstrStream[Copy_u8StreamID].SxCR |= (PRIORITY_LEVEL << SxCR_PL0);
			/* Peripheral increment offset size */
			DMA2->tstrStream[Copy_u8StreamID].SxCR |= (PERIPHERAL_INCREMENT_MODE << SxCR_PINC);

			#if DMA_INCREMENTAL == PERIPHERAL_INCREMENT_MODE
				/* Set increment step size */
				DMA2->tstrStream[Copy_u8StreamID].SxCR |= (PERIPHERAL_INCREMENT_OFFSET_SIZE << SxCR_PINCOS);
			#endif

			/* Memory increment mode */
			DMA2->tstrStream[Copy_u8StreamID].SxCR |= (MEMORY_INCREMENT_MODE << SxCR_MINC);
			/* Circular mode */
			DMA2->tstrStream[Copy_u8StreamID].SxCR |= (CIRCULAR_MODE << SxCR_CIRC);
			/* Data transfer direction */
			DMA2->tstrStream[Copy_u8StreamID].SxCR |= (DATA_TRANSFER_DIRECTION << SxCR_DIR0);
			#if DMA_MEMORY_TO_MEMORY != DATA_TRANSFER_DIRECTION
				/* Peripheral flow controller */
				DMA2->tstrStream[Copy_u8StreamID].SxCR |= (PERIPHERAL_FLOW_CONTROLLER << SxCR_PFCTRL);
			#endif
			/* Transfer complete interrupt */
			DMA2->tstrStream[Copy_u8StreamID].SxCR |= (TRANSFER_COMPLETE_INTERRUPT << SxCR_TCIE);
			/* Half Transfer complete interrupt */
			DMA2->tstrStream[Copy_u8StreamID].SxCR |= (HALF_TRANSFER_COMPLETE_INTERRUPT << SxCR_HTIE);
			/* Transfer error interrupt */
			DMA2->tstrStream[Copy_u8StreamID].SxCR |= (TRANSFER_ERROR_INTERRUPT << SxCR_TEIE);

			/* Set The block size for the corresponding StreamID */
			DMA2->tstrStream[Copy_u8StreamID].SxNDTR = Copy_u16BlockSize;

			#if DMA_PERIPHERAL_TO_MEMORY == DATA_TRANSFER_DIRECTION
				/* Set the Source address */
				DMA2->tstrStream[Copy_u8StreamID].SxPAR = Pointer_u32SourceAddress;
				/* Set the destination address */
				DMA2->tstrStream[Copy_u8StreamID].SxM0AR = Pointer_u32DestinationAddress;
			#elif DMA_MEMORY_TO_PERIPHERAL == DATA_TRANSFER_DIRECTION
				/* Set the Source address */
				DMA2->tstrStream[Copy_u8StreamID].SxPAR = Pointer_u32DestinationAddress;
				/* Set the destination address */
				DMA2->tstrStream[Copy_u8StreamID].SxM0AR = Pointer_u32SourceAddress;
			#elif DMA_MEMORY_TO_MEMORY == DATA_TRANSFER_DIRECTION
				/* Set the Source address */
				DMA2->tstrStream[Copy_u8StreamID].SxPAR = Pointer_u32SourceAddress;
				/* Set the destination address */
				DMA2->tstrStream[Copy_u8StreamID].SxM0AR = Pointer_u32DestinationAddress;
			#else
				#error "Wrong configurations.\nCheck DATA_TRANSFER_DIRECTION in MCAL/DMA/DMA_config"
			#endif

			/* Reset SxFCR register */
			DMA2->tstrStream[Copy_u8StreamID].SxFCR = SxFCR_RESET_VALUE;
			/* FIFO error interrupt */
			DMA2->tstrStream[Copy_u8StreamID].SxFCR |= (FIFO_INTERRUPT << SxFCR_FEIE);
			#if DMA_DIRECT_MODE_ENABLE == DIRECT_MODE
				/* Direct mode error interrupt */
				DMA2->tstrStream[Copy_u8StreamID].SxCR |= (DIRECT_MODE_ERROR_INTERRUPT << SxCR_DMEIE);
				/* Direct mode */
				DMA2->tstrStream[Copy_u8StreamID].SxFCR |= (DIRECT_MODE << SxFCR_DMDIS);
			#elif DMA_DIRECT_MODE_DISABLE == DIRECT_MODE
				/* Memory burst transfer configuration */
				DMA2->tstrStream[Copy_u8StreamID].SxCR |= (MEMORY_BURST << SxCR_MBURST0);
				/* Peripheral burst transfer configuration */
				DMA2->tstrStream[Copy_u8StreamID].SxCR |= (PERIPHERAL_BURST << SxCR_PBURST0);
				/* Set Memory data size */
				DMA2->tstrStream[Copy_u8StreamID].SxCR |= (Copy_u8ElementSize << SxCR_MSIZE0);
				/* Set Peripheral data size */
				DMA2->tstrStream[Copy_u8StreamID].SxCR |= (Copy_u8ElementSize << SxCR_PSIZE0);
				/* FIFO threshold selection */
				DMA2->tstrStream[Copy_u8StreamID].SxFCR |= (FIFO_THRESHOLD << SxFCR_FTH);
			#else
				#error "Wrong configurations.\nCheck DIRECT_MODE in MCAL/DMA/DMA_config"
			#endif
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}
}

void DMA2_voidSetCallBack (u8 Copy_u8StreamID, pf pfCallBackFunctions)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != pfCallBackFunctions)
	{
		/* Store the Call back function in the corresponding StreamID */
		Global_pfNotificationFunctionDMA2[Copy_u8StreamID] = pfCallBackFunctions;
	}
	else
	{
		/* Do Nothing */
	}
}

void DMA2_voidEnableStream (u8 Copy_u8StreamID)
{
	/* Stream Enable */
	SET_BIT(DMA2->tstrStream[Copy_u8StreamID].SxCR, SxCR_EN);
}

void DMA2_voidDisableStream (u8 Copy_u8StreamID)
{
	/* Stream Disable */
	SET_BIT(DMA2->tstrStream[Copy_u8StreamID].SxCR, SxCR_EN);
}

void DMA1_Stream0_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA1[0])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA1[0]();
	}
	/* Clear stream 0 FIFO error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CFEIF0);
	/* Clear stream 0 direct mode error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CDMEIF0);
	/* Clear stream 0 transfer error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CTEIF0);
	/* Clear stream 0 half transfer interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CHTIF0);
	/* Clear stream 0 transfer complete interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CTCIF0);
}

void DMA1_Stream1_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA1[1])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA1[1]();
	}
	/* Clear stream 1 FIFO error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CFEIF1);
	/* Clear stream 1 direct mode error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CDMEIF1);
	/* Clear stream 1 transfer error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CTEIF1);
	/* Clear stream 1 half transfer interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CHTIF1);
	/* Clear stream 1 transfer complete interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CTCIF1);
}

void DMA1_Stream2_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA1[2])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA1[2]();
	}
	/* Clear stream 2 FIFO error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CFEIF2);
	/* Clear stream 2 direct mode error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CDMEIF2);
	/* Clear stream 2 transfer error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CTEIF2);
	/* Clear stream 2 half transfer interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CHTIF2);
	/* Clear stream 2 transfer complete interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CTCIF2);
}

void DMA1_Stream3_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA1[3])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA1[3]();
	}
	/* Clear stream 3 FIFO error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CFEIF3);
	/* Clear stream 3 direct mode error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CDMEIF3);
	/* Clear stream 3 transfer error interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CTEIF3);
	/* Clear stream 3 half transfer interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CHTIF3);
	/* Clear stream 3 transfer complete interrupt flag */
	SET_BIT(DMA1->LIFCR, LIFCR_CTCIF3);
}

void DMA1_Stream4_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA1[4])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA1[4]();
	}
	/* Clear stream 4 FIFO error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CFEIF4);
	/* Clear stream 4 direct mode error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CDMEIF4);
	/* Clear stream 4 transfer error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CTEIF4);
	/* Clear stream 4 half transfer interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CHTIF4);
	/* Clear stream 4 transfer complete interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CTCIF4);
}

void DMA1_Stream5_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA1[5])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA1[5]();
	}
	/* Clear stream 5 FIFO error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CFEIF5);
	/* Clear stream 5 direct mode error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CDMEIF5);
	/* Clear stream 5 transfer error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CTEIF5);
	/* Clear stream 5 half transfer interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CHTIF5);
	/* Clear stream 5 transfer complete interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CTCIF5);
}

void DMA1_Stream6_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA1[6])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA1[6]();
	}
	/* Clear stream 6 FIFO error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CFEIF6);
	/* Clear stream 6 direct mode error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CDMEIF6);
	/* Clear stream 6 transfer error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CTEIF6);
	/* Clear stream 6 half transfer interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CHTIF6);
	/* Clear stream 6 transfer complete interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CTCIF6);
}

void DMA1_Stream7_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA1[7])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA1[7]();
	}
	/* Clear stream 7 FIFO error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CFEIF7);
	/* Clear stream 7 direct mode error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CDMEIF7);
	/* Clear stream 7 transfer error interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CTEIF7);
	/* Clear stream 7 half transfer interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CHTIF7);
	/* Clear stream 7 transfer complete interrupt flag */
	SET_BIT(DMA1->HIFCR, HIFCR_CTCIF7);
}


void DMA2_Stream0_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA2[0])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA2[0]();
	}
	/* Clear stream 0 FIFO error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CFEIF0);
	/* Clear stream 0 direct mode error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CDMEIF0);
	/* Clear stream 0 transfer error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CTEIF0);
	/* Clear stream 0 half transfer interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CHTIF0);
	/* Clear stream 0 transfer complete interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CTCIF0);
}

void DMA2_Stream1_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA2[1])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA2[1]();
	}
	/* Clear stream 1 FIFO error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CFEIF1);
	/* Clear stream 1 direct mode error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CDMEIF1);
	/* Clear stream 1 transfer error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CTEIF1);
	/* Clear stream 1 half transfer interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CHTIF1);
	/* Clear stream 1 transfer complete interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CTCIF1);
}

void DMA2_Stream2_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA2[2])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA2[2]();
	}
	/* Clear stream 2 FIFO error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CFEIF2);
	/* Clear stream 2 direct mode error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CDMEIF2);
	/* Clear stream 2 transfer error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CTEIF2);
	/* Clear stream 2 half transfer interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CHTIF2);
	/* Clear stream 2 transfer complete interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CTCIF2);
}

void DMA2_Stream3_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA2[3])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA2[3]();
	}
	/* Clear stream 3 FIFO error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CFEIF3);
	/* Clear stream 3 direct mode error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CDMEIF3);
	/* Clear stream 3 transfer error interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CTEIF3);
	/* Clear stream 3 half transfer interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CHTIF3);
	/* Clear stream 3 transfer complete interrupt flag */
	SET_BIT(DMA2->LIFCR, LIFCR_CTCIF3);
}

void DMA2_Stream4_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA2[4])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA2[4]();
	}
	/* Clear stream 4 FIFO error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CFEIF4);
	/* Clear stream 4 direct mode error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CDMEIF4);
	/* Clear stream 4 transfer error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CTEIF4);
	/* Clear stream 4 half transfer interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CHTIF4);
	/* Clear stream 4 transfer complete interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CTCIF4);
}

void DMA2_Stream5_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA2[5])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA2[5]();
	}
	/* Clear stream 5 FIFO error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CFEIF5);
	/* Clear stream 5 direct mode error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CDMEIF5);
	/* Clear stream 5 transfer error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CTEIF5);
	/* Clear stream 5 half transfer interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CHTIF5);
	/* Clear stream 5 transfer complete interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CTCIF5);
}

void DMA2_Stream6_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA2[6])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA2[6]();
	}
	/* Clear stream 6 FIFO error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CFEIF6);
	/* Clear stream 6 direct mode error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CDMEIF6);
	/* Clear stream 6 transfer error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CTEIF6);
	/* Clear stream 6 half transfer interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CHTIF6);
	/* Clear stream 6 transfer complete interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CTCIF6);
}

void DMA2_Stream7_IRQHandler(void)
{
	/* Check if the pfCallBackFunctions has valid address */
	if (NULL != Global_pfNotificationFunctionDMA2[7])
	{
		/* Execute the corresponding function */
		Global_pfNotificationFunctionDMA2[7]();
	}
	/* Clear stream 7 FIFO error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CFEIF7);
	/* Clear stream 7 direct mode error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CDMEIF7);
	/* Clear stream 7 transfer error interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CTEIF7);
	/* Clear stream 7 half transfer interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CHTIF7);
	/* Clear stream 7 transfer complete interrupt flag */
	SET_BIT(DMA2->HIFCR, HIFCR_CTCIF7);
}
