#ifndef DRIVENPART_DRIVEN_DIRECTOR_H
#define DRIVENPART_DRIVEN_DIRECTOR_H

#include "../DrivenPart/ControllerWegiht.h"
#include "../DrivenPart/PID_Brightness.h"
#include "../DrivenPart/Balancer.h"
#include "../DrivenPart/TargetCurvatureControl/CurvatureCtrl.h"


/**
 * 駆動指示器
 */
typedef struct{
	/**
	 * 使用制御器
	 */
ControllerWegiht use_controller;

}DrivenDirector;
	
	
/**
 * 旋回量を計算する
 */
void DrivenDirector_calc_turn_val(int target_brightness, float target_curvature);

/**
 * 駆動要求をする
 */
void DrivenDirector_request_drive(int target_brightness, float target_curvature);


#endif
