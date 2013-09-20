#ifndef _LookUpGate_
#define _LookUpGate_

#include "../StrategyFactories/StrategyFactories_inculude.h"


//StarategyPart

Section lookup;
RunningMethod beforeLookUpMethod;
RunningMethod doingLookUpMethod;
RunningMethod afterLookUpMethod;

RunningMethod look_up_running_method_array[2];


//Section firstCurve;


//StrategyPart/RunningMethodSwitchJudge


extern void look_up_factory_init();

#endif


