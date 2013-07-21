
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

int DirectionEncoder_get_direction(DirectionEncoder *this_DirectionEncoder)
{
	this_DirectionEncoder->direction =DirectionEncoder_calc_speed(this_DirectionEncoder);
	return this_DirectionEncoder->direction;
}

int DirectionEncoder_calc_speed(DirectionEncoder *this_DirectionEncoder)
{
	float revL = WheelMotor_get_count(&leftWheelMotor);
	float revR = WheelMotor_get_count(&rightWheelMotor);	

	float direction = W_RADIUS / W_DIST * (revR - revL);
	return (int)direction;
}


