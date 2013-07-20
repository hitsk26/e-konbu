#ifndef _RUNNER_
#define _RUNNER_

#include "./DrivenPart/PID_Brightness.h"
#include "./DrivenPart/PID_Tail.h"
#include "logSend.h"
#include "TargetValue.h"
#include "./UI/PushButton.h"

typedef struct{
}Runner;


void Runner_init(Runner *this_Runner);
void Runner_run(Runner *this_Runner);



#endif

