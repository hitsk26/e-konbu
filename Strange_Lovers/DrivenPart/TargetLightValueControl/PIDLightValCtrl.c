#include "PIDLightValCtrl.h"
#include "../../Factory.h"

void PLVC_init(PIDLightValCtrl *self,PIDLightValCtrlParm *parm){
	self->integratedDeviation = 0;
	self->bfDeviation = 0;
	self->lastMeasurementTime = 0;	
	self->mPIDLightValCtrlParm = parm;
//PLVCP_init(parm,180.0,0,80);
	PLVCP_init(parm,110.0,0,28);
	
}

float PLVC_calcCtrlVal(PIDLightValCtrl *self,float targLightVal,float LightVal,float time){
	
	float	turn;

	float deviation = self->movementDirection*(targLightVal - LightVal);

	self->integratedDeviation = (self->integratedDeviation + 
		(deviation * (time - self->lastMeasurementTime)));

	float differentialDeviation =  ((deviation - 
		self->bfDeviation)/(time - self->lastMeasurementTime));
	
	turn = (float)(deviation * PLVCP_getLKp(&mPIDLightValCtrlParm)
		+ self->integratedDeviation * PLVCP_getLKi(&mPIDLightValCtrlParm)
		+ differentialDeviation * PLVCP_getLKd(&mPIDLightValCtrlParm));

	if (turn < -100) {
		turn = -100;
	}else if (turn > 100) {
		turn = 100;
	}

	self->bfDeviation = deviation;
	self->lastMeasurementTime = time;

	return turn;
}

void PLVC_setCtrlParm(PIDLightValCtrl *self,PIDLightValCtrlParm *parm){
	self->mPIDLightValCtrlParm = parm;
}

PIDLightValCtrlParm* PLVC_getCtrlParm(PIDLightValCtrl *self){
	return self->mPIDLightValCtrlParm;
}

void PLVC_reset(PIDLightValCtrl *self){
	self->integratedDeviation = 0;
	self->bfDeviation = 0;
	self->lastMeasurementTime = 0;
}

void PLVC_setMovementDirection(PIDLightValCtrl *self,MovementDirection movementDirection)
{
	self->movementDirection = movementDirection;
}