/************************************************/
/* Author :jIMMY                       			*/
/* Version:V01                                  */
/************************************************/ 
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GPTIM_private.h"
#include"GPTIM_config.h"
#include"GPTIM_interface.h"

void TIM3_voidInit(void)
{
	/*Up Counter Mode*/
	TIM3->CR1&=~(0b111<<4);
	TIM3->CR1|=(DOWNCOUNTER<<4);

	/*ARR is Buffered can't changed Execpt at Update Event*/
	SET_BIT(TIM3->CR1,CR1_ARPE);

	/*Only Counter OverFlow UnderFlow Generate update Interrupt */
	SET_BIT(TIM3->CR1,CR1_URS);

	/*Enable Update Event */
	CLR_BIT(TIM3->CR1,CR1_UDIS);

	/*Disable Update Interrupt */
	CLR_BIT(TIM3->DIER,DIER_UIE);

	/*F(TIM2)=8M/(1+PSC)=1MHz
	*Ticks equal 1us*/
	TIM3->PSC = TIMER_PRESCALER;
}

void TIM3_voidSetIntervalSingle( uint32 Copy_uint32Ticks, void (*Copy_ptr)(void) )
{
	/*save CallBack*/
	TIM3_CallBack=Copy_ptr;
	/*Set Mode to Single*/
	TIM3_uint8ModeOfInterval=SINGLE_INTERVAL;

	Global3_uint32Routine =(Copy_uint32Ticks/65535);
	Global3_uint32Fraction=Copy_uint32Ticks%65535;
	/*    to be initialize before enter the interrupt */
	Global3_uint32CopyRoutine=Global3_uint32Routine;
	/*stop timer */
	CLR_BIT(TIM3->CR1, CR1_CEN);

	if(Global3_uint32Routine)
	{
		TIM3->ARR=65535;
	    /*Re-Initialize the the counter & prescaler*/
	    SET_BIT(TIM3->EGR,EGR_UG);
		/*Enable counter*/
		SET_BIT(TIM3->CR1,CR1_CEN);
	}
	else
	{
		TIM3->ARR=Global3_uint32Fraction;
	    /*Re-Initialize the the counter & prescaler*/
	    SET_BIT(TIM3->EGR, EGR_UG);
		/*Enable counter*/
		SET_BIT(TIM3->CR1, CR1_CEN);
	}

	/*Enable Update Interrupt */
	SET_BIT(TIM3->DIER, DIER_UIE);
}
void TIM3_voidSetIntervalPeriodic( uint32 Copy_uint32Ticks, void (*Copy_ptr)(void) )
{
	/*save CallBack*/
	TIM3_CallBack=Copy_ptr;
	/*Set Mode to Periodic*/
	TIM3_uint8ModeOfInterval=PERIODIC_INTERVAL;

	Global3_uint32Routine =(Copy_uint32Ticks/65535) ;
	Global3_uint32Fraction=Copy_uint32Ticks%65535;

	if(Global3_uint32Routine)
	{
		TIM3->ARR=65535;
	    /*Re-Initialize the the counter & prescaler*/
	    SET_BIT(TIM3->EGR,EGR_UG);
		/*Enable counter*/
		SET_BIT(TIM3->CR1,CR1_CEN);
	}
	else
	{
		TIM3->ARR=Global3_uint32Fraction;
	    /*Re-Initialize the the counter & prescaller*/
	    SET_BIT(TIM3->EGR,EGR_UG);
		/*Enable counter*/
		SET_BIT(TIM3->CR1,CR1_CEN);
	}

	/*Enable Update Interrupt */
	SET_BIT(TIM3->DIER,DIER_UIE);
}

uint32  TIM3_u16GetElapsedTime(void)
{
	uint32 Local_uint32ElapsedTime;
	uint16 Local_uint16Cycle=Global3_uint32Routine - Global3_uint32CopyRoutine;

	Local_uint32ElapsedTime=((TIM3->ARR)-(TIM3->CNT))+(Local_uint16Cycle*65535);
	return Local_uint32ElapsedTime;
}

/**************TIM3***********************/
void TIM3_IRQHandler(void)
{
	if(Global3_uint8Flag){
		Global3_uint32CopyRoutine=Global3_uint32Routine;
		Global3_uint8Flag=0;
	}
	if((Global3_uint32CopyRoutine)>1)
	{
		Global3_uint32CopyRoutine--;
		//Clear Underflow Flag
		CLR_BIT(TIM3->SR,SR_UIF);
		TIM3->ARR=65535;
	    //*Re-Initialize the the counter & prescaller
	    SET_BIT(TIM3->EGR,EGR_UG);

	}
	else if((Global3_uint32CopyRoutine)==1)
	{
		Global3_uint32CopyRoutine--;
		/* Clear Underflow Flag */
		CLR_BIT(TIM3->SR,SR_UIF);
		TIM3->ARR=Global3_uint32Fraction;
	    /* Re-Initialize the the counter & prescaler */
	    SET_BIT(TIM3->EGR,EGR_UG);

	}
	else
	{
		if(TIM3_uint8ModeOfInterval==SINGLE_INTERVAL)
		{
			//*Disable Update Interrupt
	        CLR_BIT(TIM3->DIER,DIER_UIE);
			//*Stop Timer
			CLR_BIT(TIM3->CR1,CR1_CEN);
		}
		//*Callback Notification
		TIM3_CallBack();
		//Clear Underflow Flag/
		CLR_BIT(TIM3->SR,SR_UIF);

		if(Global3_uint32Routine)TIM3->ARR=65535;
		else TIM3->ARR=Global3_uint32Fraction;
	    //*Re-Initialize the the counter & prescaler
	    SET_BIT(TIM3->EGR,EGR_UG);

		Global3_uint8Flag=1;
	}

}
