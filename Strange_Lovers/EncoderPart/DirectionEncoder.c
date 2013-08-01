
#include "DirectionEncoder.h"
#include "../Factory.h"

#define CYCLE_TIME 0.004
#define TARGTIME 100

#define MEASURE_TIME_CYCLE 100 //[ms]
#define EXECUTE_CYCLE_TIME 4 //[ms]

void DirectionEncoder_init(DirectionEncoder *this_DirectionEncoder)
{
	this_DirectionEncoder->direction = 0;
}

float DirectionEncoder_get_direction(DirectionEncoder *this_DirectionEncoder)
{
	this_DirectionEncoder->direction =DirectionEncoder_calc_speed(this_DirectionEncoder);
	return this_DirectionEncoder->direction;
}

float DirectionEncoder_calc_speed(DirectionEncoder *this_DirectionEncoder)
{
	int revL = WheelMotor_get_count(&leftWheelMotor);

	int revR = WheelMotor_get_count(&rightWheelMotor);	

	float direction = (float)W_RADIUS / W_DIST * (revR - revL);
	return direction;
}


