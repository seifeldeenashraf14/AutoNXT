/**
 * @file	MFMI_interface.h
 * @author 	Hosam Ayoub
 * @version 1.0
 * @date 	10 Oct 2023
 * @brief 	The Flash Memory Interface Header file that has all the prototypes and arguments of **FMI** driver
 */
#ifndef MFMI_INTERFACE_H_
#define MFMI_INTERFACE_H_

/**
 * @fn 		void MFMI_voidEraseSector(u8)
 * @brief   This function is responsible of erasing a single sector of the flash
 * @param 	Copy_u8SectorIndex The sector number that would be erased
 * @return 	none
 */
void MFMI_voidEraseSector (u8 Copy_u8SectorIndex);

/**
 * @fn 		void MFMI_voidEraseAppArea(u8)
 * @brief 	This function responsible of erasing a while bank that is passed to it
 * @param 	Local_u8BankNumber The bank number the would be erased
 * @return	none
 */
void MFMI_voidEraseAppArea (u8 Local_u8BankNumber);

/**
 * @fn 		void MFMI_voidFlashWrite(u32, u16*, u8)
 * @brief 	This function responsible for writing to flash memory for the specified **Copy_u8DataLength** from the **Copy_u32Address**
 * @param 	Copy_u32Address This is that start address from where the **FMI** will start the writing operation
 * @param 	Pointer_u16Arr This is the address of the array that would be written in memory
 * @param 	Copy_u8DataLength This is the length of the array that would be written in memory
 * @return	none
 */
void MFMI_voidFlashWrite (u32 Copy_u32Address, u16 *Pointer_u16Arr, u8 Copy_u8DataLength);


#define MFMI_SECTOR0								0			//!< SECTOR0 is the argument of @ref MFMI_voidEraseSector
#define MFMI_SECTOR1								1			//!< SECTOR1 is the argument of @ref MFMI_voidEraseSector
#define MFMI_SECTOR2								2			//!< SECTOR2 is the argument of @ref MFMI_voidEraseSector
#define MFMI_SECTOR3								3			//!< SECTOR3 is the argument of @ref MFMI_voidEraseSector
#define MFMI_SECTOR4								4			//!< SECTOR4 is the argument of @ref MFMI_voidEraseSector
#define MFMI_SECTOR5								5			//!< SECTOR5 is the argument of @ref MFMI_voidEraseSector

#define MFMI_PSIZE_BYTE								0			//!< Programming size is Byte an option for @ref MFMI_PSIZE
#define MFMI_PSIZE_HALF_WORD						1           //!< Programming size is Half Word an option for @ref MFMI_PSIZE
#define MFMI_PSIZE_WORD								2           //!< Programming size is Word an option for @ref MFMI_PSIZE
#define MFMI_PSIZE_DOUBLE_WORD						3           //!< Programming size is Double Word an option for @ref MFMI_PSIZE

#define MFMI_BANK1									1           //!< It is the argument of @ref MFMI_voidEraseAppArea
#define MFMI_BANK2									2           //!< It is the argument of @ref MFMI_voidEraseAppArea


#endif
