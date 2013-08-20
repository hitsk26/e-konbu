#include "StartUpFactory.h"


void start_up__factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop = 0;
	

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
	request_forced_stop = 1;
	RunningMethod_init(&waitTouchRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,inPushedSwitch_judge_switch_method,request_forced_stop);
	

	//tailMoveRunningMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =200;
	balancing_requrement = 0;
	target_tail_angle=127;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	RunningMethod_init(&tailMoveRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,TimeSwitch_judge_switch_method,request_forced_stop);
	

	//tailBackRunningMethod

	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time = 4;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	RunningMethod_init(&tailBackRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,TimeSwitch_judge_switch_method,request_forced_stop);
	


	start_up_running_method_array[0] =waitTouchRunningMethod;
	start_up_running_method_array[1]=tailMoveRunningMethod;
	start_up_running_method_array[2] =tailBackRunningMethod;

	int number_of_running_method=3;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 0;
	Section *nextSection = &firstStraight;
	Section_init(&startUp,nextSection,number_of_running_method,start_up_running_method_array,target_values);
}
