/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
	extern int8_t bluetooth_key;
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
#define Motor1_Pin GPIO_PIN_6
#define Motor1_GPIO_Port GPIOA
#define Motor2_Pin GPIO_PIN_7
#define Motor2_GPIO_Port GPIOA
#define Motor3_Pin GPIO_PIN_0
#define Motor3_GPIO_Port GPIOB
#define Motor4_Pin GPIO_PIN_1
#define Motor4_GPIO_Port GPIOB
#define Servos3_Pin GPIO_PIN_10
#define Servos3_GPIO_Port GPIOB
#define Servos4_Pin GPIO_PIN_11
#define Servos4_GPIO_Port GPIOB
#define IN5_Pin GPIO_PIN_12
#define IN5_GPIO_Port GPIOB
#define IN6_Pin GPIO_PIN_13
#define IN6_GPIO_Port GPIOB
#define IN7_Pin GPIO_PIN_14
#define IN7_GPIO_Port GPIOB
#define IN8_Pin GPIO_PIN_15
#define IN8_GPIO_Port GPIOB
#define IN1_Pin GPIO_PIN_9
#define IN1_GPIO_Port GPIOA
#define IN2_Pin GPIO_PIN_10
#define IN2_GPIO_Port GPIOA
#define IN3_Pin GPIO_PIN_11
#define IN3_GPIO_Port GPIOA
#define IN4_Pin GPIO_PIN_12
#define IN4_GPIO_Port GPIOA
#define Servos1_Pin GPIO_PIN_15
#define Servos1_GPIO_Port GPIOA
#define Servos2_Pin GPIO_PIN_3
#define Servos2_GPIO_Port GPIOB
#define MPU6050_SCL_Pin GPIO_PIN_8
#define MPU6050_SCL_GPIO_Port GPIOB
#define MPU6050_SDA_Pin GPIO_PIN_9
#define MPU6050_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
