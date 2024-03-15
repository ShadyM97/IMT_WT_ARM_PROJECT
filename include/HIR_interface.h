/*
 * HIR_interface.h
 *
 *  Created on: Jan 29, 2024
 *      Author: Shady
 */

#ifndef HIR_INTERFACE_H_
#define HIR_INTERFACE_H_

#define BUTTON_UP		0x1A
#define BUTTON_DOWN		0x48
#define BUTTON_LEFT		0x47
#define BUTTON_RIGHT	0x7

typedef enum
{
	NO_BUTTON_PRESSED,
	LEFT,
	RIGHT,
	UP,
	DOWN,
}Button_Pressed_t;
extern Button_Pressed_t buttonPressed;

/*
 * Function: HIR_voidReceiveFrame
 * ------------------------------
 * Description: Receives and parses the frame data from the IR sensor.
 *
 * Inputs: None
 *
 * Outputs: None
 *
 * Side Effects: Modifies global variables 'u8Flag', 'u8EdgeCounter', and 'u32FrameData'.
 *
 * Notes: Checks the value of 'u8Flag' to determine if it needs to start a new frame reception or continue receiving data.
 *        Sets the timer interval and collects the elapsed time data into 'u32FrameData'.
 */
void HIR_voidReceiveFrame(void);

/*
 * Function: HIR_voidParseData
 * ---------------------------
 * Description: Parses the received frame data and interprets it to determine the button pressed.
 *
 * Inputs: None
 *
 * Outputs: None
 *
 * Side Effects: Modifies global variables 'u8DataReceived', 'u8Flag', 'u32FrameData', and 'u8EdgeCounter'.
 *
 * Notes: Checks the validity of the received frame and extracts the data bits corresponding to the button press.
 *        Interprets the button pressed and sets 'u8DataReceived' accordingly.
 *        Prepares for the next frame reception by resetting 'u8Flag', 'u32FrameData[0]', and 'u8EdgeCounter'.
 */
void HIR_voidParseData(void);

/*
 * Function: HIR_voidReceiveData
 * ------------------------------
 * Description: Interprets the received data from the IR remote control and determines the corresponding button pressed.
 *
 * Inputs: None
 *
 * Outputs: None
 *
 * Side Effects: Modifies the global variable 'buttonPressed'
 *
 * Notes: Checks the value of 'u8DataReceived', which represents the received data from the IR sensor.
 *        Sets 'buttonPressed' to the appropriate button identifier ('LEFT', 'RIGHT', 'UP', 'DOWN', or 'NO_BUTTON_PRESSED').
 */
void HIR_voidReceiveData(void);

#endif /* HIR_INTERFACE_H_ */
