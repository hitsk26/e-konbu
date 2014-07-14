/*BlueTooth�ł̒ʐM�p�֐�


*/

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
#include "balancer.h" /* �|���U�q����p�w�b�_�t�@�C�� */
#include "logSend.h"

//static void logSend(S8 data1, S8 data2, S16 adc1, S16 adc2, S16 adc3, S16 adc4);

void logSend(S8 data1, S8 data2, S16 adc1, S16 adc2, S16 adc3, S16 adc4, S32 datas32, S32 datas32_2) {
	
	
	static U8 data_log_buffer[32];
 
		//���ӂ͌���data_log_buffer�̒��g��\���Ă���B�v����ɂ����̑��
		//32�r�b�g���A�N�Z�X���邽�߂�data_log_buffer��[1]����[3]�ւ̓A�N�Z�X���ĂȂ��B
			*((U32 *)(&data_log_buffer[0]))  = (U32)systick_get_ms();
			*(( S8 *)(&data_log_buffer[4]))  =  (S8)data1;
            *(( S8 *)(&data_log_buffer[5]))  =  (S8)data2;
            *((U16 *)(&data_log_buffer[6]))  = (U16)ecrobot_get_light_sensor(NXT_PORT_S3); //light sensor value
            *((S32 *)(&data_log_buffer[8]))  = (S32)nxt_motor_get_count(0);
            *((S32 *)(&data_log_buffer[12])) = (S32)nxt_motor_get_count(1);
            *((S32 *)(&data_log_buffer[16])) = (S32)nxt_motor_get_count(2);
            *((S16 *)(&data_log_buffer[20])) = (S16)adc1;
            *((S16 *)(&data_log_buffer[22])) = (S16)adc2;
            *((S16 *)(&data_log_buffer[24])) = (S16)adc3;
            *((S16 *)(&data_log_buffer[26])) = (S16)adc4;
			*((S32 *)(&data_log_buffer[28])) = (U32)datas32_2; 
        
            ecrobot_send_bt_packet(data_log_buffer, 32);
	
	
	
}

