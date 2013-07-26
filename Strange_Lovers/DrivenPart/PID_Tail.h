#ifndef _PID_TAIL_H_
#define _PID_TAIL_H_

#include "TargetValue.h"
#include "./TailMotor.h"


typedef struct{
}PID_TAIL;

extern void PID_TAIL_init(PID_TAIL *this_PID_TAIL);
extern void PID_tail(int target_tail_angle);

#endif

