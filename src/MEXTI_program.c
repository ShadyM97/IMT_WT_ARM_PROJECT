/*
 * MEXTI_program.c
 *
 *  Created on: Jan 18, 2024
 *      Author: Shady
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "MEXTI_private.h"
#include "MEXTI_interface.h"

static void(*GlobalExti_PTR[16])(void) ={NULL_PTR}; // array of pointers to function

void MEXTI_voidInterruptSetPort(EXTI_Line Copy_u8Line,EXTI_Port Copy_u8Port)
{
	SYSCFG->SYSCFG_EXTICR[Copy_u8Line / DIV_FAC] &= ~(MUSK <<(4 * (Copy_u8Line % DIV_FAC)));
	SYSCFG->SYSCFG_EXTICR[Copy_u8Line / DIV_FAC] |= (Copy_u8Port <<(4 * (Copy_u8Line % DIV_FAC)));
}

void MEXTI_voidInterruptEnableDisable(EXTI_Line Copy_u8IntLine , EXTI_ENDis Copy_u8ENDis)
{
	switch (Copy_u8ENDis) {
	case EXTI_Enable:
		EXTI->EXTI_IMR |= 1 << Copy_u8IntLine;
		break;
	case EXTI_Disable:
		EXTI->EXTI_IMR &= ~(1 << Copy_u8IntLine);
		break;
	default:
		break;
	}
}

void MEXTI_voidInterruptTrigger(EXTI_Line Copy_u8IntLine,EXTI_Trigger Copy_u8Trig)
{
	switch (Copy_u8Trig) {
	case EXTI_Rising:
		EXTI->EXTI_RTSR |= 1 << Copy_u8IntLine;
		EXTI->EXTI_FTSR &= ~(1 << Copy_u8IntLine);
		break;
	case EXTI_Falling:
		EXTI->EXTI_FTSR |= 1 << Copy_u8IntLine;
		EXTI->EXTI_RTSR &= ~(1 << Copy_u8IntLine);
		break;
	case EXTI_OnChange:
		EXTI->EXTI_RTSR |= 1 << Copy_u8IntLine;
		EXTI->EXTI_FTSR |= 1 << Copy_u8IntLine;
		break;
	default:
		break;
	}
}
void MEXTI0_voidCallBack(void (*ptr)(void))
{
	GlobalExti_PTR[0] = ptr;
}

void MEXTI1_voidCallBack(void (*ptr)(void))
{
	GlobalExti_PTR[1] = ptr;
}

void EXTI0_IRQHandler(void)
{
	GlobalExti_PTR[0]();
	EXTI->EXTI_PR |= 1;
}
void EXTI1_IRQHandler(void)
{
	GlobalExti_PTR[1]();
	EXTI->EXTI_PR |= (1<<1);
}
