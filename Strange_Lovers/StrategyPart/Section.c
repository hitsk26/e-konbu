#include "Section.h"



changeTerm Section_getChangeTermOfNextSection(Section *this_Section)
{
	//return 0;
}

Section Section_getNextSection(Section *this_Section)
{
	//return 0;
}

int Section_clearSection(Section *this_Section)
{
	return false;
}

void Section_run(Section *this_Section)
{
	RunningStrategy_execute_strategy(&(this_Section->current_strategy));
}

