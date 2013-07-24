#ifndef _TARGET_VALUE_H_
#define _TARGET_VALUE_H_


typedef struct{
	int target_brightness;
	int angle_of_aim;
	float target_curvature;
}TargetValue;

extern void TargetValue_init(TargetValue *this_TargetValue);
extern void TargetValue_set_target_value_brightness(TargetValue *this_TargetValue , int target_value);
extern void TargetValue_set_anglr_of_aim(TargetValue *this_TargetValue , int target_value);


#endif

