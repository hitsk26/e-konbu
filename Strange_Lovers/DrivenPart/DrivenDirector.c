#include "DrivenDirector.h"
#include "../Factory.h"



void DrivenDirector_init(DrivenDirector *this_DrivenDirector){
	this_DrivenDirector->use_controller.target_curvature_controller_weight = 0.5;
	this_DrivenDirector->use_controller.target_light_controller_weight = 0.5;
}

int DrivenDirector_calc_turn_val(DrivenDirector *this_DrivenDirector,int target_brightness, float target_curvature)
{
	return this_DrivenDirector->use_controller.target_light_controller_weight*PID_Brightness_target_control(&pid_Brightness,target_brightness) 
		+ 	this_DrivenDirector->use_controller.target_curvature_controller_weight*CurvatureCtrl_run(&curvatureCtrl,target_curvature);
}

void DrivenDirector_request_drive(DrivenDirector *this_DrivenDirector,int target_brightness, float target_curvature)
{
	int turn = DrivenDirector_calc_turn_val(this_DrivenDirector,target_brightness,target_curvature);
	
	Balancer_set_turn(&balancer , turn);
	Balancer_balance_running(&balancer);
}
