#include "Calibration.h"
#include "Factory.h"

void Calibration_init(Calibration *this_Calibration){
	this_Calibration->black_value = 0;
	this_Calibration->white_value = 0;
	this_Calibration->gyro = 0;
}


void Calibration_calibration(Calibration *this_Calibration){

	static int flg = 0;

	static U32	avg_cnt = 0;
	static U32	cal_start_time;	

	//gyro_offset
	while (1){
		if(ecrobot_get_touch_sensor(NXT_PORT_S4) == TRUE)break;
	}
	
		ecrobot_sound_tone(880, 512, 30);
		/* ジャイロセンサの値を計算するための開始時間をセットする */
		cal_start_time = ecrobot_get_systick_ms();

	while((ecrobot_get_systick_ms() - cal_start_time) < 1000U){
		/* ジャイロセンサの設定をする */
		Calibration.gyro += (U32)ecrobot_get_gyro_sensor(NXT_PORT_S1);
		avg_cnt++;
	}

		Calibration.gyro /= avg_cnt;
		ecrobot_sound_tone(440U, 500U, 30U);

	systick_wait_ms(500);
	
	//black
	while(1){
		if(ecrobot_get_touch_sensor(NXT_PORT_S4) == TRUE){
			ecrobot_sound_tone(906, 512, 30);
			Calibration.black_value = ecrobot_get_light_sensor(NXT_PORT_S3);
			systick_wait_ms(500);
			break;
		}
	}

	//white
	while(1){
		if(ecrobot_get_touch_sensor(NXT_PORT_S4) == TRUE){
			ecrobot_sound_tone(906, 512, 30);
			Calibration.white_value = ecrobot_get_light_sensor(NXT_PORT_S3);
			systick_wait_ms(500);
			break;
		}
	}

	Balancer_set_gyro(&balancer , Calibration.gyro);

	Target_value_set_target_value_brightness(&target_value,(Calibration.black_value+Calibration.white_value)/2);


	print_calibrate_value();

	end_calibration_flg = 1;
}

