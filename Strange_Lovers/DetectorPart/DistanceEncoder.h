
#ifndef __DistanceEncoder
#define __DistanceEncoder

#include "../DrivenPart/WheelMotor.h"

typedef struct{
	float distance;
	int revL_buf;
	int revR_buf;
}DistanceEncoder;


void DistanceEncoder_init(DistanceEncoder *this_DistanceEncoder);
float DistanceEncoder_calc_distance(DistanceEncoder *this_DistanceEncoder);
float DistanceEncoder_get_distance(DistanceEncoder *this_DistanceEncoder);
void DistanceEncoder_reset_Encoder(DistanceEncoder *this_DistanceEncoder);

#endif

