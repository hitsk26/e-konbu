#ifndef _PushButton_
#define _PushButton_

#include "../HardwareWrapper/TouchSensor.h"


typedef struct{
	U8 port_id;
}PushButton;


void PushButton_init(PushButton *this_PushButton, U8 port_id);

int PushButton_detect_push_button(PushButton *this_PushButton);

#endif

