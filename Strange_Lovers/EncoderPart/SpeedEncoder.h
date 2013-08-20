#ifndef __SpeedEncoder
#define __SpeedEncoder


#include "./DistanceEncoder.h"
#include "./Timer.h"
#include "../lib/MovingAverage.h"


typedef struct{
	float speed;
	float buf_distance;
}SpeedEncoder;


int SpeedEncoder_get_speed(SpeedEncoder *this_SpeedEncoder);
void SpeedEncoder_calc_speed(SpeedEncoder *this_SpeedEncoder);
void SpeedEncoder_init(SpeedEncoder *this_SpeedEncoder);

#endif 


