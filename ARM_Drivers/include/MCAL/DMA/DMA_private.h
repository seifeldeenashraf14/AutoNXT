/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : DMA                    ***********************/
/***********************            Version : 1.5                    ***********************/
/***********************            Date    : 27 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

#define DMA1_BASE_ADDRESS						(0x40026000)
#define DMA2_BASE_ADDRESS						(0x40026400)

typedef struct
{
	volatile u32 SxCR;
	volatile u32 SxNDTR;
	volatile u32 SxPAR;
	volatile u32 SxM0AR;
	volatile u32 SxM1AR;
	volatile u32 SxFCR;
}tstrDMAStream;

typedef struct
{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	volatile tstrDMAStream tstrStream[8];
}tstrDMA;

#define DMA1								((volatile tstrDMA *) DMA1_BASE_ADDRESS)
#define DMA2								((volatile tstrDMA *) DMA2_BASE_ADDRESS)

/* LIFCR bits */
#define LIFCR_CFEIF0						0
#define LIFCR_CDMEIF0                       2
#define LIFCR_CTEIF0                        3
#define LIFCR_CHTIF0                        4
#define LIFCR_CTCIF0                        5
#define LIFCR_CFEIF1                        6
#define LIFCR_CDMEIF1                       8
#define LIFCR_CTEIF1                        9
#define LIFCR_CHTIF1                        10
#define LIFCR_CTCIF1                        11
#define LIFCR_CFEIF2                        16
#define LIFCR_CDMEIF2                       18
#define LIFCR_CTEIF2                        19
#define LIFCR_CHTIF2                        20
#define LIFCR_CTCIF2                        21
#define LIFCR_CFEIF3                        22
#define LIFCR_CDMEIF3                       24
#define LIFCR_CTEIF3                        25
#define LIFCR_CHTIF3                        26
#define LIFCR_CTCIF3                        27

/* HIFCR bits */
#define HIFCR_CFEIF4						0
#define HIFCR_CDMEIF4                       2
#define HIFCR_CTEIF4                        3
#define HIFCR_CHTIF4                        4
#define HIFCR_CTCIF4                        5
#define HIFCR_CFEIF5                        6
#define HIFCR_CDMEIF5                       8
#define HIFCR_CTEIF5                        9
#define HIFCR_CHTIF5                        10
#define HIFCR_CTCIF5                        11
#define HIFCR_CFEIF6                        16
#define HIFCR_CDMEIF6                       18
#define HIFCR_CTEIF6                        19
#define HIFCR_CHTIF6                        20
#define HIFCR_CTCIF6                        21
#define HIFCR_CFEIF7                        22
#define HIFCR_CDMEIF7                       24
#define HIFCR_CTEIF7                        25
#define HIFCR_CHTIF7                        26
#define HIFCR_CTCIF7                        27

/* SxCR bits */
#define SxCR_RESET_VALUE					0x00000000
#define SxCR_CHSEL0							25
#define SxCR_MBURST0						23
#define SxCR_PBURST0						21
#define SxCR_CT								19
#define SxCR_DBM							18
#define SxCR_PL0							16
#define SxCR_PINCOS							15
#define SxCR_MSIZE0							13
#define SxCR_PSIZE0							11
#define SxCR_MINC							10
#define SxCR_PINC							9
#define SxCR_CIRC                           8
#define SxCR_DIR0                           6
#define SxCR_PFCTRL                         5
#define SxCR_TCIE                           4
#define SxCR_HTIE                           3
#define SxCR_TEIE                           2
#define SxCR_DMEIE							1
#define SxCR_EN								0

/* SxFCR bits */
#define SxFCR_RESET_VALUE					0x00000021
#define SxFCR_FEIE                          7
#define SxFCR_FS                            3
#define SxFCR_DMDIS                         2
#define SxFCR_FTH							0

#define MASK_2_BITS							0b11
#define MASK_3_BITS							0b111
#define MASK_7_BITS							0b1111111

#define INTERRUPT_FLAGS_RESET_VALUE			0xFFFFFFFF

#endif
