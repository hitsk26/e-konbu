#ifndef DRIVENPART_TARGETDIRECTIONCONTROL_DIRECTION_CTRL_H
#define DRIVENPART_TARGETDIRECTIONCONTROL_DIRECTION_CTRL_H

#include "Curvature.h"
#include "PIDCurvatureCtrl.h"
#include "CurvatureCtrlState.h"


typedef struct {
	CurvatureCtrlState C_CtrlState;
}CurvatureCtrl;

PIDCurvatureCtrl mPIDCurvatureCtrl;
Curvature mCurvature;

extern void CC_init(CurvatureCtrl *this_CurvatureCtrl,PIDCurvatureCtrl PCC);

extern void CC_setTargCurvature(CurvatureCtrl *this_CurvatureCtrl,float parm);
extern float CC_getTargCurvatureCtrl(CurvatureCtrl *this_CurvatureCtrl);
extern void CC_setCtrlParm(CurvatureCtrl *this_CurvatureCtrl,PIDCurvatureCtrlParm parm);
extern PIDCurvatureCtrlParm CC_getCtrlParm(CurvatureCtrl *this_CurvatureCtrl);
extern void CC_startCtrl(CurvatureCtrl *this_CurvatureCtrl);
extern void CC_stopCtrl(CurvatureCtrl *this_CurvatureCtrl);
extern int CC_doCtrl(CurvatureCtrl *this_CurvatureCtrl);
extern int CC_run(CurvatureCtrl *this_CurvatureCtrl);
extern void CC_changeMode(CurvatureCtrl *this_CurvatureCtrl,CurvatureCtrlState state);

#endif
