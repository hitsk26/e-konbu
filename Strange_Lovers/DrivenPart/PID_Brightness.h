#ifndef _PID_BRIGHTNESS_H_
#define _PID_BRIGHTNESS_H_


#include "./Balancer.h"
#include "../TargetValue.h"
#include "../logSend.h"

typedef struct{
}PID_BRIGHTNESS;

extern void PID_BRIGHTNESS_init(PID_BRIGHTNESS *this_PID_BRIGHTNESS);
extern void PID_Brightness(int target_brighness);

#endif

