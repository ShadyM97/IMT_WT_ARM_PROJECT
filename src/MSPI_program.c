/*
 * SPI_program.c
 *
 *  Created on: Feb 4, 2024
 *      Author: Shady
 */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "MSPI_private.h"
#include "MSPI_config.h"
#include "MSPI_interface.h"

#define THREE_BIT_MASK	0b111

void MSPI_voidInit(void)
{
	SPI1->SPI_CR1 &= ~(1 << SPE);
/*-------------------Master---------------------*/
#if SPI_MODE == SPI_MASTER
	/* Data Format 8 bit */
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<DFF)) | (SPI1_DATA_LENGTH << DFF);
	/* Frame format MSB */
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<LSBFIRST)) | (SPI1_FRAME_FORMAT << LSBFIRST);
	/* Clock Polarity CPOL/ Clock Phase CPHA */
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<CPOL)) | (SPI1_CLOCK_POLARITY << CPOL);
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<CPHA)) | (SPI1_CLOCK_PHASE<< CPHA);
	/* Baud Rate  */
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(THREE_BIT_MASK << BR)) | (SPI1_BAUDRATE << BR);
	/* Enable Slave Select */
	SPI1->SPI_CR2 |= (1 << SSOE);
	/* Master or Slave */
	SPI1->SPI_CR1 |= (1 << MSTR);
#elif SPI_MODE == SPI_SLAVE
/*-------------------Slave---------------------*/
	/* Data Format 8 bit */
	SPI1->SPI_CR1 = (SPI1->SPI_CR1 & ~(1<<DFF)) | (SPI1_DATA_LENGTH << DFF);
	/* Frame format MSB */
	SPI1->SPI_CR1 &= ~(1 << LSBFIRST);
	/* Clock Polarity CPOL/ Clock Phase CPHA */
	SPI1->SPI_CR1 &= ~(1<< CPOL);
	SPI1->SPI_CR1 &= ~(1<< CPHA);
	/* Master or Slave */
	SPI1->SPI_CR1 &= ~(1 << MSTR);
#endif
	/* SPI Enable */
	SPI1->SPI_CR1 |= (1 << SPE);
}
void MSPI_voidTranseive(uint8 u8CopyData, uint8 *u8ReceivedData)
{
	while(GET_BIT(SPI1->SPI_SR, SR_TXE) == 0);
	SPI1->SPI_DR = u8CopyData;
	while(GET_BIT(SPI1->SPI_SR, SR_RXNE) == 0);
	*u8ReceivedData = SPI1->SPI_DR;
}
