#include "FiststStraightFactory.h"


void first_straight_factory_init(){
	
	//RunningMethod

	//stableRunningMethod
	stableRunningMethod.balancing_requrement = 1;
	stableRunningMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	stableRunningMethod.gyroOffsetRevise = 0;
	
	stableRunningMethod.switch_term.distance = 970;
	stableRunningMethod.switch_term.inclination = 0;
	stableRunningMethod.switch_term.time = 0;
	
	stableRunningMethod.target_tail_angle=0;
	stableRunningMethod.use_controller.target_curvature_controller_weight= 0.0;
	stableRunningMethod.use_controller.target_light_controller_weight = 1.0;
	
	//straightLineTraceMethod
	straightLineTraceMethod.balancing_requrement = 1;
	straightLineTraceMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	straightLineTraceMethod.gyroOffsetRevise = 0;
	
	straightLineTraceMethod.switch_term.distance = 0;
	straightLineTraceMethod.switch_term.inclination = 0;
	straightLineTraceMethod.switch_term.time = 0;
	
	straightLineTraceMethod.target_tail_angle=0;
	straightLineTraceMethod.use_controller.target_curvature_controller_weight= 0.0;
	straightLineTraceMethod.use_controller.target_light_controller_weight = 1.0;


	first_straight_running_method_array[0]=stableRunningMethod;
	first_straight_running_method_array[1]=straightLineTraceMethod;

	firstStraight.current_running_method_number=0;
	firstStraight.number_of_running_method=1;
	firstStraight.running_methods=first_straight_running_method_array;

	firstStraight.target_values.target_brightness=0.5;
	firstStraight.target_values.target_curvature=0;
	firstStraight.target_values.target_speed=100;
	
	firstStraight.nextSection = &firstCurve;

}
