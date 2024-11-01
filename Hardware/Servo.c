/**
 * @author Koala
 * @brief servo init program
 * @version 0.1
 * @date 2024-10-1
 * @copyright The code copyright belongs to Koala(Shunlei Yu 2337248447@qq.com)
 */
 
#include "Servo.h"
/*
舵机初始化函数
占用定时器2的四个通道
*/
void Servo_Init(void)
{
/*开启控制舵机的定时器通道*/
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);  //开启定时器2通道1
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);  
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
	
}
/*
180度舵机控制函数
Channel： 通道1-4 对应 舵机1-4 
Angle ：舵机角度 0-180
*/

void ServoCtrl(uint8_t Channel,uint8_t Angle)
{
	short compare;
	compare = 500 + (float)Angle / 180 * 2000; //舵机角度PWM转换公式
	switch(Channel)
	  {
			case 1:            //电机1正转              
				 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,compare); 
				break;
			case 2:
				__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,compare); 
				break;
			case 3:
				__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,compare); 
				break;
			case 4:
				__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,compare); 
				break;
    }
	
}

/*
180度舵机控制函数，可控速度
Channel： 通道1-4 对应 舵机1-4 
Angle ：舵机角度 0-180
Speed : 舵机转动的速度（不用太大，一百以内就行）
*/

void ServoCtrl2(uint8_t Channel,float Angle,short Speed)   //可设置速度型,如果有需要可以使用,不太好用
{
	
	float compare=0;
	
	compare = 500+(Angle*2000/180);
	for(short i=0;i<compare;i += Speed)
	{
		if      (Channel==1)     __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,i); 
		else	if(Channel==2) 		 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,i); 
		else	if(Channel==3)     __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,i); 
		else	if(Channel==4)		 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,i); 
		HAL_Delay(1);	
	}
	
}
