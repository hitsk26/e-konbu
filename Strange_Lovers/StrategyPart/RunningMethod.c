#include "RunningMethod.h"
#include "../Factory.h"

int runningMethod_check_executed(RunningMethod *this_RunningMethod)
{
	return 0;
}

void RunningMethod_execute_method(RunningMethod *this_RunningMethod, TargetValues target_value)
{
	target_value.target_brightness =target_value.target_brightness /* + •â³—Ê */;
	target_value.target_curvature = target_value.target_curvature/* + •â³—Ê */;
	target_value.target_speed = target_value.target_speed/* + •â³—Ê */;

	DrivenDirector_request_drive(&drivenDirector,target_value.target_brightness, target_value.target_curvature,target_value.target_speed,this_RunningMethod->target_tail_angle,this_RunningMethod->balancing_requrement,this_RunningMethod->use_controller,this_RunningMethod->gyroOffsetRevise);

}
