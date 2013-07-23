
#include "CurvatureEncoder.h"
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
	float revL = WheelMotor_get_count(&leftWheelMotor);
	float revR = WheelMotor_get_count(&rightWheelMotor);	

	float curvature = W_RADIUS / W_DIST * (revR - revL);
	return (int)curvature;
}


