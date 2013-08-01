#include "PIDLightValCtrl.h"
#include "../../Factory.h"

void PLVC_init(PIDLightValCtrl *this_PIDLightValCtrl){
	this_PIDLightValCtrl->deviation = 0;
	this_PIDLightValCtrl->integratedDeviation = 0;
	this_PIDLightValCtrl->differentialDeviation = 0;
	this_PIDLightValCtrl->deviation = 0;
	this_PIDLightValCtrl->lastMeasurementTime = 0;
}

int PLVC_calcCtrlVal(PIDLightValCtrl *this_PIDLightValCtrl,PIDLightValCtrlParm *this_PIDLightValCtrlParm,int targLightVal,int LightVal,float time){
	
	int	turn;


	this_PIDLightValCtrl->deviation = targLightVal - LightVal;

	this_PIDLightValCtrl->integratedDeviation = (float) (this_PIDLightValCtrl->integratedDeviation + 
		(this_PIDLightValCtrl->deviation * (time - this_PIDLightValCtrl->lastMeasurementTime)));

	this_PIDLightValCtrl->differentialDeviation = (float) ((this_PIDLightValCtrl->deviation - 
		this_PIDLightValCtrl->bfDeviation)/(time - this_PIDLightValCtrl->lastMeasurementTime));



	//turn = Kp*hensa + Ki*i_hensa + Kd*d_hensa + b;

	turn = (int)(this_PIDLightValCtrl->deviation * PLVCP_getLKp(&mPIDLightValCtrlParm)
		//+ this_PIDLightValCtrl->integratedDeviation * PLVCP_getLKi(&mPIDLightValCtrlParm)
		+ this_PIDLightValCtrl->differentialDeviation * PLVCP_getLKd(&mPIDLightValCtrlParm));

	if (turn < -100) {
		turn = -100;
	}else if (turn > 100) {
		turn = 100;
	}

	//turn = DirectionCtrl_run(&directionCtrl,90);

	//ecrobot_debug1((int)this_PIDLightValCtrl->deviation,turn,(int)this_PIDLightValCtrl->differentialDeviation);

	logSend((int)(this_PIDLightValCtrl->deviation * PLVCP_getLKp(&this_PIDLightValCtrl->mPIDLightValCtrlParm)
		+ this_PIDLightValCtrl->integratedDeviation * PLVCP_getLKi(&this_PIDLightValCtrl->mPIDLightValCtrlParm)
		+ this_PIDLightValCtrl->differentialDeviation * PLVCP_getLKd(&this_PIDLightValCtrl->mPIDLightValCtrlParm)),0,0,0,0,0,0,0);

	return turn;

	/*

	int cmd_turn;

	if(targLightVal > 0)
		this_PIDLightValCtrl->deviation = targLightVal - LightVal;
	else
		this_PIDLightValCtrl->deviation = LightVal - targLightVal;
	
	this_PIDLightValCtrl->integratedDeviation = (float) (this_PIDLightValCtrl->integratedDeviation + 
		(this_PIDLightValCtrl->deviation * (time - this_PIDLightValCtrl->lastMeasurementTime)));

	this_PIDLightValCtrl->differentialDeviation = (float) ((this_PIDLightValCtrl->deviation - 
		this_PIDLightValCtrl->bfDeviation)/(time - this_PIDLightValCtrl->lastMeasurementTime));

	cmd_turn = (int)(this_PIDLightValCtrl->deviation * PLVCP_getLKp(&this_PIDLightValCtrl->mPIDLightValCtrlParm)
		+ this_PIDLightValCtrl->integratedDeviation * PLVCP_getLKi(&this_PIDLightValCtrl->mPIDLightValCtrlParm)
		+ this_PIDLightValCtrl->differentialDeviation * PLVCP_getLKd(&this_PIDLightValCtrl->mPIDLightValCtrlParm));

	if(cmd_turn > 100)
		cmd_turn = 100;
	else if(cmd_turn < -100)
		cmd_turn = -100;

	this_PIDLightValCtrl->bfDeviation = this_PIDLightValCtrl->deviation;
	this_PIDLightValCtrl->lastMeasurementTime = time;

	return cmd_turn;

	ecrobot_debug1(cmd_turn,targLightVal,LightVal);
	*/
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

