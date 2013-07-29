#include "Runner.h"
#include "../Factory.h"

#define CYCLE_TIME 0.004


void Runner_init(Runner *this_Runner,Section *start_section){
	this_Runner->current_section = start_section;
}
void Runner_run(Runner *this_Runner){
	
	if(Section_run(this_Runner->current_section)==1){
		Section_init(this_Runner->current_section);
		this_Runner->current_section = Section_get_next_section(this_Runner->current_section);
	}
}


