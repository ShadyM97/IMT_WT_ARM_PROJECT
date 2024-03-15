/*
 * HIR_program.c
 *
 *  Created on: Jan 29, 2024
 *      Author: Shady
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "GPTIM_interface.h"
#include "HIR_interface.h"

uint8 u8Flag = 0;
uint32 u32FrameData[50] = {0};
uint8 u8EdgeCounter = 0;
uint8 u8DataReceived = 0;
uint8 buttonPressed = 0;

void HIR_voidReceiveData(void)
{
	if (u8DataReceived == BUTTON_LEFT)
	{
		buttonPressed = LEFT;
	}
	else if(u8DataReceived == BUTTON_RIGHT)
	{
		buttonPressed = RIGHT;
	}
	else if(u8DataReceived == BUTTON_UP)
	{
		buttonPressed = UP;
	}
	else if(u8DataReceived == BUTTON_DOWN)
	{
		buttonPressed = DOWN;
	}
	else
	{
		buttonPressed = NO_BUTTON_PRESSED;
	}
}

void HIR_voidReceiveFrame(void)
{
	if (u8Flag == 0)
	{
		//Start Timer
		TIM3_voidSetIntervalSingle(100000, HIR_voidParseData);
		// Set Flag
		u8Flag = 1;
	}
	else
	{
		// Get Elapsed Time and put in Array
		u32FrameData[u8EdgeCounter] = (TIM3_u16GetElapsedTime() / 2);
		TIM3_voidSetIntervalSingle(100000, HIR_voidParseData);
		u8EdgeCounter++;
	}
}

void HIR_voidParseData(void)
{
	uint8 u8ArrCounter = 0;
	u8DataReceived = 0;

	if ((u32FrameData[0] >= 10000) && (u32FrameData[0] <= 15000))
	{
		for (u8ArrCounter = 0; u8ArrCounter < 8; u8ArrCounter++)
		{
			// Set Data Bit if 2000 to 2300
			if ((u32FrameData[u8ArrCounter + 17] >= 2000) && (u32FrameData[u8ArrCounter + 17] <= 2300))
			{
				SET_BIT(u8DataReceived, u8ArrCounter);
			}
			// Clear Data Bit
			else
			{
				CLR_BIT(u8DataReceived, u8ArrCounter);
			}
		}
		/* Send received Data */
		HIR_voidReceiveData();
	}
	else
	{
		/* Invalid Frame */
	}
	u8Flag    		= 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}

