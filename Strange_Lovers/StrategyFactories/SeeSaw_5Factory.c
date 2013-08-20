#include "SeeSaw_5Factory.h"


void seesaw_5_factory_init(){


	//SeesawFinalLineTrace
	SeesawFinalLineTraceMethod.balancing_requrement = 0;
	SeesawFinalLineTraceMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	SeesawFinalLineTraceMethod.gyroOffsetRevise = 0;
	
	SeesawFinalLineTraceMethod.switch_term.distance = 20;
	SeesawFinalLineTraceMethod.switch_term.inclination = 0;
	SeesawFinalLineTraceMethod.switch_term.time = 0;
	
	SeesawFinalLineTraceMethod.target_tail_angle=0;
	SeesawFinalLineTraceMethod.use_controller.target_curvature_controller_weight= 0;
	SeesawFinalLineTraceMethod.use_controller.target_light_controller_weight = 1;

	seesaw_5_running_method_array[0]=SeesawFinalLineTraceMethod;

	seesaw_5.current_running_method_number = 0;
	seesaw_5.number_of_running_method = 1;
	seesaw_5.running_methods = seesaw_5_running_method_array;
	seesaw_5.target_values.target_brightness = 0.5;
	seesaw_5.target_values.target_curvature = 0;
	seesaw_5.target_values.target_speed = 50;
	seesaw_5.nextSection = &firstCurve;
	
}
