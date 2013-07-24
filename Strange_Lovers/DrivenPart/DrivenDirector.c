#include "DrivenDirector.h"
#include "../Factory.h"



void DrivenDirector_init(DrivenDirector *this_DrivenDirector){
	this_DrivenDirector->use_controller.target_curvature_controller_weight = 0.5;
	this_DrivenDirector->use_controller.target_light_controller_weight = 0.5;
}

int DrivenDirector_calc_turn_value(DrivenDirector *this_DrivenDirector,int target_brightness, float target_curvature)
{
	CC_setTargCurvature(&mCurvatureCtrl,target_curvature);
	return this_DrivenDirector->use_controller.target_light_controller_weight*PID_Brightness_target_control(&pid_Brightness,target_brightness) 
		+ 	this_DrivenDirector->use_controller.target_curvature_controller_weight* CC_run(&mCurvatureCtrl);;
}

void DrivenDirector_request_drive(DrivenDirector *this_DrivenDirector,int target_brightness, float target_curvature)
{
	int turn = DrivenDirector_calc_turn_value(this_DrivenDirector,target_brightness,target_curvature);
	Balancer_set_turn(&balancer , turn);
	Balancer_balance_running(&balancer);
}
