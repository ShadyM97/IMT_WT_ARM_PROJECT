/*
 * HTFT_program.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Shady
 */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "MGPIO_interface.h"
#include "MSPI_interface.h"
#include "TIMER2_interface.h"
#include "MSYSTICK_interface.h"
#include "HTFT_config.h"
#include "HTFT_interface.h"

static void HTFT_voidWriteData(uint8 copy_u8Data);
static void HTFT_voidSendCMD(uint8 copy_u8CMD);

void HTFT_voidInit(void)
{
	/* RESET */
	MGPIO_voidSetResetPin(RESET_PIN_PORT, RESET_PIN_PIN, PIN_SET);
	TIMER2_delayus(100);
	MGPIO_voidSetResetPin(RESET_PIN_PORT, RESET_PIN_PIN, PIN_RESET);
	TIMER2_delayus(100);
	MGPIO_voidSetResetPin(RESET_PIN_PORT, RESET_PIN_PIN, PIN_SET);
	TIMER2_delayus(100);
	MGPIO_voidSetResetPin(RESET_PIN_PORT, RESET_PIN_PIN, PIN_RESET);
	TIMER2_delayus(100);
	MGPIO_voidSetResetPin(RESET_PIN_PORT, RESET_PIN_PIN, PIN_SET);
	TIMER2_delayus(100);

	/* Sleep Out */
	HTFT_voidSendCMD(0x11);

	MSYSTICK_voidDelayms(10);
	/* Color Mode (Half Parameter) */
	HTFT_voidSendCMD(0x3A);
	HTFT_voidWriteData(0x05);
	/* Display On */
	HTFT_voidSendCMD(0x29);

}

void HTFT_voidWriteData(uint8 copy_u8Data)
{
	uint8 receivedData;
	MGPIO_voidSetResetPin(A0_PIN_PORT, A0_PIN_PIN, PIN_SET);
	MSPI_voidTranseive(copy_u8Data, &receivedData);
}

/*
 * Function: HTFT_voidSendCMD
 * ---------------------------
 * Description: Sends a command to the TFT display module.
 *
 * Inputs:
 *     - copy_u8CMD: Command byte to be sent to the display
 *
 * Outputs: None
 *
 * Side Effects: Sends a command to the display module.
 *
 * Notes: Sets the A0 pin to indicate command transmission and sends the specified command byte to the display.
 */
void HTFT_voidSendCMD(uint8 copy_u8CMD)
{
	uint8 receivedData;
	MGPIO_voidSetResetPin(A0_PIN_PORT, A0_PIN_PIN, PIN_RESET);
	MSPI_voidTranseive(copy_u8CMD, &receivedData);
}
/*
 * Function: HTFT_voidDisplay
 * ---------------------------
 * Description: Displays an image on the TFT display module by sending pixel data.
 *
 * Inputs:
 *     - copy_u8Image: Pointer to the array containing pixel data of the image
 *
 * Outputs: None
 *
 * Side Effects: Sends pixel data to the display module.
 *
 * Notes: Sets the X and Y axes, writes pixel data to the display RAM, and displays the image on the screen.
 */
void HTFT_voidDisplay(const uint16 *copy_u8Image)
{
	uint16 u16pixelCounter = 0;
	uint8 u8HighData = 0;
	uint8 u8LowData	= 0;

	/* Set X Axis */
	HTFT_voidSendCMD(0x2A);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);

	HTFT_voidWriteData(0);
	HTFT_voidWriteData(127);
	/* Set Y Axis */
	HTFT_voidSendCMD(0x2B);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);

	HTFT_voidWriteData(0);
	HTFT_voidWriteData(159);
	/* Write on RAM */
	HTFT_voidSendCMD(0x2C);
	/* Display Data */
	for(u16pixelCounter = 0; u16pixelCounter < 20480; u16pixelCounter++)
	{
		u8HighData = (uint8)(copy_u8Image[u16pixelCounter] >> 8);
		u8LowData = (uint8)(copy_u8Image[u16pixelCounter]);
		HTFT_voidWriteData(u8HighData);
		HTFT_voidWriteData(u8LowData);

	}
}

/* SPI MSB
 * CPH -> 1
 * BAUD-> /2*/
/* Init: Reset Sequence */

/* Display
 * Set x
 * Set y
 * Send Data */
