/**
 * @file	MFMI_program.c
 * @author 	Hosam Ayoub
 * @version 1.0
 * @date 	10 Oct 2023
 * @brief 	The Flash Memory Interface C file that has the functions body which is responsible for erasing and writing in the flash
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/FMI/MFMI_interface.h"
#include "MCAL/FMI/MFMI_private.h"
#include "MCAL/FMI/MFMI_config.h"

/**
 * @fn 		void MFMI_voidEraseAppArea(u8)
 * @brief 	This function responsible of erasing a while bank that is passed to it
 * @param 	Local_u8BankNumber The bank number the would be erased
 * @return	none
 * @details This function erase the whole bank by erasing every sector in it one by one
 */
void MFMI_voidEraseAppArea (u8 Local_u8BankNumber)
{
	u8 Local_u8Iterator;
	if (Local_u8BankNumber == MFMI_BANK1)
	{
		for (Local_u8Iterator = 1; Local_u8Iterator < MFMI_SECTOR5; Local_u8Iterator++)
		{
			MFMI_voidEraseSector (Local_u8Iterator);
		}
	}
	else if (Local_u8BankNumber == MFMI_BANK2)
	{
		MFMI_voidEraseSector(MFMI_SECTOR5);
	}
}

/**
 * @fn 		void MFMI_voidEraseSector(u8)
 * @brief   This function is responsible of erasing a single sector of the flash
 * @param 	Copy_u8SectorIndex The sector number that would be erased
 * @return 	none
 * @details This function erase the specified sector using the sequence found on data sheet which is:
 * -# Check that no Flash memory operation is ongoing by checking the BSY bit in the FLASH_SR register
 * -# Set the SER bit and select the sector out of the 5 sectors (for STM32F401xB/C) and out of 7 (for STM32F401xD/E) in the main memory block you wish to erase (SNB) in the FLASH_CR register
 * -# Set the STRT bit in the FLASH_CR register
 * -# Wait for the BSY bit to be cleared
 */
void MFMI_voidEraseSector (u8 Copy_u8SectorIndex)
{
	if ((MFMI_SECTOR5 < Copy_u8SectorIndex) || (MFMI_SECTOR0 == Copy_u8SectorIndex))
	{
		/* Do nothing */
	}
	else
	{
		/* Check if there is a Flash memory operation ongoing */
		while (GET_BIT(FMI->SR, SR_BSY));

		/* Check if the operations was locked */
		if (GET_BIT(FMI->CR, CR_LOCK))
		{
			/* Unlock sequence */
			FMI->KEYR = FMI_KEY1;
			FMI->KEYR = FMI_KEY2;
		}

		/* Set the erase sector */
		FMI->CR &= ~(MASK_4BIT << CR_SNB);
		FMI->CR |=  (Copy_u8SectorIndex << CR_SNB);
		/* Enable sector erase */
		SET_BIT(FMI->CR, CR_SER);
		/* Enable start but */
		SET_BIT(FMI->CR, CR_STRT);
		/* Check if there is a Flash memory operation ongoing */
		while (GET_BIT(FMI->SR, SR_BSY));
		/* Clear end of operations */
		SET_BIT(FMI->SR, SR_EOP);
		/* Disable sector erase */
		CLR_BIT(FMI->CR, CR_SER);
	}

}

/**
 * @fn 		void MFMI_voidFlashWrite(u32, u16*, u8)
 * @brief 	This function responsible for writing to flash memory for the specified **Copy_u8DataLength** from the **Copy_u32Address**
 * @param 	Copy_u32Address This is that start address from where the **FMI** will start the writing operation
 * @param 	Pointer_u16Arr This is the address of the array that would be written in memory
 * @param 	Copy_u8DataLength This is the length of the array that would be written in memory
 * @return	none
 * @details This function write on the specified sector using the sequence found on data sheet which is:
 * -# Check that no main Flash memory operation is ongoing by checking the BSY bit in the FLASH_SR register.
 * -# Set the PG bit in the FLASH_CR register
 * -# Perform the data write operation(s) to the desired memory address (inside main memory block or OTP area):
 * 	- Byte access in case of x8 parallelism
 * 	- Half-word access in case of x16 parallelism
 * 	- Word access in case of x32 parallelism
 * 	- Double word access in case of x64 parallelism
 * -# Wait for the BSY bit to be cleared.
 */
void MFMI_voidFlashWrite (u32 Copy_u32Address, u16 *Pointer_u16Arr, u8 Copy_u8DataLength)
{
	if ((0x0803FFFF < Copy_u32Address) || (0x08004000 > Copy_u32Address))
	{
		/* Do nothing */
	}
	else
	{
		u8 Local_u8Iterator;
		/* Check if there is a Flash memory operation ongoing */
		while (GET_BIT(FMI->SR, SR_BSY));
		/* Check if the operations was locked */
		if (GET_BIT(FMI->CR, CR_LOCK))
		{
			/* Unlock sequence */
			FMI->KEYR = FMI_KEY1;
			FMI->KEYR = FMI_KEY2;
		}
		/* Set programming size */
		FMI->CR &= ~(MASK_2BIT << CR_PSIZE);
		FMI->CR |=  (MFMI_PSIZE << CR_PSIZE);

		for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataLength; Local_u8Iterator++)
		{
			/* Enable programming */
			SET_BIT(FMI->CR, CR_PG);
			/* Program the address */
			#if MFMI_PSIZE_BYTE == MFMI_PSIZE
				*((volatile u8 *)Copy_u32Address) = Pointer_u16Arr[Local_u8Iterator];
				Copy_u32Address += 1;
			#elif MFMI_PSIZE_HALF_WORD == MFMI_PSIZE
				*((volatile u16 *)Copy_u32Address) = Pointer_u16Arr[Local_u8Iterator];
				Copy_u32Address += 2;
			#elif MFMI_PSIZE_WORD == MFMI_PSIZE
				*((volatile u32 *)Copy_u32Address) = Pointer_u16Arr[Local_u8Iterator];
				Copy_u32Address += 4;
			#elif MFMI_PSIZE_DOUBLE_WORD == MFMI_PSIZE
				*((volatile u64 *)Copy_u32Address) = Pointer_u16Arr[Local_u8Iterator];
				Copy_u32Address += 8;
			#else
			#error "Wrong PSIZE configuration, check include/MCAL/FMI/MFMI_config.h"
			#endif
			/* Check if there is a Flash memory operation ongoing */
			while (GET_BIT(FMI->SR, SR_BSY));
			/* Clear end of operations */
			SET_BIT(FMI->SR, SR_EOP);
			/* Disable programming */
			CLR_BIT(FMI->CR, CR_PG);
		}
	}
}
