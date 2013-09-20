#ifndef _SeeSaw_3Factory_
#define _SeeSaw_3Factory_

#include "../StrategyFactories/StrategyFactories_inculude.h"

#include "SeeSaw_4Factory.h"


//StarategyPart

Section seesaw_3;
RunningMethod SeesawForwardRunningMethod;
RunningMethod SeesawRunningUpMethod;
RunningMethod SeesawRunningUp2Method;
RunningMethod SeesawUpslopeRunningMethod;
RunningMethod SeesawSwitchDownslopeMethod;
RunningMethod SeesawDownslopeRunningMethod;
RunningMethod seesaw_3_running_method_array[6];


//StrategyPart/RunningMethodSwitchJudge

extern void seesaw_3_factory_init();

#endif


