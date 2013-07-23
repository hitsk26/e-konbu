
#include "CurvatureEncoder.h"
#include "DirectionEncoder.h"
#include "../Factory.h"

#define CYCLE_TIME 0.004
#define TARGTIME 100

#define MEASURE_TIME_CYCLE 100 //[ms]
#define EXECUTE_CYCLE_TIME 4 //[ms]

void CurvatureEncoder_init(CurvatureEncoder *this_CurvatureEncoder)
{
	this_CurvatureEncoder->curvature = 0;
}

int CurvatureEncoder_get_curvature(CurvatureEncoder *this_CurvatureEncoder)
{
	this_CurvatureEncoder->curvature =CurvatureEncoder_calc_curvature(this_CurvatureEncoder);
	return this_CurvatureEncoder->curvature;
}

int CurvatureEncoder_calc_curvature(CurvatureEncoder *this_CurvatureEncoder)
{
	float theta=0;
	int distance=0;
	static float buf_theta=0;
	static int buf_distance=0;
	float curvature=0;
	static float curvature_store=0;
	static int bufTime =0;
	
	distance = DistanceEncoder_get_distance(&distanceEncoder);
	theta = DirectionEncoder_get_direction(&directionEncoder);
	unsigned int time =  Timer_get_ms(&timer);

	if(!(theta == buf_theta)){
		curvature = rad2deg((distance - buf_distance) / (theta - buf_theta));
	}
	else{
		curvature= 0.0;
	}
	curvature_store += curvature;

	if((time - bufTime) >= TARGTIME)
	{
		this_CurvatureEncoder->curvature = (int)curvature_store/25; //25‰ñ•ª‚Ì•½‹Ï‚ğæ‚Á‚Ä‚é
		curvature_store = 0;
		bufTime = time;
	}

	buf_distance = distance;
	buf_theta= theta;

	return (int)this_CurvatureEncoder->curvature;
}

