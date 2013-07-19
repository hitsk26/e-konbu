#include "Factory.h"

void initialization(){
	Balancer_init(&balancer);
	Calibration_init(&calibration);
	TargetValue_init(&targetValue);
	PID_TAIL_init(&pid_tail);
	PID_BRIGHTNESS_init(&pid_brightness);
	Display_init(&display);
	Runner_init(&runner);

	//UI
	PushButton_init(&pushButton,NXT_PORT_S4);
	WheelMotor_init(&rightWheelMotor,NXT_PORT_B);
	WheelMotor_init(&leftWheelMotor,NXT_PORT_C);


	//DetectorPart
	Timer_init(&timer);
	DistanceEncoder_init(&distanceEncoder);
	InclinationEncoder_init(&inclinationEncoder,NXT_PORT_S1);
}
