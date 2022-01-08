/* USER CODE BEGIN 0 */
#include "motor.h"
#include "gpio.h"
#include "tim.h"
STATE state_car = state_forward;
int standard_L = 1500; // 90度
int standard_R = 1500; // 90度
void motor1_forward(void)
{
	// MOTOR1 前进
	HAL_GPIO_WritePin(MOTOR1_FORWARD_GPIO_Port, MOTOR1_FORWARD_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR1_BACKWARD_GPIO_Port, MOTOR1_BACKWARD_Pin, GPIO_PIN_RESET);
}

void motor1_backward(void)
{
	// MOTOR1 后退
	HAL_GPIO_WritePin(MOTOR1_FORWARD_GPIO_Port, MOTOR1_FORWARD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR1_BACKWARD_GPIO_Port, MOTOR1_BACKWARD_Pin, GPIO_PIN_SET);
}

void motor1_stop(void)
{
	// MOTOR1 停止
	HAL_GPIO_WritePin(MOTOR1_FORWARD_GPIO_Port, MOTOR1_FORWARD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR1_BACKWARD_GPIO_Port, MOTOR1_BACKWARD_Pin, GPIO_PIN_RESET);
}

void motor2_forward(void)
{
	// MOTOR2 前进
	HAL_GPIO_WritePin(MOTOR2_FORWARD_GPIO_Port, MOTOR2_FORWARD_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR2_BACKWARD_GPIO_Port, MOTOR2_BACKWARD_Pin, GPIO_PIN_RESET);
}

void motor2_backward(void)
{
	// MOTOR2 后退
	HAL_GPIO_WritePin(MOTOR2_FORWARD_GPIO_Port, MOTOR2_FORWARD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR2_BACKWARD_GPIO_Port, MOTOR2_BACKWARD_Pin, GPIO_PIN_SET);
}

void motor2_stop(void)
{
	// MOTOR2 停止
	HAL_GPIO_WritePin(MOTOR2_FORWARD_GPIO_Port, MOTOR2_FORWARD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR2_BACKWARD_GPIO_Port, MOTOR2_BACKWARD_Pin, GPIO_PIN_RESET);
}

/* 前进 */
void car_forward(void)
{
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET); // LED0亮
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); // LED1亮
	motor1_forward();
	motor2_forward();
}
/* 后退 */
void car_backward(void)
{
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET); // LED0灭
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET); // LED1灭
	motor1_backward();
	motor2_backward();
}
/* 停止 */
void car_stop(void)
{
	motor1_stop();
	motor2_stop();
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET); // LED0灭
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET); // LED1灭
}
/* 左转 */
void car_left(void)
{
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET); // LED0亮
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);	 // LED1灭
	motor1_backward();
	motor2_forward();
}
/* 右转 */
void car_right(void)
{
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);	 // LED0灭
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); // LED1亮
	motor1_forward();
	motor2_backward();
}

//  状态机转移
void state_trans()
{
	static int road = 0; // 轨迹序号
	static int go_long = 3000;
	static int go_short = 1000;
	static int turn_time = 1500;
	static int stop_time = 500;
	switch (state_car)
	{
	case state_forward:
		if (road == 2 || road == 6)
		{
			HAL_Delay(go_short);
		}
		else
		{
			HAL_Delay(go_long);
		}
		state_car = state_stop;
		break;
	case state_left:
		HAL_Delay(turn_time);
		state_car = state_stop;
		break;
	case state_right:
		HAL_Delay(turn_time);
		state_car = state_stop;
		break;
	case state_stop:
		road++;
		HAL_Delay(stop_time);
		switch (road)
		{
		case 1:
			state_car = state_left;
			break;
		case 2:
			state_car = state_forward;
			break;
		case 3:
			state_car = state_left;
			break;
		case 4:
			state_car = state_forward;
			break;
		case 5:
			state_car = state_right;
			break;
		case 6:
			state_car = state_forward;
			break;
		case 7:
			state_car = state_right;
			break;
		default:
			state_car = state_forward;
			road = 0;
			break;
		}
		break;
	default:
		break;
	}
}
// 状态机执行
void state_exe()
{
	switch (state_car)
	{
	case state_forward:
		car_forward(); // 直行
		break;
	case state_left:
		car_left(); // 左转
		break;
	case state_right:
		car_right(); // 右转
		break;
	case state_stop:
		car_stop();
		break;
	default:
		break;
	}
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
	car_forward(); // 直行
	HAL_Delay(go_long);

	car_stop();
	HAL_Delay(stop_time);

	car_left(); // 左转
	HAL_Delay(turn_time);

	car_stop();
	HAL_Delay(stop_time);

	car_forward(); // 直行
	HAL_Delay(go_short);

	car_stop();
	HAL_Delay(stop_time);

	car_left(); // 左转
	HAL_Delay(turn_time);

	car_stop();
	HAL_Delay(stop_time);

	car_forward(); // 直行
	HAL_Delay(go_long);

	car_stop();
	HAL_Delay(stop_time);

	car_right(); // 右转
	HAL_Delay(turn_time);

	car_stop();
	HAL_Delay(stop_time);

	car_forward(); // 直行
	HAL_Delay(go_short);

	car_stop();
	HAL_Delay(stop_time);

	car_right(); // 右转
	HAL_Delay(turn_time);

	car_stop();
	HAL_Delay(stop_time);
}
/* USER CODE END 0 */
