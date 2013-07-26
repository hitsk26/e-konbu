#include "Runner.h"
#include "Factory.h"

#define CYCLE_TIME 0.004

float cut_off(float value,int criterion);

void Runner_init(Runner *this_Runner){


}
void Runner_run(Runner *this_Runner){
	DrivenDirector_request_drive(&drivenDirector,targetValue.target_brightness,targetValue.target_curvature,targetValue.target_tail_angle);
}


