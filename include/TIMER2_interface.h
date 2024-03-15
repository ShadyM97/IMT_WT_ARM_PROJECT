/*
 * TIMER1_interface.h
 *
 *  Created on: Mar 9, 2024
 *      Author: Shady
 */

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

/*
 * Function: TIMER2_delayus
 * -------------------------
 * Delays the program execution by the specified number of microseconds.
 *
 * Parameters:
 *      - u32Delay: The number of microseconds to delay.
 *
 * Returns: None
 */
void TIMER2_delayus(uint32 u32Delay);

/*
 * Function: TIMER2_delayms
 * -------------------------
 * Delays the program execution by the specified number of milliseconds.
 *
 * Parameters:
 *      - u32Delay: The number of milliseconds to delay.
 *
 * Returns: None
 */
void TIMER2_delayms(uint32 u32Delay);

#endif /* TIMER1_INTERFACE_H_ */
