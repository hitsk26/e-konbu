#include "./StrategyPart/Runner.h"
#include "./StrategyPart/RunnerState.h"

#include "Factory.h"

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"




//カウンタの宣言
DeclareCounter(SysTimerCnt);

//タスクの宣言
DeclareTask(ActionTask);
DeclareTask(INITIALIZE);
DeclareTask(UI);

//初期処理
void ecrobot_device_initialize(void){
	ecrobot_init_bt_slave("LEJOS-OSEK");
	ecrobot_set_light_sensor_active(NXT_PORT_S3);
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
		end_calibration_flg =1;
		Runner_start_run(&runner);
	}
	TerminateTask();
}

TASK(ActionTask){

	Runner_execute(&runner);

	TerminateTask();
}

TASK(UI){

	if(Runner_get_runner_state(&runner)==RUN){
		 Starter_accept_stop_run(&starter);
	}
	else if(Runner_get_runner_state(&runner)==STOP){
		 Starter_accept_start_run(&starter);
	}

	TerminateTask();
}
