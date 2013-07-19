#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "ecrobot_interface.h"

#include "Balancer.h"
#include "Calibration.h"
#include "TargetValue.h"
#include "./UI/PushButton.h"
#include "WheelMotor.h"
#include "DetectorPart/Timer.h"

#include "DetectorPart/DistanceEncoder.h"


Balancer balancer;
Calibration calibration;
TargetValue targetValue;


//UI package
PushButton pushButton;

WheelMotor rightWheelMotor;
WheelMotor leftWheelMotor;

//DetectorPart
Timer timer;
DistanceEncoder distanceEncoder;


extern void initialization();

#endif


