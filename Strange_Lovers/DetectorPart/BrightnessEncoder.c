#include "BrightnessEncoder.h"
#include "../Factory.h"

void BrightnessEncoder_init(BrightnessEncoder *this_BrightnessEncoder,U8 port_id)
{
	this_BrightnessEncoder->port_id = port_id;
}

int BrightnessEncoder_get_inclination(BrightnessEncoder *this_BrightnessEncoder)
{
	return LightSensor_get_light_sensor(this_BrightnessEncoder->port_id);
}

