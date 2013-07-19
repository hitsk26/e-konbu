

#include "../HardwareWrapper/SystemTimer.h"
#include "ecrobot_interface.h"

typedef struct  {
	
}Timer;

void Timer_init(Timer *this_Timer);

unsigned int Timer_get_ms(Timer *this_Timer);
