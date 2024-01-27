/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : FMI                    ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 10 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/FMI/FMI_interface.h"
#include "MCAL/FMI/FMI_private.h"
#include "MCAL/FMI/FMI_config.h"

void FMI_voidEraseAppArea (u8 Local_u8BankNumber)
{
	u8 Local_u8Iterator;
	if (Local_u8BankNumber == FMI_BANK1)
	{
		for (Local_u8Iterator = 1; Local_u8Iterator < FMI_SECTOR5; Local_u8Iterator++)
		{
			FMI_voidEraseSector (Local_u8Iterator);
		}
	}
	else if (Local_u8BankNumber == FMI_BANK2)
	{
		FMI_voidEraseSector(FMI_SECTOR5);
	}
}

void FMI_voidEraseSector (u8 Copy_u8SectorIndex)
{
	if ((FMI_SECTOR5 < Copy_u8SectorIndex) || (FMI_SECTOR0 == Copy_u8SectorIndex))
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

void FMI_voidFlashWrite (u32 Copy_u32Address, u16 *Pointer_u16Arr, u8 Copy_u8DataLength)
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
		FMI->CR |=  (FMI_PSIZE << CR_PSIZE);

		for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataLength; Local_u8Iterator++)
		{
			/* Enable programming */
			SET_BIT(FMI->CR, CR_PG);
			/* Program the address */
#if FMI_PSIZE_BYTE == FMI_PSIZE
			*((volatile u8 *)Copy_u32Address) = Pointer_u16Arr[Local_u8Iterator];
			Copy_u32Address += 1;
#elif FMI_PSIZE_HALF_WORD == FMI_PSIZE
			*((volatile u16 *)Copy_u32Address) = Pointer_u16Arr[Local_u8Iterator];
			Copy_u32Address += 2;
#elif FMI_PSIZE_WORD == FMI_PSIZE
			*((volatile u32 *)Copy_u32Address) = Pointer_u16Arr[Local_u8Iterator];
			Copy_u32Address += 4;
#elif FMI_PSIZE_DOUBLE_WORD == FMI_PSIZE
			*((volatile u64 *)Copy_u32Address) = Pointer_u16Arr[Local_u8Iterator];
			Copy_u32Address += 8;
#else
#error "Wrong PSIZE configuration, check include/MCAL/FMI/FMI_config.h"
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
