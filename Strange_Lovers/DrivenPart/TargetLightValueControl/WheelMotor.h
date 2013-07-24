#ifndef _WHEEL_MOTOR_H
#define _WHEEL_MOTOR_H

/**
 * êKîˆäpìx
 */

#include "ecrobot_interface.h"
#include "Log.h"

typedef struct{
	int speed;
	int turn;
} WheelMotor;

Log mmLog;

extern void WM_ctrl(WheelMotor *this_WheelMotor);
extern void WM_setSpeed(WheelMotor *this_WheelMotor,int parm);
extern void WM_setTurn(WheelMotor *this_WheelMotor,int parm);
extern void WM_init(WheelMotor *this_WheelMotor);


#endif
