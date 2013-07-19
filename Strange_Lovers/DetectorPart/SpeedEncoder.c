
#include "SpeedEncoder.h"
#include "../Factory.h"


#define MEASURE_TIME_CYCLE 100 //[ms]
#define EXECUTE_CYCLE_TIME 4 //[ms]

int SpeedEncoder_get_speed(SpeedEncoder *this_SpeedEncoder)
{
	this_SpeedEncoder->speed =SpeedEncoder_calc_speed(this_SpeedEncoder);
	return this_SpeedEncoder->speed;
}

int SpeedEncoder_calc_speed(SpeedEncoder *this_SpeedEncoder)
{

	static int buf_distance=0;
	static int buf_time = 0;
	static int count=0;
	static float speed_store=0,speed=0;
	
	int distance = DistanceEncoder_get_distance(&distanceEncoder);
	unsigned int time =  Timer_get_ms(&timer);

	speed_store += ((distance - buf_distance) / (time -  buf_time));
	if(count>= 25){
	speed = speed_store / 25 ;
	speed_store =0;
	count = 0;
	}
	count++;

	buf_distance= distance;
	buf_time = time;

	return speed;
}

void SpeedEncoder_init(SpeedEncoder *this_SpeedEncoder)
{
	this_SpeedEncoder->speed = 0;

}

