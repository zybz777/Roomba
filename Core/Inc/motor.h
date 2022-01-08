#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "main.h"

typedef enum
{
    state_forward,
    state_left,
    state_right,
    state_stop
} STATE;
extern STATE state_car;
// 单独轮子
void motor1_forward(void);
void motor1_backward(void);
void motor1_stop(void);
void motor2_forward(void);
void motor2_backward(void);
void motor2_stop(void);
// 车子整体
void car_forward(void);
void car_backward(void);
void car_stop(void);
void car_left(void);
void car_right(void);
// 路线方式
void routine_road(void); //回字形常规路线
void state_trans(void);
void state_exe(void);
#endif                   /* MOTOR_MODULE_ENABLED */
