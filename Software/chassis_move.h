#ifndef __CHASSIS_MOVE_H__
#define __CHASSIS_MOVE_H__

#include "main.h" //HAL库文件声明

extern TIM_HandleTypeDef htim2;//声明TIM2的HAL库结构体


void chassis_move_init(void);//底盘初始化
void chassis_set_speed(void);//底盘电机速度设置

#endif 

