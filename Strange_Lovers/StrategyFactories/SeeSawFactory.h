#ifndef _SeeSawFactory_
#define _SeeSawFactory_

#include "../DrivenPart/DrivenDirector.h"
#include "../DrivenPart/ControllerWeight.h"


#include "../EncoderPart/DistanceEncoder.h"
#include "../EncoderPart/SpeedEncoder.h"
#include "../EncoderPart/Timer.h"
#include "../EncoderPart/InclinationEncoder.h"
#include "../EncoderPart/BrightnessEncoder.h"
#include "../EncoderPart/DirectionEncoder.h"
#include "../EncoderPart/CurvatureEncoder.h"

#include "../StrategyPart/Runner.h"
#include "../StrategyPart/RunningMethod.h"
#include "../StrategyPart/Section.h"
#include "../StrategyPart/SwitchTerm.h"
#include "../StrategyPart/TargetValues.h"
#include "../StrategyPart/SwitchTerm.h"

#include "../StrategyPart/RunningMethodSwitchJudge/SwitchJudge.h"
#include "../StrategyPart/RunningMethodSwitchJudge/DistanceSwitch.h"
#include "../StrategyPart/RunningMethodSwitchJudge/InclinationSwitch.h"
#include "../StrategyPart/RunningMethodSwitchJudge/MultipleTermSwitch.h"

#include "FiststCurveFactory.h"


//StarategyPart

Section seesaw;
RunningMethod SeesawFirstLineTraceMethod;
RunningMethod SeesawRunningUpMethod;
RunningMethod SeesawUpslopeRunningMethod;
RunningMethod SeesawSwitchDownslopeMethod;
RunningMethod SeesawDownslopeRunningMethod;
RunningMethod SeesawRunningDownMethod;
RunningMethod SeesawFinalLineTraceMethod;
RunningMethod seesaw_running_method_array[7];


//StrategyPart/RunningMethodSwitchJudge

extern void seesaw_factory_init();

#endif


