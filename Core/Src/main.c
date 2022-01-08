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
#include "state_machine.h"
#include "hc-sr04.h"
#include "motor.h"
#include "car.h"
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
Hcsr04InfoTypeDef Hcsr04_mid;
Hcsr04InfoTypeDef Hcsr04_left;
Hcsr04InfoTypeDef Hcsr04_right;
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
  // 瓒呭０娉紶鎰熷櫒鍒濆鍖�
  Hcsr04Init(&Hcsr04_mid, &htim2, TIM_CHANNEL_4);
  Hcsr04Init(&Hcsr04_left, &htim2, TIM_CHANNEL_2);
  Hcsr04Init(&Hcsr04_right, &htim2, TIM_CHANNEL_3);
  Hcsr04Start(&Hcsr04_mid, TRIG_GPIO_Port, TRIG_Pin);
  Hcsr04Start(&Hcsr04_left, TRIG1_GPIO_Port, TRIG1_Pin);
  Hcsr04Start(&Hcsr04_right, TRIG2_GPIO_Port, TRIG2_Pin);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
  HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET); // LED0闂佽法鍠愰弸濠氬箯閿燂拷
  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); // LED1闂佽法鍠愰弸濠氬箯閿燂拷
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* 闂佸湱枪椤︻喚绮崡顧珁0闂佹寧绋戦懟顖涚閻樼粯鏅搁柨鐕傛嫹? */
    // if (HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET)
    // {
    //   while (HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET)
    //     ;
    //   flag = 1;
    // }
    // if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET)
    // {
    //   while (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET)
    //     ;
    //   flag = 0;
    // }
    state_exe();
    // motor1_forward();
    // motor2_forward();
    // car_forward();
 
    // if (flag == 1)
    // {
    //   // 闂佸憡鎸哥粔鐢稿蓟閻斿吋鈷曟繝濠傛媼閺嗭繝鏌ㄩ悤鍌涘?
    //   if (Hcsr04Read(&Hcsr04Info) < 20)
    //   {
    //     flag_mid = 1;
    //   }
    //   else
    //   {
    //     flag_mid = 0;
    //   }

    //   // 閻庡綊娼婚梽鍕蓟閻斿吋鈷曟繝濠傛媼閺嗭繝鏌ㄩ悤鍌涘?
    //   if (Hcsr04Read(&Hcsr04Info1) < 10)
    //   {
    //     flag_left = 1;
    //   }
    //   else
    //   {
    //     flag_left = 0;
    //   }
    //   // 闂佸憡鐟ㄥ▍鏇㈠蓟閿燂拷
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

    // /******** 闂佸搫绉村ú銈囨崲閺冣偓閹峰懎顓奸崱妞剧帛闂佽法鍣﹂幏锟�? ********/
    // if (flag == 1)
    // {
    //   car_ctrl(flag_mid, flag_left, flag_right);
    // }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  //闁诲繐绻愰弫鍓弒tic闁荤姳绀佹晶浠嬫偪閸℃稒鏅搁柨鐕傛嫹?1us婵炴垶鎼╅崢浠嬪蓟閿燂拷
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000000);
  //閻庣偣鍊涢崺鏍ь渻娣囩s
  HAL_Delay(nus - 1);
  //闂佽鍘归崹褰捤囬惉鐝乻tic婵炴垶鎼╅崢浠嬪蓟閸ヮ剚鏅搁柨鐕傛嫹?1ms
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);
}
/**
 * @description: 闁诲氦顫夌喊宥咁渻閸岀偛闂柕濞垮妿缂堝鏌涢幋鐘插妺鐎规洜鍠栭幊銏ゆ憥閸屾繂骞€闂佽法鍣﹂幏锟�?
 * @param {TIM_HandleTypeDef} *htim
 * @return {*}
 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
  Hcsr04TimIcIsr(&Hcsr04_mid, htim);
  Hcsr04TimIcIsr(&Hcsr04_left, htim);
  Hcsr04TimIcIsr(&Hcsr04_right, htim);
}

/**
 * @description: 闁诲氦顫夌喊宥咁渻閸岀偛闂柕濠忕畱椤掋垽鏌涢幋锝嗐€冮柤鍨灴閺佹捇鏁撻敓锟�?
 * @param {*}
 * @return {*}
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  Hcsr04TimOverflowIsr(&Hcsr04_mid, htim);
  Hcsr04TimOverflowIsr(&Hcsr04_left, htim);
  Hcsr04TimOverflowIsr(&Hcsr04_right, htim);
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
