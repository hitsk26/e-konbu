
#ifndef __DistanceEncoder
#define __DistanceEncoder

#include "../WheelMotor.h"

typedef struct {

}DistanceEncoder;


void DistanceEncoder_init();
static void DistanceEncoder_calc_distance();
int DistanceEncoder_get_distance();

#endif

