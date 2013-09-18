#include "SeeSaw_3Factory.h"
#include "../StrategyPart/RunningMethodSwitchJudge/inPushedSwitch.h"


void seesaw_3_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);

	//SeesawRunningUp
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 1.0;
	switch_term.distance =150;
	switch_term.inclination = 600;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time = 0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&SeesawRunningUpMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//SeesawUpslopeRunning
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 1.0;
	switch_term.distance = 150;
	switch_term.inclination = 600;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time = 0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=15;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&SeesawUpslopeRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	
	//SeesawSwitchDownslope
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 1.0;
	switch_term.distance = 20;
	switch_term.inclination = 0;
	switch_term.inPushed =0;
	switch_term.speed = 0;
	switch_term.time = 0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=-10;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;//éûä‘Ç≈êÿÇËë÷Ç¶ÇÊÇ§Ç©Ç∆
	RunningMethod_init(&SeesawSwitchDownslopeMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	
	//SeesawDownslopeRunning
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance = 0;
	switch_term.inclination =0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time = 0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&SeesawDownslopeRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	


	seesaw_3_running_method_array[0]=SeesawRunningUpMethod;
	seesaw_3_running_method_array[1]=SeesawUpslopeRunningMethod;
	seesaw_3_running_method_array[2]=SeesawSwitchDownslopeMethod;
	seesaw_3_running_method_array[3]=SeesawDownslopeRunningMethod;


	int number_of_running_method=4;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 60;
	Section *nextSection = &seesaw_4;
	RunningMethod *runningMethod = seesaw_3_running_method_array;
	Section_init(&seesaw_3,nextSection,number_of_running_method,runningMethod,target_values);

}
