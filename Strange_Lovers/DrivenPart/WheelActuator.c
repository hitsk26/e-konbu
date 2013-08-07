#include "WheelActuator.h"
#include "../Factory.h"


void WheelActuator_init(WheelActuator *this_WheelActuator){
	this_WheelActuator->forward = 35;
	this_WheelActuator->turn = 0;
	this_WheelActuator->gyro_offset = 600;
}

void WheelActuator_balance_running(WheelActuator *this_WheelActuator,S8 *pwm_l,S8 *pwm_r){
	
	balance_control(
				(F32)this_WheelActuator->forward,
				(F32)this_WheelActuator->turn,
				(F32)InclinationEncoder_get_inclination(&inclinationEncoder),
				(F32)inclinationEncoder.gyro_offset,
				(F32)nxt_motor_get_count(NXT_PORT_C),
				(F32)nxt_motor_get_count(NXT_PORT_B),
				(F32)ecrobot_get_battery_voltage(),
				pwm_l,
				pwm_r);
}


void WheelActuator_set_forward(WheelActuator *this_WheelActuator , S8 forward){
	this_WheelActuator->forward = forward;
}

void WheelActuator_set_turn(WheelActuator *this_WheelActuator , S8 turn){
	this_WheelActuator->turn = turn;
}

void WheelActuator_tail_running(WheelActuator *this_WheelActuator,S8 *pwm_l,S8 *pwm_r){
	*pwm_l = cutoff(this_WheelActuator->forward + 	this_WheelActuator->turn,100);
	*pwm_r = cutoff(this_WheelActuator->forward - 	this_WheelActuator->turn,100);

}

void WheelActuator_dirve_motors(WheelActuator *this_WheelActuator){
	S8 pwm_l=0,pwm_r=0;
	if(this_WheelActuator->self_balancing_requirment == 1){
		WheelActuator_balance_running(&wheelActuator,&pwm_l,&pwm_r);
	}
	else if(this_WheelActuator->self_balancing_requirment==0){
		 WheelActuator_tail_running(&wheelActuator,&pwm_l,&pwm_r);
	}
	else {
	//fetal error
	}

	WheelMotor_drive_motor(&leftWheelMotor,pwm_l);
	WheelMotor_drive_motor(&rightWheelMotor,pwm_r);
}


void WheelActuator_set_self_balancing_requirement(WheelActuator *this_WheelActuator,int self_balancing_requirment){
	this_WheelActuator->self_balancing_requirment= self_balancing_requirment;
}