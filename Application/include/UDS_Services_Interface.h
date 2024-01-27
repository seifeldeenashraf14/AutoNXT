/*
 * UDS_Services_Interface.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Seif
 */

#ifndef UDS_SERVICES_INTERFACE_H_
#define UDS_SERVICES_INTERFACE_H_

#include "LIB/STD_Types.h"
#include "../include/UDS_Services_Private.h"

typedef enum
{
	Not_Supported=1,
	Supported,
	Supported_Default,
	Supported_Programming,
	Supported_Extended,
	Supported_All_sessions,
}Support_Type;

typedef enum
{

	No_Security=1,
	Security_One,
	Security_Two,
	Seucrity_Three,
	Max_Number_OfSecurties,
}Security_Type;

typedef enum
{
	No_Read_No_Write=1,
	Read,
	Write,
	Read_Write,
}Acess_Type;

typedef enum
{
	Service_Not_Supported=0x11,
	Sub_Service_Not_Supported=0x12,
	Security_Acess_Denied=0x33,
    Out_of_Range=0x31,
}NRC_Type;

typedef struct
{
    Support_Type Object_Support;
	Security_Type Object_Security_Level;
	Acess_Type Object_acess;
}Object_Status;

typedef enum
{
	Session_Control_Index,
	Security_Level_Index,
	ECU_Reset_Index,
	Routine_Control_Index,
	Read_Control_Index,
	Write_Control_Index,
	Number_Of_Services,
}Service_ID;

typedef enum
{
	Start_Routine_Index,
	Soft_Reset_Index,
	Hard_Reset_Index,
	Level_One_Seed_Index,
	Level_One_Key_Index,
	Level_Two_Seed_Index,
	Level_Two_Key_Index,
	Level_Three_Seed_Index,
	Level_Three_Key_Index,
	Default_Session_Index,
	Programming_Session_Index,
	Extended_Session_Index,
	Number_Of_SubFunctions,
}Sub_Function_ID;

/***********************Sessions *******************/
#define Default_Sessions 0x01

#define Programming_Session 0x02

#define Extended_Session 0x03


/******************** Services ID*************************/

#define Security_Level 0x27

#define Session_Control 0x10

#define ECU_Reset 0x11

#define Read_DataByIdentfier 0x22

#define Write_DataByIdentfier 0x2E

#define Routine_Control 0x31

/******************Positive Response**************/

#define Security_Level_PositiveResponse 0x67

#define Session_Control_PositiveResponse 0x50

#define ECU_Reset_PositiveResponse 0x51

#define Read_DataByIdentfier_PositiveResponse 0x62

#define Write_DataByIdentfier_PositiveResponse 0x6E

#define Routine_Control_PositiveResponse 0x71

/********************Programming Session Services ID ******************/
#define Request_Download 0x34

#define Transfer_Data 0x36

#define Transfer_Exit 0x37


/********************Routine Control Sub Functions***************/
#define Start_Routine 0x01

/****************** ECU Reset SubFunctions*****************/
#define Soft_Reset 0x01

#define Hard_Reset 0x02

/**************Security Level SubFunctions*************/
#define Level_One_Seed 0x01

#define Level_One_Key 0x02

#define Level_Two_Seed 0x03

#define Level_Two_Key 0x04

#define Level_Three_Seed 0x05

#define Level_Three_Key 0x06

/*************Negative Response ****************/
#define Negative_Response 0x7f

#define Unlocked 0
#define Locked 1

#endif /* UDS_SERVICES_INTERFACE_H_ */
