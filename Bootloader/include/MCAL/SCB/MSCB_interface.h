/**
 * @file MSCB_interface.h
 * @author Hosam Ayoub
 * @version 1.0
 * @date 08 Nov 2023
 * @brief The System Control Block C file that has all the functions prototypes and arguments of the **SCB** driver
 */
#ifndef MSCB_INTERFACE_H_
#define MSCB_INTERFACE_H_

void MSCB_voidReset (void);
void MSCB_voidJumpToApplication (u32 Pointer_u32Address);

#endif
