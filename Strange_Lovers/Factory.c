#include "Factory.h"

void initialization(){
	Balancer_init(&balancer);
	Calibration_init(&calibration);
	Target_value_init(&target_value);
}