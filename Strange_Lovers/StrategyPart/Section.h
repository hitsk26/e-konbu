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
	int targetSpeed;

	/**
	 * 曲率半径
	 */
	float target_curvature;
	int target_brightness;
	struct Section *nextSection;
	RunningStrategy runningStrategy[];
	
}Section;

	/**
	 * 次区間切替条件取得
	 */
	changeTerm Section_getChangeTermOfNextSection();

	/**
	 * 次区間を取得する
	 */
	Section Section_getNextSection();

	/**
	 * 走破する
	 */
	int Section_clearSection();

	void Section_run();

#endif
