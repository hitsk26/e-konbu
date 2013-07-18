#include "Factory.h"

void initialization(){
	Balancer_init(&balancer);
	Calibration_init(&calibration);
	TargetValue_init(&targetValue);

	//UI
	PushButton_init(&pushButton,NXT_PORT_S4);
	WheelMotor_init(&rightWheelMotor,NXT_PORT_B);
	WheelMotor_init(&leftWheelMotor,NXT_PORT_C);

}
