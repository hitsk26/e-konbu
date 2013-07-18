#ifndef _CALIBRATION_H_
#define _CALIBRATION_H_

#include "Balancer.h"
#include "Target_Value.h"
#include "Display.h"



typedef struct{
	int black_value;
	int white_value;
	U32 gyro;
}Calibration;

int end_calibration_flg = 0;

extern void Calibration_init(Calibration *this_Calibration);
extern void Calibration_calibration();

#endif

