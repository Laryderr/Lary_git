/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * 
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "motor_controll.h"
#include "PS2.h"

//#include "my_headfile.h"
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
#define MotorR1_A_Pin GPIO_PIN_0
#define MotorR1_A_GPIO_Port GPIOF
#define MotorR1_B_Pin GPIO_PIN_1
#define MotorR1_B_GPIO_Port GPIOF
#define red_Pin GPIO_PIN_6
#define red_GPIO_Port GPIOF
#define green_Pin GPIO_PIN_7
#define green_GPIO_Port GPIOF
#define blue_Pin GPIO_PIN_8
#define blue_GPIO_Port GPIOF
#define CS_Pin GPIO_PIN_6
#define CS_GPIO_Port GPIOA
#define blade_motor_A_Pin GPIO_PIN_14
#define blade_motor_A_GPIO_Port GPIOF
#define blade_motor_B_Pin GPIO_PIN_15
#define blade_motor_B_GPIO_Port GPIOF
#define MotorR2_A_Pin GPIO_PIN_0
#define MotorR2_A_GPIO_Port GPIOG
#define MotorR2_B_Pin GPIO_PIN_1
#define MotorR2_B_GPIO_Port GPIOG
#define left_1_Pin GPIO_PIN_10
#define left_1_GPIO_Port GPIOE
#define left_2_Pin GPIO_PIN_12
#define left_2_GPIO_Port GPIOE
#define right_1_Pin GPIO_PIN_14
#define right_1_GPIO_Port GPIOE
#define CLK_Pin GPIO_PIN_13
#define CLK_GPIO_Port GPIOB
#define CMD_Pin GPIO_PIN_14
#define CMD_GPIO_Port GPIOB
#define DAT_Pin GPIO_PIN_15
#define DAT_GPIO_Port GPIOB
#define right_2_Pin GPIO_PIN_8
#define right_2_GPIO_Port GPIOD
#define MotorL2_A_Pin GPIO_PIN_11
#define MotorL2_A_GPIO_Port GPIOD
#define MotorL2_B_Pin GPIO_PIN_12
#define MotorL2_B_GPIO_Port GPIOD
#define Buzzer_Pin GPIO_PIN_7
#define Buzzer_GPIO_Port GPIOG
#define belt_motor_A_Pin GPIO_PIN_0
#define belt_motor_A_GPIO_Port GPIOD
#define belt_motor_B_Pin GPIO_PIN_1
#define belt_motor_B_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
