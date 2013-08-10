#ifndef __ParameterReciver
#define __ParameterReciver

#include "../DrivenPart/TargetLightValueControl/LightValCtrl.h"
#include "../DrivenPart/TargetSpeedControl/SpeedCtrl.h"
#include "../DrivenPart/TargetCurvatureControl/CurvatureCtrl.h"

typedef struct {
	LightValCtrl *lightValCtrl;
	SpeedCtrl *speedCtrl;
	CurvatureCtrl *curvatureCtrl;
}ParameterReceiver;



void ParameterReceiver_init(ParameterReceiver *self,LightValCtrl *lightValCtrl,SpeedCtrl *speedCtrl,CurvatureCtrl *curvatureCtrl);

void ParamterReceiver_paramter_adjust(ParameterReceiver *self);


#endif

