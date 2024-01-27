/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : Service                ***********************/
/***********************            SWC     : HexParser              ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 01 Oct 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/FMI/FMI_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "Service/HexParser/HexParser_interface.h"
#include "Service/HexParser/HexParser_private.h"
#include "Service/HexParser/HexParser_config.h"

u16 Global_u16DataBuffer[100];
pf x = NULL;

static u8 HexParser_u8AsciiToHex (u8 Copy_u8Ascii)
{
	u8 Local_u8Hex = 0;
	if (('0' <= Copy_u8Ascii) && (Copy_u8Ascii <= '9'))
	{
		Local_u8Hex = Copy_u8Ascii - '0';
	}
	else if (('A' <= Copy_u8Ascii) && (Copy_u8Ascii <= 'F'))
	{
		Local_u8Hex = Copy_u8Ascii - ('A' - 10);
	}
	return Local_u8Hex;
}

void HexParser_voidParseData (s8 *Pointer_u8Data)
{
	u8 Local_u8CC, Local_u8Digit0, Local_u8Digit1, Local_u8Digit2, Local_u8Digit3, Local_u8Iterator, Local_u8CheckSum = 0, Local_u8Summation = 0;
	u32 Local_u32Address;
	/* Convert character count */
	Local_u8Digit0 = HexParser_u8AsciiToHex(Pointer_u8Data[1]);
	Local_u8Digit1  = HexParser_u8AsciiToHex(Pointer_u8Data[2]);
	Local_u8CC = (Local_u8Digit0 << 4) | Local_u8Digit1;
	/* Add to checksum */
	Local_u8Summation += Local_u8CC;

	/* Convert address */
	Local_u8Digit0 = HexParser_u8AsciiToHex(Pointer_u8Data[3]);
	Local_u8Digit1 = HexParser_u8AsciiToHex(Pointer_u8Data[4]);
	Local_u8Digit2 = HexParser_u8AsciiToHex(Pointer_u8Data[5]);
	Local_u8Digit3 = HexParser_u8AsciiToHex(Pointer_u8Data[6]);
	Local_u32Address = (FLASH_BASE_ADDRESS) | (Local_u8Digit0 << 12) | (Local_u8Digit1 << 8) | (Local_u8Digit2 << 4) | (Local_u8Digit3);
	/* Add to checksum */
	Local_u8Summation += (Local_u8Digit0 << 4) + (Local_u8Digit1);
	Local_u8Summation += (Local_u8Digit2 << 4) + (Local_u8Digit3);

	for (Local_u8Iterator = 0; Local_u8Iterator < (Local_u8CC/2); Local_u8Iterator++)
	{
		Local_u8Digit0 = HexParser_u8AsciiToHex(Pointer_u8Data[9  + (Local_u8Iterator * 4)]);
		Local_u8Digit1 = HexParser_u8AsciiToHex(Pointer_u8Data[10 + (Local_u8Iterator * 4)]);
		Local_u8Digit2 = HexParser_u8AsciiToHex(Pointer_u8Data[11 + (Local_u8Iterator * 4)]);
		Local_u8Digit3 = HexParser_u8AsciiToHex(Pointer_u8Data[12 + (Local_u8Iterator * 4)]);
		/* Convert big endian to little endian */
		Global_u16DataBuffer[Local_u8Iterator] = (Local_u8Digit2 << 12) | (Local_u8Digit3 << 8) | (Local_u8Digit0 << 4) | (Local_u8Digit1);
		/* Add to checksum */
		Local_u8Summation += (Local_u8Digit0 << 4) + (Local_u8Digit1);
		Local_u8Summation += (Local_u8Digit2 << 4) + (Local_u8Digit3);
	}

	/* Calculate Checksum */
	Local_u8Digit0 = HexParser_u8AsciiToHex(Pointer_u8Data[9  + (Local_u8Iterator * 4)]);
	Local_u8Digit1 = HexParser_u8AsciiToHex(Pointer_u8Data[10 + (Local_u8Iterator * 4)]);
	Local_u8CheckSum = (Local_u8Digit0 << 4) | (Local_u8Digit1);

	/* Get the Two's complement of the Summation */
	Local_u8Summation = (0xFF - Local_u8Summation) + 1;

	/* Check if the record is correct or no*/
	if (Local_u8Summation == Local_u8CheckSum)
	{
		FMI_voidFlashWrite(Local_u32Address, Global_u16DataBuffer, (Local_u8CC/2));
	}
	else
	{
		asm("nop");
		/* Do Nothing */
	}
}

void HexParser_voidParseRecord (s8 *Pointer_u8Data)
{
	switch (Pointer_u8Data[8])
	{
	case '0':
		HexParser_voidParseData(Pointer_u8Data);
		UART_voidTransmit("k");
		break;
	case '4':
		/* Set high address */
		UART_voidTransmit("k");
		break;
	case '1':
		/* End of file */
		if (Pointer_u8Data[11] == '\n')
		{
			/*Send ok to tool to send the next Record */
			UART_voidTransmit("k");
			x();
		}
		else
		{
			/*Send ok to tool to send the next Record */
			HexParser_voidParseData(Pointer_u8Data);
			/*Send ok to tool to send the next Record */
			UART_voidTransmit("k");
		}
		break;
	case '5':
		/* Set high address */
		UART_voidTransmit("k");
		break;
	default:
		break;
	}
}

void HexParser_voidSetCallBack(pf PointerToFunction)
{
	if (PointerToFunction != NULL)
	{
		x = PointerToFunction;
	}
	else
	{
		/* Do Nothing */
	}
}
