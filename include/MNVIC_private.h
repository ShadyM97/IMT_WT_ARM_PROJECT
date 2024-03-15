/*
 * MNVIC_private.h
 *
 *  Created on: Jan 17, 2024
 *      Author: Shady
 */

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS	0xE000E100
#define MNVIC_VECTKEY	0x05FA0000
#define REG_DIV		32

typedef struct
{
	uint32 ISER[8];
	uint32 reserved1[24];
	uint32 ICER[8];
	uint32 reserved2[24];
	uint32 ISPR[8];
	uint32 reserved3[24];
	uint32 ICPR[8];
	uint32 reserved4[24];
	uint32 IABR[8];
	uint32 reserved5[56];
	uint8 IPR[240];
	uint32 reserved6[580];

}NVIC_t;

#define NVIC	((volatile NVIC_t*)(NVIC_BASE_ADDRESS))
#define SCB_AIRCR *((volatile uint32*)(0xE000ED0C))

#endif /* MNVIC_PRIVATE_H_ */
