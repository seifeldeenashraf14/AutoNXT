/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : EXTI                   ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 12 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
/*************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/* Arguments */
/* EXTI_LINE */
#define EXTI_LINE0											0
#define EXTI_LINE1                                          1
#define EXTI_LINE2                                          2
#define EXTI_LINE3                                          3
#define EXTI_LINE4                                          4
#define EXTI_LINE5                                          5
#define EXTI_LINE6                                          6
#define EXTI_LINE7                                          7
#define EXTI_LINE8                                          8
#define EXTI_LINE9                                          9
#define EXTI_LINE10											10
#define EXTI_LINE11                                         11
#define EXTI_LINE12                                         12
#define EXTI_LINE13                                         13
#define EXTI_LINE14                                         14
#define EXTI_LINE15                                         15

/* EXTI PORT */
#define EXTI_PORTA                                          0
#define EXTI_PORTB                                          1
#define EXTI_PORTC                                          2
#define EXTI_PORTD                                          3
#define EXTI_PORTE                                          4
#define EXTI_PORTH                                      	7

/* State */
#define EXTI_DISABLE										0
#define EXTI_ENABLE											1

/* Trigger */
#define EXTI_RISING											0
#define EXTI_FALLING                                        1
#define EXTI_ONCHANGE                                       2

/* Functions */
void EXTI_voidSetPortInterrupt (u8 Copy_u8PORT, u8 Copy_u8Line);
void EXTI_voidInterruptEnableDisable(u8 Copy_u8Line , u8 Copy_tstrState);
void EXTI_voidInterruptTrigger(u8 Copy_u8Line,u8 Copy_u8Trigger);
void EXTI_voidCallBack(u8 Copy_u8Index, pf pfCallBack);
void EXTI_voidSetSWInterrupt (u8 Copy_u8Line);



#endif
