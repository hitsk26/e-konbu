#ifndef _BALANCER_H_
#define _BALANCER_H_

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
//#include "balancer.h"
#include "C:/cygwin/nxtOSEK\ecrobot/nxtway_gs_balancer/balancer.h"

S8 forward = 10;
S8 turn = 0;
S8	pwm_l, pwm_r;

U32	gyro_offset = 600;

extern void balance_running();
extern void set_forward(int forward_buf);
extern void set_turn(int turn_buf);
extern void set_gyro(U32 gyro);

#endif