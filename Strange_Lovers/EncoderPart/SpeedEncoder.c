
#include "SpeedEncoder.h"
#include "../Factory.h"

#define CYCLE_TIME 0.004

void SpeedEncoder_init(SpeedEncoder *this_SpeedEncoder)
{
	this_SpeedEncoder->speed = 0;
	this_SpeedEncoder->buf_distance =0;
}

float SpeedEncoder_get_speed(SpeedEncoder *this_SpeedEncoder)
{
	return this_SpeedEncoder->speed;
}

void SpeedEncoder_calc_speed(SpeedEncoder *this_SpeedEncoder)
{
	float distance = DistanceEncoder_get_distance(&distanceEncoder);
	float speed = ((distance - this_SpeedEncoder->buf_distance)/CYCLE_TIME);

	this_SpeedEncoder->speed  = MovingAverage_get_averaged_value(&speedEncoderMovingAverage,speed);
	this_SpeedEncoder->buf_distance=distance;

}





