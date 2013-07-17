#include "PID_Brightness.h"
#include "Factory.h"

void PID_Brightness(){

	static	float	hensa = 0;
	static	int		turn = 0;

	static const float Kp =	1.0;
	static const float Ki =	0.0	;
	static const float Kd =	0.0	;
	static const float b = 0;

	static float i_hensa = 0;
	static float d_hensa = 0;
	static float bf_hensa = 0;

	

	hensa = Target_value_get(&target_value); - ecrobot_get_light_sensor(NXT_PORT_S3);

	i_hensa = i_hensa + (hensa * 0.004);

	d_hensa = (bf_hensa - hensa )/0.004;
	bf_hensa = hensa;

	turn = Kp*hensa + Ki*i_hensa + Kd*d_hensa + b;

	if (turn < -100) {
		turn = -100;
	}else if (turn > 100) {
		turn = 100;
	}

	Balancer_set_turn(&balancer , turn);
	Balancer_balance_running();


	logSend(hensa,turn,0,0,0,0,0,0);

}