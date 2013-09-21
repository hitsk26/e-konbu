#include "MarkerSwitch.h"
#include "../../Factory.h"

int MarkerSwitch_judge_switch_method(SwitchTerm switch_term)
{	
	int judge_flag=0;

	DirectionEncoder_get_direction(&directionEncoder); //Œü‚«‚ÌŒv‘ª
	BrightnessEncoder_get_brightness(&brightnessEncoder);//‹P“x‚ÌŒv‘ª



	return judge_flag;
}