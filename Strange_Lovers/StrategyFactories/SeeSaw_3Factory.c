#include "SeeSaw_3Factory.h"


void seesaw_3_factory_init(){

	//SeesawRunningUp
	SeesawRunningUpMethod.balancing_requrement = 1;
	SeesawRunningUpMethod.fp_SwitchJudge= InclinationSwitch_judge_switch_method;
	SeesawRunningUpMethod.gyroOffsetRevise = 10;

	SeesawRunningUpMethod.switch_term.distance = 0;
	SeesawRunningUpMethod.switch_term.inclination = 600;
	SeesawRunningUpMethod.switch_term.time = 0;
	SeesawRunningUpMethod.switch_term.speed = 0;
		
	SeesawRunningUpMethod.target_tail_angle= 0;
	SeesawRunningUpMethod.use_controller.target_curvature_controller_weight= 0;
	SeesawRunningUpMethod.use_controller.target_light_controller_weight = 1;

	//SeesawUpslopeRunning
	SeesawUpslopeRunningMethod.balancing_requrement = 0;
	SeesawUpslopeRunningMethod.fp_SwitchJudge= InclinationSwitch_judge_switch_method;
	SeesawUpslopeRunningMethod.gyroOffsetRevise = 0;
	
	SeesawUpslopeRunningMethod.switch_term.distance = 0;
	SeesawUpslopeRunningMethod.switch_term.inclination = 600;
	SeesawUpslopeRunningMethod.switch_term.time = 0;
	
	SeesawUpslopeRunningMethod.target_tail_angle=0;
	SeesawUpslopeRunningMethod.use_controller.target_curvature_controller_weight= 0;
	SeesawUpslopeRunningMethod.use_controller.target_light_controller_weight = 1;

	//SeesawSwitchDownslope
	SeesawSwitchDownslopeMethod.balancing_requrement = 0;
	SeesawSwitchDownslopeMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;//éûä‘Ç≈êÿÇËë÷Ç¶ÇÊÇ§Ç©Ç∆
	SeesawSwitchDownslopeMethod.gyroOffsetRevise = 0;
	
	SeesawSwitchDownslopeMethod.switch_term.distance = 0;
	SeesawSwitchDownslopeMethod.switch_term.inclination = 0;
	SeesawSwitchDownslopeMethod.switch_term.time = 0;
	
	SeesawSwitchDownslopeMethod.target_tail_angle=0;
	SeesawSwitchDownslopeMethod.use_controller.target_curvature_controller_weight= 0;
	SeesawSwitchDownslopeMethod.use_controller.target_light_controller_weight = 1;

	//SeesawDownslopeRunning
	SeesawDownslopeRunningMethod.balancing_requrement = 0;
	SeesawDownslopeRunningMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	SeesawDownslopeRunningMethod.gyroOffsetRevise = 0;
	
	SeesawDownslopeRunningMethod.switch_term.distance = 20;
	SeesawDownslopeRunningMethod.switch_term.inclination = 0;
	SeesawDownslopeRunningMethod.switch_term.time = 0;
	
	SeesawDownslopeRunningMethod.target_tail_angle=0;
	SeesawDownslopeRunningMethod.use_controller.target_curvature_controller_weight= 0;
	SeesawDownslopeRunningMethod.use_controller.target_light_controller_weight = 1;

	seesaw_3_running_method_array[0]=SeesawRunningUpMethod;
	seesaw_3_running_method_array[1]=SeesawUpslopeRunningMethod;
	seesaw_3_running_method_array[2]=SeesawSwitchDownslopeMethod;
	seesaw_3_running_method_array[3]=SeesawDownslopeRunningMethod;

	seesaw_3.current_running_method_number = 0;
	seesaw_3.number_of_running_method = 4;
	seesaw_3.running_methods = seesaw_3_running_method_array;
	seesaw_3.target_values.target_brightness = 0.5;
	seesaw_3.target_values.target_curvature = 0;
	seesaw_3.target_values.target_speed = 50;
	seesaw_3.nextSection = &seesaw_4;
	
}
