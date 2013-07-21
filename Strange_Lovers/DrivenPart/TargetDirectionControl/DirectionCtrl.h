#ifndef DRIVENPART_TARGETDIRECTIONCONTROL_DIRECTION_CTRL_H
#define DRIVENPART_TARGETDIRECTIONCONTROL_DIRECTION_CTRL_H


typedef struct {
	
}DirectionCtrl;


int DirectionCtrl_do_direction_ctrl(DirectionCtrl *this_DirectionCtrl);


int DirectionCtrl_run(DirectionCtrl *this_DirectionCtrl,int target_direction);


#endif
