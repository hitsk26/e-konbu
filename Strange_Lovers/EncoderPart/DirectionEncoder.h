#ifndef __DirectionEncoder
#define __DirectionEncoder


#include "./DistanceEncoder.h"
#include "../DrivenPart/WheelMotor.h"
#include "../NXTSettings.h"



typedef struct{
	float direction;
	
}DirectionEncoder;


float DirectionEncoder_get_direction(DirectionEncoder *this_DirectionEncoder);
void DirectionEncoder_calc_speed(DirectionEncoder *this_DirectionEncoder);
void DirectionEncoder_init(DirectionEncoder *this_DirectionEncoder);

#endif 


