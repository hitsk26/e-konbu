#include "PIDCurvatureCtrl.h"

extern void PCC_init(PIDCurvatureCtrl *self)
{
	self->deviation = 0;
	self->integratedDeviation = 0;
	self->differentialDeviation = 0;
	self->bfDeviation = 0;
	self->lastMeasurementTime = 0;
	self->turn_buf=0;

}

extern int PCC_calcCurvatureCtrlVal(PIDCurvatureCtrl *self,float targCurvature,float curvature,float time)
{
	float turn;
	
	self->deviation =   targCurvature - curvature;

	self->integratedDeviation = (float) (self->integratedDeviation + 
		(self->deviation * (time - self->lastMeasurementTime)));

	self->differentialDeviation = (float) ((self->deviation - 
		self->bfDeviation)/(time - self->lastMeasurementTime));

	turn = (self->deviation * PCCP_getCKp(&self->mPIDCurvatureCtrlParm)
		+ self->integratedDeviation * PCCP_getCKi(&self->mPIDCurvatureCtrlParm)
		+ self->differentialDeviation * PCCP_getCKd(&self->mPIDCurvatureCtrlParm));
	
	turn = turn + self->turn_buf;
	
	if(turn > 100)
		turn = 100;
	else if(turn < -100)
		turn = -100;

	self->bfDeviation = self->deviation;
	self->lastMeasurementTime = time;
	self->turn_buf = turn;

	return (int)turn;
}

PIDCurvatureCtrlParm PCC_getPIDCurvatureCtrlParm(PIDCurvatureCtrl *self)
{
	return self->mPIDCurvatureCtrlParm;
}

extern void PCC_setPIDCurvatureCtrlParm(PIDCurvatureCtrl *self,PIDCurvatureCtrlParm parm)
{
	self->mPIDCurvatureCtrlParm = parm;
}

extern void PCC_reset(PIDCurvatureCtrl *self)
{
	self->deviation = 0;
	self->integratedDeviation = 0;
	self->differentialDeviation = 0;
	self->bfDeviation = 0;
	self->lastMeasurementTime = 0;
}
