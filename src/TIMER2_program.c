/*
 * TIMER2_program.c
 *
 *  Created on: Mar 9, 2024
 *      Author: Shady
 */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "TIMER2_private.h"
#include "TIMER2_config.h"
#include "TIMER2_interface.h"

void TIMER2_delayus(uint32 u32Delay)
{
	TIMER2->TIMx_PSC = 16 - 1; // Set prescaler to get 16MHz/16 for Microsecond
	TIMER2->TIMx_ARR = u32Delay; // us
	TIMER2->TIMx_CNT = 0;
	SET_BIT(TIMER2->TIMx_CR1, CR1_CEN);

	while (!GET_BIT(TIMER2->TIMx_SR, SR_UIF));
	CLR_BIT(TIMER2->TIMx_SR, SR_UIF);
}
void TIMER2_delayms(uint32 u32Delay)
{
	TIMER2->TIMx_PSC = 16000 - 1; // Set prescaler to get 16MHz/16000 for Millisecond
	TIMER2->TIMx_ARR = u32Delay; // ms
	TIMER2->TIMx_CNT = 0;
	SET_BIT(TIMER2->TIMx_CR1, CR1_CEN);

	while (!GET_BIT(TIMER2->TIMx_SR, SR_UIF));
	CLR_BIT(TIMER2->TIMx_SR, SR_UIF);
}
