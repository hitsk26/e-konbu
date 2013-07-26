#ifndef DRIVENPART_DRIVEN_DIRECTOR_H
#define DRIVENPART_DRIVEN_DIRECTOR_H

#include "../DrivenPart/ControllerWeight.h"
#include "../DrivenPart/PID_Brightness.h"
#include "../DrivenPart/Balancer.h"
#include "../DrivenPart/TargetCurvatureControl/CurvatureCtrl.h"
#include "../DrivenPart/PID_Tail.h"
#include "../DrivenPart/TargetSpeedControl/SpeedCtrl.h"

/**
 * ‹ì“®w¦Ší
 */
typedef struct{

}DrivenDirector;
	
	

void DrivenDirector_init(DrivenDirector *this_DrivenDirector);

/**
 * ù‰ñ—Ê‚ğŒvZ‚·‚é
 */
int DrivenDirector_calc_turn_value(DrivenDirector *this_DrivenDirector,int target_brightness, float target_curvature,ControllerWegiht use_controller);

/**
 * ‹ì“®—v‹‚ğ‚·‚é
 */
void DrivenDirector_request_drive(DrivenDirector *this_DrivenDirector,int target_brightness, float target_curvature,int target_speed,int target_tail_angle,int self_balancing_requirement,ControllerWegiht use_controller,int gyro_offset_revise);


#endif
