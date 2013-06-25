#include "Display.h"

void print_calibrate_value(){
	display_update();
	ecrobot_debug1(black_value,white_value,gyro);
}