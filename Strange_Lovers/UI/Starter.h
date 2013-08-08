#ifndef _Starter_
#define _Starter_

#include "../HardwareWrapper/TouchSensor.h"
#include "../StrategyPart/Runner.h"


typedef struct{

}Starter;


void Starter_init(Starter *self);

void Starter_accept_start_run(Starter *self);

void Starter_accept_stop_run(Starter *self);


#endif

