#ifndef __LowPassFillter
#define __LowPassFillter

typedef struct {
float gain;
float buf;
}LowPassfFillter;

void LowPassfFillter_init(LowPassfFillter *self,float gain);
float LowPassFilter_get_filltered_value(LowPassfFillter *self,float mesured_value);

#endif
