
#ifndef __CoordinateEncoder
#define __CoordinateEncoder

#include "../EncoderPart/DistanceEncoder.h"
#include "../EncoderPart/DirectionEncoder.h"

typedef struct{
	float xCoo;
	float yCoo;
	float distance_buf;
}CoordinateEncoder;


void CoordinateEncoder_init(CoordinateEncoder *self);
void CoordinateEncoder_calc_coordinate(CoordinateEncoder *self);
float CoordinateEncoder_get_coordinate(CoordinateEncoder *self);
float CoordinateEncoder_get_total_coordinate(CoordinateEncoder *self);
void CoordinateEncoder_reset_Encoder(CoordinateEncoder *self);

#endif

