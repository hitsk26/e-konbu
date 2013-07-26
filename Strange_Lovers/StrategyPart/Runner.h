#ifndef _RUNNER_
#define _RUNNER_

#include "../UI/PushButton.h"
#include "Section.h"

typedef struct{
Section *current_section;
}Runner;


void Runner_init(Runner *this_Runner,Section *start_section);
void Runner_run(Runner *this_Runner);



#endif

