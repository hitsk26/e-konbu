#ifndef _LIGHT_VAL_CTRL_H
#define _LIGHT_VAL_CTRL_H

#include "PIDLightValCtrl.h"
#include "PIDLightValCtrlParm.h"
#include "WheelMotor.h"
#include "LightVal.h"
#include "LightValCtrlState.h"

typedef struct{
	LightValCtrlState LV_CtrlState;
}LightValCtrl;



extern void LVC_init(LightValCtrl *this_LightValCtrl,LightValEncoder LVE,WheelMotor WM,PIDLightValCtrl PLVC);
extern void LVC_setTargLightVal(LightValCtrl *this_LightValCtrl,int parm);
extern int LVC_getTargLightValCtrl(LightValCtrl *this_LightValCtrl);
extern void LVC_setCtrlParm(LightValCtrl *this_LightValCtrl,PIDLightValCtrlParm parm);
extern PIDLightValCtrlParm LVC_getCtrlParm(LightValCtrl *this_LightValCtrl);
extern void LVC_startCtrl(LightValCtrl *this_LightValCtrl);
extern void LVC_stopCtrl(LightValCtrl *this_LightValCtrl);
extern void LVC_doCtrl(LightValCtrl *this_LightValCtrl);
extern void LVC_run(LightValCtrl *this_LightValCtrl);
extern void LVC_changeMode(LightValCtrl *this_LightValCtrl,LightValCtrlState state);
extern LightValRange LVC_getLightValRange(LightValCtrl *this_LightValCtrl);
extern void LVC_setLightValRange(LightValCtrl *this_LightValCtrl,LightValRange LVR);
extern void LVC_setLightValListener(LightValCtrl *this_LightValCtrl,LightValListener LVL);


#endif
