#ifndef STRATEGYPART_RUNNING_METHOD_H
#define STRATEGYPART_RUNNING_METHOD_H


#include "../DrivenPart/DrivenDirector.h"
#include "SwitchTerm.h"
#include "TargetValues.h"
#include "../DrivenPart/ControllerWeight.h"

#include "../StrategyPart/RunningMethodSwitchJudge/SwitchJudge.h"
#include "../NXTSettings.h"

typedef struct {
	
	/**
	 * �|������̗L��
	 */
	int balancing_requrement;

	/**
	 * �g�p�����
	 */
	ControllerWeight use_controller;

	/**
	 * �K���p�x
	 */
	int target_tail_angle;

	/**
	 * �W���C���I�t�Z�b�g�␳�l
	 */
	int gyroOffsetRevise;

	/**
	 * ���@�؂�ւ�����l
	 */
	SwitchTerm switch_term;
	
	//���@�؂�ւ��̊֐��ւ̃|�C���^
	 int (*fp_SwitchJudge)(SwitchTerm);

	 int request_forced_stop;

	 MovementDirection movementDirection;

}RunningMethod;

void RunningMethod_init(RunningMethod *self,int balancing_requrement,ControllerWeight use_controller,int target_tail_angle,
					int gyroOffsetRevise,SwitchTerm switch_term,int (*fp_SwitchJudge)(SwitchTerm),int request_forced_stop,MovementDirection movementDirection);


	/**
	 * ���@�؂�ւ����f
	 */
	int  RunningMethod_check_executed(RunningMethod *self);

	/**
	 * ���@�����s����
	 */
	void RunningMethod_execute_method(RunningMethod *self,TargetValues target_value);


#endif
