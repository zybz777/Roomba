#include "car.h"

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
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);   // LED1灭
    motor1_backward();
    motor2_forward();
}
/* 右转 */
void car_right(void)
{
    HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);   // LED0灭
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); // LED1亮
    motor1_forward();
    motor2_backward();
}
