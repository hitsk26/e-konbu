#include "CurvatureCtrl.h"
#include "../../Factory.h"

#define CYCLE_TIME 0.004

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

float CC_doCtrl(CurvatureCtrl *this_CurvatureCtrl)
{
	float curvature = C_getCurvature(&mCurvature,ecrobot_get_systick_ms());
	float turn = PCC_calcCurvatureCtrlVal(&mPIDCurvatureCtrl,
		C_getTargCurvature(&mCurvature),curvature,systick_get_ms()*0.001);
	return turn;
}

float CC_run(CurvatureCtrl *this_CurvatureCtrl)
{
	float turn = 0;
	switch(this_CurvatureCtrl->C_CtrlState){
	case C_CTRL_ON:
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

