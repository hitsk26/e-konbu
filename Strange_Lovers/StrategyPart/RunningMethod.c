#include "RunningMethod.h"
#include "../Factory.h"

int RunningMethod_check_executed(RunningMethod *this_RunningMethod)
{
	return SwitchJudge_judge_switch_method(this_RunningMethod->fp_SwitchJudge,this_RunningMethod->switch_term);
}

void RunningMethod_execute_method(RunningMethod *this_RunningMethod, TargetValues target_values)
{
		DrivenDirector_request_drive(&drivenDirector,target_values.target_brightness, target_values.target_curvature,
		target_values.target_speed,this_RunningMethod->target_tail_angle,this_RunningMethod->balancing_requrement,
		this_RunningMethod->use_controller,this_RunningMethod->gyroOffsetRevise);
}
