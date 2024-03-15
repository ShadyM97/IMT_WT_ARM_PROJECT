/*
 * MSYSTICK_private.h
 *
 *  Created on: Jan 21, 2024
 *      Author: Shady
 */

#ifndef MSYSTICK_PRIVATE_H_
#define MSYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS	(0xE000E010)

#define SYSTICK_ENABLE 0
#define TICKINT		1
#define CLKSOURCE	2
#define COUNTFLAG	16


#define SYSTICK_AHB	0
#define SYSTICK_AHB_DIVIDE_8 1

typedef struct
{
	uint32 CTRL;
	uint32 LOAD;
	uint32 VAL;
	uint32 CALIB;
}SYSTICK_t;

#define SYSTICK	((volatile SYSTICK_t*)(SYSTICK_BASE_ADDRESS))


#endif /* MSYSTICK_PRIVATE_H_ */
