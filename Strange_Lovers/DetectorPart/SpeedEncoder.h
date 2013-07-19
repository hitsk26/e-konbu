
#include "./DistanceEncoder.h"
#include "./Timer.h"

typedef struct{
	int speed;
	
}SpeedEncoder;


void SpeedEncoder_get_speed(SpeedEncoder *this_SpeedEncoder);
void SpeedEncoder_calc_speed(SpeedEncoder *this_SpeedEncoder);
void SpeedEncoder_init(SpeedEncoder *this_SpeedEncoder);

