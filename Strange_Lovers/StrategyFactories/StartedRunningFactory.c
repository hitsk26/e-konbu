#include "StartedRunningFactory.h"


void started_running_factory_init(){

	//CompleteStopMethod
	CompleteStopMethod.balancing_requrement = 0;
	CompleteStopMethod.fp_SwitchJudge = inPushedSwitch_judge_switch_method;
	CompleteStopMethod.gyroOffsetRevise = 0;

	CompleteStopMethod.switch_term.distance = 0;
	CompleteStopMethod.switch_term.inclination = 0;
	CompleteStopMethod.switch_term.time = 0;
	CompleteStopMethod.switch_term.inPushed = 1;

	CompleteStopMethod.target_tail_angle = 100;
	CompleteStopMethod.use_controller.target_curvature_controller_weight = 0.0;
	CompleteStopMethod.use_controller.target_light_controller_weight = 1.0;

	//StartedRunningMethod
	StartedRunningMethod.balancing_requrement = 0;
	StartedRunningMethod.fp_SwitchJudge = TimeSwitch_judge_switch_method;
	StartedRunningMethod.gyroOffsetRevise = 0;

	StartedRunningMethod.switch_term.distance = 0;
	StartedRunningMethod.switch_term.inclination = 0;
	StartedRunningMethod.switch_term.time = 0.2;
	StartedRunningMethod.switch_term.inPushed = 0;

	StartedRunningMethod.target_tail_angle = 126;
	StartedRunningMethod.use_controller.target_curvature_controller_weight = 0.0;
	StartedRunningMethod.use_controller.target_light_controller_weight = 1.0;

	//stableRunningMethod
	stableRunningMethod.balancing_requrement = 1;
	stableRunningMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	stableRunningMethod.gyroOffsetRevise = 0;
	
	stableRunningMethod.switch_term.distance = 100/*970*/;
	stableRunningMethod.switch_term.inclination = 0;
	stableRunningMethod.switch_term.time = 0;
	stableRunningMethod.switch_term.inPushed = 0;

	stableRunningMethod.target_tail_angle=0;
	stableRunningMethod.use_controller.target_curvature_controller_weight= 0.0;
	stableRunningMethod.use_controller.target_light_controller_weight = 1.0;

	Started_running_method_array[0] = CompleteStopMethod;
	Started_running_method_array[1] = StartedRunningMethod;
	Started_running_method_array[2] = stableRunningMethod;

	StartedRunning.current_running_method_number = 0;
	StartedRunning.number_of_running_method = 3;
	StartedRunning.target_values.target_brightness = 574;
	StartedRunning.target_values.target_curvature = 0;
	StartedRunning.target_values.target_speed = 20;
	StartedRunning.nextSection = &firstStraight;



	//écä[
	/*
	//RunningMethod

	//stableRunningMethod
	stableRunningMethod.balancing_requrement = 0;
	stableRunningMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	stableRunningMethod.gyroOffsetRevise = 0;
	
	stableRunningMethod.switch_term.distance = 300/*970*;
	stableRunningMethod.switch_term.inclination = 0;
	stableRunningMethod.switch_term.time = 0;
	
	stableRunningMethod.target_tail_angle=0;
	stableRunningMethod.use_controller.target_curvature_controller_weight= 0.0;
	stableRunningMethod.use_controller.target_light_controller_weight = 1.0;
	
	//straightLineTraceMethod
	straightLineTraceMethod.balancing_requrement = 0;
	straightLineTraceMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	straightLineTraceMethod.gyroOffsetRevise = 0;
	
	straightLineTraceMethod.switch_term.distance = 300;
	straightLineTraceMethod.switch_term.inclination = 0;
	straightLineTraceMethod.switch_term.time = 0;
	
	straightLineTraceMethod.target_tail_angle=0;
	straightLineTraceMethod.use_controller.target_curvature_controller_weight= 0.5;
	straightLineTraceMethod.use_controller.target_light_controller_weight = 0.5;


	first_straight_running_method_array[0]=stableRunningMethod;
	first_straight_running_method_array[1]=straightLineTraceMethod;

	firstStraight.current_running_method_number=0;
	firstStraight.number_of_running_method=2;
	firstStraight.running_methods=first_straight_running_method_array;
	firstStraight.target_values.target_brightness=574;
	firstStraight.target_values.target_curvature=0;
	firstStraight.target_values.target_speed=20;
	firstStraight.nextSection = &firstCurve;
	*/

}
