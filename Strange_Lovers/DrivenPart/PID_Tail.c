#include "PID_Tail.h"
#include "../Factory.c"

static float i_hensa = 0;
static float bf_hensa = 0;

	
void PID_TAIL_init(PID_TAIL *this_PID_TAIL){
	i_hensa = 0;
	bf_hensa = 0;
}


void PID_tail(int target_tail_angle){

	static const float Kp_s = 2.4;
	static const float Ki_s = 0.00;
	static const float Kd_s = 0.00;
	float hensa = 0;
	float d_hensa = 0;
	float speed = 0;
	hensa = target_tail_angle - TailMotor_get_count(&tailMotor);

	i_hensa = i_hensa + (hensa*0.004);
	d_hensa = (bf_hensa - hensa)/0.004;
	bf_hensa = hensa;
	speed = Kp_s*hensa + Ki_s*i_hensa + Kd_s*d_hensa ;

	if (speed < -100) {
		speed= -100;
	}else if (speed > 100) {
		speed = 100;
	}

	TailMotor_drive_tail(&tailMotor,speed);
}

