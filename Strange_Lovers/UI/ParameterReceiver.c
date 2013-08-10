#include "ParameterReceiver.h"

#define BUF_SIZE 11

static void ParameterReceiver_init_buf(char *buf,int buf_size );

void ParameterReceiver_init(ParameterReceiver *self,LightValCtrl *lightValCtrl,SpeedCtrl *speedCtrl,CurvatureCtrl *curvatureCtrl)
{
	self->lightValCtrl = lightValCtrl;
	self->curvatureCtrl = curvatureCtrl;
	self->speedCtrl = speedCtrl;
}

void ParamterReceiver_paramter_adjust(ParameterReceiver *self){
	int receive_length=0;
	char buf[ BUF_SIZE];
	
	ParameterReceiver_init_buf(buf,BUF_SIZE);

	receive_length = ecrobot_read_bt(buf, 0,  BUF_SIZE);
	if (receive_length > 0)
	{
		ecrobot_sound_tone(449,40,30);

		if(is_receive_data_number(buf){
			adjust_value(buf);
		}
		else {
			switch_adujusting_value(buf);
			}
	}

	ParamterReceiver_display_info(self);
	


}
static void ParameterReceiver_init_buf(char *buf,int buf_size ){
	int i=0;
	for (i=0; i< buf_size ; i++)
	{
		buf[i] = 0;
	}
}

