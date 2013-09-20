#include "SonorSensor.h"

int SonorSensor_get_sonor_sensor(U8 port_id)
{
	return (S32)ecrobot_get_sonar_sensor(port_id);
}

