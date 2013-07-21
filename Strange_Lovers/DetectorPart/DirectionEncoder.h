#ifndef __DirectionEncoder
#define __DirectionEncoder


#include "./DistanceEncoder.h"
#include "./Timer.h"

typedef struct{
	int direction;
	
}DirectionEncoder;


int DirectionEncoder_get_speed(DirectionEncoder *this_DirectionEncoder);
int DirectionEncoder_calc_speed(DirectionEncoder *this_DirectionEncoder);
void DirectionEncoder_init(DirectionEncoder *this_DirectionEncoder);

#endif 


