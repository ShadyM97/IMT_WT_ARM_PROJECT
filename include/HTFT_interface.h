/*
 * HTFT_interface.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Shady
 */

#ifndef HTFT_INTERFACE_H_
#define HTFT_INTERFACE_H_

/*
 * Function: HTFT_voidInit
 * ------------------------
 * Description: Initializes the TFT display module by resetting, sending initialization commands, and setting display parameters.
 *
 * Inputs: None
 *
 * Outputs: None
 *
 * Side Effects: Resets the display, sends initialization commands, and sets display parameters.
 *
 * Notes: Resets the display module, sends initialization commands to configure parameters such as color mode,
 *        and turns on the display.
 */
void HTFT_voidInit(void);

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
void HTFT_voidDisplay(const uint16 *copy_u8Image);


#endif /* HTFT_INTERFACE_H_ */
