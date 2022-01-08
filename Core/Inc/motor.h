#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "gpio.h"

// 单独电机
void motor1_forward(void);
void motor1_backward(void);
void motor1_stop(void);
void motor2_forward(void);
void motor2_backward(void);
void motor2_stop(void);

// 路线方式
#endif /* MOTOR_MODULE_ENABLED */
