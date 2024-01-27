/*
 * HMotorDriver_Interface.h
 *
 *  Created on: Oct 10, 2023
 *      Author: lenovo
 */

#ifndef HMOTORDRIVER_INTERFACE_H_
#define HMOTORDRIVER_INTERFACE_H_

void HMotor_VoidCarInit(void);
void HMotor_VoidCarForword(void);
void HMotor_VoidCarBackword(void);
void HMotor_VoidCarStop(void);
void HMotor_VoidCarRight(void);
void HMotor_VoidCarLeft(void);
void HMotor_VoidCarSpeed(u16 Copy_u16DutyCycle);
void HMotor_VoidCarSpeedRight(u16 Copy_u16DutyCycle);
void HMotor_VoidCarSpeedLeft(u16 Copy_u16DutyCycle);
#endif /* HMOTORDRIVER_INTERFACE_H_ */
