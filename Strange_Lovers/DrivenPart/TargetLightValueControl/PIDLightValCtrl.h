#ifndef _PID_LIGHT_VAL_CTRL_H
#define _PID_LIGHT_VAL_CTRL_H

#include "PIDLightValCtrlParm.h"
#include "LightVal.h"
#include "../../EncoderPart/BrightnessEncoder.h"
#include "../../logSend.h"


typedef struct{
	float deviation;
	float integratedDeviation;
	float differentialDeviation;
	float bfDeviation;
	float lastMeasurementTime;
	PIDLightValCtrlParm mPIDLightValCtrlParm;
}PIDLightValCtrl;



extern void PLVC_init(PIDLightValCtrl *this_PIDLightValCtrl);
extern int PLVC_calcCtrlVal(PIDLightValCtrl *this_PIDLightValCtrl,PIDLightValCtrlParm *this_PIDLightValCtrlParm,float targLightVal,float LightVal,float time);
extern void PLVC_setCtrlParm(PIDLightValCtrl *this_PIDLightValCtrl,PIDLightValCtrlParm parm);
extern PIDLightValCtrlParm PLVC_getCtrlParm(PIDLightValCtrl *this_PIDLightValCtrl);
extern void PLVC_reset(PIDLightValCtrl *this_PIDLightValCtrl);

#endif
