#ifndef __Motor
#define __Motor
#include "ecrobot_interface.h"


int Motor_get_count(U8 port_id);
void Motor_set_speed(int port_id, int pwm, int brake);


#endif