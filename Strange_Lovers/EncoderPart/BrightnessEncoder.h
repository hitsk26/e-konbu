#ifndef Brightness_Encoder
#define Brightness_Encoder

#include "../HardwareWrapper/LightSensor.h"
#include "../lib/LowPassFillter.h"


typedef struct {
	U8 port_id;
	int black_value;
	int white_value;
	LowPassFillter *lowPassfFillter;
}BrightnessEncoder;


void BrightnessEncoder_init(BrightnessEncoder *this_BrightnessEncoder,U8 port_id,LowPassFillter *lowPassfFillter);
int BrightnessEncoder_get_brightness(BrightnessEncoder *this_BrightnessEncoder);
float BrightnessEncoder_get_brightness_normalize(BrightnessEncoder *this_BrightnessEncoder);
void BrightnessEncoder_set_black(BrightnessEncoder *this_BrightnessEncoder,int black);
void BrightnessEncoder_set_white(BrightnessEncoder *this_BrightnessEncoder,int white);

#endif
