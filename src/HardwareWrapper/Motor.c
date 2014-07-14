#include "Motor.h"

int Motor_get_count(U32 port_id)
{
	return nxt_motor_get_count(port_id);
}

void Motor_set_speed(U32 port_id, int pwm, int brake)
{
	nxt_motor_set_speed(port_id,pwm,brake);
}

void Motor_set_count(U32 port_id,int count)
{
	nxt_motor_set_count(port_id,count);
}