#include "Balancer.h"



void Balancer_init(Balancer *this_Balancer){
	this_Balancer->forward = 35;
	this_Balancer->turn = 0;
	this_Balancer->gyro_offset = 600;
}

void Balancer_balance_running(){

	balance_control(
				(F32)balancer.forward,
				(F32)balancer.turn,
				(F32)ecrobot_get_gyro_sensor(NXT_PORT_S1),
				(F32)balancer.gyro_offset,
				(F32)nxt_motor_get_count(NXT_PORT_C),
				(F32)nxt_motor_get_count(NXT_PORT_B),
				(F32)ecrobot_get_battery_voltage(),
				&pwm_l,
				&pwm_r);
				nxt_motor_set_speed(NXT_PORT_C, pwm_l, 1);
				nxt_motor_set_speed(NXT_PORT_B, pwm_r, 1);
}


void Balancer_set_forward(Balancer *this_Balancer , S8 forward){
	this_Balancer->forward = forward;
}

void Balancer_set_turn(Balancer *this_Balancer , S8 turn){
	this_Balancer->turn = turn;
}

void Balancer_set_gyro(Balancer *this_Balancer , U32 gyro){
	this_Balancer->gyro_offset = gyro;
}

