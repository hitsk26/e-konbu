#include "BrightnessEncoder.h"
#include "../Factory.h"

void BrightnessEncoder_init(BrightnessEncoder *this_BrightnessEncoder,U8 port_id)
{
	this_BrightnessEncoder->port_id = port_id;
	this_BrightnessEncoder->black_value = 0;
	this_BrightnessEncoder->white_value = 0;
}

int BrightnessEncoder_get_brightness(BrightnessEncoder *this_BrightnessEncoder)
{
	return LightSensor_get_light_sensor(this_BrightnessEncoder->port_id);
}

float BrightnessEncoder_get_brightness_normalize(BrightnessEncoder *this_BrightnessEncoder){
	float normalize;

	normalize = (float)((int)LightSensor_get_light_sensor(this_BrightnessEncoder->port_id) - this_BrightnessEncoder->white_value)
		/(float)(this_BrightnessEncoder->black_value - this_BrightnessEncoder->white_value);

	return normalize;
}

void BrightnessEncoder_set_black(BrightnessEncoder *this_BrightnessEncoder,int black){
	this_BrightnessEncoder->black_value = black;
}
void BrightnessEncoder_set_white(BrightnessEncoder *this_BrightnessEncoder,int white){
	this_BrightnessEncoder->white_value = white;
}