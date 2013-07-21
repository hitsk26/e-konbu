#include "CommonFunction.h"

int cutoff(int value, int criterion){
	
	int cut_offed;
	
	if(value>criterion){
		cut_offed = criterion;
	}
	else if(value<-criterion){
		cut_offed = -criterion;
	}
	else {
	cut_offed = value;
	}

	return cut_offed;
}

