#ifndef STRATEGYPART_RUNNINGMETHODSWITCHJUDGE_SWITCH_JUDGE_H
#define STRATEGYPART_RUNNINGMETHODSWITCHJUDGE_SWITCH_JUDGE_H

#include "../../StrategyPart/SwitchTerm.h"

/**
 * �؂�ւ�����
 */
typedef struct {
	
}SwitchJudge;

	/**
	 * �؂�ւ����肷��
	 */
	int SwitchJudge_judge_switch_method(int (*switch_judge_fp)(SwitchTerm),SwitchTerm switch_term);

#endif

