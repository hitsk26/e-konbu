#ifndef _PID_BRIGHTNESS_H_
#define _PID_BRIGHTNESS_H_


#include "./Balancer.h"
#include "../TargetValue.h"
#include "../DetectorPart/BrightnessEncoder.h"

typedef struct{
}PID_Brightness;

extern void PID_Brightness_init(PID_Brightness *this_PID_Brightness);


extern int PID_Brightness_target_control(PID_Brightness *this_PID_Brigtness,int target_brighness);

#endif

