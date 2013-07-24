#include "WheelMotor.h"

void WM_init(WheelMotor *this_WheelMotor){
	this_WheelMotor->speed = 0;
	this_WheelMotor->turn = 0;
}

void WM_ctrl(WheelMotor *this_WheelMotor){
	nxt_motor_set_speed(NXT_PORT_B,(int)(this_WheelMotor->speed - this_WheelMotor->turn/2),1);
	nxt_motor_set_speed(NXT_PORT_C,(int)(this_WheelMotor->speed + this_WheelMotor->turn/2),1);

}

void WM_setSpeed(WheelMotor *this_WheelMotor,int parm){
	if(parm > 100)
		parm = 100;
	else if(parm < -100)
		parm = -100;

	this_WheelMotor->speed = parm;
}

void WM_setTurn(WheelMotor *this_WheelMotor,int parm){
	if(parm > 100)
		parm = 100;
	else if(parm < -100)
		parm = -100;

	this_WheelMotor->turn = parm;
}
