#include "DrivenDirector.h"
#include "../logSend.h"
#include "../Factory.h"
#include "../EncoderPart/DistanceEncoder.h"

void DrivenDirector_check_halt_request_target_control_(DrivenDirector *self,ControllerWeight use_controller);


void DrivenDirector_init(DrivenDirector *self){
}

float DrivenDirector_calc_turn_value(DrivenDirector *self,float target_brightness, float target_curvature,ControllerWeight use_controller,MovementDirection movementDirection)
{
	CC_setTargCurvature(&mCurvatureCtrl,target_curvature);
	LV_setTargLightVal(&mLightVal,target_brightness);
	PLVC_setMovementDirection(mLightValCtrl.mPIDLightValCtrl,movementDirection);
	PCC_setMovementDirection(mCurvatureCtrl.mPIDCurvatureCtrl,movementDirection);
	float brightness_turn = LVC_run(&mLightValCtrl);
	float curvature_turn = CC_run(&mCurvatureCtrl);

	logSend(0,0,DistanceEncoder_get_distance(&distanceEncoder),CurvatureEncoder_get_curvature(&curvatureEncoder)*1000,curvature_turn,brightness_turn,0,0);
	return use_controller.target_light_controller_weight*brightness_turn  
		+  use_controller.target_curvature_controller_weight*curvature_turn;
}

void DrivenDirector_request_drive(DrivenDirector *self ,float target_brightness, float target_curvature,int target_speed,int target_tail_angle,int self_balancing_requirement,ControllerWeight use_controller,int gyro_offset_revise,MovementDirection movementDirection)
{
	DrivenDirector_check_halt_request_target_control_(self,use_controller);
	float turn = DrivenDirector_calc_turn_value(self,target_brightness,target_curvature,use_controller,movementDirection);
	PID_tail(target_tail_angle);
	SC_setTargSpeed(&mSpeedCtrl, target_speed);
	SC_run(&mSpeedCtrl);

	WheelActuator_set_turn(&wheelActuator , turn);
	WheelActuator_set_self_balancing_requirement(&wheelActuator,self_balancing_requirement);
	WheelActuator_revise_gyro_offset(&wheelActuator,gyro_offset_revise);
	WheelActuator_dirve_motors(&wheelActuator);
}
void DrivenDirector_request_stop(DrivenDirector *self,int target_tail_angle)
{
	PID_tail(target_tail_angle);
	WheelActuator_stop_wheel_motors(&wheelActuator);
}

void DrivenDirector_check_halt_request_target_control_(DrivenDirector *self,ControllerWeight use_controller){
	if(use_controller.target_curvature_controller_weight == 0){
		CC_stopCtrl(&mCurvatureCtrl);
	}
	else {
		CC_startCtrl(&mCurvatureCtrl);
	}
	
	if(use_controller.target_light_controller_weight==0){
		LVC_stopCtrl(&mLightValCtrl);
	}
	else {
		LVC_startCtrl(&mLightValCtrl);
	}
}

