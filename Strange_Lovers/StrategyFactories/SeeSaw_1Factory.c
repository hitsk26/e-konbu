#include "SeeSaw_1Factory.h"


void seesaw_1_factory_init(){

	//SeesawLineTraceMethod
	SeesawFirstLineTraceMethod.balancing_requrement = 0;
	SeesawFirstLineTraceMethod.fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	SeesawFirstLineTraceMethod.gyroOffsetRevise = 0;
	
	SeesawFirstLineTraceMethod.switch_term.distance = 500;
	SeesawFirstLineTraceMethod.switch_term.inclination = 0;
	SeesawFirstLineTraceMethod.switch_term.time = 30000;
	SeesawFirstLineTraceMethod.switch_term.speed = 30;
	
	SeesawFirstLineTraceMethod.target_tail_angle=100;
	SeesawFirstLineTraceMethod.use_controller.target_curvature_controller_weight= 1;
	SeesawFirstLineTraceMethod.use_controller.target_light_controller_weight = 0;

	seesaw_1_running_method_array[0]=SeesawFirstLineTraceMethod;

	seesaw_1.current_running_method_number = 0;
	seesaw_1.number_of_running_method = 1;
	seesaw_1.running_methods = seesaw_1_running_method_array;
	seesaw_1.target_values.target_brightness = 0.5;
	seesaw_1.target_values.target_curvature = 0;
	seesaw_1.target_values.target_speed = 50;
	seesaw_1.nextSection = &seesaw_3;
	
}
