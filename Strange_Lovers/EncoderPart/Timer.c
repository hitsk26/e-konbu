
#include "Timer.h"

void Timer_init(Timer *this_Timer)
{
	//none
}

unsigned int Timer_get_ms(Timer *this_Timer)
{
	return (unsigned int)SystemTimer_get_ms() - this_Timer->initial_time;
}

void Timer_reset(Timer *this_Timer)
{
	this_Timer->init_time = (unsigned int)SystemTimer_get_ms();;
}
