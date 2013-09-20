#include "CommonInitializeInterface.h"
#include "../../Factory.h"


//InCourse
#include "../In/FiststStraightFactory.h"
#include "../In/SlopeFactory.h"
#include "../In/StartUpFactory.h"
#include "../In/SecondStraightFactory.h"
#include "../In/SecondCurveFactory.h"
#include "../In/ThurdStraightFactory.h"
#include "../In/ThurdCurveFactory.h"
#include "../In/ForthStraightFactory.h"
#include "../In/ForthCurveFactory.h"
#include "../In/InFifthStraightFactory.h"
#include "../In/InFifthCurveFactory.h"
#include "../In/AfterInFifthCurveStraight.h"
#include "../In/InSixthCurveFactory.h"
#include "../StartUpWithTailFactory.h"

void strategies_init(){

	first_curve_factory_init();
	after_slope_straight_factory_init();
	slope_factory_init();
	first_straight_factory_init();
	start_up__factory_init();
	second_straight_factory_init();
	second_curve_factory_init();
	thurd_straight_factory_init();
	thurd_curve_factory_init();
	forth_straight_factory_init();
	forth_curve_factory_init();
	start_up_with_tail_factory_init();
	In_fifth_straight_factory_init();
	In_fifth_curve_factory_init();
	after_In_fifth_curve_straight_factory_init();
	In_sixth_curve_factory_init();
	
	startSection = &startUp;

}

