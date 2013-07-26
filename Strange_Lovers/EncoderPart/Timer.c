
#include "Timer.h"

void Timer_init(Timer *this_Timer)
{
	//none
}

unsigned int Timer_get_ms(Timer *this_Timer)
{
	return (unsigned int)SystemTimer_get_ms();
}

