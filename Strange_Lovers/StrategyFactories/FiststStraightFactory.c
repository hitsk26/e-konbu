#include "FiststStraightFactory.h"


void first_straight_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;

	
	//First Straight 1010mm

	//stableRunningMethod
	use_controller.target_curvature_controller_weight = 1.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance = 100;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	RunningMethod_init(&stableRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,DistanceSwitch_judge_switch_method);
	

	//straightLineTraceMethod
	use_controller.target_curvature_controller_weight = 1.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =10 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	RunningMethod_init(&straightLineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,DistanceSwitch_judge_switch_method);
	


	first_straight_running_method_array[0]=stableRunningMethod;
	first_straight_running_method_array[1]=straightLineTraceMethod;
	int number_of_running_method=2;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 200;
	Section *nextSection = &slope;
	Section_init(&firstStraight,nextSection,number_of_running_method,first_straight_running_method_array,target_values);
}
