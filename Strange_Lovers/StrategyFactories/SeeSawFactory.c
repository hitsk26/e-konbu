#include "SeeSawFactory.h"


void seesaw_factory_init(){

	//seesawRunningMethod

	//SeesawLineTraceMethod
	SeesawLineTraceMethod.balancing_requrement = 0;
	SeesawLineTraceMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	SeesawLineTraceMethod.gyroOffsetRevise = 0;
	
	SeesawLineTraceMethod.switch_term.distance = 300;
	SeesawLineTraceMethod.switch_term.inclination = 0;
	SeesawLineTraceMethod.switch_term.time = 0;
	
	SeesawLineTraceMethod.target_tail_angle=0;
	SeesawLineTraceMethod.use_controller.target_curvature_controller_weight= 0.5;
	SeesawLineTraceMethod.use_controller.target_light_controller_weight = 0.5;
	
	//straightLineTraceMethod
	SeesawRunningUpMethod.balancing_requrement = 0;
	SeesawRunningUpMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	SeesawRunningUpMethod.gyroOffsetRevise = 0;
	
	SeesawRunningUpMethod.switch_term.distance = 300;
	SeesawRunningUpMethod.switch_term.inclination = 0;
	SeesawRunningUpMethod.switch_term.time = 0;
	
	SeesawRunningUpMethod.target_tail_angle=0;
	SeesawRunningUpMethod.use_controller.target_curvature_controller_weight= 0.5;
	SeesawRunningUpMethod.use_controller.target_light_controller_weight = 0.5;


	seesaw_running_method_array[0]=SeesawLineTraceMethod;
	seesaw_running_method_array[1]=SeesawRunningUpMethod;

	seesaw.current_running_method_number = 0;
	seesaw.number_of_running_method = 2;
	seesaw.running_methods = seesaw_running_method_array;
	seesaw.target_values.target_brightness = 574;
	seesaw.target_values.target_curvature = 0;
	seesaw.target_values.target_speed = 20;
	seesaw.nextSection = &firstCurve;
	
}
