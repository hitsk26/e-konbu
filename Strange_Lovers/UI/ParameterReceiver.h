#ifndef __ParameterReciver
#define __ParameterReciver

#include "../DrivenPart/TargetLightValueControl/LightValCtrl.h"
#include "../DrivenPart/TargetSpeedControl/SpeedCtrl.h"
#include "../DrivenPart/TargetCurvatureControl/CurvatureCtrl.h"

typedef struct {
	LightValCtrl *lightValCtrl;

}ParameterReceiver;



void ParameterReceiver_init(ParameterReceiver *self);

void ParamterReceiver_paramter_adjust(ParameterReceiver *self);


#endif

