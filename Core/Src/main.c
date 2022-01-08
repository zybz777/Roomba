/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motor.h"
#include "hc-sr04.h"
#include "car_control.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
Hcsr04InfoTypeDef Hcsr04Info;
Hcsr04InfoTypeDef Hcsr04Info1;
Hcsr04InfoTypeDef Hcsr04Info2;
int flag_mid = 0;
int flag_left = 0;
int flag_right = 0;
int flag = 0;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  //HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);//娴ｈ儻鍏榯im1闁岸浜�2 pwm
  Hcsr04Init(&Hcsr04Info, &htim2, TIM_CHANNEL_4);  //  鐡掑懎锛愬▔銏∧侀崸妤€鍨垫慨瀣
  Hcsr04Init(&Hcsr04Info1, &htim2, TIM_CHANNEL_2); //  鐡掑懎锛愬▔銏∧侀崸妤€鍨垫慨瀣
  Hcsr04Init(&Hcsr04Info2, &htim2, TIM_CHANNEL_3); //  鐡掑懎锛愬▔銏∧侀崸妤€鍨垫慨瀣
  Hcsr04Start(&Hcsr04Info, TRIG_GPIO_Port, TRIG_Pin);
  Hcsr04Start(&Hcsr04Info1, TRIG1_GPIO_Port, TRIG1_Pin);
  Hcsr04Start(&Hcsr04Info2, TRIG2_GPIO_Port, TRIG2_Pin);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* 閹稿绗卥ey0閿涘苯浠犻敓锟�? */
    // if (HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET)
    // {
    //   while (HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET)
    //     ; //閺夋儳绱戦幐澶愭暛閸氬孩澧界悰灞藉З閿燂拷?
    //   flag = 1;
    // }
    // if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET)
    // {
    //   while (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET)
    //     ; //閺夋儳绱戦幐澶愭暛閸氬孩澧界悰灞藉З閿燂拷?
    //   flag = 0;
    // }

    // if (flag == 1)
    // {
    //   // 閸撳秵鏌熼梾婊咁暡閿燂拷?
    //   if (Hcsr04Read(&Hcsr04Info) < 20)
    //   {
    //     flag_mid = 1;
    //   }
    //   else
    //   {
    //     flag_mid = 0;
    //   }

    //   // 瀹革附鏌熼梾婊咁暡閿燂拷?
    //   if (Hcsr04Read(&Hcsr04Info1) < 10)
    //   {
    //     flag_left = 1;
    //   }
    //   else
    //   {
    //     flag_left = 0;
    //   }
    //   // 閸欒櫕鏌�
    //   if (Hcsr04Read(&Hcsr04Info2) < 10)
    //   {
    //     flag_right = 1;
    //   }
    //   else
    //   {
    //     flag_right = 0;
    //   }
    //   Hcsr04Start(&Hcsr04Info, TRIG_GPIO_Port, TRIG_Pin);
    //   Hcsr04Start(&Hcsr04Info1, TRIG1_GPIO_Port, TRIG1_Pin);
    //   Hcsr04Start(&Hcsr04Info2, TRIG2_GPIO_Port, TRIG2_Pin);
    //   HAL_Delay(50);
    // }
    // else
    // {
    //   STOP();
    // }

    // /******** 閺嶅洤绻旀担宥嗗付閿燂拷? ********/
    // if (flag == 1)
    // {
    //   car_ctrl(flag_mid, flag_left, flag_right);
    // }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET); //LED0閿熸枻鎷�
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); //LED1閿熸枻鎷�
    state_exe();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_Delay_us(uint32_t nus)
{
  //鐏忓敄ystic鐠佸墽鐤嗛敓锟�?1us娑擃厽鏌�
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000000);
  //瀵よ埖妞俷us
  HAL_Delay(nus - 1);
  //閹垹顦瞫ystic娑擃厽鏌囬敓锟�?1ms
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);
}
/**
 * @description: 鐎规碍妞傞崳銊ㄧ翻閸戠儤宕熼懢铚傝厬閿燂拷?
 * @param {TIM_HandleTypeDef} *htim
 * @return {*}
 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
  Hcsr04TimIcIsr(&Hcsr04Info, htim);
  Hcsr04TimIcIsr(&Hcsr04Info1, htim);
  Hcsr04TimIcIsr(&Hcsr04Info2, htim);
}

/**
 * @description: 鐎规碍妞傞崳銊﹀閸戣桨鑵戦敓锟�?
 * @param {*}
 * @return {*}
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  Hcsr04TimOverflowIsr(&Hcsr04Info, htim);
  Hcsr04TimOverflowIsr(&Hcsr04Info1, htim);
  Hcsr04TimOverflowIsr(&Hcsr04Info2, htim);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
