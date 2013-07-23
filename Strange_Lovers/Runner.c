#include "Runner.h"
#include "Factory.h"

#define CYCLE_TIME 0.004

float cut_off(float value,int criterion);

void Runner_init(Runner *this_Runner){


}
void Runner_run(Runner *this_Runner){

	//PID_Brightness_target_control(&pid_Brightness,targetValue.target_brightness);
	DrivenDirector_request_drive(&drivenDirector,targetValue.target_brightness,30);
	PID_tail(targetValue.angle_of_aim);
	SC_run(&mSpeedCtrl);
}


