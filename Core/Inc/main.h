/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ECHO2_Pin GPIO_PIN_2
#define ECHO2_GPIO_Port GPIOA
#define ECHO_Pin GPIO_PIN_3
#define ECHO_GPIO_Port GPIOA
#define TRIG_Pin GPIO_PIN_4
#define TRIG_GPIO_Port GPIOA
#define KEY0_Pin GPIO_PIN_5
#define KEY0_GPIO_Port GPIOC
#define TRIG2_Pin GPIO_PIN_2
#define TRIG2_GPIO_Port GPIOB
#define LED0_Pin GPIO_PIN_8
#define LED0_GPIO_Port GPIOA
#define KEY1_Pin GPIO_PIN_15
#define KEY1_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOD
#define ECHO1_Pin GPIO_PIN_3
#define ECHO1_GPIO_Port GPIOB
#define TRIG1_Pin GPIO_PIN_4
#define TRIG1_GPIO_Port GPIOB
#define MOTOR1_FORWARD_Pin GPIO_PIN_5
#define MOTOR1_FORWARD_GPIO_Port GPIOB
#define MOTOR1_BACKWARD_Pin GPIO_PIN_6
#define MOTOR1_BACKWARD_GPIO_Port GPIOB
#define MOTOR2_FORWARD_Pin GPIO_PIN_7
#define MOTOR2_FORWARD_GPIO_Port GPIOB
#define MOTOR2_BACKWARD_Pin GPIO_PIN_8
#define MOTOR2_BACKWARD_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
void HAL_Delay_us(uint32_t nus);
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
