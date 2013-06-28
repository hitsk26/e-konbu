#ifndef _CALIBRATION_H_
#define _CALIBRATION_H_

#include "Balancer.h"
#include "Target_Value.h"
#include "Display.h"


int black_value = 0;
int white_value = 0;
U32 gyro = 0;

int end_calibration_flg = 0;

extern void calibration();

#endif