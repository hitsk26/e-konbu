#include "SeeSaw_2_3Factory.h"


void seesaw_2_3factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);

	use_controller.target_curvature_controller_weight = 1.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =10;
	switch_term.inclination = 600;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time = 1000;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&SeesawBeforeForwardRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	seesaw_2_3running_method_array[0]=SeesawBeforeForwardRunningMethod;


	int number_of_running_method=1;
	TargetValues target_values; 
	target_values.target_brightness = 0.3;
	target_values.target_curvature = -0.3;
	target_values.target_speed = 50;
	Section *nextSection = &seesaw_3;
	RunningMethod *runningMethod = seesaw_2_3running_method_array;
	Section_init(&seesaw_2_3,nextSection,number_of_running_method,runningMethod,target_values);


}
