#ifndef _LIGHT_VAL_ENCODER_H
#define _LIGHT_VAL_ENCODER_H

typedef struct{
}LightValEncoder;

#include "ecrobot_interface.h"

extern void LVE_init(LightValEncoder *this_LightValEncoder);
extern int LVE_getLightVal(LightValEncoder *thisLightValEncoder);

#endif
