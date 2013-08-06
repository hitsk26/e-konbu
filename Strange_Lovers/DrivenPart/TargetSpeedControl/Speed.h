#ifndef _SPEED_H
#define _SPEED_H

#include "math.h"


#define LIMIT 100

typedef struct{
	float targSpeed;
	float bfSpeed;
} Speed;

extern void S_init(Speed *this_Speed);
extern int S_getSpeed(Speed *this_Speed,int time);
extern int S_getTargSpeed(Speed *this_Speed);
extern int S_getBfSpeed(Speed *this_Speed);
extern void S_setTargSpeed(Speed *this_Speed,int parm);

#endif
