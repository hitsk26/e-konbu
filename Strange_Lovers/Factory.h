#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "ecrobot_interface.h"

#include "Calibration.h"
#include "TargetValue.h"
#include "Display.h"
#include "Runner.h"
#include "./UI/PushButton.h"

#include "./DrivenPart/WheelMotor.h"
#include "./DrivenPart/Balancer.h"
#include "./DrivenPart/PID_Tail.h"
#include "./DrivenPart/PID_Brightness.h"

#include "DetectorPart/DistanceEncoder.h"
#include "DetectorPart/SpeedEncoder.h"
#include "DetectorPart/Timer.h"
#include "DetectorPart/InclinationEncoder.h"


Balancer balancer;
Calibration calibration;
TargetValue targetValue;
PID_TAIL pid_tail;
PID_BRIGHTNESS pid_brightness;
Display display;
Runner runner;

//UI package
PushButton pushButton;

WheelMotor rightWheelMotor;
WheelMotor leftWheelMotor;

//DetectorPart
Timer timer;
DistanceEncoder distanceEncoder;
SpeedEncoder speedEncoder;
InclinationEncoder inclinationEncoder;




extern void initialization();

#endif


