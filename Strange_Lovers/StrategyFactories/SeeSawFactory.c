#include "SeeSawFactory.h"


void seesaw_factory_init(){

	//SeesawLineTraceMethod
	SeesawFirstLineTraceMethod.balancing_requrement = 0;
	SeesawFirstLineTraceMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	SeesawFirstLineTraceMethod.gyroOffsetRevise = 0;
	
	SeesawFirstLineTraceMethod.switch_term.distance = 100;
	SeesawFirstLineTraceMethod.switch_term.inclination = 0;
	SeesawFirstLineTraceMethod.switch_term.time = 0;
	
	SeesawFirstLineTraceMethod.target_tail_angle=0;
	SeesawFirstLineTraceMethod.use_controller.target_curvature_controller_weight= 0;
	SeesawFirstLineTraceMethod.use_controller.target_light_controller_weight = 1;
	
	//SeesawRunningUp
	SeesawRunningUpMethod.balancing_requrement = 0;
	SeesawRunningUpMethod.fp_SwitchJudge= InclinationSwitch_judge_switch_method;
	SeesawRunningUpMethod.gyroOffsetRevise = 0;

	SeesawRunningUpMethod.switch_term.distance = 0;
	SeesawRunningUpMethod.switch_term.inclination = 600;
	SeesawRunningUpMethod.switch_term.time = 0;
		
	SeesawRunningUpMethod.target_tail_angle=0;
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

	//SeesawRunningDown
	SeesawRunningDownMethod.balancing_requrement = 0;
	SeesawRunningDownMethod.fp_SwitchJudge= InclinationSwitch_judge_switch_method;
	SeesawRunningDownMethod.gyroOffsetRevise = 0;
	
	SeesawRunningDownMethod.switch_term.distance = 0;
	SeesawRunningDownMethod.switch_term.inclination = 600;
	SeesawRunningDownMethod.switch_term.time = 0;
	
	SeesawRunningDownMethod.target_tail_angle=0;
	SeesawRunningDownMethod.use_controller.target_curvature_controller_weight= 0;
	SeesawRunningDownMethod.use_controller.target_light_controller_weight = 1;

	//SeesawFinalLineTrace
	SeesawFinalLineTraceMethod.balancing_requrement = 0;
	SeesawFinalLineTraceMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	SeesawFinalLineTraceMethod.gyroOffsetRevise = 0;
	
	SeesawFinalLineTraceMethod.switch_term.distance = 20;
	SeesawFinalLineTraceMethod.switch_term.inclination = 0;
	SeesawFinalLineTraceMethod.switch_term.time = 0;
	
	SeesawFinalLineTraceMethod.target_tail_angle=0;
	SeesawFinalLineTraceMethod.use_controller.target_curvature_controller_weight= 0;
	SeesawFinalLineTraceMethod.use_controller.target_light_controller_weight = 1;

	seesaw_running_method_array[0]=SeesawFirstLineTraceMethod;
	seesaw_running_method_array[1]=SeesawRunningUpMethod;
	seesaw_running_method_array[2]=SeesawUpslopeRunningMethod;
	seesaw_running_method_array[3]=SeesawSwitchDownslopeMethod;
	seesaw_running_method_array[4]=SeesawDownslopeRunningMethod;
	seesaw_running_method_array[5]=SeesawRunningDownMethod;
	seesaw_running_method_array[6]=SeesawFinalLineTraceMethod;

	seesaw.current_running_method_number = 0;
	seesaw.number_of_running_method = 2;
	seesaw.running_methods = seesaw_running_method_array;
	seesaw.target_values.target_brightness = 574;
	seesaw.target_values.target_curvature = 0;
	seesaw.target_values.target_speed = 20;
	seesaw.nextSection = &firstCurve;
	
}
