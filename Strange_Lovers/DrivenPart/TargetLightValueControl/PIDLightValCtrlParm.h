#ifndef _PID_LIGHT_VAL_CTRL_PARM_H
#define _PID_LIGHT_VAL_CTRL_PARM_H

typedef struct{
	float lKp;
	float lKi;
	float lKd;
}PIDLightValCtrlParm;

extern void PLVCP_init(PIDLightValCtrlParm *this_PIDLightValCtrlParm,float Kp,float Ki,float Kd);
extern float PLVCP_getLKp(PIDLightValCtrlParm *this_PIDLightValCtrlParm);
extern void PLVCP_setLKp(PIDLightValCtrlParm *this_PIDLightValCtrlParm,float parm);
extern float PLVCP_getLKi(PIDLightValCtrlParm *this_PIDLightValCtrlParm);
extern void PLVCP_setLKi(PIDLightValCtrlParm *this_PIDLightValCtrlParm,float parm);
extern float PLVCP_getLKd(PIDLightValCtrlParm *this_PIDLightValCtrlParm);
extern void PLVCP_setLKd(PIDLightValCtrlParm *this_PIDLightValCtrlParm,float parm);

#endif
