/**
 * @file	MSTK_interface.h
 * @author 	Hosam Ayoub
 * @version 1.0
 * @date 	5 oct 2023
 * @brief 	The Systick Timer interface header file that has all the Prototypes of **STK** driver
 */
 
#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_

/* Functions */
/**
 * @fn 		void MSTK_voidInit (void)
 * @brief   This funciton used to Control the Clock Source and the interrupt 
 * @param 	none
 * @return 	none
 */
void MSTK_voidInit (void);

/**
 * @fn 		void MSTK_voidStart (void)
 * @brief   This funciton used to Start the Timer to count down  
 * @param 	none
 * @return 	none
 */
void MSTK_voidStart (void);

/**
 * @fn 		void MSTK_voidStop (void)
 * @brief   This funciton is used to stop the counting at anytime in the system  
 * @param 	none
 * @return 	none
 */
void MSTK_voidStop (void);

/**
 * @fn 		void MSTK_voidEnableInterrupt (void)
 * @brief   This funciton is used to enable the interrupt on the countflag bit when reaches to 0
 * @param 	none
 * @return 	none
 */
void MSTK_voidEnableInterrupt (void);

/**
 * @fn 		void MSTK_voidDisableInterrupt (void)
 * @brief   This funciton is used to disable the interrupt on the countflag bit when reaches to 0  
 * @param 	none
 * @return 	none
 */
void MSTK_voidDisableInterrupt (void);

/**
 * @fn 		void MSTK_voidGetFlag (u8 *Pointer_u8Value)
 * @brief   This funciton is used to read the flag   
 * @param 	(u8) adress of any variable which will hold the value of the bit flag
 * @return 	none
 */
void MSTK_voidGetFlag (u8 *Pointer_u8Value);

/**
 * @fn 		void MSTK_voidSetLoadValue (u32 Copy_u32Ticks)
 * @brief   This funciton is used to set the value which need to count from to 0
 * @param 	(u32) the number of ticks that will be counted
 * @return 	none
 */
void MSTK_voidSetLoadValue (u32 Copy_u32Ticks);

/**
 * @fn 		void MSTK_voidSetSingleIntervalMS (u32 Copy_u32MilliSeconds, pf pfCallBack)
 * @brief   This funciton is used to generate an interrupt after period of time
 * @param 	(u32 , pf) the Period of time and the address of the function that will be executed when the interrupt occurs
 * @return 	none
 */
void MSTK_voidSetSingleIntervalMS (u32 Copy_u32MilliSeconds, pf pfCallBack);

/**
 * @fn 		void MSTK_voidBusyWaiting (u32 Copy_u32Ticks)
 * @brief   This funciton is used to make the system busy for a period of time
 * @param 	(u32) the number of ticks that will be count from
 * @return 	none
 */
void MSTK_voidBusyWaiting (u32 Copy_u32Ticks);

/**
 * @fn 		void MSTK_voidDelayUS (u32 Copy_u32MicroSeconds)
 * @brief   This funciton is used to delay the system by a period of time in microseconds
 * @param 	(u32) the period of time in microseconds
 * @return 	none
 */
void MSTK_voidDelayUS (u32 Copy_u32MicroSeconds);
/**
 * @fn 		void MSTK_voidDelayUS (u32 Copy_u32MicroSeconds)
 * @brief   This funciton is used to delay the system by a period of time in millisecond
 * @param 	(u32) the period of time in millisecond
 * @return 	none
 */
void MSTK_voidDelayMS (u32 Copy_u32MilliSeconds);

/**
 * @fn 		void MSTK_voidGetRemainingTime (u32 *Pointer_u32MicroSecondsBuffer);
 * @brief   This funciton is used to calculate the remaining time untill it reaches to 0
 * @param 	(u32) address which is assign to a pointer and will assign the remaining time to this variable in millisecond
 * @return 	none
 */
void MSTK_voidGetRemainingTime (u32 *Pointer_u32MicroSecondsBuffer);

/**
 * @fn 		void MSTK_voidGetElapsedTime (u32 *Pointer_u32MicroSecondsBuffer);
 * @brief   This funciton is used to calculate the elapsed time from it starts to count
 * @param 	(u32) address which is assign to a pointer and will assign the remaining time to this variable in microseconds
 * @return 	none
 */
void MSTK_voidGetElapsedTime (u32 *Pointer_u32MicroSecondsBuffer);

/**
 * @fn 		void MSTK_voidSetCallBackFunction (pf pfCallBack);
 * @brief   This funciton is used to calculate the elapsed time from it starts to count
 * @param 	pointer to funciton which holds the address of the specific funciton that will be executed when interrupt occurs
 * @return 	none
 */
void MSTK_voidSetCallBackFunction (pf pfCallBack);

/* Configuration Arguments */
#define CLK_AHB_BY_8							0		//!< this bit macro defines the clock to be divided by 8
#define CLK_AHB									1		//!< this bit macro defines the clock to be the clock of the bus

#define INTERRUPT_OFF                           0		//!< this bit macro disabled any interrupt when it selected to this  interrupt
#define INTERRUPT_ON                            1		//!< this bit macro enabled any interrupt when it selected to this interrupt	

#endif
