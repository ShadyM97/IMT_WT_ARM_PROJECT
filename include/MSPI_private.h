/*
 * SPI_private.h
 *
 *  Created on: Feb 4, 2024
 *      Author: Shady
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI1_BASE_ADDRESS	0x40013000

#define SPI_MASTER 	1
#define SPI_SLAVE	0

#define DFF			11
#define LSBFIRST	7
#define SPE			6
#define BR			5
#define MSTR		2
#define CPOL		1
#define CPHA		0

#define SSOE		2

#define SR_BSY		7
#define SR_TXE		1
#define SR_RXNE		0

#define BAUDRATE_2   0
#define BAUDRATE_4   1
#define BAUDRATE_8   2
#define BAUDRATE_16  3
#define BAUDRATE_32  4
#define BAUDRATE_64  5
#define BAUDRATE_128 6
#define BAUDRATE_256 7

#define DATA_LENGTH_8  0
#define DATA_LENGTH_16 1

#define MSB_FIRST 	0
#define LSB_FIRST	1

#define CLOCK_POLARITY_HIGH	1
#define CLOCK_POLARITY_LOW	0

#define CLOCK_PHASE_FIRST	0
#define CLOCK_PHASE_SECOND	1
typedef struct
{
	uint32 SPI_CR1;
	uint32 SPI_CR2;
	uint32 SPI_SR;
	uint32 SPI_DR;
	uint32 SPI_CRCPR;
	uint32 SPI_RXCRCR;
	uint32 SPI_TXCRCR;
	uint32 SPI_I2SCFGR;
	uint32 SPI_I2SPR;
}SPI_t;

#define SPI1	((volatile SPI_t*)(SPI1_BASE_ADDRESS))


#endif /* SPI_PRIVATE_H_ */
