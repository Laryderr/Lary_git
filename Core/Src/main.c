/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32f4xx.h"
//#include "bsp_debug_usart.h"
//#include "bsp_SysTick.h"
//#include "core_delay.h"
//#include "bsp_dht11.h"
//#include "bsp_esp8266.h"
//#include "bsp_esp8266_test.h"
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
uint8_t txdatabuffer[4],rxdatabuffer[2];
uint16_t tof_diatance=0;
uint16_t wifi_order_fin = 0;
uint16_t tof_flag=0;
  u8 key=0;
extern uint16_t wifi_order[6];
extern u8 Flag;
//extern uint16_t wifi_flag=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_TIM9_Init();
  MX_USART6_UART_Init();
  /* USER CODE BEGIN 2 */
  PS2_SetInit();
  HAL_UART_Receive_IT(&huart6,rxdatabuffer,sizeof(rxdatabuffer));
  //Debug_USART_Config ();                                                      //��ʼ������1
  //CPU_TS_TmrInit();                                                     //��ʼ��DWT��������������ʱ����
  //LED_GPIO_Config();                                                    //��ʼ��RGB�ʵ�
	//ESP8266_Init ();                                                      //��ʼ��WiFiģ��ʹ�õĽӿں�����
	//DHT11_GPIO_Config ();                                                        //��ʼ��DHT11


  //printf ( "\r\n野火 WF-ESP8266 WiFi模块测试例程\r\n" );                 //打印测试例程提示信息

  //ESP8266_StaTcpClient_Unvarnish_ConfigTest();                          //对ESP8266进行配置
  //SysTick_Init ();                                                       //配置 SysTick �??????? 10ms 中断�???????次，在中断里读取传感器数�???????
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    

    /*wifi_order_swtich();

    if(wifi_flag == 1)
    {
      motor_controll_wifi();
    }*/
    //key =PS2_DataKey();
    // HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_SET);
    motor_controll_V1();
    wifi_order_swtich();
    motor_controll_wifi();
    HAL_GPIO_WritePin(blade_motor_A_GPIO_Port,blade_motor_A_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(blade_motor_B_GPIO_Port,blade_motor_B_Pin,GPIO_PIN_RESET);
   
    HAL_GPIO_TogglePin(red_GPIO_Port,red_Pin);
    if(tof_flag==2)
    {
      HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
    }/*else{
      HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
      tof_flag=0;
    }*/
    
    /*if( read_dht11_finish ) // read_dht11_finish == 1 or read_dht11_finish == -1
    {
      
      ESP8266_SendDHT11DataTest(); // ESP8266 发�?�一次温湿度数据
      //printf("read_dht11_finish=%d\r\n", read_dht11_finish);    //Debug
      read_dht11_finish = 0;       // 清零标志�???????
      
      
    }*/
    
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin==GPIO_PIN_6)
  {
    uint32_t temp=HAL_GetTick();
    *((uint32_t*)txdatabuffer) = temp;
    while(huart6.gState!=HAL_UART_STATE_READY)
    HAL_UART_Transmit_IT(&huart6,txdatabuffer,sizeof(txdatabuffer));
  }
  all_turnoff();
  HAL_GPIO_WritePin(blade_motor_A_GPIO_Port,blade_motor_A_Pin,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(blade_motor_B_GPIO_Port,blade_motor_B_Pin,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(belt_motor_A_GPIO_Port,belt_motor_A_Pin,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(belt_motor_B_GPIO_Port,belt_motor_B_Pin,GPIO_PIN_RESET);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(huart==&huart6)
  {
    HAL_UART_Receive_IT(&huart6,rxdatabuffer,sizeof(rxdatabuffer));
    tof_diatance=*((uint16_t*)rxdatabuffer);
    //HAL_UART_Receive_IT(&huart6,rxdatabuffer,sizeof(rxdatabuffer));
    tof_flag=1;
    HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
  }
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM7 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM7) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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

#ifdef  USE_FULL_ASSERT
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
