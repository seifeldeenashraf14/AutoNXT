/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : STK                    ***********************/
/***********************            Version : 2.0                    ***********************/
/***********************            Date    : 05 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
/*************************/
#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

/* Functions */
void STK_voidInit (void);
void STK_voidStart (void);
void STK_voidStop (void);
void STK_voidEnableInterrupt (void);
void STK_voidDisableInterrupt (void);
void STK_voidGetFlag (u8 *Pointer_u8Value);
void STK_voidSetLoadValue (u32 Copy_u32Ticks);
void STK_voidSetSingleIntervalMS (u32 Copy_u32MilliSeconds, pf pfCallBack);
void STK_voidBusyWaiting (u32 Copy_u32Ticks);
void STK_voidDelayUS (u32 Copy_u32MicroSeconds);
void STK_voidDelayMS (u32 Copy_u32MilliSeconds);
void STK_voidGetRemainingTime (u32 *Pointer_u32MicroSecondsBuffer);
void STK_voidGetElapsedTime (u32 *Pointer_u32MicroSecondsBuffer);
void STK_voidSetCallBackFunction (pf pfCallBack);

/* Configuration Arguments */
#define CLK_AHB_BY_8							0
#define CLK_AHB									1

#define INTERRUPT_OFF                           0
#define INTERRUPT_ON                            1

#endif
