#ifndef _SPEED_CTRL_H
#define _SPEED_CTRL_H

#include "Speed.h"
#include "PIDSpeedCtrl.h"
#include "WheelMotor.h"
#include "SpeedCtrlState.h"

typedef struct{
	SpeedCtrlState S_CtrlState;
} SpeedCtrl;

PIDSpeedCtrl mPIDSpeedCtrl;
WheelMotor mWheelMotor;
Speed mSpeed;

extern void SC_init(SpeedCtrl *this_SpeedCtrl,SpeedEncoder SE,WheelMotor WM,PIDSpeedCtrl PSC);
extern void SC_setTargSpeed(SpeedCtrl *this_SpeedCtrl,int parm);
extern float SC_getTargSpeedCtrl(SpeedCtrl *this_SpeedCtrl);
extern void SC_setCtrlParm(SpeedCtrl *this_SpeedCtrl,PIDSpeedCtrlParm parm);
extern PIDSpeedCtrlParm SC_getCtrlParm(SpeedCtrl *this_SpeedCtrl);
extern void SC_startCtrl(SpeedCtrl *this_SpeedCtrl);
extern void SC_stopCtrl(SpeedCtrl *this_SpeedCtrl);
extern void SC_doCtrl(SpeedCtrl *this_SpeedCtrl);
extern void SC_run(SpeedCtrl *this_SpeedCtrl);
extern void SC_changeMode(SpeedCtrl *this_SpeedCtrl,SpeedCtrlState state);

#endif
