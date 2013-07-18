#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Balancer.h"
#include "Calibration.h"
#include "TargetValue.h"
#include "./UI/PushButton.h"
#include "ecrobot_interface.h"

Balancer balancer;
Calibration calibration;
TargetValue targetValue;


//UI package
PushButton pushButton;

extern void initialization();

#endif


