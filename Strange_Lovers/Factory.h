#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "ecrobot_interface.h"

#include "Calibration.h"
#include "TargetValue.h"
#include "Display.h"
#include "Runner.h"
#include "./UI/PushButton.h"

#include "./DrivenPart/WheelMotor.h"
#include "./DrivenPart/TailMotor.h"
#include "./DrivenPart/Balancer.h"
#include "./DrivenPart/PID_Tail.h"
#include "./DrivenPart/PID_Brightness.h"

#include "DetectorPart/DistanceEncoder.h"
#include "DetectorPart/SpeedEncoder.h"
#include "DetectorPart/Timer.h"
#include "DetectorPart/InclinationEncoder.h"



Calibration calibration;
TargetValue targetValue;

Display display;
Runner runner;

//UI package
PushButton pushButton;



//DetectorPart
Timer timer;
DistanceEncoder distanceEncoder;
SpeedEncoder speedEncoder;
InclinationEncoder inclinationEncoder;

//DrivenPart
PID_TAIL pid_tail;
PID_Brightness pid_Brightness;
Balancer balancer;
WheelMotor rightWheelMotor;
WheelMotor leftWheelMotor;
TailMotor tailMotor;



extern void initialization();

#endif


