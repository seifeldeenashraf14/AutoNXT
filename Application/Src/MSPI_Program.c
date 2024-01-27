/*
 * MSPI_Program.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Hesham Yasser
 */

#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/MCAL/SPI/MSPI_Interface.h"
#include "../include/MCAL/SPI/MSPI_Private.h"
#include "../include/MCAL/SPI/MSPI_Config.h"

PtrToFunc_void SPI_CallBack[SPI_NUMBER];

void MSPI1_voidInit (void)
{
	/*Set Data Size*/
#if MSPI1_DATA_SIZE == MSPI_16BIT_DATA
	SET_BIT (SPI1->CR1 , CR1_DFF);
#else
	CLR_BIT (SPI1->CR1 , CR1_DFF);
#endif
	/*Set slave management mode*/
#if MSPI1_SS_MANAGE == MSPI_SW_SLAVE_MANAGEMENT
	SET_BIT (SPI1->CR1 , CR1_SSM);
	SET_BIT(SPI1->CR1 , CR1_SSI);
#else
	CLR_BIT (SPI1->CR1 , CR1_SSM);
#endif
	/*Set Data Order*/
#if MSPI1_DATA_ORDER == MSPI_LSB_FIRST
	SET_BIT (SPI1->CR1 , CR1_LSBFIRST);
#else
	CLR_BIT (SPI1->CR1 , CR1_LSBFIRST);
#endif
	/*Set Clock Mode*/
	SPI1->CR1 &= ~(TWO_BIT_MASK<<CR1_CLK_SELECT);
	SPI1->CR1 |= (MSPI1_CLK_MODE<<CR1_CLK_SELECT);
	/*Set Interrupt States*/
#if MSPI1_TX_INTERRUPT_STATE == MSPI_INTERRUPT_ENABLE
	SET_BIT (SPI1->CR2 , CR2_TXEIE);
#else
	CLR_BIT (SPI1->CR2 , CR2_TXEIE);
#endif
#if MSPI1_RX_INTERRUPT_STATE == MSPI_INTERRUPT_ENABLE
	SET_BIT (SPI1->CR2 , CR2_RXNEIE);
#else
	CLR_BIT (SPI1->CR2 , CR2_RXNEIE);
#endif
	/*Set SPI Mode*/
#if MSPI1_MASTER_SLAVE == MSPI_MASTER
	SET_BIT (SPI1->CR1 , CR1_MSTR);
	/*Set Prescaler*/
	SPI1->CR1 &= ~(THREE_BIT_MASK<<CR1_BR);
	SPI1->CR1 |= (MSPI1_PRESCALER<<CR1_CLK_SELECT);
#else
	CLR_BIT (SPI1->CR1 , CR1_MSTR);
#endif
	/*ٍSet SPI State*/
#if MSPI1_STATE == MSPI_ENABLED
	SET_BIT (SPI1->CR1 , CR1_SPE);
#else
	CLR_BIT (SPI1->CR1 , CR1_SPE);
#endif
}

u16 MSPI1_voidSendReceiveData (u16 A_u16Data)
{
	/*Put data in SPI Data Register*/
#if MSPI1_DATA_SIZE == MSPI_16BIT_DATA
	SPI1->DR = A_u16Data;
#else
	SPI1->DR = (u8) A_u16Data;
#endif
	/*wait until SPI finishes*/
	while (GET_BIT(SPI1->SR , SR_BSY) == SPI_BUSY);
	return SPI1->DR;
}

void MSPI1_voidSetCallBack (PtrToFunc_void p_CallBackFunc)
{
	/*Set Call Back Function*/
	SPI_CallBack[0] = p_CallBackFunc;
}


void SPI1_IRQHandler (void)
{
	if (SPI_CallBack[0] != NULL)
	{
		SPI_CallBack[0]();
	}
}

void MSPI2_voidInit (void)
{
	/*Set Data Size*/
#if MSPI2_DATA_SIZE == MSPI_16BIT_DATA
	SET_BIT (SPI2->CR1 , CR1_DFF);
#else
	CLR_BIT (SPI2->CR1 , CR1_DFF);
#endif
	/*Set slave management mode*/
#if MSPI2_SS_MANAGE == MSPI_SW_SLAVE_MANAGEMENT
	SET_BIT (SPI2->CR1 , CR1_SSM);
	SET_BIT(SPI2->CR1 , CR1_SSI);
#else
	CLR_BIT (SPI2->CR1 , CR1_SSM);
#endif
	/*Set Data Order*/
#if MSPI2_DATA_ORDER == MSPI_LSB_FIRST
	SET_BIT (SPI2->CR1 , CR1_LSBFIRST);
#else
	CLR_BIT (SPI2->CR1 , CR1_LSBFIRST);
#endif
	/*Set Clock Mode*/
	SPI2->CR1 &= ~(TWO_BIT_MASK<<CR1_CLK_SELECT);
	SPI2->CR1 |= (MSPI2_CLK_MODE<<CR1_CLK_SELECT);
	/*Set Interrupt States*/
#if MSPI2_TX_INTERRUPT_STATE == MSPI_INTERRUPT_ENABLE
	SET_BIT (SPI2->CR2 , CR2_TXEIE);
#else
	CLR_BIT (SPI2->CR2 , CR2_TXEIE);
#endif
#if MSPI2_RX_INTERRUPT_STATE == MSPI_INTERRUPT_ENABLE
	SET_BIT (SPI2->CR2 , CR2_RXNEIE);
#else
	CLR_BIT (SPI2->CR2 , CR2_RXNEIE);
#endif
	/*Set SPI Mode*/
#if MSPI2_MASTER_SLAVE == MSPI_MASTER
	SET_BIT (SPI2->CR1 , CR1_MSTR);
	/*Set Prescaler*/
	SPI2->CR1 &= ~(THREE_BIT_MASK<<CR1_BR);
	SPI2->CR1 |= (MSPI2_PRESCALER<<CR1_CLK_SELECT);
#else
	CLR_BIT (SPI2->CR1 , CR1_MSTR);
#endif
	/*ٍSet SPI State*/
#if MSPI2_STATE == MSPI_ENABLED
	SET_BIT (SPI2->CR1 , CR1_SPE);
#else
	CLR_BIT (SPI2->CR1 , CR1_SPE);
#endif
}

u16 MSPI2_voidSendReceiveData (u16 A_u16Data)
{
	/*Put data in SPI Data Register*/
#if MSPI2_DATA_SIZE == MSPI_16BIT_DATA
	SPI2->DR = A_u16Data;
#else
	SPI2->DR = (u8) A_u16Data;
#endif
	/*wait until SPI finishes*/
	while (GET_BIT(SPI2->SR , SR_BSY) == SPI_BUSY);
	return SPI2->DR;
}

void MSPI2_voidSetCallBack (PtrToFunc_void p_CallBackFunc)
{
	/*Set Call Back Function*/
	SPI_CallBack[1] = p_CallBackFunc;
}


void SPI2_IRQHandler (void)
{
	if (SPI_CallBack[1] != NULL)
	{
		SPI_CallBack[1]();
	}
}


u16 MSPI2_u16ReadReceivedValue(void)
{
	while (GET_BIT(SPI2->SR , SR_BSY) == SPI_BUSY);
	return SPI2->DR;
}

