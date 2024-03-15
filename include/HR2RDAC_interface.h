/*
 * HR2RDAC_interface.h
 *
 *  Created on: Jan 23, 2024
 *      Author: Shady
 */

#ifndef HR2RDAC_INTERFACE_H_
#define HR2RDAC_INTERFACE_H_

#define SAMPLING_RATE	125 // 8kHz

/*
 * Function: HR2RDAC_voidinit
 * ---------------------------
 * Description: Initializes the HR2RDAC module by configuring GPIO pins and setting output modes.
 *
 * Inputs: None
 *
 * Outputs: None
 *
 * Side Effects: Configures GPIO pins and sets output modes for the HR2RDAC module.
 *
 * Notes: Configures each GPIO pin of the DAC_PORT as output and sets its output mode to push-pull with mid speed.
 */
void HR2RDAC_voidinit(void);
/*
 * Function: HR2RDAC_voidSetData
 * ------------------------------
 * Description: Sets data to the HR2RDAC module by writing bits to GPIO pins and delaying between each write.
 *
 * Inputs:
 *     - p8arr: Pointer to the array containing data to be set
 *     - u32arrSize: Size of the data array
 *
 * Outputs: None
 *
 * Side Effects: Writes data bits to GPIO pins and introduces delay between writes.
 *
 * Notes: Iterates through the data array and writes each bit to the corresponding GPIO pin of the DAC_PORT.
 *        Delays 100 microseconds between each write operation.
 */
void HR2RDAC_voidSetData(const uint8 *p8arr, uint32 u32arrSize);


#endif /* HR2RDAC_INTERFACE_H_ */
