#include "SlopeFactory.h"


void slope_factory_init(){
	
	//RunningMethod

	//slopeRunningMethod
	slopeRunningMethod.balancing_requrement = 1;
	slopeRunningMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	slopeRunningMethod.gyroOffsetRevise = 0;
	
	slopeRunningMethod.switch_term.distance = 1710;
	slopeRunningMethod.switch_term.inclination = 0;
	slopeRunningMethod.switch_term.time = 0;
	
	slopeRunningMethod.target_tail_angle=0;
	slopeRunningMethod.use_controller.target_curvature_controller_weight= 0.5;
	slopeRunningMethod.use_controller.target_light_controller_weight = 0.5;
	
	slope_running_method_array[0]=slopeRunningMethod;
	
	slope.current_running_method_number=0;
	slope.number_of_running_method=1;
	slope.running_methods=slope_running_method_array;

	slope.target_values.target_brightness=0.5;
	slope.target_values.target_curvature=0;
	slope.target_values.target_speed=200;
	
	slope.nextSection = &afterSlopeStraight;

}
