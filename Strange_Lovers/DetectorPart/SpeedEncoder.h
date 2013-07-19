#ifndef __SpeedEncoder
#define __SpeedEncoder


#include "./DistanceEncoder.h"
#include "./Timer.h"

typedef struct{
	int speed;
	
}SpeedEncoder;


int SpeedEncoder_get_speed(SpeedEncoder *this_SpeedEncoder);
int SpeedEncoder_calc_speed(SpeedEncoder *this_SpeedEncoder);
void SpeedEncoder_init(SpeedEncoder *this_SpeedEncoder);

#endif 


