#include "InclinationEncoder.h"
#include "../Factory.h"

void InclinationEncoder_init(InclinationEncoder *this_InclinationEncoder,U8 port_id)
{
	this_InclinationEncoder->port_id = port_id;
}

int InclinationEncoder_get_inclination(InclinationEncoder *this_InclinationEncoder)
{
	return GyroSensor_get_gyro_sensor(this_InclinationEncoder->port_id);
}


void InclinationEncoder_set_gyro_offset(InclinationEncoder *this_InclinationEncoder,int gyro_offset){

	this_InclinationEncoder->gyro_offset = gyro_offset;
}