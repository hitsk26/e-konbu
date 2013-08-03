#ifndef __CurvatureEncoder
#define __CurvatureEncoder


#include "./DistanceEncoder.h"
#include "./DirectionEncoder.h"

typedef struct{
	float curvature;
	
}CurvatureEncoder;


float CurvatureEncoder_get_curvature(CurvatureEncoder *this_CurvatureEncoder);
void CurvatureEncoder_calc_curvature(CurvatureEncoder *this_CurvatureEncoder);
void CurvatureEncoder_init(CurvatureEncoder *this_CurvatureEncoder);

#endif 


