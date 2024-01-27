/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : HAL                    ***********************/
/***********************            SWC     : IR                     ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 21 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

extern volatile u8 Global_u8Data;

void IR_voidInit (void);
void IR_voidStart (pf pfCallBack);
void IR_voidStop (void);
void RGB_LED (void);

#endif
