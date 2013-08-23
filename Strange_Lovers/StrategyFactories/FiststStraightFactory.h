#ifndef _FirstStraightFactory_
#define _FirstStraightFactory_

#include "../StrategyFactories/StrategyFactories_inculude.h"

#include "SlopeFactory.h"


//StarategyPart

Section firstStraight;
RunningMethod stableRunningMethod;
RunningMethod straightLineTraceMethod;

RunningMethod first_straight_running_method_array[2];


//Section firstCurve;


//StrategyPart/RunningMethodSwitchJudge


extern void first_straight_factory_init();

#endif


