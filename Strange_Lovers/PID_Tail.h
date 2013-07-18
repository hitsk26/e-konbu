#ifndef _PID_TAIL_H_
#define _PID_TAIL_H_

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "TargetValue.h"

typedef struct{
}PID_TAIL;

extern void PID_TAIL_init(PID_TAIL *this_PID_TAIL);
extern void PID_tail(int angle_of_aim);

#endif

