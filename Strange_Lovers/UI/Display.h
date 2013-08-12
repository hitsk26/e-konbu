#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "Calibration.h"
#include "ecrobot_interface.h"

typedef struct{
}Display;

extern void Display_init(Display *this_Display);
extern void Display_print_calibrate_value(int black_value,int white_value,int gyro_offset);
extern void Display_print_PID_paramteres(float Kp,float Ki,float Kd);

#endif

