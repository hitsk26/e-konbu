#include "BrightnessEncoder.h"
#include "../Factory.h"
#include "../logSend.h"

void BrightnessEncoder_init(BrightnessEncoder *this_BrightnessEncoder,U8 port_id,LowPassFillter *lowPassFillter)
{
	this_BrightnessEncoder->port_id = port_id;
	this_BrightnessEncoder->black_value = 0;
	this_BrightnessEncoder->white_value = 0;
	this_BrightnessEncoder->lowPassfFillter = lowPassFillter;

	LowPassFillter_init(this_BrightnessEncoder->lowPassfFillter,0.1);

}

int BrightnessEncoder_get_brightness(BrightnessEncoder *this_BrightnessEncoder)
{
	return LightSensor_get_light_sensor(this_BrightnessEncoder->port_id);
}

float BrightnessEncoder_get_brightness_normalize(BrightnessEncoder *this_BrightnessEncoder){
	float normalize;
	float filltered_brightness = LowPassFilter_get_filltered_value(this_BrightnessEncoder->lowPassfFillter,(int)LightSensor_get_light_sensor(this_BrightnessEncoder->port_id));

	normalize = (float)(filltered_brightness - this_BrightnessEncoder->white_value)
		/(float)(this_BrightnessEncoder->black_value - this_BrightnessEncoder->white_value);


	ecrobot_debug1(this_BrightnessEncoder->black_value,this_BrightnessEncoder->white_value,LightSensor_get_light_sensor(this_BrightnessEncoder->port_id));

	return normalize;
}

void BrightnessEncoder_set_black(BrightnessEncoder *this_BrightnessEncoder,int black){
	this_BrightnessEncoder->black_value = black;
}
void BrightnessEncoder_set_white(BrightnessEncoder *this_BrightnessEncoder,int white){
	this_BrightnessEncoder->white_value = white;
}