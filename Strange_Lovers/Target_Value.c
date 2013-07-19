#include "Target_Value.h"
#include "Factory.h"

void Target_value_init(Target_value *this_Target_value){
	this_Target_value->target_value_brightness = 0;
	this_Target_value->angle_of_aim = 0;
}

void set_target_value_brightness(Target_value *this_Target_value , int target_value){
	this_Target_value->target_value_brightness = target_value;
}

<<<<<<< HEAD
void set_anglr_of_aim(Target_value *this_Target_value , int target_value){
	this_Target_value->angle_of_aim = target_value;
}

extern int Target_value_get(Target_value *this_Target_value){
return 0;
}


=======
>>>>>>> parent of b18677e... tail to start is compleat
