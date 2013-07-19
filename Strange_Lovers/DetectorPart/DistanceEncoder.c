#include "DistanceEncoder.h"
#include "../Factory.h"
#define CIRCUMFERENCE 258


void DistanceEncoder_init(DistanceEncoder *this_DistanceEncoder)
{
	this_DistanceEncoder->distance = 0;
	this_DistanceEncoder->revL_buf=0;
	this_DistanceEncoder->revR_buf=0;

	}


int DistanceEncoder_get_distance(DistanceEncoder *this_DistanceEncoder)
{
	this_DistanceEncoder->distance = DistanceEncoder_calc_distance(this_DistanceEncoder);
	return this_DistanceEncoder->distance;
}

int DistanceEncoder_calc_distance(DistanceEncoder *this_DistanceEncoder)
{
	S16 revL=0,revR=0;
	revL = WheelMotor_get_count(&leftWheelMotor);
	revR = WheelMotor_get_count(&rightWheelMotor);	
	int distance = CIRCUMFERENCE/360.0 * (((revL - this_DistanceEncoder->revL_buf) + (revR- this_DistanceEncoder->revR_buf)) /2.0);
	return distance;
}

 void DistanceEncoder_reset_Encoder(DistanceEncoder *this_DistanceEncoder)
{
	this_DistanceEncoder->revL_buf=WheelMotor_get_count(&leftWheelMotor);
	this_DistanceEncoder->revR_buf=WheelMotor_get_count(&rightWheelMotor);	
}