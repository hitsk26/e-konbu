
#include "SpeedEncoder.h"
#include "../lib/MovingAverage.h"

#include "../Factory.h"

#define CYCLE_TIME 0.004


int SpeedEncoder_get_speed(SpeedEncoder *this_SpeedEncoder)
{
	this_SpeedEncoder->speed =SpeedEncoder_calc_speed(this_SpeedEncoder);
	return this_SpeedEncoder->speed;
}

int SpeedEncoder_calc_speed(SpeedEncoder *this_SpeedEncoder)
{

	static float speedStore=0,bufDistance=0;
	float distance = DistanceEncoder_get_distance(&distanceEncoder);
	float distance_diff = ((distance - bufDistance)/CYCLE_TIME);
	static float moving_average_buf[25];
	static int index=0;
	
	if(index>=25){
		index=0;
	}
	this_SpeedEncoder->speed  = moving_average(distance_diff,moving_average_buf,25,index);
	index++;

	bufDistance = distance;
	
	return (int)this_SpeedEncoder->speed;
}

void SpeedEncoder_init(SpeedEncoder *this_SpeedEncoder)
{
	this_SpeedEncoder->speed = 0;

}



