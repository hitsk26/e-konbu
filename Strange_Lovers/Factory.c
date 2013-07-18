#include "Factory.h"

void initialization(){
	Balancer_init(&balancer);
	Calibration_init(&calibration);
	TargetValue_init(&targetValue);

	//UI
	PushButton_init(&pushButton,NXT_PORT_S4);

}
