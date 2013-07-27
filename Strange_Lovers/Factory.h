#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "ecrobot_interface.h"

#include "./lib/CommonFunction.h"
#include "./lib/mymath.h"


#include "Calibration.h"
#include "TargetValue.h"
#include "Display.h"

#include "./UI/PushButton.h"

#include "./DrivenPart/WheelMotor.h"
#include "./DrivenPart/TailMotor.h"
#include "./DrivenPart/Balancer.h"
#include "./DrivenPart/PID_Tail.h"
#include "./DrivenPart/PID_Brightness.h"
#include "./DrivenPart/DrivenDirector.h"
#include "DrivenPart/ControllerWeight.h"

#include "./DrivenPart/TargetSpeedControl/SpeedCtrl.h"
#include "DrivenPart/TargetCurvatureControl/CurvatureCtrl.h"
#include "DrivenPart/TargetCurvatureControl/PIDCurvatureCtrl.h"
#include "DrivenPart/TargetCurvatureControl/Curvature.h"
#include "DrivenPart/TargetCurvatureControl/PIDCurvatureCtrlParm.h"

#include "EncoderPart/DistanceEncoder.h"
#include "EncoderPart/SpeedEncoder.h"
#include "EncoderPart/Timer.h"
#include "EncoderPart/InclinationEncoder.h"
#include "EncoderPart/BrightnessEncoder.h"
#include "EncoderPart/DirectionEncoder.h"
#include "EncoderPart/CurvatureEncoder.h"

#include "./StrategyPart/Runner.h"
#include "./StrategyPart/RunningMethod.h"
#include "./StrategyPart/Section.h"
#include "./StrategyPart/SwitchTerm.h"
#include "./StrategyPart/TargetValues.h"
#include "./StrategyPart/SwitchTerm.h"

#include "StrategyPart/RunningMethodSwitchJudge/SwitchJudge.h"
#include "StrategyPart/RunningMethodSwitchJudge/DistanceSwitch.h"
#include "StrategyPart/RunningMethodSwitchJudge/InclinationSwitch.h"
#include "StrategyPart/RunningMethodSwitchJudge/MultipleTermSwitch.h"

#include "./StrategyFactories/FiststStraightFactory.h"



Calibration calibration;
TargetValue targetValue;

Display display;

//UI package
PushButton pushButton;



//EncoderPart
Timer timer;
DistanceEncoder distanceEncoder;
SpeedEncoder speedEncoder;
InclinationEncoder inclinationEncoder;
BrightnessEncoder brightnessEncoder; 
DirectionEncoder directionEncoder;
CurvatureEncoder curvatureEncoder; 

//DrivenPart
PID_TAIL pid_tail;
PID_Brightness pid_Brightness;
Balancer balancer;
WheelMotor rightWheelMotor;
WheelMotor leftWheelMotor;
TailMotor tailMotor;
DrivenDirector drivenDirector;


//DrivenPart/SpeedControl
SpeedCtrl mSpeedCtrl;
PIDSpeedCtrlParm mPIDSpeedCtrlParm;

//DrivenPart/DirectionCtrl
CurvatureCtrl mCurvatureCtrl; 
PIDCurvatureCtrl mPIDCurvatureCtrl;
PIDCurvatureCtrlParm mPIDCurvatureCtrlParm;

//PIDLightValCtrl mPIDLightValCtrl;
//WheelMotor mWheelMotor;
//LightVal mLightVal;

//StarategyPart
Runner runner;


//StrategyPart/RunningMethodSwitchJudge


extern void initialization();

#endif


