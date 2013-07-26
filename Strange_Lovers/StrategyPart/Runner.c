#include "Runner.h"
#include "../Factory.h"

#define CYCLE_TIME 0.004


float cut_off(float value,int criterion);

void Runner_init(Runner *this_Runner,Section start_section){

}
void Runner_run(Runner *this_Runner){
	Section_run(&(this_Runner->current_section));
}


