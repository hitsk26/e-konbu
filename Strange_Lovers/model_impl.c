#include "./StrategyPart/Runner.h"
#include "Factory.h"


int count_start=0;
int flg_tail=0;
int Start_flg =0;


//走行状態初期化
//RN_STATE rn_state = RN_CALIBRATION;

void Runner_init(Runner *this_Runner){
	
}

//カウンタの宣言
DeclareCounter(SysTimerCnt);

//タスクの宣言
DeclareTask(ActionTask);
DeclareTask(INITIALIZE);


//イベントの宣言
DeclareEvent(RUNEVENT);

//初期処理
void ecrobot_device_initialize(void){

	ecrobot_set_light_sensor_active(NXT_PORT_S3);
	ecrobot_set_motor_rev(NXT_PORT_A,0);
	ecrobot_set_motor_rev(NXT_PORT_B,0);
	ecrobot_set_motor_rev(NXT_PORT_C,0);
	ecrobot_init_bt_slave("LEJOS-OSEK");

	initialization();

}

//後始末処理
void ecrobot_device_terminate(void){

	ecrobot_set_light_sensor_inactive(NXT_PORT_S3);
	ecrobot_set_motor_speed(NXT_PORT_B, 0);
	ecrobot_set_motor_speed(NXT_PORT_C, 0);
	ecrobot_term_bt_connection();

}


/*--------------------------------------------------------------------------*/
/* OSEK hooks                                                               */
/*--------------------------------------------------------------------------*/
void StartupHook(void){}
void ShutdownHook(StatusType ercd){}
void PreTaskHook(void){}
void PostTaskHook(void){}
void ErrorHook(StatusType ercd){}


/*--------------------------------------------------------------------------*/
/* Function to be invoked from a category 2 interrupt                       */
/*--------------------------------------------------------------------------*/
void user_1ms_isr_type2(void){
	StatusType ercd;
	/*
	 *  Increment OSEK Alarm System Timer Count
     */
	ercd = SignalCounter( SysTimerCnt );
	if( ercd != E_OK ){
		ShutdownOS( ercd );
	}
}


TASK(INITIALIZE){

	if(end_calibration_flg == 0){
		Calibration_calibration(&calibration);
		TargetValue_set_anglr_of_aim(&targetValue,100);
		end_calibration_flg =1;
	}
	
	if(PushButton_detect_push_button(&pushButton) == TRUE)
	Start_flg =1;
	
	if(Start_flg==1){

		if(count_start < 50){
			TargetValue_set_anglr_of_aim(&targetValue,126);
			count_start++;
		}else{
			TargetValue_set_anglr_of_aim(&targetValue,0);
			flg_tail=1;
		}

	}

	if(flg_tail==1){

		SetEvent(ActionTask,RUNEVENT);
	}

	PID_tail(targetValue.target_tail_angle);


	TerminateTask();
}

TASK(ActionTask){

	WaitEvent(RUNEVENT);
	ClearEvent(RUNEVENT);

	Runner_run(&runner);

	TerminateTask();
}

