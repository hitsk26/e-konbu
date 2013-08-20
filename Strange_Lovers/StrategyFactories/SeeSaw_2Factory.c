#include "SeeSaw_2Factory.h"


void seesaw_2_factory_init(){

	//SeesawRunningBuck
	SeesawRunningBuckMethod.balancing_requrement = 0;
	SeesawRunningBuckMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	SeesawRunningBuckMethod.gyroOffsetRevise = 0;

	SeesawRunningBuckMethod.switch_term.distance = 1000;
	SeesawRunningBuckMethod.switch_term.inclination = 0;
	SeesawRunningBuckMethod.switch_term.time = 0;
	SeesawRunningBuckMethod.switch_term.speed = 0;
		
	SeesawRunningBuckMethod.target_tail_angle=100;
	SeesawRunningBuckMethod.use_controller.target_curvature_controller_weight= 1;
	SeesawRunningBuckMethod.use_controller.target_light_controller_weight = 0;

	seesaw_2_running_method_array[0]=SeesawRunningBuckMethod;


	seesaw_2.current_running_method_number = 0;
	seesaw_2.number_of_running_method = 1;
	seesaw_2.running_methods = seesaw_2_running_method_array;
	seesaw_2.target_values.target_brightness = 0.5;
	seesaw_2.target_values.target_curvature = 0;
	seesaw_2.target_values.target_speed = -50;
	seesaw_2.nextSection = &seesaw_3;
	
}
