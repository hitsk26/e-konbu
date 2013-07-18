#include "Display.h"

void print_calibrate_value(int black_value,int white_value,int gyro_offset){
	display_update();
	ecrobot_debug1(black_value,white_value,(int)gyro_offset);
}

