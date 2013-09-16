#include "SeeSawFactory.h"


void seesaw_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);
	
	TargetValues target_values;
	Section *nextSection;
	RunningMethod *runningMethod;

	int number_of_running_method; //区間で実施する走法の個数
	use_controller.target_curvature_controller_weight =0.0; //曲率制御の重み付け
	use_controller.target_light_controller_weight =1.0;	//輝度制御の重み付け
	switch_term.distance = 500; //距離切替を採用した際の切替条件 [mm]
	switch_term.inclination = 0; //傾き切替を採用した際の切替条件
	switch_term.speed = 40; //速度切替条件 [mm/s]
	switch_term.time =2000; //時間切替条件 [ms]
	balancing_requrement = 0; //倒立制御の有無 1:倒立走行 0:尻尾走行 合わせて尻尾角度を９５度程度にする必要あり
	target_tail_angle=100; //尻尾の目標角度
	gyroOffsetRevise=0; //ジャイロオフセット変更量　+方向に増やすと急加速 -方向に増やすと急原則　ただし数センチ程度進んだ段階でオフセットを戻さないとバランスを崩して転倒する
	request_forced_stop= 0; //完全に停止したい場合に1 通常の制御を掛ける場合は0
	movementDirection = FORWARD; //進行方向に従って設定する　前進 FORWARD 後退BACKWARD
	fp_SwitchJudge = SpeedTimerMultipleSwitch_judge_switch_method; //切替を判定する関数名を指定　
	/*
	距離切替 DistanceSwitch_judge_switch_method
	時間切替 TTimeSwitch_judge_switch_method
	など
	*/

	RunningMethod_init(&SeesawFirstLineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	seesaw_1_running_method_array[0]=SeesawFirstLineTraceMethod; //実施する走法を配列順番に格納

	number_of_running_method=1; //区間で実施する走法の個数
	  
	target_values.target_brightness = 0.5; //目標輝度
	target_values.target_curvature = 0.0; //目標曲率 [1/mm]
	target_values.target_speed = 100;  //目標速度 [mm/s]
	nextSection = &seesaw_stop; //次の区間
	runningMethod = seesaw_1_running_method_array;
	Section_init(&seesaw_1,nextSection,number_of_running_method,runningMethod,target_values);

	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	use_controller.target_runner_angle_controller_weight = 1.0;
	switch_term.distance = -100;
	switch_term.inclination = 0;
	switch_term.inPushed = 1;
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

	number_of_running_method=1;
	 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = -100;
	target_values.target_runner_angle = 0;

	nextSection = &seesaw_2_2;
	runningMethod = seesaw_2_running_method_array;
	Section_init(&seesaw_2,nextSection,number_of_running_method,runningMethod,target_values);
	
	
		
	//tailplusmovingMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance = 0;
	switch_term.inclination = 0;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time =200;
	switch_term.tail_angle =119;
	balancing_requrement = 0;
	target_tail_angle=119;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailplusmovingMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	
	//tailbackMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance = 0;
	switch_term.inclination = 0;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time =200;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailbackMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	


	seesaw_2_2running_method_array[0]=tailplusmovingMethod;
	seesaw_2_2running_method_array[1]=tailbackMethod;


	number_of_running_method=2;
	 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 0;
	nextSection = &seesaw_3;
	runningMethod = seesaw_2_2running_method_array;
	Section_init(&seesaw_2_2,nextSection,number_of_running_method,runningMethod,target_values);

	
	//SeesawRunningUp
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 1.0;
	switch_term.distance =100;
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
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;//時間で切り替えようかと
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


	number_of_running_method=4;
	 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 100;
	nextSection = &seesaw_4;
	runningMethod = seesaw_3_running_method_array;
	Section_init(&seesaw_3,nextSection,number_of_running_method,runningMethod,target_values);

	
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 1.0;
	switch_term.distance = 0;
	switch_term.inclination = 600;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time = 0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = InclinationSwitch_judge_switch_method;
	RunningMethod_init(&SeesawRunningDownMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	seesaw_4_running_method_array[0]=SeesawRunningDownMethod;

	number_of_running_method=1;
	 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 0;
	nextSection = &seesaw_5;
	runningMethod = seesaw_4_running_method_array;
	Section_init(&seesaw_4,nextSection,number_of_running_method,runningMethod,target_values);
	
	
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 1.0;
	switch_term.distance = 20;
	switch_term.inclination =0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time = 0;
	balancing_requrement = 1;
	target_tail_angle=100;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&SeesawFinalLineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	
	seesaw_5_running_method_array[0]=SeesawFinalLineTraceMethod;

	seesaw_5.current_running_method_number = 0;
	seesaw_5.number_of_running_method = 1;
	seesaw_5.running_methods = seesaw_5_running_method_array;
	seesaw_5.target_values.target_brightness = 0.5;
	seesaw_5.target_values.target_curvature = 0;
	seesaw_5.target_values.target_speed = 50;
	//seesaw_5.nextSection = &firstCurve;

	number_of_running_method=1;
	 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 50;
	//nextSection = &firstCurve;
	runningMethod = seesaw_5_running_method_array;
	Section_init(&seesaw_5,nextSection,number_of_running_method,runningMethod,target_values);
	
	
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance = 500;
	switch_term.inclination = 0;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time =5000;
	balancing_requrement = 0;
	target_tail_angle=100;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&SeesawStopMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	seesaw_stop_running_method_array[0]=SeesawStopMethod;

	number_of_running_method=1;
	 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 0;
	nextSection = &seesaw_2;
	runningMethod = seesaw_stop_running_method_array;
	Section_init(&seesaw_stop,nextSection,number_of_running_method,runningMethod,target_values);


}
