#include "Starter.h"
#include "../Factory.h"


void Starter_init(Starter *self)
{
	
}

void Starter_accept_start_run(Starter *self)
{
	if(PushButton_detect_push_button(&pushButton) == TRUE){ 
		ecrobot_sound_tone(880, 512, 30);
		systick_wait_ms(500);
		initialization();
		Timer_reset(&timer);
		Runner_start_run(&runner);
	}

}

void Starter_accept_stop_run(Starter *self)
{
	if(PushButton_detect_push_button(&pushButton) == TRUE){ 
		ecrobot_sound_tone(880, 512, 30);
		systick_wait_ms(500);
		Runner_stop_run(&runner);
	}
}

