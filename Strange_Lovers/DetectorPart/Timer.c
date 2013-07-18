
#include "Timer.h"

void Timer_init(Timer *this_Timer)
{
	//none
}

int Timer_get_ms(Timer *this_Timer)
{
	return (int)SystemTimer_get_ms();
}

