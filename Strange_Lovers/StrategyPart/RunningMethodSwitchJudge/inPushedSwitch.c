#include "inPushedSwitch.h"
#include "../../Factory.h"


int inPushedSwitch_judge_switch_method(SwitchTerm switch_term)
{
	int start_flag = 0;

	if(PushButton_detect_push_button(&pushButton) == TRUE){
		start_flag = 1;
	}
	
		return start_flag;

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

