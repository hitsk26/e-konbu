
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "DetectorPart/DistanceEncoder.h"
#include "DetectorPart/Timer.h"

namespace DetectorPart
{
class SpeedEncoder
{
private:
	SpeedEncoder speedEncoder;
	DistanceEncoder distanceEncoder;
	Timer timer;

public:
	void SpeedEncoder_get_speed();

	void SpeedEncoder_calc_speed();

	void SpeedEncoder_init();

};

}  // namespace DetectorPart
