#include "CommonFunction.h"

float LPF(float value,float weight,float buf_output);

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

float LPF(float value,float weight,float buf_output){
	
	float filltered_value = weight*value + (1-weight)*buf_output;
	
	return filltered_value;
}
