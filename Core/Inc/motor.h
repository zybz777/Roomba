#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "main.h"

// 单独轮子
void MOTOR1FORWARD(void);
void MOTOR1BACKWARD(void);
void MOTOR1STOP(void);
void MOTOR2FORWARD(void);
void MOTOR2BACKWARD(void);
void MOTOR2STOP(void);
// 车子整体
void FORWARD(void);
void BACKWARD(void);
void STOP(void);
void LEFT(void);
void RIGHT(void);
// 转弯
void LEFT_90(void);
void RIGHT_90(void);
void LEFT_N(float angle);
void RIGHT_N(float angle);
// 路线方式
void routine_road(void); //回字形常规路线
#endif                   /* MOTOR_MODULE_ENABLED */
