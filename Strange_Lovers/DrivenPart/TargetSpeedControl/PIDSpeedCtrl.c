#include "PIDSpeedCtrl.h"

void PSC_init(PIDSpeedCtrl *this_PIDSpeedCtrl){
	this_PIDSpeedCtrl->deviation = 0;
	this_PIDSpeedCtrl->integratedDeviation = 0;
	this_PIDSpeedCtrl->differentialDeviation = 0;
	this_PIDSpeedCtrl->bfDeviation = 0;
	this_PIDSpeedCtrl->lastMeasurementTime = 0;
}

int PSC_calcSpeedCtrlVal(PIDSpeedCtrl *this_PIDSpeedCtrl,float targSpeed,float bfSpeed,float speed,float time){
	int forward=0;
	
	this_PIDSpeedCtrl->deviation = targSpeed - speed;
	
	this_PIDSpeedCtrl->integratedDeviation = (float) (this_PIDSpeedCtrl->integratedDeviation + 
		(this_PIDSpeedCtrl->deviation * (time - this_PIDSpeedCtrl->lastMeasurementTime)));

	this_PIDSpeedCtrl->differentialDeviation = (float) ((this_PIDSpeedCtrl->deviation - 
		this_PIDSpeedCtrl->bfDeviation)/(time - this_PIDSpeedCtrl->lastMeasurementTime));

	forward = (int)(this_PIDSpeedCtrl->deviation * PSCP_getSKp(&this_PIDSpeedCtrl->mPIDSpeedCtrlParm)
		+ this_PIDSpeedCtrl->integratedDeviation * PSCP_getSKi(&this_PIDSpeedCtrl->mPIDSpeedCtrlParm)
		+ this_PIDSpeedCtrl->differentialDeviation * PSCP_getSKd(&this_PIDSpeedCtrl->mPIDSpeedCtrlParm));


	this_PIDSpeedCtrl->bfDeviation = this_PIDSpeedCtrl->deviation;
	this_PIDSpeedCtrl->lastMeasurementTime = time;
	
	forward = forward + bfSpeed;
	
	if(forward > 100)
		forward = 100;
	else if(forward < -100)
		forward = -100;
	
	return forward;
}

PIDSpeedCtrlParm PSC_getPIDSpeedCtrlParm(PIDSpeedCtrl *this_PIDSpeedCtrl){
	return this_PIDSpeedCtrl->mPIDSpeedCtrlParm;
}

void PSC_setPIDSpeedCtrlParm(PIDSpeedCtrl *this_PIDSpeedCtrl,PIDSpeedCtrlParm parm){
	this_PIDSpeedCtrl->mPIDSpeedCtrlParm = parm;
}

void PSC_reset(PIDSpeedCtrl *this_PIDSpeedCtrl){
	this_PIDSpeedCtrl->deviation = 0;
	this_PIDSpeedCtrl->integratedDeviation = 0;
	this_PIDSpeedCtrl->differentialDeviation = 0;
	this_PIDSpeedCtrl->bfDeviation = 0;
	this_PIDSpeedCtrl->lastMeasurementTime = 0;
}
