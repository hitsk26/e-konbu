#ifndef DRIVENPART_DRIVEN_DIRECTOR_H
#define DRIVENPART_DRIVEN_DIRECTOR_H

#include "../DrivenPart/ControllerWegiht.h"
#include "../DrivenPart/PID_Brightness.h"
#include "../DrivenPart/Balancer.h"
#include "../DrivenPart/TargetCurvatureControl/CurvatureCtrl.h"
#include "../DrivenPart/PID_Tail.h"
#include "../DrivenPart/TargetSpeedControl/SpeedCtrl.h"

/**
 * 駆動指示器
 */
typedef struct{
	/**
	 * 使用制御器
	 */
ControllerWegiht use_controller;

}DrivenDirector;
	
	

void DrivenDirector_init(DrivenDirector *this_DrivenDirector);

/**
 * 旋回量を計算する
 */
int DrivenDirector_calc_turn_value(DrivenDirector *this_DrivenDirector,int target_brightness, float target_curvature);

/**
 * 駆動要求をする
 */
void DrivenDirector_request_drive(DrivenDirector *this_DrivenDirector,int target_brightness, float target_curvature,int target_speed,int target_tail_angle,int self_balancing_requirement,ControllerWegiht used_controller,int gyro_offset_revise);


#endif
