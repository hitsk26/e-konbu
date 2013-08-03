#include "LowPassfFillter.h"


void LowPassfFillter_init(LowPassfFillter *self,float gain){
	self->gain = gain;
	self->buf = 0;
}
float LowPassFilter_get_filltered_value(LowPassfFillter *self,float mesured_value){
	float filltered_value = 0;

	filltered_value = self->gain* mesured_value + (1-self->gain)*self->buf ;
	self->buf = filltered_value ;

	return filltered_value;
}
