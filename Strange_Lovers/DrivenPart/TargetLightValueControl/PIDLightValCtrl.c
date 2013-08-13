#include "PIDLightValCtrl.h"
#include "../../Factory.h"

void PLVC_init(PIDLightValCtrl *this_PIDLightValCtrl){
	this_PIDLightValCtrl->integratedDeviation = 0;
	this_PIDLightValCtrl->bfDeviation = 0;
	this_PIDLightValCtrl->lastMeasurementTime = 0;	
}

int PLVC_calcCtrlVal(PIDLightValCtrl *this_PIDLightValCtrl,PIDLightValCtrlParm *this_PIDLightValCtrlParm,float targLightVal,float LightVal,float time){
	
	float	turn;


	float deviation = targLightVal - LightVal;

	this_PIDLightValCtrl->integratedDeviation = (this_PIDLightValCtrl->integratedDeviation + 
		(deviation * (time - this_PIDLightValCtrl->lastMeasurementTime)));

	float differentialDeviation =  ((deviation - 
		this_PIDLightValCtrl->bfDeviation)/(time - this_PIDLightValCtrl->lastMeasurementTime));



	
	turn = (float)(deviation * PLVCP_getLKp(&mPIDLightValCtrlParm)
		+ this_PIDLightValCtrl->integratedDeviation * PLVCP_getLKi(&mPIDLightValCtrlParm)
		+ differentialDeviation * PLVCP_getLKd(&mPIDLightValCtrlParm));

	if (turn < -100) {
		turn = -100;
	}else if (turn > 100) {
		turn = 100;
	}

	this_PIDLightValCtrl->bfDeviation = deviation;
	this_PIDLightValCtrl->lastMeasurementTime = time;

	return (int)turn;
}

void PLVC_setCtrlParm(PIDLightValCtrl *this_PIDLightValCtrl,PIDLightValCtrlParm parm){
	this_PIDLightValCtrl->mPIDLightValCtrlParm = parm;
}

PIDLightValCtrlParm PLVC_getCtrlParm(PIDLightValCtrl *this_PIDLightValCtrl){
	return this_PIDLightValCtrl->mPIDLightValCtrlParm;
}

void PLVC_reset(PIDLightValCtrl *this_PIDLightValCtrl){
	this_PIDLightValCtrl->integratedDeviation = 0;
	this_PIDLightValCtrl->bfDeviation = 0;
	this_PIDLightValCtrl->lastMeasurementTime = 0;
}

