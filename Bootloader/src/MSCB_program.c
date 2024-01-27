/**
 * @file MSCB_program.c
 * @author Hosam Ayoub
 * @version 1.0
 * @date 08 Nov 2023
 * @brief The System Control Block C file that has the functions body of **SCB** driver
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/SCB/MSCB_interface.h"
#include "MCAL/SCB/MSCB_private.h"
#include "MCAL/SCB/MSCB_config.h"

/**
 * @fn void MSCB_voidReset(void)
 * @param none
 * @return none
 * @brief This function do a soft reset to the microcontroller
 */
void MSCB_voidReset (void)
{
	SCB_AIRCR = (RESET_VALUE | (1 << SCB_AIRCR_SYSRESETREQ));
}

/**
 * @fn void MSCB_voidSetVectorTable(u32)
 * @brief This function set the vector table of the microcontroller
 * @return none
 * @param Pointer_u32Address
 */
void MSCB_voidSetVectorTable (u32 Pointer_u32Address)
{
	SCB_VTOR = Pointer_u32Address;
}
