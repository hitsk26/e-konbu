#include "DrivenDirector.h"
#include "../Factory.h"
#include "../logSend.h"



void DrivenDirector_init(DrivenDirector *this_DrivenDirector){
}

int DrivenDirector_calc_turn_value(DrivenDirector *this_DrivenDirector,float target_brightness, float target_curvature,ControllerWeight use_controller)
{
	CC_setTargCurvature(&mCurvatureCtrl,target_curvature);
	LV_setTargLightVal(&mLightVal,target_brightness);

	int brightness_turn = LVC_run(&mLightValCtrl,&mPIDLightValCtrlParm);
	int curvature_turn = CC_run(&mCurvatureCtrl);
	logSend(0,0,brightness_turn,curvature_turn,use_controller.target_light_controller_weight*brightness_turn  
		+  use_controller.target_curvature_controller_weight*curvature_turn,SpeedEncoder_get_speed(&speedEncoder),0,0);

	return use_controller.target_light_controller_weight*brightness_turn  
		+  use_controller.target_curvature_controller_weight*curvature_turn;
}

void DrivenDirector_request_drive(DrivenDirector *this_DrivenDirector ,float target_brightness, float target_curvature,int target_speed,int target_tail_angle,int self_balancing_requirement,ControllerWeight use_controller,int gyro_offset_revise)
{
	int turn = DrivenDirector_calc_turn_value(this_DrivenDirector,target_brightness,target_curvature,use_controller);

	PID_tail(target_tail_angle);
	SC_setTargSpeed(&mSpeedCtrl, target_speed);
	SC_run(&mSpeedCtrl);
	
	WheelActuator_set_turn(&wheelActuator , turn);
	WheelActuator_set_self_balancing_requirement(&wheelActuator,self_balancing_requirement);
	WheelActuator_dirve_motors(&wheelActuator);

	
}
