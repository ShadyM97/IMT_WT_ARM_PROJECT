#ifndef _OS_PRV_H
#define _OS_PRV_H
typedef enum
{
	Suspended,
	Ready
}TaskState;




typedef struct
{
	void(*TaskHandler)(void);
	uint32 periodicty;
	uint32 FirstDelay;
	TaskState RunState;

}Task;


















#endif
