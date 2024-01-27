/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : NVIC                   ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 11 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/NVIC/NVIC_interface.h"
#include "MCAL/NVIC/NVIC_private.h"
#include "MCAL/NVIC/NVIC_config.h"

static u8 Global_u8IPR;

void NVIC_voidEnablePeripheralInterrupt (u8 Copy_u8Peripheral)
{
	/* Set enable bit of the peripheral */
	SET_BIT((NVIC->ISER[Copy_u8Peripheral/REG_SIZE]), (Copy_u8Peripheral%REG_SIZE));
}

void NVIC_voidDisablePeripheralInterrupt (u8 Copy_u8Peripheral)
{
	/* Set disable bit of the peripheral */
	SET_BIT((NVIC->ICER[Copy_u8Peripheral/REG_SIZE]), (Copy_u8Peripheral%REG_SIZE));
}

void NVIC_voidEnablePeripheralInterruptPending (u8 Copy_u8Peripheral)
{
	/* Set enable pending bit of the peripheral */
	SET_BIT((NVIC->ISPR[Copy_u8Peripheral/REG_SIZE]), (Copy_u8Peripheral%REG_SIZE));
}

void NVIC_voidDisablePeripheralInterruptPending (u8 Copy_u8Peripheral)
{
	/* Set disable pending bit of the peripheral */
	SET_BIT((NVIC->ICPR[Copy_u8Peripheral/REG_SIZE]), (Copy_u8Peripheral%REG_SIZE));
}

void NVIC_voidIsPeripheralInterruptActive (u8 Copy_u8Peripheral, u8 *Pointer_u8Read)
{
	/* Get reading from the interrupt active flag of the peripheral */
	*Pointer_u8Read = GET_BIT((NVIC->IABR[Copy_u8Peripheral/REG_SIZE]), (Copy_u8Peripheral%REG_SIZE));
}

void NVIC_voidSetInterruptGroupMode (u8 Copy_u8GroupMode)
{
	/* Store the NVIC_GroupMode in static global variable */
	Global_u8IPR = Copy_u8GroupMode;
	/* Set NVIC_GroupMode in AIRCR register while masking other bits */
	SCB_AIRCR = (NVIC_VECTKEY | (Copy_u8GroupMode << NVIC_PRIGROUP_SHIFT));
}


void NVIC_voidSetInterruptPriority (u8 Copy_u8Peripheral, u8 Copy_u8NVIC_Group, u8 Copy_u8SubGroup)
{
	/* Switching on NVIC_GroupMode */
	switch (Global_u8IPR)
	{
	/* Set NVIC_Group and sub NVIC_Group priority to NVIC_Group16Sub0 (16 NVIC_Groups - 0 SubNVIC_Groups) */
	case NVIC_GROUP16SUB0: NVIC->IPR[Copy_u8Peripheral] = Copy_u8NVIC_Group << 4; break;
	/* Set NVIC_Group and sub NVIC_Group priority to NVIC_Group8Sub2 (8 NVIC_Groups - 2 SubNVIC_Groups) */
	case NVIC_GROUP8SUB2 : NVIC->IPR[Copy_u8Peripheral] = Copy_u8NVIC_Group << 5 | Copy_u8SubGroup << 4; break;
	/* Set NVIC_Group and sub NVIC_Group priority to NVIC_Group4Sub4 (4 NVIC_Groups - 4 SubNVIC_Groups) */
	case NVIC_GROUP4SUB4 : NVIC->IPR[Copy_u8Peripheral] = Copy_u8NVIC_Group << 6 | Copy_u8SubGroup << 4; break;
	/* Set NVIC_Group and sub NVIC_Group priority to NVIC_Group2Sub8 (2 NVIC_Groups - 8 SubNVIC_Groups) */
	case NVIC_GROUP2SUB8 : NVIC->IPR[Copy_u8Peripheral] = Copy_u8NVIC_Group << 7 | Copy_u8SubGroup << 4; break;
	/* Set NVIC_Group and sub NVIC_Group priority to NVIC_Group0Sub16 (0 NVIC_Groups - 16 SubNVIC_Groups) */
	case NVIC_GROUP0SUB16: NVIC->IPR[Copy_u8Peripheral] = Copy_u8SubGroup << 4; break;
	default: break;
	}
}
