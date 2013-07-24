#include "LightVal.h"
#include "../../Factory.h"

void LV_init(LightVal *this_LightVal,LightValEncoder LVE){

	mLightValEncoder = LVE;
	LVE_init(&mLightValEncoder);
	this_LightVal->targLightVal = 0;
}

int LV_getLightVal(LightVal *this_LightVal){

	int lightVal = LVE_getLightVal(&mLightValEncoder);
	BrightnessEncoder_get_brightness(BrightnessEncoder *this_BrightnessEncoder);

	if(LVR_checkRange(&mLightValRange,lightVal) == 0)
		LVL_emergency(&mLightValListener,lightVal);

	return lightVal;
}

int LV_getTargLightVal(LightVal *this_LightVal){
	return this_LightVal->targLightVal;
}

void LV_setTargLightVal(LightVal *this_LightVal,int parm){
	this_LightVal->targLightVal = parm;
}

LightValRange LV_getLightValRange(LightVal *this_LightVal){
	return mLightValRange;
}

void LV_setLightValListener(LightVal *this_LightVal,LightValListener LVL){
	mLightValListener = LVL;
}

void LV_setLightValRange(LightVal *this_LightVal,LightValRange LVR){
	mLightValRange = LVR;
}

