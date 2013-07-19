
#ifndef __DistanceEncoder
#define __DistanceEncoder

#include "../WheelMotor.h"

typedef struct{
	int distance;
	int revL_buf;
	int revR_buf;
}DistanceEncoder;


void DistanceEncoder_init(DistanceEncoder *this_DistanceEncoder);
static int DistanceEncoder_calc_distance(DistanceEncoder *this_DistanceEncoder);
int DistanceEncoder_get_distance(DistanceEncoder *this_DistanceEncoder);
void DistanceEncoder_reset_Encoder(DistanceEncoder *this_DistanceEncoder);

#endif

