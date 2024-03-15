/*
 * SPI_interface.h
 *
 *  Created on: Feb 4, 2024
 *      Author: Shady
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/*
 * Function: MSPI_voidInit
 * -----------------------
 * Initializes the SPI peripheral according to the configured settings.
 *
 * Parameters: None
 *
 * Returns: None
 */
void MSPI_voidInit(void);

/*
 * Function: MSPI_voidTranseive
 * ----------------------------
 * Transmits a byte of data over SPI and receives a byte of data.
 *
 * Parameters:
 *      - u8CopyData: The data byte to be transmitted.
 *      - u8ReceivedData: Pointer to store the received data byte.
 *
 * Returns: None
 */
void MSPI_voidTranseive(uint8 u8CopyData, uint8 *u8ReceivedData);



#endif /* SPI_INTERFACE_H_ */
