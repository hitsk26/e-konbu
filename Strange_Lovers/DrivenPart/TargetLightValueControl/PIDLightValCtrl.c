#include "PIDLightValCtrl.h"
#include "../../Factory.h"

void PLVC_init(PIDLightValCtrl *this_PIDLightValCtrl){
	this_PIDLightValCtrl->deviation = 0;
	this_PIDLightValCtrl->integratedDeviation = 0;
	this_PIDLightValCtrl->differentialDeviation = 0;
	this_PIDLightValCtrl->deviation = 0;
	this_PIDLightValCtrl->lastMeasurementTime = 0;
}

int PLVC_calcCtrlVal(PIDLightValCtrl *this_PIDLightValCtrl,PIDLightValCtrlParm *this_PIDLightValCtrlParm,float targLightVal,float LightVal,float time){
	
	float	turn;


	this_PIDLightValCtrl->deviation = targLightVal - LightVal;

	this_PIDLightValCtrl->integratedDeviation = (this_PIDLightValCtrl->integratedDeviation + 
		(this_PIDLightValCtrl->deviation * (time - this_PIDLightValCtrl->lastMeasurementTime)));

	this_PIDLightValCtrl->differentialDeviation =  ((this_PIDLightValCtrl->deviation - 
		this_PIDLightValCtrl->bfDeviation)/(time - this_PIDLightValCtrl->lastMeasurementTime));



	//turn = Kp*hensa + Ki*i_hensa + Kd*d_hensa + b;

	turn = (float)(this_PIDLightValCtrl->deviation * PLVCP_getLKp(&mPIDLightValCtrlParm)
		//+ this_PIDLightValCtrl->integratedDeviation * PLVCP_getLKi(&mPIDLightValCtrlParm)
		+ this_PIDLightValCtrl->differentialDeviation * PLVCP_getLKd(&mPIDLightValCtrlParm));

	if (turn < -100) {
		turn = -100;
	}else if (turn > 100) {
		turn = 100;
	}

	//ecrobot_debug1(turn,(int)(LightVal*100), (targLightVal - LightVal)*100);
	this_PIDLightValCtrl->bfDeviation = this_PIDLightValCtrl->deviation;
	this_PIDLightValCtrl->lastMeasurementTime = time;

	return (int)turn;
}

void PLVC_setCtrlParm(PIDLightValCtrl *this_PIDLightValCtrl,PIDLightValCtrlParm parm){
	this_PIDLightValCtrl->mPIDLightValCtrlParm = parm;
	PLVCP_init(&this_PIDLightValCtrl->mPIDLightValCtrlParm);
}

PIDLightValCtrlParm PLVC_getLtrlParm(PIDLightValCtrl *this_PIDLightValCtrl){
	return this_PIDLightValCtrl->mPIDLightValCtrlParm;
}

void PLVC_reset(PIDLightValCtrl *this_PIDLightValCtrl){
	this_PIDLightValCtrl->deviation = 0;
	this_PIDLightValCtrl->integratedDeviation = 0;
	this_PIDLightValCtrl->differentialDeviation = 0;
	this_PIDLightValCtrl->bfDeviation = 0;
	this_PIDLightValCtrl->lastMeasurementTime = 0;
}

