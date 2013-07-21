#include "PIDSpeedCtrl.h"

void PSC_init(PIDSpeedCtrl *this_PIDSpeedCtrl){
	this_PIDSpeedCtrl->deviation = 0;
	this_PIDSpeedCtrl->integratedDeviation = 0;
	this_PIDSpeedCtrl->differentialDeviation = 0;
	this_PIDSpeedCtrl->bfDeviation = 0;
	this_PIDSpeedCtrl->lastMeasurementTime = 0;
}

int PSC_calcSpeedCtrlVal(PIDSpeedCtrl *this_PIDSpeedCtrl,float targSpeed,float bfSpeed,float speed,float time){
	int cmd_turn;

	if(targSpeed > 0)
		this_PIDSpeedCtrl->deviation = targSpeed - speed;
	else
		this_PIDSpeedCtrl->deviation = speed - targSpeed;
	
	this_PIDSpeedCtrl->integratedDeviation = (float) (this_PIDSpeedCtrl->integratedDeviation + 
		(this_PIDSpeedCtrl->deviation * (time - this_PIDSpeedCtrl->lastMeasurementTime)));

	this_PIDSpeedCtrl->differentialDeviation = (float) ((this_PIDSpeedCtrl->deviation - 
		this_PIDSpeedCtrl->bfDeviation)/(time - this_PIDSpeedCtrl->lastMeasurementTime));

	cmd_turn = (int)(this_PIDSpeedCtrl->deviation * PSCP_getSKp(&this_PIDSpeedCtrl->mPIDSpeedCtrlParm)
		+ this_PIDSpeedCtrl->integratedDeviation * PSCP_getSKi(&this_PIDSpeedCtrl->mPIDSpeedCtrlParm)
		+ this_PIDSpeedCtrl->differentialDeviation * PSCP_getSKd(&this_PIDSpeedCtrl->mPIDSpeedCtrlParm));

	if(cmd_turn > 100)
		cmd_turn = 100;
	else if(cmd_turn < -100)
		cmd_turn = -100;

	this_PIDSpeedCtrl->bfDeviation = this_PIDSpeedCtrl->deviation;
	this_PIDSpeedCtrl->lastMeasurementTime = time;

	return cmd_turn + bfSpeed;
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
