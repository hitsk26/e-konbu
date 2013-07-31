#include "TimeSwitch.h"
#include "../../Factory.h"


int TimeSwitch_judge_switch_method(SwitchTerm switch_term)
{
	Timer_get_ms(&timer) ;

	//DistanceSwitch_judge_switch_methodをコピッた残骸
	/*
	int judge_flag=0;

	if(DistanceEncoder_get_distance(&distanceEncoder) > switch_term.distance){
			judge_flag=1;
			DistanceEncoder_reset_Encoder(&distanceEncoder);
	}
	else {
		judge_flag=0;
	}
	return judge_flag;
	*/ 
}

