#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "ecrobot_interface.h"

#include "Balancer.h"
#include "Calibration.h"
#include "TargetValue.h"
#include "./UI/PushButton.h"
#include "WheelMotor.h"

Balancer balancer;
Calibration calibration;
TargetValue targetValue;


//UI package
PushButton pushButton;

WheelMotor rightWheelMotor;
WheelMotor leftWheelMotor;


extern void initialization();

#endif


