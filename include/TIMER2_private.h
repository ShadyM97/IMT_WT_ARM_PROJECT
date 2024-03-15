/*
 * TIMER1_private.h
 *
 *  Created on: Mar 9, 2024
 *      Author: Shady
 */

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#define TIMER2_BASE_ADDRESS	0x40000000

#define CR1_CKD 	8
#define CR1_ARPE 	7
#define CR1_CMS		5
#define CR1_DIR		4
#define CR1_OPM		3
#define CR1_URS		2
#define CR1_UDIS	1
#define CR1_CEN		0

#define SR_UIF		0

typedef struct{
	uint32 TIMx_CR1;
	uint32 TIMx_CR2;
	uint32 TIMx_SMCR;
	uint32 TIMx_DIER;
	uint32 TIMx_SR;
	uint32 TIMx_EGR;
	uint32 TIMx_CCMR1;
	uint32 TIMx_CCMR2;
	uint32 TIMx_CCER;
	uint32 TIMx_CNT;
	uint32 TIMx_PSC;
	uint32 TIMx_ARR;
	uint32 reserved1;
	uint32 TIMx_CCR1;
	uint32 TIMx_CCR2;
	uint32 TIMx_CCR3;
	uint32 TIMx_CCR4;
	uint32 reserved2;
	uint32 TIMx_DCR;
	uint32 TIMx_DMAR;
	uint32 TIM2_OR;
} TIMER_t;

#define TIMER2	((volatile TIMER_t*)(TIMER2_BASE_ADDRESS))
#endif /* TIMER1_PRIVATE_H_ */
