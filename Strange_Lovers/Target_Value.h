#ifndef _TARGET_VALUE_H_
#define _TARGET_VALUE_H_


typedef struct{
	int target_value_brightness;
	int angle_of_aim;
}Target_value;

extern void Target_value_init(Target_value *this_Target_value);
extern void Target_value_set_target_value_brightness(Target_value *this_Target_value , int target_value);
extern void Target_value_set_anglr_of_aim(Target_value *this_Target_value , int target_value);
extern int Target_value_get(Target_value *this_Target_value);

#endif

