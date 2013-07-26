#ifndef STRATEGYPART_RUNNING_STRATEGY_H
#define STRATEGYPART_RUNNING_STRATEGY_H

#include "../DrivenPart/DrivenDirector.h"
//#include "../StrategyPart/StrategySwitchJudge/SwitchJudge.h"

typedef struct {
	int targetSpeed;

	/**
	 * 曲率半径
	 */
	float target_curvature;
	int target_brightness;

	
	/**
	 * 倒立制御の有無
	 */
	int selfBalancingRequrement;

	/**
	 * 使用制御器
	 */
	int usedController;

	/**
	 * 尻尾角度
	 */
	int target_tail_angle;

	/**
	 * ジャイロオフセット補正値
	 */
	int gyroOffsetRevise;

	/**
	 * 戦略切り替え判定値
	 */
	int strategyChangeDecideValue;

}RunningStrategy;

/**
 * 走行戦略
 */

	/**
	 * 戦略切り替え
	 */
	void RunningStrategy_change_strategy(RunningStrategy *this_RunningStrategy);

	/**
	 * 戦略を実行する
	 */
	void RunningStrategy_execute_strategy(RunningStrategy *this_RunningStrategy);

#endif
