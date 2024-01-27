/*
 * Ultrasonic_Interface.h
 *
 *  Created on: Nov 3, 2023
 *      Author: Hesham Yasser
 */

#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

void HUltrasonic_voidInit (void);


void HUltrasonic_voidTrigger (void);

u16 HUltrasonic_u16ReadDistanceNonBlocking (void);

u16 HUltrasonic_voidReadDistanceBlocking (void);


#endif /* ULTRASONIC_INTERFACE_H_ */
