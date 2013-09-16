#ifndef _SeeSawFactory_
#define _SeeSawFactory_

#include "../StrategyFactories/StrategyFactories_inculude.h"


//StarategyPart

Section seesaw_1;
RunningMethod SeesawFirstLineTraceMethod;

RunningMethod seesaw_1_running_method_array[1];


//StrategyPart/RunningMethodSwitchJudge

extern void seesaw_factory_init();

Section seesaw_2;
RunningMethod SeesawRunningBuckMethod;

RunningMethod seesaw_2_running_method_array[1];

Section seesaw_2_2;
	
RunningMethod tailplusmovingMethod;
RunningMethod tailbackMethod;


RunningMethod seesaw_2_2running_method_array[2];



Section seesaw_3;
RunningMethod SeesawRunningUpMethod;
RunningMethod SeesawUpslopeRunningMethod;
RunningMethod SeesawSwitchDownslopeMethod;
RunningMethod SeesawDownslopeRunningMethod;
RunningMethod seesaw_3_running_method_array[4];



Section seesaw_4;
RunningMethod SeesawRunningDownMethod;
RunningMethod seesaw_4_running_method_array[1];



Section seesaw_5;
RunningMethod SeesawFinalLineTraceMethod;
RunningMethod seesaw_5_running_method_array[1];



Section seesaw_stop;
RunningMethod SeesawStopMethod;

RunningMethod seesaw_stop_running_method_array[1];


#endif


