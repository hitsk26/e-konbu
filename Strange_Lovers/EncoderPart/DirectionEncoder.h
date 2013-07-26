#ifndef __DirectionEncoder
#define __DirectionEncoder


#include "./DistanceEncoder.h"
#include "../DrivenPart/WheelMotor.h"


// é‘ó÷îºåaÅAëñçsëÃïù
#define WHEEL_R		41	//[mm]
#define MACHINE_W	162	//[mm]

typedef struct{
	float direction;
	
}DirectionEncoder;


float DirectionEncoder_get_direction(DirectionEncoder *this_DirectionEncoder);
float DirectionEncoder_calc_speed(DirectionEncoder *this_DirectionEncoder);
void DirectionEncoder_init(DirectionEncoder *this_DirectionEncoder);

#endif 


