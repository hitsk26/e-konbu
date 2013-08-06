#include "Calibration.h"
#include "Factory.h"

void Calibration_init(Calibration *this_Calibration){
	this_Calibration->gyro = 0;
}


void Calibration_calibration(Calibration *this_Calibration){

	static U32	avg_cnt = 0;
	static U32	cal_start_time;	

	//gyro_offset
	while (1){
		if(PushButton_detect_push_button(&pushButton) == TRUE)break;
	}
	
		ecrobot_sound_tone(880, 512, 30);
		/* ジャイロセンサの値を計算するための開始時間をセットする */
		cal_start_time = ecrobot_get_systick_ms();

	while((ecrobot_get_systick_ms() - cal_start_time) < 1000U){
		/* ジャイロセンサの設定をする */
		this_Calibration->gyro += InclinationEncoder_get_inclination(&inclinationEncoder);
		avg_cnt++;
	}

		this_Calibration->gyro /= avg_cnt;
		ecrobot_sound_tone(440U, 500U, 30U);

	systick_wait_ms(500);
	
	//black
	while(1){
		if(PushButton_detect_push_button(&pushButton) == TRUE){
			ecrobot_sound_tone(906, 512, 30);
			//this_Calibration->black_value = BrightnessEncoder_get_brightness(&brightnessEncoder);
			BrightnessEncoder_set_black(&brightnessEncoder,BrightnessEncoder_get_brightness(&brightnessEncoder));
			systick_wait_ms(500);
			break;
		}
	}

	//white
	while(1){
		if(PushButton_detect_push_button(&pushButton) == TRUE){
			ecrobot_sound_tone(906, 512, 30);
			//this_Calibration->white_value = BrightnessEncoder_get_brightness(&brightnessEncoder);
			BrightnessEncoder_set_white(&brightnessEncoder,BrightnessEncoder_get_brightness(&brightnessEncoder));
			systick_wait_ms(500);
			break;
		}
	}

	InclinationEncoder_set_gyro_offset(&inclinationEncoder ,this_Calibration->gyro);

	end_calibration_flg = 1;
}

