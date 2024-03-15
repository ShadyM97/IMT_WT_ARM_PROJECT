/************************************************/
/* Author :Jimmy                      		    */
/* Version:V01                                  */
/************************************************/
#ifndef    GPTIM_INTERFACE_H
#define    GPTIM_INTERFACE_H

/********************CR1**********************/
#define   CR1_CEN           0
#define   CR1_UDIS          1
#define   CR1_URS           2
#define   CR1_OPM           3
#define   CR1_ARPE          7
/******************DIER***********************/
#define   DIER_UIE           0
/*******************EGR**************************/
#define   EGR_UG            0
/*******************SR***************************/
#define   SR_UIF           0
/********************TIM3********************/

void TIM3_voidInit(void);
void TIM3_voidSetBusyWait( uint32 Copy_uint32Ticks );
void TIM3_voidSetIntervalSingle  ( uint32 Copy_uint32Ticks, void (*Copy_ptr)(void) );
void TIM3_voidSetIntervalPeriodic( uint32 Copy_uint32Ticks, void (*Copy_ptr)(void) );
void TIM3_voidStopInterval(void);
uint32  TIM3_u16GetElapsedTime(void);
uint32  TIM3_u16GetRemainingTime(void);




#endif
