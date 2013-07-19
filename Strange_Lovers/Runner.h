#ifndef _RUNNER_
#define _RUNNER_

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
#include "balancer.h"

//#include "Balancer.h"
#include "RN_State.h"
#include "PID_Brightness.h"
#include "PID_Tail.h"
#include "Calibration.h"
#include "logSend.h"
#include "TargetValue.h"
#include "./UI/PushButton.h"

typedef struct{
}Runner;

extern void Runner_init(Runner *this_Runner);

#endif

