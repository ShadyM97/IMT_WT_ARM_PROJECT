/************************************************/
/* Author :JIMMY		                        */
/* Version:V01                                  */
/************************************************/
#ifndef    BASICTIMERS_PRIVATE_H
#define    BASICTIMERS_PRIVATE_H
/****************TIM2*******************/

static volatile  uint32 Global2_uint32Routine=0;
static volatile  uint32 Global2_uint32Fraction;
static volatile  uint32 Global2_uint32CopyRoutine;
static volatile  uint8  Global2_uint8Flag=1;
/* Define Callback Global Variable */
/* Define Variable for interval mode */
static volatile uint8 TIM2_uint8ModeOfInterval;

/****************TIM3*******************/

static volatile  uint32 Global3_uint32Routine=0;
static volatile  uint32 Global3_uint32Fraction;
static volatile  uint32 Global3_uint32CopyRoutine;
static volatile  uint8  Global3_uint8Flag=1;
static void (*TIM3_CallBack)(void);
static volatile  uint8     TIM3_uint8ModeOfInterval;




/*Interval Mode*/
#define    SINGLE_INTERVAL     0
#define    PERIODIC_INTERVAL   1

typedef struct
{
	volatile uint32 CR1;           /*00*/
	volatile uint32 CR2;           /*04*/
	volatile uint32 SMCR;          /*08*/
	volatile uint32 DIER;          /*0C*/
	volatile uint32 SR;            /*10*/
	volatile uint32 EGR;           /*14*/
	volatile uint32 CCMR1;         /*18*/
	volatile uint32 CCMR2;         /*1C*/
	volatile uint32 CCER;          /*20*/
	volatile uint32 CNT;           /*24*/
	volatile uint32 PSC;           /*28*/
	volatile uint32 ARR;           /*2C*/
	volatile uint32 Reserved1;     /*30*/
	volatile uint32 CCR1;          /*34*/
	volatile uint32 CCR2;          /*38*/
	volatile uint32 CCR3;          /*3C*/
	volatile uint32 CCR4;          /*40*/
	volatile uint32 Reserved2;     /*44*/
	volatile uint32 DCR;           /*48*/
	volatile uint32 DMAR;          /*4C*/
}TIM_t;
#define  TIM3    ((volatile TIM_t*)0x40000400)
#endif
