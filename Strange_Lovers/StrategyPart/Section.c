#include "Section.h"

static void Section_update_current_running_methods(Section *this_Section);

struct Section* Section_get_next_section(Section *this_Section)
{
	return this_Section->nextSection;
}

int Section_clear_section(Section *this_Section)
{
	if(this_Section->current_running_method_number >= this_Section->number_of_running_method)
	return 1;
	else {
		return 0;
	}
}

void Section_run(Section *this_Section)
{
	RunningMethod_execute_method(&(this_Section->running_methods[this_Section->current_running_method_number]),this_Section->target_value);
	
	if(RunningMethod_check_executed(&(this_Section->running_methods[this_Section->current_running_method_number]))){
		Section_update_current_running_methods(this_Section);
	}
}

static void Section_update_current_running_methods(Section *this_Section){
	
	if(this_Section->current_running_method_number +1 < this_Section->number_of_running_method ) {
		this_Section->current_running_method_number +=1;
	}
	else {
		//none
	}

}
	
