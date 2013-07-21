#include "Speed.h"
#include "../../Factory.h"

void S_init(Speed *this_Speed){
	this_Speed->targSpeed = 0;
	this_Speed->bfSpeed = 0;
}

int S_getSpeed(Speed *this_Speed,int time){

	int speed = SpeedEncoder_get_speed(&speedEncoder);

	this_Speed->bfSpeed = speed;
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
