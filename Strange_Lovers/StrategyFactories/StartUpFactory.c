#include "StartUpFactory.h"


void first_straight_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;

	

	//waitTouchRunningMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance = 0;
	switch_term.inclination = 0;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 0;
	target_tail_angle=95;
	gyroOffsetRevise=0;
	RunningMethod_init(&waitTouchRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,inPushe);
	

	//tailMoveRunningMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =2000;
	balancing_requrement = 0;
	target_tail_angle=127;
	gyroOffsetRevise=0;
	RunningMethod_init(&tailMoveRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,TimeSwitch_judge_switch_method);
	


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
