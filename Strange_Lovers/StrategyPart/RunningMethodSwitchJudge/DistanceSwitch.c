#include "DistanceSwitch.h"
#include "../../Factory.h"

int DistanceSwitch_judge_switch_method(SwitchTerm switch_term)
{
	int judge_flag=0;

	if(switch_term.distance >= 0)
	{
		if(DistanceEncoder_get_distance(&distanceEncoder) > switch_term.distance){
				judge_flag=1;
		}
		else {
			judge_flag=0;
		}
	}else{
		if(DistanceEncoder_get_distance(&distanceEncoder) < switch_term.distance){
				judge_flag=1;
		}
		else {
			judge_flag=0;
		}
	}
	return judge_flag;
}