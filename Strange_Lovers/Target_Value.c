#include "Target_Value.h"

void set_target_value_brightness(int target_value){
	target_value_brightness = target_value;
}

void set_anglr_of_aim(int target_value){
	anglr_of_aim = target_value;
}

extern int get_tail_value(){
	return anglr_of_aim;
}
extern int get_brightness_value(){
	return target_value_brightness;
}


