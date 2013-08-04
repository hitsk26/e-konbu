#ifndef _FirstStraightFactory_
#define _FirstStraightFactory_

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

Section afterSlopeStraight;
RunningMethod afterSlopeStraightRunningMethod;

RunningMethod after_slope_straight_running_method_array[1];



//StrategyPart/RunningMethodSwitchJudge


extern void after_slope_straight_factory_init();

#endif


