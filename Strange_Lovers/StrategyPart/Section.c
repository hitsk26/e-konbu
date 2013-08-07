#include "Section.h"
#include "../Factory.h"


static void Section_update_current_running_methods(Section *this_Section);

//‹æŠÔÅŒã‚Ì‘––@ŽÀsI—¹”»’f
static int Section_clear_section(Section *this_Section,int executed_flag);


void Section_init(Section *this_Section){
	this_Section->current_running_method_number=0;
}


struct Section* Section_get_next_section(Section *this_Section)
{
	return this_Section->nextSection;
}

int Section_clear_section(Section *this_Section,int executed_flag)
{

	if(executed_flag==1 && 
		this_Section->current_running_method_number+1 == this_Section->number_of_running_method){
			ecrobot_sound_tone(880,10,60);
			return 1;
	}
	else {
		return 0;
	}
}

int Section_run(Section *this_Section)
{
	int cleared_flag=0;

	RunningMethod_execute_method(&(this_Section->running_methods[this_Section->current_running_method_number]),this_Section->target_values);
	
	
	int executed_flag =  RunningMethod_check_executed(&(this_Section->running_methods[this_Section->current_running_method_number]));
	
	if(Section_clear_section(this_Section,executed_flag)){
		cleared_flag = 1;
	}

	if(executed_flag==1){
		Section_update_current_running_methods(this_Section);
	}
	
	return cleared_flag;
}

static void Section_update_current_running_methods(Section *this_Section){
	
	if(this_Section->current_running_method_number +1 < this_Section->number_of_running_method ) {
		this_Section->current_running_method_number +=1;
		ecrobot_sound_tone(300,500,50);
	}
	else {
		//none
	}

}
	

