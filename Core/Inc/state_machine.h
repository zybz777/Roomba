#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include "main.h"
#include "car.h"
typedef enum
{
    state_forward,
    state_left,
    state_right,
    state_stop
} STATE;
extern STATE state_car;
void state_trans(void);
void state_exe(void);

#endif
