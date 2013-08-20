#ifndef DRIVENPART_DRIVEN_DIRECTOR_H
#define DRIVENPART_DRIVEN_DIRECTOR_H

#include "../DrivenPart/ControllerWeight.h"
#include "../DrivenPart/WheelActuator.h"
#include "../DrivenPart/TargetCurvatureControl/CurvatureCtrl.h"
#include "../DrivenPart/PID_Tail.h"
#include "../DrivenPart/TargetSpeedControl/SpeedCtrl.h"
#include "../DrivenPart/TargetLightValueControl/LightValCtrl.h"


/**
 * ‹ì“®w¦Ší
 */
typedef struct{

}DrivenDirector;
	
	

void DrivenDirector_init(DrivenDirector *this_DrivenDirector);

/**
 * ù‰ñ—Ê‚ğŒvZ‚·‚é
 */
float DrivenDirector_calc_turn_value(DrivenDirector *this_DrivenDirector,float target_brightness, float target_curvature,ControllerWeight use_controller);

/**
 * ‹ì“®—v‹‚ğ‚·‚é
 */
void DrivenDirector_request_drive(DrivenDirector *this_DrivenDirector,float target_brightness, float target_curvature,int target_speed,int target_tail_angle,int self_balancing_requirement,ControllerWeight use_controller,int gyro_offset_revise);

void DrivenDirector_request_stop(DrivenDirector *self,int target_tail_angle);
#endif
