#ifndef STRATEGYPART_SWITCH_TERM_H
#define STRATEGYPART_SWITCH_TERM_H

/**
 * 切り替え判定値
 */
typedef struct {
	/**
	 * 移動距離
	 */
	float distance;

	/**
	 * 傾き
	 */
	int inclination;

	/**
	 * 時間
	 */
	int time;

	/**
	 * タッチセンサ押下時
	 */
	bool inPushed;
	
}SwitchTerm;
#endif
