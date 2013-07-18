#include "Factory.h"

void initialization(){
	Balancer_init(&balancer);
	Calibration_init(&calibration);
	TargetValue_init(&targetValue);
}
