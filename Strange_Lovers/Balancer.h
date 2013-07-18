#ifndef _BALANCER_H_
#define _BALANCER_H_

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
//#include "balancer.h"
#include "/cygdrive/c/cygwin/nxtOSEK/ecrobot/nxtway_gs_balancer/balancer.h"
#include "WheelMotor.h"



typedef struct{
	S8 forward;
	S8 turn;
	S8	pwm_l, pwm_r;
	U32	gyro_offset;
}Balancer;


extern void Balancer_init(Balancer *this_Balancer);
extern void Balancer_balance_running();
extern void Balancer_set_forward(Balancer *this_Balancer , S8 forward);
extern void Balancer_set_turn(Balancer *this_Balancer , S8 turn);
extern void Balancer_set_gyro(Balancer *this_Balancer , U32 gyro);

#endif

