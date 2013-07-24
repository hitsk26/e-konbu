#ifndef _PID_CURVATURE_CONTROL_H
#define _PID_CURVATURE_CONTROL_H

#include "PIDCurvatureCtrlParm.h"

typedef struct{
	float deviation;
	float integratedDeviation;
	float differentialDeviation;
	float bfDeviation;
	float lastMeasurementTime;
	PIDCurvatureCtrlParm mPIDCurvatureCtrlParm;
} PIDCurvatureCtrl;

extern void PCC_init(PIDCurvatureCtrl *this_PIDCurvatureCtrl);
extern int PCC_calcCurvatureCtrlVal(PIDCurvatureCtrl *this_PIDCurvatureCtrl,float targCurvature,float curvature,float time);
extern PIDCurvatureCtrlParm PCC_getPIDCurvatureCtrlParm(PIDCurvatureCtrl *this_PIDCurvatureCtrl);
extern void PCC_setPIDCurvatureCtrlParm(PIDCurvatureCtrl *this_PIDCurvatureCtrl,PIDCurvatureCtrlParm parm);
extern void PCC_reset(PIDCurvatureCtrl *this_PIDCurvatureCtrl);


#endif
