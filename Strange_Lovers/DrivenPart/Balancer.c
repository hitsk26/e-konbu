#include "Balancer.h"
#include "Factory.h"


void Balancer_init(Balancer *this_Balancer){
	this_Balancer->forward = 35;
	this_Balancer->turn = 0;
	this_Balancer->gyro_offset = 600;
}

void Balancer_balance_running(Balancer *this_Balancer){
	S8 pwm_l=0,pwm_r=0;
	
	balance_control(
				(F32)this_Balancer->forward,
				(F32)this_Balancer->turn,
				(F32)InclinationEncoder_get_inclination(&inclinationEncoder),
				(F32)balancer.gyro_offset,
				(F32)nxt_motor_get_count(NXT_PORT_C),
				(F32)nxt_motor_get_count(NXT_PORT_B),
				(F32)ecrobot_get_battery_voltage(),
				&pwm_l,
				&pwm_r);
				WheelMotor_drive_motor(&leftWheelMotor,pwm_l);
				WheelMotor_drive_motor(&rightWheelMotor,pwm_r);
}


void Balancer_set_forward(Balancer *this_Balancer , S8 forward){
	this_Balancer->forward = forward;
}

void Balancer_set_turn(Balancer *this_Balancer , S8 turn){
	this_Balancer->turn = turn;
}

void Balancer_set_gyro(Balancer *this_Balancer , U32 gyro_offset){
	this_Balancer->gyro_offset = gyro_offset;
}

