
#include "SpeedEncoder.h"
#include "../Factory.h"

#define CYCLE_TIME 0.004
#define TARGTIME 100

#define MEASURE_TIME_CYCLE 100 //[ms]
#define EXECUTE_CYCLE_TIME 4 //[ms]

int SpeedEncoder_get_speed(SpeedEncoder *this_SpeedEncoder)
{
	this_SpeedEncoder->speed =SpeedEncoder_calc_speed(this_SpeedEncoder);
	return this_SpeedEncoder->speed;
}

int SpeedEncoder_calc_speed(SpeedEncoder *this_SpeedEncoder)
{


	
	static float speedStore=0,bufDistance=0;
	static int bufTime =0;
	
	float distance = DistanceEncoder_get_distance(&distanceEncoder);
	float distance_diff = ((distance - bufDistance)/CYCLE_TIME)/10; //‚P‚O‚ÅŠ„‚Á‚Ä‚¢‚é‚Ì‚Í’PˆÊ‚ğcm/s‚É‚·‚é‚½‚ß
	unsigned int time =  Timer_get_ms(&timer);

	speedStore += distance_diff;

	if((time - bufTime) >= TARGTIME)
	{
		this_SpeedEncoder->speed = (int)speedStore/25; //25‰ñ•ª‚Ì•½‹Ï‚ğæ‚Á‚Ä‚é
		speedStore = 0;
		bufTime = time;
	}

	bufDistance = distance;

	return (int)this_SpeedEncoder->speed;
}

void SpeedEncoder_init(SpeedEncoder *this_SpeedEncoder)
{
	this_SpeedEncoder->speed = 0;

}

