#include "FiststStraightFactory.h"


void first_curve_factory_init(){
	
	//RunningMethod
	
	//curveLineTraceMethod
	curveLineTraceMethod.balancing_requrement = 0;
	curveLineTraceMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	curveLineTraceMethod.gyroOffsetRevise = 0;
	
	curveLineTraceMethod.switch_term.distance = 500;
	curveLineTraceMethod.switch_term.inclination = 0;
	curveLineTraceMethod.switch_term.time = 0;
	
	curveLineTraceMethod.target_tail_angle=0;
	curveLineTraceMethod.use_controller.target_curvature_controller_weight= 1.0;
	curveLineTraceMethod.use_controller.target_light_controller_weight = 0.0;

	first_curve_running_method_array[0]=curveLineTraceMethod;

	firstCurve.current_running_method_number=0;
	firstCurve.number_of_running_method=1;
	firstCurve.running_methods=first_curve_running_method_array;
	firstCurve.target_values.target_brightness=574;
	firstCurve.target_values.target_curvature=0;
	firstCurve.target_values.target_speed=20;
	firstCurve.nextSection = &firstCurve;

}
