#ifndef MSYSTICK_INT_H
#define MSYSTICK_INT_H

typedef enum
{
	SYSTICKEnable,
	SYSTICKDisable
}SYSTICKState;


/*
 * Function: MSYSTICK_voidInit
 * ---------------------------
 * Description: Initializes the system tick timer according to the configured settings.
 *
 * Inputs: None
 *
 * Outputs: None
 *
 * Side Effects: Modifies the SYSTICK registers
 *
 * Notes: Configures the system tick timer source clock and clears any previous configuration.
 */
void MSYSTICK_voidInit(void);

/*
 * Function: MSYSTICK_voidStart
 * ----------------------------
 * Description: Starts the system tick timer with the specified load value.
 *
 * Inputs:
 *     - Copy_uint32Loadvalue: Load value for the system tick timer
 *
 * Outputs: None
 *
 * Side Effects: Modifies the SYSTICK registers
 *
 * Notes: Loads the specified value into the SYSTICK LOAD register and starts the timer.
 */
void MSYSTICK_voidStart(uint32 Copy_uint32Loadvalue);

/*
 * Function: MSYSTICK_voidReadFlag
 * --------------------------------
 * Description: Reads the count flag of the system tick timer.
 *
 * Inputs: None
 *
 * Outputs:
 *     - Returns 1 if the count flag is set, otherwise returns 0
 *
 * Side Effects: None
 *
 * Notes: Reads the COUNTFLAG bit of the SYSTICK CTRL register.
 */
uint8   MSYSTICK_voidReadFlag(void);

/*
 * Function: MSYSTICK_voidCtrlIntState
 * ------------------------------------
 * Description: Controls the interrupt state of the system tick timer.
 *
 * Inputs:
 *     - Copy_State: State of the system tick timer interrupt (Enable or Disable)
 *
 * Outputs: None
 *
 * Side Effects: Modifies the SYSTICK CTRL register
 *
 * Notes: Sets or clears the TICKINT bit of the SYSTICK CTRL register based on the input state.
 */
void MSYSTICK_voidCtrlIntState(SYSTICKState Copy_State );

/*
 * Function: MSYSTICK_voidDelayUs
 * -------------------------------
 * Description: Delays the execution by the specified number of microseconds.
 *
 * Inputs:
 *     - Copy_uint32Delayvalue: Delay value in microseconds
 *
 * Outputs: None
 *
 * Side Effects: Modifies the SYSTICK registers
 *
 * Notes: Disables the system tick timer interrupts, starts the timer with the appropriate load value,
 *        and waits until the count flag is set.
 */
void MSYSTICK_voidDelayUs(uint32 Copy_uint32Delayvalue);

/*
 * Function: MSYSTICK_voidDelayms
 * --------------------------------
 * Description: Delays the execution by the specified number of milliseconds.
 *
 * Inputs:
 *     - Copy_uint32Delayvalue: Delay value in milliseconds
 *
 * Outputs: None
 *
 * Side Effects: Modifies the SYSTICK registers
 *
 * Notes: Disables the system tick timer interrupts, starts the timer with the appropriate load value,
 *        and waits until the count flag is set.
 */
void MSYSTICK_voidDelayms(uint32 Copy_uint32Delayvalue);

/*
 * Function: MSYSTICK_uint32GetElapsedTime
 * ---------------------------------------
 * Description: Calculates the elapsed time since the start of the system tick timer.
 *
 * Inputs: None
 *
 * Outputs:
 *     - Returns the elapsed time in system ticks
 *
 * Side Effects: None
 *
 * Notes: Subtracts the current value of the SYSTICK VAL register from the SYSTICK LOAD register.
 */
uint32  MSYSTICK_uint32GetElapsedTime(void);
/*
 * Function: MSYSTICK_uint32GetRemainingTime
 * -----------------------------------------
 * Description: Calculates the remaining time until the system tick timer reaches its load value.
 *
 * Inputs: None
 *
 * Outputs:
 *     - Returns the remaining time in system ticks
 *
 * Side Effects: None
 *
 * Notes: Returns the value of the SYSTICK VAL register.
 */
uint32  MSYSTICK_uint32GetRemainingTime(void);

/*
 * Function: MSYSTICK_voidSetInterval_single
 * -----------------------------------------
 * Description: Sets a single-shot interval for the system tick timer and associates a callback function to be called upon completion.
 *
 * Inputs:
 *     - Copy_uint32Loadvalue: Load value for the system tick timer
 *     - CallbackFunction: Pointer to the callback function
 *
 * Outputs: None
 *
 * Side Effects: Modifies the SYSTICK registers
 *
 * Notes: Enables system tick timer interrupts, starts the timer with the specified load value,
 *        and associates the provided callback function with the system tick interrupt.
 */
void MSYSTICK_voidSetInterval_single(uint32 Copy_uint32Loadvalue, void (*CallbackFunction)(void));

/*
 * Function: MSYSTICK_voidSetInterval_periodic
 * -------------------------------------------
 * Description: Sets a periodic interval for the system tick timer and associates a callback function to be called upon each timer expiration.
 *
 * Inputs:
 *     - Copy_uint32Loadvalue: Load value for the system tick timer
 *     - CallbackFunction: Pointer to the callback function
 *
 * Outputs: None
 *
 * Side Effects: Modifies the SYSTICK registers
 *
 * Notes: Enables system tick timer interrupts, starts the timer with the specified load value,
 *        and associates the provided callback function with the system tick interrupt.
 */
void MSYSTICK_voidSetInterval_periodic(uint32 Copy_uint32Loadvalue, void (*CallbackFunction)(void));
















#endif
