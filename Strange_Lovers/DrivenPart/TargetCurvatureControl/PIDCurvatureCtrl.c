#include "PIDCurvatureCtrl.h"

extern void PCC_init(PIDCurvatureCtrl *this_PIDCurvatureCtrl)
{
	this_PIDCurvatureCtrl->deviation = 0;
	this_PIDCurvatureCtrl->integratedDeviation = 0;
	this_PIDCurvatureCtrl->differentialDeviation = 0;
	this_PIDCurvatureCtrl->bfDeviation = 0;
	this_PIDCurvatureCtrl->lastMeasurementTime = 0;
}

extern int PCC_calcCurvatureCtrlVal(PIDCurvatureCtrl *this_PIDCurvatureCtrl,float targCurvature,float curvature,float time)
{
	int cmd_turn;

	this_PIDCurvatureCtrl->deviation = targCurvature - curvature;

	this_PIDCurvatureCtrl->integratedDeviation = (float) (this_PIDCurvatureCtrl->integratedDeviation + 
		(this_PIDCurvatureCtrl->deviation * (time - this_PIDCurvatureCtrl->lastMeasurementTime)));

	this_PIDCurvatureCtrl->differentialDeviation = (float) ((this_PIDCurvatureCtrl->deviation - 
		this_PIDCurvatureCtrl->bfDeviation)/(time - this_PIDCurvatureCtrl->lastMeasurementTime));

	cmd_turn = (int)(this_PIDCurvatureCtrl->deviation * PCCP_getCKp(&this_PIDCurvatureCtrl->mPIDCurvatureCtrlParm)
		+ this_PIDCurvatureCtrl->integratedDeviation * PCCP_getCKi(&this_PIDCurvatureCtrl->mPIDCurvatureCtrlParm)
		+ this_PIDCurvatureCtrl->differentialDeviation * PCCP_getCKd(&this_PIDCurvatureCtrl->mPIDCurvatureCtrlParm));

	if(cmd_turn > 100)
		cmd_turn = 100;
	else if(cmd_turn < -100)
		cmd_turn = -100;

	this_PIDCurvatureCtrl->bfDeviation = this_PIDCurvatureCtrl->deviation;
	this_PIDCurvatureCtrl->lastMeasurementTime = time;

	return (-1)*cmd_turn;
}

PIDCurvatureCtrlParm PCC_getPIDCurvatureCtrlParm(PIDCurvatureCtrl *this_PIDCurvatureCtrl)
{
	return this_PIDCurvatureCtrl->mPIDCurvatureCtrlParm;
}

extern void PCC_setPIDCurvatureCtrlParm(PIDCurvatureCtrl *this_PIDCurvatureCtrl,PIDCurvatureCtrlParm parm)
{
	this_PIDCurvatureCtrl->mPIDCurvatureCtrlParm = parm;
}

extern void PCC_reset(PIDCurvatureCtrl *this_PIDCurvatureCtrl)
{
	this_PIDCurvatureCtrl->deviation = 0;
	this_PIDCurvatureCtrl->integratedDeviation = 0;
	this_PIDCurvatureCtrl->differentialDeviation = 0;
	this_PIDCurvatureCtrl->bfDeviation = 0;
	this_PIDCurvatureCtrl->lastMeasurementTime = 0;
}
