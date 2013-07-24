#include "CurvatureCtrl.h"
#include "../../Factory.h"


#define CYCLE_TIME 0.004


//fake implementation
int CurvatureCtrl_run(CurvatureCtrl *this_CurvatureCtrl,int target_curvature)
{
	static	float	hensa = 0;
	static	int		turn = 0;

	static const float cKp = 1.8;
	static const float cKi = 0.9;
	static const float cKd =	0.001;

	static float i_hensa = 0;
	static float d_hensa = 0;
	static float bf_hensa = 0;

	hensa =  CurvatureEncoder_get_curvature(&curvatureEncoder) - target_curvature;

	i_hensa = i_hensa + (hensa * CYCLE_TIME);
	d_hensa = (bf_hensa - hensa )/CYCLE_TIME;
	bf_hensa = hensa;

	turn = cKp*hensa + cKi*i_hensa + cKd*d_hensa;
	turn = cutoff(turn,100);
	
	return turn;
}

int CurvatureCtrl_do_curvature_ctrl(CurvatureCtrl *this_CurvatureCtrl)
{
	return 0;
}
