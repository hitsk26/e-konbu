#include "DrivenDirector.h"
#include "../Factory.h"



void DrivenDirector_init(DrivenDirector *this_DrivenDirector){
}

int DrivenDirector_calc_turn_value(DrivenDirector *this_DrivenDirector,int target_brightness, float target_curvature,ControllerWeight use_controller)
{
	CC_setTargCurvature(&mCurvatureCtrl,target_curvature);
	int brightness_turn = PID_Brightness_target_control(&pid_Brightness,target_brightness);
	int curvature_turn = CC_run(&mCurvatureCtrl);
	return /*use_controller.target_light_controller_weight*brightness_turn  
		+*/  use_controller.target_curvature_controller_weight*curvature_turn;
}

void DrivenDirector_request_drive(DrivenDirector *this_DrivenDirector ,int target_brightness, float target_curvature,int target_speed,int target_tail_angle,int self_balancing_requirement,ControllerWeight use_controller,int gyro_offset_revise)
{
	int turn = DrivenDirector_calc_turn_value(this_DrivenDirector,target_brightness,target_curvature,use_controller)
		+ LVC_run(&mLightValCtrl,&mPIDLightValCtrlParm);
	PID_tail(target_tail_angle);
	SC_setTargSpeed(&mSpeedCtrl,target_speed);
	SC_run(&mSpeedCtrl);
	LV_setTargLightVal(&mLightVal,target_brightness);
	Balancer_set_turn(&balancer , turn);
	Balancer_balance_running(&balancer);

	//ecrobot_debug1(LVC_run(&mLightValCtrl,&mPIDLightValCtrlParm),turn,0);
}
