#include "Runner.h"
#include "Factory.h"

void RN_mode_change();
void RN_run();

int count_start=0;
int flg_tail=0;
int Start_flg =0;


//走行状態初期化
//RN_STATE rn_state = RN_CALIBRATION;

void Runner_init(Runner *this_Runner){
	this_Runner->rn_state = RN_CALIBRATION;
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

	PID_tail(targetValue.angle_of_aim);


	TerminateTask();
}

TASK(ActionTask){

	WaitEvent(RUNEVENT);
	ClearEvent(RUNEVENT);


	//RN_mode_change();
	//RN_run();

	PID_Brightness(targetValue.target_brightness);
	PID_tail(targetValue.angle_of_aim);


	TerminateTask();
}

void RN_mode_change(){

	switch (runner.rn_state){
		case (RN_CALIBRATION):
			if(end_calibration_flg == 1 && PushButton_detect_push_button(&pushButton) == TRUE){
				runner.rn_state = RN_RUNNING;
				//set_anglr_of_aim(0);
			}
			break;

		case (RN_RUNNING):
			break;

		case (RN_COMPLATION):
			break;
	}

}

void RN_run(){

	switch (runner.rn_state){
		case (RN_CALIBRATION):
			if(end_calibration_flg == 0){
				Calibration_calibration(&calibration);
				TargetValue_set_anglr_of_aim(&targetValue,100);

				end_calibration_flg =1;
			}
			PID_tail(targetValue.angle_of_aim);
			break;

		case (RN_RUNNING):
			//Balance_running();
		/*	if(get_tail_value() < 110){
				set_anglr_of_aim(get_tail_value());
				anglr_of_aim++;
				if(get_tail_value() == 110) set_anglr_of_aim(0);
			}*/

			if(count_start < 50){
				TargetValue_set_anglr_of_aim(&targetValue,126);
				count_start++;
			}else
				{
					TargetValue_set_anglr_of_aim(&targetValue,0);
					flg_tail=1;
			}

			//if(count_start==1)set_anglr_of_aim(0);

			if(flg_tail==1)PID_Brightness(targetValue.target_brightness);
			PID_tail(targetValue.angle_of_aim);

			//logSend(0,0,0,0,0,0,0,0);
			break;

		case (RN_COMPLATION):
			break;
	}

}


