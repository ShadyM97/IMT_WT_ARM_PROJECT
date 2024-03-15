#ifndef _OS_INT_H
#define _OS_INT_H

/*
 * Function: OS_u8CreateTask
 * --------------------------
 * Description: Creates a new task with the specified parameters and adds it to the task list.
 *
 * Inputs:
 *     - copy_Handler: Pointer to the task function
 *     - Copy_u8Periodicty: Periodicity of the task in system ticks
 *     - Copy_u8Periority: Priority of the task
 *     - Copy_u8FirstDelay: Initial delay before the task starts executing
 *
 * Outputs:
 *     - Returns an error code:
 *         - 0: No error
 *         - 1: Maximum number of tasks exceeded
 *         - 2: Task with the same priority already exists
 *
 * Side Effects: Modifies the global variables 'SystemTask' and 'TaskTiming'
 *
 * Notes: Checks if the specified priority is within the allowed range.
 *        Checks if a task with the same priority already exists.
 *        Adds the new task to the task list if conditions are met.
 */
uint8 OS_u8CreateTask(void(*copy_Handler)(void),uint32 Copy_u8Periodicty,uint8 Copy_u8Periority,uint8 Copy_u8FirstDelay);

/*
 * Function: Scheduler
 * --------------------
 * Description: Manages task execution based on their priority and periodicity.
 *
 * Inputs: None
 *
 * Outputs: None
 *
 * Side Effects: Modifies the global variables 'SystemTask' and 'TaskTiming'
 *
 * Notes: Loops through all tasks and checks if they are ready to run.
 *        Executes ready tasks and updates their timing.
 */
void Scheduler(void);

/*
 * Function: OS_DeleteTask
 * ------------------------
 * Description: Deletes a task with the specified priority.
 *
 * Inputs:
 *     - Copy_u8Periority: Priority of the task to delete
 *
 * Outputs: None
 *
 * Side Effects: Modifies the global variable 'SystemTask'
 *
 * Notes: Sets the task entry to an empty state, effectively removing it from the task list.
 */
void OS_DeleteTask(uint8 Copy_u8Periority);

/*
 * Function: SuspendTask
 * ----------------------
 * Description: Suspends a task with the specified priority.
 *
 * Inputs:
 *     - Copy_u8Periority: Priority of the task to suspend
 *
 * Outputs: None
 *
 * Side Effects: Modifies the 'RunState' field of the specified task
 *
 * Notes: Changes the run state of the task to 'Suspended', preventing it from executing.
 */
void SuspendTask(uint8 Copy_u8Periority);

/*
 * Function: ResumeTask
 * ---------------------
 * Description: Resumes a suspended task with the specified priority.
 *
 * Inputs:
 *     - Copy_u8Periority: Priority of the task to resume
 *
 * Outputs: None
 *
 * Side Effects: Modifies the 'RunState' field of the specified task
 *
 * Notes: Changes the run state of the task to 'Ready', allowing it to execute.
 */
void ResumeTask(uint8 Copy_u8Periority);

/*
 * Function: StartOS
 * -----------------
 * Description: Initializes and starts the operating system by setting up the system tick timer to call the scheduler periodically.
 *
 * Inputs: None
 *
 * Outputs: None
 *
 * Side Effects: None
 *
 * Notes: Configures the system tick timer to generate periodic interrupts with a period defined by TICK_TIME.
 *        Calls the scheduler function (Scheduler) whenever the system tick interrupt occurs.
 */
void StartOS(void);
















#endif
