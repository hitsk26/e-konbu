#include "InSixthCurveFactory.h"
#include "BalanceStopFactory.h"


void In_fifth_curve_factory_init()
{

	//Section Local variables
	TargetValues target_values; 
	Section *nextSection;
	RunningMethod *runningMethod;

	//RunningMethod Local Variables
	ControllerWeight use_controller;
	SwitchTerm switch_term={0,0,0,0,0};
	int number_of_running_method=0;
	int balancing_requrement =1;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop = 0;
	int (*fp_SwitchJudge)(SwitchTerm);
	MovementDirection movementDirection = FORWARD;
	

	//InSixCurveLineTraceMethod
	use_controller.target_curvature_controller_weight =0.4;
	use_controller.target_light_controller_weight = 0.6;
	switch_term.distance = 2031;//2231
	//switch_term.distance =1300.265;
	//switch_term.distance =1200.265;
	
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&InSixthCurveLineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);


	
	//InSixthCurve Section
	In_sixth_curve_running_method_array[0]=InSixthCurveLineTraceMethod;
	runningMethod = In_sixth_curve_running_method_array;
	number_of_running_method=1;
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.000755594;
	
	target_values.target_speed = 400;
	nextSection = &balanceStop;

	Section_init(&InSixthCurve,nextSection,number_of_running_method,runningMethod,target_values);

}


