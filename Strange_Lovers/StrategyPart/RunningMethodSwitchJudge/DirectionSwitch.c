#include "DirectionSwitch.h"
#include "../../Factory.h"


#define ACCEPT_RANGE 3



int DirectionSwitch_judge_switch_method(SwitchTerm switch_term)
{	
	int judge_flag=0;
	float direction = DirectionEncoder_get_direction(&directionEncoder);
	
	if(switch_term.direction >= 0)
	{
		if(direction >= switch_term.direction){
				judge_flag=1;
		}
	}else{
		if(direction < switch_term.direction){
				judge_flag=1;
		}
	}
	return judge_flag;
}