#ifndef __CurvatureEncoder
#define __CurvatureEncoder


#include "./DistanceEncoder.h"
#include "../DrivenPart/WheelMotor.h"

typedef struct{
	int curvature;
	
}CurvatureEncoder;


int CurvatureEncoder_get_curvature(CurvatureEncoder *this_CurvatureEncoder);
int CurvatureEncoder_calc_curvature(CurvatureEncoder *this_CurvatureEncoder);
void CurvatureEncoder_init(CurvatureEncoder *this_CurvatureEncoder);

#endif 


