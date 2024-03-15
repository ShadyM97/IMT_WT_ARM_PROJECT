/*
 * HR2RDAC_program.c
 *
 *  Created on: Jan 23, 2024
 *      Author: Shady
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "TIMER2_interface.h"
#include "HR2RDAC_config.h"
#include "HR2RDAC_interface.h"

void HR2RDAC_voidinit(void)
{
	MGPIO_voidSetMode(DAC_PORT, PIN_0,PIN_OUTPUT);
	MGPIO_voidSetMode(DAC_PORT, PIN_1,PIN_OUTPUT);
	MGPIO_voidSetMode(DAC_PORT, PIN_2,PIN_OUTPUT);
	MGPIO_voidSetMode(DAC_PORT, PIN_3,PIN_OUTPUT);
	MGPIO_voidSetMode(DAC_PORT, PIN_4,PIN_OUTPUT);
	MGPIO_voidSetMode(DAC_PORT, PIN_5,PIN_OUTPUT);
	MGPIO_voidSetMode(DAC_PORT, PIN_6,PIN_OUTPUT);
	MGPIO_voidSetMode(DAC_PORT, PIN_7,PIN_OUTPUT);

	MGPIO_voidSetOutputMode(DAC_PORT, PIN_0, PUSH_PULL, MID_SPEED);
	MGPIO_voidSetOutputMode(DAC_PORT, PIN_1, PUSH_PULL, MID_SPEED);
	MGPIO_voidSetOutputMode(DAC_PORT, PIN_2, PUSH_PULL, MID_SPEED);
	MGPIO_voidSetOutputMode(DAC_PORT, PIN_3, PUSH_PULL, MID_SPEED);
	MGPIO_voidSetOutputMode(DAC_PORT, PIN_4, PUSH_PULL, MID_SPEED);
	MGPIO_voidSetOutputMode(DAC_PORT, PIN_5, PUSH_PULL, MID_SPEED);
	MGPIO_voidSetOutputMode(DAC_PORT, PIN_6, PUSH_PULL, MID_SPEED);
	MGPIO_voidSetOutputMode(DAC_PORT, PIN_7, PUSH_PULL, MID_SPEED);

}

void HR2RDAC_voidSetData(const uint8 *p8arr, uint32 u32arrSize)
{
	uint32 u32counter;
	for(u32counter = 0; u32counter < u32arrSize; u32counter++)
	{
		MGPIO_voidWritePin(DAC_PORT, PIN_0, GET_BIT(p8arr[u32counter], PIN_0));
		MGPIO_voidWritePin(DAC_PORT, PIN_1, GET_BIT(p8arr[u32counter], PIN_1));
		MGPIO_voidWritePin(DAC_PORT, PIN_2, GET_BIT(p8arr[u32counter], PIN_2));
		MGPIO_voidWritePin(DAC_PORT, PIN_3, GET_BIT(p8arr[u32counter], PIN_3));
		MGPIO_voidWritePin(DAC_PORT, PIN_4, GET_BIT(p8arr[u32counter], PIN_4));
		MGPIO_voidWritePin(DAC_PORT, PIN_5, GET_BIT(p8arr[u32counter], PIN_5));
		MGPIO_voidWritePin(DAC_PORT, PIN_6, GET_BIT(p8arr[u32counter], PIN_6));
		MGPIO_voidWritePin(DAC_PORT, PIN_7, GET_BIT(p8arr[u32counter], PIN_7));
		TIMER2_delayus(100);
	}
}
