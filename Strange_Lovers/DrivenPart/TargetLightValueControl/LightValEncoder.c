#include "LightValEncoder.h"

void LVE_init(LightValEncoder *this_LightValEncoder){
}

int LVE_getLightVal(LightValEncoder *thisLightValEncoder){
	return ecrobot_get_light_sensor(NXT_PORT_S3);
}
