/**
 * @author Koala
 * @brief header of motor.c
 * @version 0.1
 * @date 2024-10-1
 * @copyright The code copyright belongs to Koala(Shunlei Yu 2337248447@qq.com)
 */
#ifndef __MOTOR_H__	
#define __MOTOR_H__

#include "main.h" //HAL库文件声明
#include "tim.h"

//L为左轮，R为右轮
//前轮
#define LF_GO 	    HAL_GPIO_WritePin(IN1_GPIO_Port,  IN1_Pin,  GPIO_PIN_SET);     HAL_GPIO_WritePin(IN2_GPIO_Port,  IN2_Pin,  GPIO_PIN_RESET)
#define RF_GO	    HAL_GPIO_WritePin(IN3_GPIO_Port,  IN3_Pin,  GPIO_PIN_SET);     HAL_GPIO_WritePin(IN4_GPIO_Port,  IN4_Pin,  GPIO_PIN_RESET)

#define LF_BACK 	HAL_GPIO_WritePin(IN1_GPIO_Port,  IN1_Pin,  GPIO_PIN_RESET);   HAL_GPIO_WritePin(IN2_GPIO_Port,  IN2_Pin,  GPIO_PIN_SET)
#define RF_BACK		HAL_GPIO_WritePin(IN3_GPIO_Port,  IN3_Pin,  GPIO_PIN_RESET);   HAL_GPIO_WritePin(IN4_GPIO_Port,  IN4_Pin,  GPIO_PIN_SET)
//后轮
#define LB_GO 	    HAL_GPIO_WritePin(IN5_GPIO_Port,  IN5_Pin,  GPIO_PIN_RESET);     HAL_GPIO_WritePin(IN6_GPIO_Port,  IN6_Pin,  GPIO_PIN_SET)
#define RB_GO	    HAL_GPIO_WritePin(IN7_GPIO_Port,  IN7_Pin,  GPIO_PIN_RESET);     HAL_GPIO_WritePin(IN8_GPIO_Port,  IN8_Pin,  GPIO_PIN_SET)

#define LB_BACK 	HAL_GPIO_WritePin(IN5_GPIO_Port,  IN5_Pin,  GPIO_PIN_SET);   HAL_GPIO_WritePin(IN6_GPIO_Port,  IN6_Pin,  GPIO_PIN_RESET)
#define RB_BACK		HAL_GPIO_WritePin(IN7_GPIO_Port,  IN7_Pin,  GPIO_PIN_SET);   HAL_GPIO_WritePin(IN8_GPIO_Port,  IN8_Pin,  GPIO_PIN_RESET)

/*外部调用*/
void Motor_Init(void);

void Motor_SetCurrent(uint8_t PIN,int8_t Speed);

#endif 
