#include "Runner.h"
#include "Factory.h"
#define CYCLE_TIME 0.004
float cut_off(float value,int criterion);

void Runner_init(Runner *this_Runner){


}
void Runner_run(Runner *this_Runner){

	PID_Brightness(targetValue.target_brightness);
	PID_tail(targetValue.angle_of_aim);

}


