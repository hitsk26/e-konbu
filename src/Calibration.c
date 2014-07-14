#include "Calibration.h"
#include "Factory.h"

void Calibration_init(Calibration *this_Calibration){
	this_Calibration->gyro = 0;
}


int Calibration_calibration(Calibration *this_Calibration){

	static U32	avg_cnt = 0;
	static U32	cal_start_time;	

	//gyro_offset
	while (1){
		if(PushButton_detect_push_button(&pushButton) == TRUE)break;
	}
	
		ecrobot_sound_tone(880, 512, 10);
		/* �W���C���Z���T�̒l���v�Z���邽�߂̊J�n���Ԃ��Z�b�g���� */
		cal_start_time = ecrobot_get_systick_ms();

	while((ecrobot_get_systick_ms() - cal_start_time) < 1000U){
		/* �W���C���Z���T�̐ݒ������ */
		this_Calibration->gyro += InclinationEncoder_get_inclination(&inclinationEncoder);
		avg_cnt++;
	}

		this_Calibration->gyro /= avg_cnt;
		ecrobot_sound_tone(440U, 500U, 10);

	systick_wait_ms(500);
	
	//black
	while(1){
		if(PushButton_detect_push_button(&pushButton) == TRUE){
			ecrobot_sound_tone(906, 512, 10);
			BrightnessEncoder_set_black(&brightnessEncoder,BrightnessEncoder_get_brightness(&brightnessEncoder));
			systick_wait_ms(500);
			break;
		}
	}

	//white
	while(1){
		if(PushButton_detect_push_button(&pushButton) == TRUE){
			ecrobot_sound_tone(906, 512, 10);
			BrightnessEncoder_set_white(&brightnessEncoder,BrightnessEncoder_get_brightness(&brightnessEncoder));
			systick_wait_ms(500);
			break;
		}
	}

	InclinationEncoder_set_gyro_offset(&inclinationEncoder ,this_Calibration->gyro);
	InclinationEncoder_set_initial_gyro_offset(&inclinationEncoder ,this_Calibration->gyro);

	while(1){
		if(PushButton_detect_push_button(&pushButton) == TRUE){
			systick_wait_ms(500);
			break;
		}
	}
	//�L�����u���[�V�������I��������1��Ԃ�
	return 1;
}

