/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : FMI                    ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 10 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef FMI_INTERFACE_H_
#define FMI_INTERFACE_H_

void FMI_voidEraseAppArea (void);
void FMI_voidEraseSector (u8 Copy_u8SectorIndex);
void FMI_voidFlashWrite (u32 Copy_u32Address, u16 *Pointer_u16Arr, u8 Copy_u8DataLength);

#define FMI_SECTOR0								0
#define FMI_SECTOR1								1
#define FMI_SECTOR2								2
#define FMI_SECTOR3								3
#define FMI_SECTOR4								4
#define FMI_SECTOR5								5

#define FMI_PSIZE_BYTE							0
#define FMI_PSIZE_HALF_WORD						1
#define FMI_PSIZE_WORD							2
#define FMI_PSIZE_DOUBLE_WORD					3


#endif
