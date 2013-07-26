#ifndef Brightness_Encoder
#define Brightness_Encoder

#include "../HardwareWrapper/LightSensor.h"

typedef struct {
	U8 port_id;
}BrightnessEncoder;


void BrightnessEncoder_init(BrightnessEncoder *this_BrightnessEncoder,U8 port_id);
int BrightnessEncoder_get_brightness(BrightnessEncoder *this_BrightnessEncoder);


#endif
