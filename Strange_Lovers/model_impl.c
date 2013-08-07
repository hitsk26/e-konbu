#include "./StrategyPart/Runner.h"
#include "./StrategyPart/RunnerState.h"

#include "Factory.h"

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

int count_start=0;
int flg_tail=0;
int Start_flg =0;


//カウンタの宣言
DeclareCounter(SysTimerCnt);

//タスクの宣言
DeclareTask(ActionTask);
DeclareTask(INITIALIZE);
DeclareTask(UI);


//イベントの宣言
DeclareEvent(RUNEVENT);

//アラームの宣言
DeclareAlarm(cyclic_alarm1);

//初期処理
void ecrobot_device_initialize(void){
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
		TargetValue_set_anglr_of_aim(&targetValue,0);		//100
		end_calibration_flg =1;
		Runner_start_run(&runner);
	}
	
	if(PushButton_detect_push_button(&pushButton) == TRUE)
	{
		Start_flg =1;
		flg_tail = 1;
	}
	/*
	if(Start_flg==1){

		if(count_start < 50){
			TargetValue_set_anglr_of_aim(&targetValue,0);	//126
			count_start++;
		}else{
			TargetValue_set_anglr_of_aim(&targetValue,0);
			flg_tail=1;
		}

	}
	*/

	if(flg_tail==1){
		//SetEvent(ActionTask,RUNEVENT);
	}

	//PID_tail(/*targetValue.target_tail_angle*/90);
	

	TerminateTask();
}

TASK(ActionTask){

	// 4msec 毎にイベント通知する設定
    //SetRelAlarm(cyclic_alarm1, 1, 4); 

	//WaitEvent(RUNEVENT);
	//ClearEvent(RUNEVENT);
	
	Runner_execute(&runner);

	TerminateTask();
}

TASK(UI){

	if(PushButton_detect_push_button(&pushButton) == TRUE && (Runner_get_runner_state(&runner)==RUN)){
		ecrobot_sound_tone(880, 512, 30);
		systick_wait_ms(500);
		Runner_stop_run(&runner);
	}
	else if(PushButton_detect_push_button(&pushButton) == TRUE && (Runner_get_runner_state(&runner)==STOP)){
		ecrobot_sound_tone(880, 512, 30);
		systick_wait_ms(500);
		initialization();
		Runner_start_run(&runner);
	
	}
	TerminateTask();
}
