
#include "CurvatureEncoder.h"
#include "DirectionEncoder.h"
#include "../lib/MovingAverage.h"
#include "../Factory.h"

#define CYCLE_TIME 0.004
#define TARGTIME 100

void CurvatureEncoder_init(CurvatureEncoder *this_CurvatureEncoder)
{
	this_CurvatureEncoder->curvature = 0;
}

float CurvatureEncoder_get_curvature(CurvatureEncoder *this_CurvatureEncoder)
{
	return this_CurvatureEncoder->curvature;
}

void CurvatureEncoder_calc_curvature(CurvatureEncoder *this_CurvatureEncoder)
{
	float theta=0;
	float distance=0;
	static float buf_theta=0;
	static float buf_distance=0;
	float curvature=0;
	float averaged_curvature=0;
	static float moving_average_buf[25];

	static int index=0;
	
	
	int revL=0,revR=0;
	static int revR_buf=0,revL_buf=0;
	static float curvature_buf=0;


	revL = WheelMotor_get_count(&leftWheelMotor);
	revR = WheelMotor_get_count(&rightWheelMotor);	
	
	float diff_revL = (revL - revL_buf)/CYCLE_TIME;
	float diff_revR = (revR - revR_buf)/CYCLE_TIME;

	if(diff_revL + diff_revR!=0){
	curvature = ((diff_revL - diff_revR) / (diff_revL + diff_revR) )*16.10/2.0;
	//curvature = 1/ curvature;	
	//curvature = (float)(diff_revL - diff_revR / diff_revL + diff_revR )*161;
	
	}
	else {
		curvature = curvature_buf;
	}
	revL_buf = revL;
	revR_buf = revR;
	
	/*
	distance = DistanceEncoder_get_distance(&distanceEncoder); 
	theta = DirectionEncoder_get_direction(&directionEncoder);

	if(!(theta == buf_theta)){
		curvature =  deg2rad(((distance - buf_distance / theta - buf_theta)));
	}

	else{
		curvature= 0.0;
	}
	*/

	if(index>=25){
		index=0;
	}
	averaged_curvature  = moving_average(curvature,moving_average_buf,25,index);
	index++;


	buf_distance = distance;
	buf_theta= theta;
	curvature_buf= curvature;


	this_CurvatureEncoder->curvature =averaged_curvature;
}

