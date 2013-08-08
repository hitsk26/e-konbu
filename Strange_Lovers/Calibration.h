#ifndef _CALIBRATION_H_
#define _CALIBRATION_H_

#include "Balancer.h"
#include "TargetValue.h"
#include "UI/Display.h"
#include "UI/PushButton.h"
#include "EncoderPart/InclinationEncoder.h"
#include "./EncoderPart/BrightnessEncoder.h"


typedef struct{
	U32 gyro;
}Calibration;

int end_calibration_flg = 0;

extern void Calibration_init(Calibration *this_Calibration);
extern void Calibration_calibration(Calibration *this_Calibration);

#endif

