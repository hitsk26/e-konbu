#include "PIDLightValCtrl.h"
#include "../../Factory.h"

void PLVC_init(PIDLightValCtrl *this_PIDLightValCtrl){
	this_PIDLightValCtrl->deviation = 0;
	this_PIDLightValCtrl->integratedDeviation = 0;
	this_PIDLightValCtrl->differentialDeviation = 0;
	this_PIDLightValCtrl->deviation = 0;
	this_PIDLightValCtrl->lastMeasurementTime = 0;
}

int PLVC_calcCtrlVal(PIDLightValCtrl *this_PIDLightValCtrl,int targLightVal,int LightVal,float time){
	
	static	float	hensa = 0;
	static	int		turn = 0;

	static const float Kp =	1.0;
	static const float Ki =	0.0	;
	static const float Kd =	0.0	;
	static const float b = 0;

	static float i_hensa = 0;
	static float d_hensa = 0;
	static float bf_hensa = 0;

	

	hensa = LV_getTargLightVal(&mLightVal) - BrightnessEncoder_get_brightness(&brightnessEncoder);

	i_hensa = i_hensa + (hensa * 0.004);

	d_hensa = (bf_hensa - hensa )/0.004;
	bf_hensa = hensa;

	turn = Kp*hensa + Ki*i_hensa + Kd*d_hensa + b;

	if (turn < -100) {
		turn = -100;
	}else if (turn > 100) {
		turn = 100;
	}

	//turn = DirectionCtrl_run(&directionCtrl,90);

	return turn;
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

