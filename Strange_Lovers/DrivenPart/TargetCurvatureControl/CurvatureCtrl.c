#include "CurvatureCtrl.h"
#include "../../Factory.h"


#define CYCLE_TIME 0.004


//fake implementation
int CurvatureCtrl_run(CurvatureCtrl *this_CurvatureCtrl,int target_curvature)
{
	static	float	hensa = 0;
	static	int		turn = 0;

	static const float cKp = 1.8;
	static const float cKi = 0.9;
	static const float cKd =	0.001;

	static float i_hensa = 0;
	static float d_hensa = 0;
	static float bf_hensa = 0;

	hensa =  CurvatureEncoder_get_curvature(&curvatureEncoder) - target_curvature;

	i_hensa = i_hensa + (hensa * CYCLE_TIME);
	d_hensa = (bf_hensa - hensa )/CYCLE_TIME;
	bf_hensa = hensa;

	turn = cKp*hensa + cKi*i_hensa + cKd*d_hensa;
	turn = cutoff(turn,100);
	
	return turn;
}




void CC_init(CurvatureCtrl *this_CurvatureCtrl,PIDCurvatureCtrl PCC)
{
	mPIDCurvatureCtrl = PCC;
	PCC_init(&mPIDCurvatureCtrl);
	C_init(&mCurvature);
	this_CurvatureCtrl->C_CtrlState = C_CTRL_OFF;
}

void CC_setTargCurvature(CurvatureCtrl *this_CurvatureCtrl,float parm)
{
	C_setTargCurvature(&mCurvature,parm);
}

float CC_getTargCurvatureCtrl(CurvatureCtrl *this_CurvatureCtrl)
{
	return C_getTargCurvature(&mCurvature);
}

void CC_setCtrlParm(CurvatureCtrl *this_CurvatureCtrl,PIDCurvatureCtrlParm parm)
{
	PCC_setPIDCurvatureCtrlParm(&mPIDCurvatureCtrl,parm);
}

PIDCurvatureCtrlParm CC_getCtrlParm(CurvatureCtrl *this_CurvatureCtrl)
{
	return PCC_getPIDCurvatureCtrlParm(&mPIDCurvatureCtrl);
}

void CC_startCtrl(CurvatureCtrl *this_CurvatureCtrl)
{
	CC_changeMode(&(*this_CurvatureCtrl),C_CTRL_ON);
}

void CC_stopCtrl(CurvatureCtrl *this_CurvatureCtrl)
{
	PCC_reset(&mPIDCurvatureCtrl);
	CC_changeMode(&(*this_CurvatureCtrl),C_CTRL_OFF);
}

int CC_doCtrl(CurvatureCtrl *this_CurvatureCtrl)
{
	int turn = PCC_calcCurvatureCtrlVal(&mPIDCurvatureCtrl,
		C_getTargCurvature(&mCurvature),C_getCurvature(&mCurvature,ecrobot_get_systick_ms()),systick_get_ms()*0.001);
	return turn;
}

int CC_run(CurvatureCtrl *this_CurvatureCtrl)
{
	int turn = 0;
	switch(this_CurvatureCtrl->C_CtrlState){
	case C_CTRL_ON:
		//���v�H
		turn = CC_doCtrl(&(*this_CurvatureCtrl));
		break;
	case C_CTRL_OFF:
		turn = 0;
		break;
	default:
		turn = 0;
		break;
	}

	return turn;
}

void CC_changeMode(CurvatureCtrl *this_CurvatureCtrl,CurvatureCtrlState state)
{
	this_CurvatureCtrl->C_CtrlState = state;
}