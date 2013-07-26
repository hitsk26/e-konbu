#include "RunningStrategy.h"
#include "../Factory.h"


void RunningStrategy_changeStrategy(RunningStrategy *this_RunningStrategy)
{
}

void RunningStrategy_executeStrategy(RunningStrategy *this_RunningStrategy)
{
	DrivenDirector_request_drive(&drivenDirector,this_RunningStrategy->target_brightness, this_RunningStrategy->target_curvature,this_RunningStrategy->target_tail_angle);

}
