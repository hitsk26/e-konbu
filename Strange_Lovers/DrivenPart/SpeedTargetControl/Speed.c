#include "Speed.h"
#include "DegRadMath.h"

void S_init(Speed *this_Speed,SpeedEncoder SE){
	this_Speed->targSpeed = 0;
	this_Speed->bfSpeed = 0;
	this_Speed->mSpeedEncoder = SE;
	Log_init(&mLog);
}

int S_getSpeed(Speed *this_Speed,int time){

	int speed = SE_getSpeed(&this_Speed->mSpeedEncoder,time);
	Log_setData3(&mLog,speed);
	this_Speed->bfSpeed = speed;

	Log_logSend(&mLog);

	return speed;
}

int S_getBfSpeed(Speed *this_Speed){
	return this_Speed->bfSpeed;
}

int S_getTargSpeed(Speed *this_Speed){
	return this_Speed->targSpeed;
}

void S_setTargSpeed(Speed *this_Speed,int parm){
	this_Speed->targSpeed = parm;
}
