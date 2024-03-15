/*
 * MEXTI_private.h
 *
 *  Created on: Jan 18, 2024
 *      Author: Shady
 */

#ifndef MEXTI_PRIVATE_H_
#define MEXTI_PRIVATE_H_


#define EXTI_BASE_ADDRESS	0x40013C00
#define SYSCFG_BASE_ADDRESS	0x40013800

#define DIV_FAC	4
#define MUSK	15
typedef struct
{
	uint32 EXTI_IMR;
	uint32 EXTI_EMR;
	uint32 EXTI_RTSR;
	uint32 EXTI_FTSR;
	uint32 EXTI_SWIER;
	uint32 EXTI_PR;

}EXTI_t;

typedef struct
{
	uint32 SYSCFG_MEMRMP;
	uint32 SYSCFG_PMC;
	uint32 SYSCFG_EXTICR[4];
	uint32 reserved[2];
	uint32 SYSCFG_CMPCR;
}SYSCFG_t;


#define EXTI	((volatile EXTI_t*)(EXTI_BASE_ADDRESS))
#define SYSCFG	((volatile SYSCFG_t*)(SYSCFG_BASE_ADDRESS))



#endif /* MEXTI_PRIVATE_H_ */
