

float moving_average(float mesured_value,float *buf,int max_count,int index){
	buf[index]=mesured_value;
	
	int i=0;
	float average=0,sum=0;
	for(i=0;i<max_count;++i){
		sum += buf[i];
	}
	average = (float)sum /  max_count;
	return average;
}

