#include "ParameterReceiver.h"

void ParameterReceiver_init(ParameterReceiver *self,LightValCtrl *lightValCtrl,SpeedCtrl *speedCtrl,CurvatureCtrl *curvatureCtrl)
{
	self->lightValCtrl = lightValCtrl;
	self->curvatureCtrl = curvatureCtrl;
	self->speedCtrl = speedCtrl;
}

void ParamterReceiver_paramter_adjust(ParameterReceiver *self){


}

