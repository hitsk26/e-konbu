#include "PID_Tail.h"
#include "Factory.c"


void PID_TAIL_init(PID_TAIL *this_PID_TAIL){

}


void PID_tail(int angle_of_aim){

	static const float Kp_s = 2.4;
	static const float Ki_s = 0.00;
	static const float Kd_s = 0.00;
	static const float b = 0;
	static float hensa = 0;
	static float i_hensa = 0;
	static float d_hensa = 0;
	static float bf_hensa = 0;
	static float speed = 0;
	
	hensa = angle_of_aim - ecrobot_get_motor_rev(NXT_PORT_A);
	i_hensa = i_hensa + (hensa*0.004);
	d_hensa = (bf_hensa - hensa)/0.004;
	bf_hensa = hensa;
	speed = Kp_s*hensa + Ki_s*i_hensa + Kd_s*d_hensa + b;

	if (speed < -100) {
		speed= -100;
	}else if (speed > 100) {
		speed = 100;
	}
	

	ecrobot_set_motor_speed(NXT_PORT_A,speed);
}

