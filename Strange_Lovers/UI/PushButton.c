#include "PushButton.h"


void PushButton_init(PushButton *this_PushButton, U8 port_id)
{
	this_PushButton->port_id = port_id;
}

int PushButton_detect_push_button(PushButton *this_PushButton)
{
	return TouchSensor_getTouchSensor(this_PushButton->port_id);
}
