/**
 * @def SHexParser_INTERFACE_H_
 * @brief The HexParser Header file that has all the prototypes and arguments of **HexParser** driver
 * @author Hosam Ayoub
 * @date 	10 Oct 2023
 * @version 1.0
 */

#ifndef SHexParser_INTERFACE_H_
#define SHexParser_INTERFACE_H_
/**
 * @enum tenumStatus
 * @brief Enumeration for determine the status.
 *
 */
typedef enum
{
	OK, NOK
}tenumStatus;

/**
 * @fn tenumStatus SHexParser_tenumStatusParseData(s8*)
 * @brief This Function responsible for parsing and processing a line of Intel Hexadecimal format data
 *
 * @param Pointer_u8Data	contain a data record in Intel HEX format.
 * @return tenumStatus	a status indicates whether the Parsing and Writing Were successful (OK) or not (NOK).
 */
tenumStatus SHexParser_tenumStatusParseData (s8 *Pointer_u8Data);

/**
 * @fn tenumStatus SHexParser_tenumStatusParseRecord(s8*)
 * @brief This function is responsible for parsing different types of Intel Hex records and taking appropriate actions based on the record type.
 *
 * @param Pointer_u8Data		A pointer to a character array containing Intel Hexadecimal formatted data.
 * @return tenumStatus	a status indicating the success or failure of the parsing process.
 */
tenumStatus SHexParser_tenumStatusParseRecord (s8 *Pointer_u8Data);

/**
 * @fn tenumStatus SHexParser_tenumStatusSetCallBack(pf)
 * @brief  This function to set a callback function that can be executed in response to specific conditions.
 *
 * @param PointerToFunction
 * @return tenumStatus 	a status (OK or NOK) indicating the success or failure of setting the callback.
 */
tenumStatus SHexParser_tenumStatusSetCallBack(pf PointerToFunction);

/**
 * @fn tenumStatus SHexParser_tenumStatusSetStartAddress(s8*)
 * @brief This function is responsible for setting the start address for the application based on the data provided in an Intel Hex record.
 *
 * @param Pointer_s8Data		A pointer to a character array containing Intel Hexadecimal formatted data.
 * @return  tenumStatus   a status (OK or NOK) indicating the success or failure of the operation.
 */
tenumStatus SHexParser_tenumStatusSetStartAddress (s8 *Pointer_s8Data);

extern u32 Global_u32FlashBaseAddress, Global_u32StartAddress, Global_u32ApplicationAddress;

#endif
