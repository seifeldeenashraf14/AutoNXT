

#include "../include/UDS_Services_Interface.h"

#include "../include/MCAL/UART/MUART_Interface.h"
#include "../ThirdParty/FreeRTOS/include/FreeRTOS.h"
#include "../ThirdParty/FreeRTOS/include/task.h"
extern Object_Status Service_ID_Array [];
extern Object_Status Sub_FunctionsArray [];
u8 Uart_Recieve;
u8 Current_Session=Default_Sessions;
u8 Sub_Service=0;
u8 Session_control_Flag=0,SubSession_control_Flag;
void UDS_Task(void)
{

	MUART1_voidu8Receive(&Uart_Recieve);
	if(Uart_Recieve==Session_Control)
	{
		if(Session_control_Flag==0)
		{
			if(Service_ID_Array[Session_Control_Index].Object_Support==Not_Supported)
			{
				MUART1_voidTransmitCharacter(0x7f);
				MUART1_voidTransmitCharacter(Session_Control);
				MUART1_voidTransmitCharacter(Service_Not_Supported);
			}

			else if(Service_ID_Array[Session_Control_Index].Object_Support==Supported_All_sessions)
			{
					Session_control_Flag=1;
			}
			else if(Service_ID_Array[Session_Control_Index].Object_Support==Supported_Default)
			{
				if(Current_Session==Default_Sessions)
				{
					Session_control_Flag=1;
				}
				else
				{
					MUART1_voidTransmitCharacter(0x7f);
					MUART1_voidTransmitCharacter(Session_Control);
					MUART1_voidTransmitCharacter(Service_Not_Supported);
				}
			}
			else if(Service_ID_Array[Session_Control_Index].Object_Support==Supported_Programming)
			{
				if(Current_Session==Supported_Programming)
				{
					Session_control_Flag=1;
				}
				else
				{
					MUART1_voidTransmitCharacter(0x7f);
					MUART1_voidTransmitCharacter(Session_Control);
					MUART1_voidTransmitCharacter(Service_Not_Supported);
				}
			}
			else if(Service_ID_Array[Session_Control_Index].Object_Support==Supported_Extended)
			{
				if(Current_Session==Supported_Extended)
				{
					Session_control_Flag=1;
				}
				else
				{
					MUART1_voidTransmitCharacter(0x7f);
					MUART1_voidTransmitCharacter(Session_Control);
					MUART1_voidTransmitCharacter(Service_Not_Supported);
				}
			}
		}
		if(Session_control_Flag==1)
		{
			MUART1_voidu8Receive(&Uart_Recieve);
			if(Uart_Recieve==Default_Sessions)
			{
				if(Sub_FunctionsArray[Default_Session_Index].Object_Support==Not_Supported)
				{
					MUART1_voidTransmitCharacter(0x7f);
					MUART1_voidTransmitCharacter(Session_Control);
					MUART1_voidTransmitCharacter(Sub_Service_Not_Supported);
				}
				else if(Sub_FunctionsArray[Default_Session_Index].Object_Support==Supported_All_sessions)
				{

					SubSession_control_Flag=1;
				}

				else if(Sub_FunctionsArray[Default_Session_Index].Object_Support==Supported_All_sessions)
				{

				}
			}
			else if(Uart_Recieve==Programming_Session)
			{

			}
			else if(Uart_Recieve==Extended_Session)
			{

			}
			else
			{

			}


		}


	}

}
