#ifndef DRIVENPART_DRIVEN_DIRECTOR_H
#define DRIVENPART_DRIVEN_DIRECTOR_H

#include "../DrivenPart/ControllerWeight.h"
#include "../DrivenPart/WheelActuator.h"
#include "../DrivenPart/TargetCurvatureControl/CurvatureCtrl.h"
#include "../DrivenPart/PID_Tail.h"
#include "../DrivenPart/TargetSpeedControl/SpeedCtrl.h"
#include "../DrivenPart/TargetLightValueControl/LightValCtrl.h"


/**
 * �쓮�w����
 */
typedef struct{

}DrivenDirector;
	
	

void DrivenDirector_init(DrivenDirector *this_DrivenDirector);

/**
 * ����ʂ��v�Z����
 */
float DrivenDirector_calc_turn_value(DrivenDirector *self,float target_brightness, float target_curvature,float target_runner_angle,ControllerWeight use_controller,MovementDirection movementDirection);
/**
 * �쓮�v��������
 */
void DrivenDirector_request_drive(DrivenDirector *self ,float target_brightness, float target_curvature,float target_runner_angle,int target_speed,int target_tail_angle,int self_balancing_requirement,ControllerWeight use_controller,int gyro_offset_revise,MovementDirection movementDirection);

void DrivenDirector_request_stop(DrivenDirector *self,int target_tail_angle);
#endif
