#ifndef _CALIBRATION_H_
#define _CALIBRATION_H_

#include "Balancer.h"
#include "Target_Value.h"
#include "Display.h"


int black_value = 0;
int white_value = 0;
static U32 gyro = 0;

extern void Calibration();

#endif