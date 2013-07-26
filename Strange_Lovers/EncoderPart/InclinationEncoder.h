#ifndef DETECTORPART_INCLINATION_ENCODER_H
#define DETECTORPART_INCLINATION_ENCODER_H

#include "../HardwareWrapper/GyroSensor.h"

typedef struct {
	U8 port_id;
	
}InclinationEncoder;


void InclinationEncoder_init(InclinationEncoder *this_InclinationEncoder,U8 port_id);
int InclinationEncoder_get_inclination(InclinationEncoder *this_InclinationEncoder);


#endif
