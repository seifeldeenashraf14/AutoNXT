/*
 * UDS_Services_Config.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Seif
 */

#include "../include/UDS_Services_Interface.h"
#include "../include/UDS_Services_Config.h"

Object_Status Service_ID_Array [Number_Of_Services]=
{            /**********Session_Control********/
		{ Supported_All_sessions ,No_Security   , null },
		/**********Security_Level********/
		{ Supported_All_sessions ,null   , null },
		/**********ECU_Reset********/
		{ Supported_All_sessions ,Security_One   , null },
		/********Routine_Control******/
		{ Supported_All_sessions ,Security_One  , null },
		/********Read_Control******/
		{ Supported_All_sessions ,Security_One   , null },
		/********Write_Control******/
		{ Supported_All_sessions ,Security_One   , null },
};

Object_Status Sub_FunctionsArray [Number_Of_SubFunctions]=
{            /**********Start_Routine********/
		{ Supported_All_sessions ,No_Security  , null },
		/**********Soft_Reset********/
		{ Supported_All_sessions ,Security_One  , null },
		/**********Hard_Reset********/
		{ Supported_All_sessions ,Security_One  , null },
		/********Level_One_Seed******/
		{ Supported_All_sessions ,Security_One  , null },
		/********Level_One_Key******/
		{ Supported_All_sessions ,Security_One  , null },
		/********Level_Two_Seed******/
		{ Supported_All_sessions ,Security_One  , null },
		/********Level_Two_Key******/
		{ Supported_All_sessions ,Security_One  , null },
		/********Level_Three_Seed******/
		{ Supported_All_sessions ,Security_One  , null },
		/********Level_Three_Key******/
		{ Supported_All_sessions ,Security_One  , null },
		/********Default Session******/
		{ Supported_All_sessions ,Security_One  ,null },
		/********Programming Session******/
		{ Supported_All_sessions ,Security_One  , null },
		/******** Extended Session******/
		{ Supported_All_sessions ,Security_One  , null },
};


Object_Status Identifier [Number_Of_Identifiers]=
{            /**********Session_Control********/
		{ Supported_All_sessions ,No_Security  , null },
		/**********Security_Level********/
		{ Supported_All_sessions ,null , null },
		/**********ECU_Reset********/
		{ Supported_All_sessions ,Security_One  , null },
		/********Routine_Control******/
		{ Supported_All_sessions ,Security_One   , null },
		/********Read_Control******/
		{ Supported_All_sessions ,Security_One   , null },
		/********Write_Control******/
		{ Supported_All_sessions ,Security_One  , null },
};

u8 Seucrity_LevelsStatus[Max_Number_OfSecurties]=
{
		/****************Security_One***************/
		Locked,
		/****************Security_One***************/
		Unlocked,
		/****************Security_One***************/
		Unlocked,

};
