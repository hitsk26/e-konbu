#include "CommonInitializeInterface.h"
#include "../../Factory.h"

//OutCourse

#include "../FiststStraightFactory.h"
#include "../SlopeFactory.h"
#include "../StartUpFactory.h"
#include "../SecondStraightFactory.h"
#include "../SecondCurveFactory.h"
#include "../ThurdStraightFactory.h"
#include "../ThurdCurveFactory.h"
#include "../ForthStraightFactory.h"
#include "../ForthCurveFactory.h"
#include "../OutFifthStraightFactory.h"
#include "../OutFifthCurveFactory.h"
#include "../AfterOutFifthCurveStraight.h"
#include "../OutSixthCurveFactory.h"

#include "../SeeSaw_stopFactory.h"
#include "../StartUpWithTailFactory.h"
#include "../SeeSaw_1Factory.h"
#include "../SeeSaw_stopFactory.h"
#include "../SeeSaw_2Factory.h"
#include "../SeeSaw_2_2Factory.h"
#include "../SeeSaw_3Factory.h"
#include "../SeeSaw_4Factory.h"
#include "../SeeSaw_5Factory.h"



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
	out_fifth_straight_factory_init();
	out_fifth_curve_factory_init();
	after_out_fifth_curve_straight_factory_init();
	out_sixth_curve_factory_init();

	
	seesaw_1_factory_init();
	seesaw_stop_factory_init();
	seesaw_2_factory_init();
	seesaw_2_2factory_init();
	seesaw_3_factory_init();
	seesaw_4_factory_init();
	seesaw_5_factory_init();

	startSection = &startUp;

}

