#ifndef STRATEGYPART_SECTION_H
#define STRATEGYPART_SECTION_H

#include "../StrategyPart/RunningStrategy.h"
#include "../StrategyPart/changeTerm.h"


/**
 * 区間
 */

typedef struct {
	/**
	 * 目標前進速度
	 */
	
	struct Section *nextSection;
	RunningStrategy current_strategy;
	
}Section;

	/**
	 * 次区間切替条件取得
	 */
	changeTerm Section_getChangeTermOfNextSection(Section *this_Section);

	/**
	 * 次区間を取得する
	 */
	Section Section_getNextSection(Section *this_Section);

	/**
	 * 走破する
	 */
	int Section_clearSection(Section *this_Section);

	void Section_run(Section *this_Section);

#endif
