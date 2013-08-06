#include "PIDLightValCtrlParm.h"

void PLVCP_init(PIDLightValCtrlParm *this_PIDLightValCtrlParm){
	this_PIDLightValCtrlParm->lKp = 145.0;
	this_PIDLightValCtrlParm->lKi = 0.15;
	this_PIDLightValCtrlParm->lKd = 4.0;
}
float PLVCP_getLKp(PIDLightValCtrlParm *this_PIDLightValCtrlParm){
	return this_PIDLightValCtrlParm->lKp;
}
void PLVCP_setLKp(PIDLightValCtrlParm *this_PIDLightValCtrlParm,float parm){
	this_PIDLightValCtrlParm->lKp = parm;
}
float PLVCP_getLKi(PIDLightValCtrlParm *this_PIDLightValCtrlParm){
	return this_PIDLightValCtrlParm->lKi;
}
void PLVCP_setLKi(PIDLightValCtrlParm *this_PIDLightValCtrlParm,float parm){
	this_PIDLightValCtrlParm->lKi = parm;
}
float PLVCP_getLKd(PIDLightValCtrlParm *this_PIDLightValCtrlParm){
	return this_PIDLightValCtrlParm->lKd;
}
void PLVCP_setLKd(PIDLightValCtrlParm *this_PIDLightValCtrlParm,float parm){
	this_PIDLightValCtrlParm->lKd = parm;
}

