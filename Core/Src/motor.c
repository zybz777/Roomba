/* USER CODE BEGIN 0 */
#include "motor.h"
#include "gpio.h"
#include "tim.h"

int standard_L = 320; // 90度
int standard_R = 300; // 90度
void MOTOR1FORWARD(void)
{
	// MOTOR1 前进
	HAL_GPIO_WritePin(MOTOR1_FORWARD_GPIO_Port, MOTOR1_FORWARD_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR1_BACKWARD_GPIO_Port, MOTOR1_BACKWARD_Pin, GPIO_PIN_RESET);
}

void MOTOR1BACKWARD(void)
{
	// MOTOR1 后退
	HAL_GPIO_WritePin(MOTOR1_FORWARD_GPIO_Port, MOTOR1_FORWARD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR1_BACKWARD_GPIO_Port, MOTOR1_BACKWARD_Pin, GPIO_PIN_SET);
}

void MOTOR1STOP(void)
{
	// MOTOR1 停止
	HAL_GPIO_WritePin(MOTOR1_FORWARD_GPIO_Port, MOTOR1_FORWARD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR1_BACKWARD_GPIO_Port, MOTOR1_BACKWARD_Pin, GPIO_PIN_RESET);
}

void MOTOR2FORWARD(void)
{
	// MOTOR2 前进
	HAL_GPIO_WritePin(MOTOR2_FORWARD_GPIO_Port, MOTOR2_FORWARD_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR2_BACKWARD_GPIO_Port, MOTOR2_BACKWARD_Pin, GPIO_PIN_RESET);
}

void MOTOR2BACKWARD(void)
{
	// MOTOR2 后退
	HAL_GPIO_WritePin(MOTOR2_FORWARD_GPIO_Port, MOTOR2_FORWARD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR2_BACKWARD_GPIO_Port, MOTOR2_BACKWARD_Pin, GPIO_PIN_SET);
}

void MOTOR2STOP(void)
{
	// MOTOR1 停止
	HAL_GPIO_WritePin(MOTOR2_FORWARD_GPIO_Port, MOTOR2_FORWARD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR2_BACKWARD_GPIO_Port, MOTOR2_BACKWARD_Pin, GPIO_PIN_RESET);
}

/* 前进 */
void FORWARD(void)
{
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET); //LED0亮
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); //LED1亮
	MOTOR1FORWARD();
	MOTOR2FORWARD();
}
/* 后退 */
void BACKWARD(void)
{
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET); //LED0灭
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET); //LED1灭
	MOTOR1BACKWARD();
	MOTOR2BACKWARD();
}
/* 停止 */
void STOP(void)
{
	MOTOR1STOP();
	MOTOR2STOP();
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET); //LED0灭
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET); //LED1灭
}
/* 左转 */
void LEFT(void)
{
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET); //LED0亮
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);	 //LED1灭
	MOTOR1BACKWARD();
	MOTOR2FORWARD();
}
/* 右转 */
void RIGHT(void)
{
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);	 //LED0灭
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); //LED1亮
	MOTOR1FORWARD();
	MOTOR2BACKWARD();
}
void LEFT_90(void)
{
	LEFT();
	HAL_Delay(standard_L);
	STOP();
}
void RIGHT_90(void)
{
	RIGHT();
	HAL_Delay(standard_R);
	STOP();
}
void LEFT_N(float angle)
{
	float temp = angle / 90 * standard_L;
	LEFT();
	HAL_Delay(temp);
	STOP();
}
void RIGHT_N(float angle)
{
	float temp = angle / 90 * standard_R;
	RIGHT();
	HAL_Delay(temp);
	STOP();
}
// 路线规划
void routine_road()
{
	static int go_long = 3000;
	static int go_short = 1000;
	static int turn_time = 1500;
	static int stop_time = 500;
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 1000);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 1000);
	FORWARD(); // 直行
	HAL_Delay(go_long);

	STOP();
	HAL_Delay(stop_time);

	LEFT(); // 左转
	HAL_Delay(turn_time);

	STOP();
	HAL_Delay(stop_time);

	FORWARD(); // 直行
	HAL_Delay(go_short);

	STOP();
	HAL_Delay(stop_time);

	LEFT(); // 左转
	HAL_Delay(turn_time);

	STOP();
	HAL_Delay(stop_time);

	FORWARD(); // 直行
	HAL_Delay(go_long);

	STOP();
	HAL_Delay(stop_time);

	RIGHT(); // 右转
	HAL_Delay(turn_time);

	STOP();
	HAL_Delay(stop_time);

	FORWARD(); // 直行
	HAL_Delay(go_short);

	STOP();
	HAL_Delay(stop_time);

	RIGHT(); // 右转
	HAL_Delay(turn_time);

	STOP();
	HAL_Delay(stop_time);
}
/* USER CODE END 0 */
