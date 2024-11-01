/**
 * @author Koala
 * @brief header of servo.c
 * @version 0.1
 * @date 2024-10-1
 * @copyright The code copyright belongs to Koala(Shunlei Yu 2337248447@qq.com)
 */
#ifndef _SERVO_H
#define _SERVO_H

#include "tim.h"



//外部调用

void Servo_Init(void);

void ServoCtrl(uint8_t Channel,uint8_t Angle);

void ServoCtrl2(uint8_t Channel,float Angle,short Speed);
#endif

