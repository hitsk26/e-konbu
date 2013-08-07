#include "Factory.h"

void initialization(){
	
	ecrobot_set_light_sensor_active(NXT_PORT_S3);
	ecrobot_set_motor_rev(NXT_PORT_A,0);
	ecrobot_set_motor_rev(NXT_PORT_B,0);
	ecrobot_set_motor_rev(NXT_PORT_C,0);
	ecrobot_init_bt_slave("LEJOS-OSEK");

	Calibration_init(&calibration);
	TargetValue_init(&targetValue);
	
	Display_init(&display);
	

	//UI
	PushButton_init(&pushButton,NXT_PORT_S4);

	//lib
	MovingAverage_init(&speedEncoderMovingAverage,25);
	MovingAverage_init(&curvatureEncoderMovingAverage,25);
	


	//EncoderPart
	Timer_init(&timer);
	DistanceEncoder_init(&distanceEncoder);
	InclinationEncoder_init(&inclinationEncoder,NXT_PORT_S1);
	BrightnessEncoder_init(&brightnessEncoder,NXT_PORT_S3,&lowPassFillter);
	DirectionEncoder_init(&directionEncoder);


	//DrivenPart
	PID_TAIL_init(&pid_tail);
	WheelActuator_init(&wheelActuator);
	WheelMotor_init(&rightWheelMotor,NXT_PORT_B);
	WheelMotor_init(&leftWheelMotor,NXT_PORT_C);
	TailMotor_init(&tailMotor,NXT_PORT_A);
	DrivenDirector_init(&drivenDirector);

	//DrivenPart/TargetSpeedControl
	SC_setCtrlParm(&mSpeedCtrl,mPIDSpeedCtrlParm);
	
	PSCP_init(&mPIDSpeedCtrlParm);
	PSC_init(&mPIDSpeedCtrl);
	SC_init(&mSpeedCtrl,mPIDSpeedCtrl);
	SC_setTargSpeed(&mSpeedCtrl,20);
	SC_startCtrl(&mSpeedCtrl);

	//DrivenPart/TargetCurvatureControl
	PCC_init(&mPIDCurvatureCtrl);
	PCCP_init(&mPIDCurvatureCtrlParm);
	CC_init(&mCurvatureCtrl,mPIDCurvatureCtrl);
	CC_setCtrlParm(&mCurvatureCtrl,mPIDCurvatureCtrlParm);
	CC_setTargCurvature(&mCurvatureCtrl,0);
	CC_startCtrl(&mCurvatureCtrl);

	//DrivenPart/TargetLightValueControl
	PLVCP_init(&mPIDLightValCtrlParm);
	PLVC_init(&mPIDLightValCtrl);
	LVC_init(&mLightValCtrl,brightnessEncoder,mPIDLightValCtrl);

	//initialize Sections pleas call them here!!
	first_curve_factory_init();
	after_slope_straight_factory_init();
	slope_factory_init();
	first_straight_factory_init();
	seesaw_factory_init();
	
	//StrategyPart
	Runner_init(&runner,&firstStraight);
}

void reset_objects(){

}

void restart(){

	reset_objects();
	initialization();
}

