#include "SeeSaw_2Factory.h"


void seesaw_2_factory_init(){
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
	use_controller.target_runner_angle_controller_weight = 0.0;

	switch_term.distance = -250;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 0;
	target_tail_angle=100;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = BACKWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(& SeesawRunningBuckMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	seesaw_2_running_method_array[0]=SeesawRunningBuckMethod;

	int number_of_running_method=1;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.003;
	target_values.target_speed = -50;
	target_values.target_runner_angle = 0;

	Section *nextSection = &seesaw_2_2;
	RunningMethod *runningMethod = seesaw_2_running_method_array;
	Section_init(&seesaw_2,nextSection,number_of_running_method,runningMethod,target_values);
	
}


