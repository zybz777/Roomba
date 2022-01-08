/*
 * @Author       : yzy
 * @Date         : 2021-05-31 17:03:27
 * @LastEditors  : yzy
 * @LastEditTime : 2021-05-31 19:02:54
 * @Description  : 
 * @FilePath     : \F103_Test\BSP_HARDWARE\hc-sr04.h
 */
#ifndef HCSR04_H_
#define HCSR04_H_

#include "main.h"
#include "stm32f1xx_hal.h"

typedef struct
{
	uint8_t  edge_state;
	uint16_t tim_overflow_counter;
	uint32_t prescaler;
	uint32_t period;
	uint32_t t1;	//	上升沿时间
	uint32_t t2;	//	下降沿时间
	uint32_t high_level_us;	//	高电平持续时间
	float    distance;
	TIM_TypeDef* instance;
	uint32_t ic_tim_ch;
	HAL_TIM_ActiveChannel active_channel;
}Hcsr04InfoTypeDef;



/**
 * @description: 超声波模块的输入捕获定时器通道初始化
 * @param {TIM_HandleTypeDef} *htim
 * @param {uint32_t} Channel
 * @return {*}
 */
void Hcsr04Init(Hcsr04InfoTypeDef*Hcsr04Info, TIM_HandleTypeDef *htim, uint32_t Channel);

/**
 * @description: HC-SR04触发
 * @param {*}
 * @return {*}
 */
void Hcsr04Start(Hcsr04InfoTypeDef*Hcsr04Info, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/**
 * @description: 定时器计数溢出中断处理函数
 * @param {*}    main.c中重定义void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
 * @return {*}
 */
void Hcsr04TimOverflowIsr(Hcsr04InfoTypeDef*Hcsr04Info, TIM_HandleTypeDef *htim);

/**
 * @description: 输入捕获计算高电平时间->距离
 * @param {*}    main.c中重定义void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
 * @return {*}
 */
void Hcsr04TimIcIsr(Hcsr04InfoTypeDef*Hcsr04Info, TIM_HandleTypeDef* htim);

/**
 * @description: 读取距离 
 * @param {*}
 * @return {*}
 */
float Hcsr04Read(Hcsr04InfoTypeDef*Hcsr04Info);

#endif /* HCSR04_H_ */

