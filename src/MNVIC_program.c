/*
 * MNVIC_program.c
 *
 *  Created on: Jan 17, 2024
 *      Author: Shady
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "MNVIC_private.h"
#include "MNVIC_interface.h"

static uint8 Global_u8GroupPriority = 0;

void NVIC_voidEnable(uint32 position)
{
	NVIC->ISER[position / REG_DIV] |= 1 << (position % REG_DIV);
}

void NVIC_voidDisable(uint32 position)
{
	NVIC->ICPR[position / REG_DIV] |= 1 << (position % REG_DIV);
}

void NVIC_voidPendingSet(uint32 position)
{
	NVIC->ISPR[position / REG_DIV] |= 1 << (position % REG_DIV);
}

void NVIC_voidPendingClear(uint32 position)
{
	NVIC->ICPR[position / REG_DIV] |= 1 << (position % REG_DIV);
}
void NVIC_voidSetInterruptGroupMode(MNVIC_Group_t Copy_uddtGroupMode)
{
	Global_u8GroupPriority = Copy_uddtGroupMode;
	uint32 u32Data = MNVIC_VECTKEY | (Copy_uddtGroupMode<<8);
	SCB_AIRCR = u32Data;
}
void NVIC_voidSetInterruptPriority(uint8 Copy_u8IntPos,uint8 Copy_u8GroupNum,uint8 Copy_u8SubGroupNum)
{
	switch(Global_u8GroupPriority)
	{
	case Group16Sub0:
		NVIC->IPR[Copy_u8IntPos] |= Copy_u8GroupNum<<4;
		break;
	case Group8Sub2:
		NVIC->IPR[Copy_u8IntPos] |= Copy_u8GroupNum<<5 | Copy_u8SubGroupNum<<4;
		break;
	case Group4Sub4:
		NVIC->IPR[Copy_u8IntPos] |= Copy_u8GroupNum<<6 | Copy_u8SubGroupNum<<4;
		break;
	case Group2Sub8:
		NVIC->IPR[Copy_u8IntPos] |= Copy_u8GroupNum<<7 | Copy_u8SubGroupNum<<4;
		break;
	case Group0Sub16:
		NVIC->IPR[Copy_u8IntPos] |= Copy_u8SubGroupNum<<4;
		break;
	}
}

