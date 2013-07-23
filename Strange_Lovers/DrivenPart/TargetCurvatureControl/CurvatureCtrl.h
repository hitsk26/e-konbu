#ifndef DRIVENPART_TARGETDIRECTIONCONTROL_DIRECTION_CTRL_H
#define DRIVENPART_TARGETDIRECTIONCONTROL_DIRECTION_CTRL_H


typedef struct {
	
}CurvatureCtrl;


int CurvatureCtrl_do_curvature_ctrl(CurvatureCtrl *this_CurvatureCtrl);


int CurvatureCtrl_run(CurvatureCtrl *this_CurvatureCtrl,int target_curvature);


#endif
