#include "SeeSaw_4Factory.h"


void seesaw_4_factory_init(){

	//SeesawRunningDown
	SeesawRunningDownMethod.balancing_requrement = 0;
	SeesawRunningDownMethod.fp_SwitchJudge= InclinationSwitch_judge_switch_method;
	SeesawRunningDownMethod.gyroOffsetRevise = 0;
	
	SeesawRunningDownMethod.switch_term.distance = 0;
	SeesawRunningDownMethod.switch_term.inclination = 600;
	SeesawRunningDownMethod.switch_term.time = 0;
	
	SeesawRunningDownMethod.target_tail_angle=0;
	SeesawRunningDownMethod.use_controller.target_curvature_controller_weight= 0;
	SeesawRunningDownMethod.use_controller.target_light_controller_weight = 1;

	seesaw_4_running_method_array[0]=SeesawRunningDownMethod;

	seesaw_4.current_running_method_number = 0;
	seesaw_4.number_of_running_method = 1;
	seesaw_4.running_methods = seesaw_4_running_method_array;
	seesaw_4.target_values.target_brightness = 0.5;
	seesaw_4.target_values.target_curvature = 0;
	seesaw_4.target_values.target_speed = 50;
	seesaw_4.nextSection = &seesaw_5;
	
}
