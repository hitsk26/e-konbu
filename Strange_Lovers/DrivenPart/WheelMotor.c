#include "WheelMotor.h"

static float count_LPF(int current_count,float current_count_weight);

void WheelMotor_init(WheelMotor *this_WheelMotor,U32 port_id){
	this_WheelMotor->port_id = port_id;
}

int WheelMotor_get_count(WheelMotor *this_WheelMotor)
{
	return Motor_get_count(this_WheelMotor->port_id);

	//return count_LPF(Motor_get_count(this_WheelMotor->port_id),0.1);
}

void WheelMotor_drive_motor(WheelMotor *this_WheelMotor, int pwm)
{
Motor_set_speed(this_WheelMotor->port_id,pwm,1); //3rd paramter means barake mode

}
float count_LPF(int current_count,float current_count_weight){
	static int buf_filtered_count=0;
	float filltered_count=0;
	
	filltered_count = current_count_weight*current_count + (1-current_count_weight)*buf_filtered_count;
	buf_filtered_count = filltered_count;
	
	return filltered_count;
}