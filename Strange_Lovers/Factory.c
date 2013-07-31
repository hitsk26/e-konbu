#include "Factory.h"

void initialization(){
	
	Calibration_init(&calibration);
	TargetValue_init(&targetValue);
	
	Display_init(&display);
	

	//UI
	PushButton_init(&pushButton,NXT_PORT_S4);
	
	//DetectorPart
	Timer_init(&timer);
	DistanceEncoder_init(&distanceEncoder);
	InclinationEncoder_init(&inclinationEncoder,NXT_PORT_S1);
	BrightnessEncoder_init(&brightnessEncoder,NXT_PORT_S3);
	DirectionEncoder_init(&directionEncoder);


	//DrivenPart
	PID_TAIL_init(&pid_tail);
	PID_Brightness_init(&pid_Brightness);
	Balancer_init(&balancer);
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

	//initialize Sections pleas call them here!!
	first_straight_factory_init();
	first_curve_factory_init();
	seesaw_factory_init();
	started_running_factory_init();

	//StrategyPart
	Runner_init(&runner,&firstStraight);
}
