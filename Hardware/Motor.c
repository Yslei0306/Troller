/**
 * @author Koala
 * @brief motor init program
 * @version 0.1
 * @date 2024-10-1
 * @copyright The code copyright belongs to Koala(Shunlei Yu 2337248447@qq.com)
 */
#include "motor.h"

/*
С����ʼ������
ռ�ö�ʱ��3���ĸ�ͨ��
*/
void Motor_Init(void)
{
	/*�������Ƶ���Ķ�ʱ��ͨ��*/
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);  //������ʱ��3ͨ��1
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);  
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);

}
/*
С�����ƺ���
Motor�� ������1-4 
Speed: ������ٶ�
*/

void Motor_SetCurrent(uint8_t Motor,int8_t Speed)
{
	if(Speed > 100)
	{
		Speed = 100;
	}
	else if(Speed < -100)
	{
		Speed = -100;
	}
	int16_t compare = Speed * 200;
	switch (Motor)
	{
		case 1:
			if(Speed >= 0)
			{		
				LF_GO;				
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,compare); 
			}
			else	
			{
				LF_BACK;
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,-compare);
			}
			break;
		case 2:
			if(Speed >= 0)
			{		
				RF_GO;				
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,compare); 
			}
			else	
			{
				RF_BACK;
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,-compare);
			}
			break;
		case 3:
			if(Speed >= 0)
			{		
				LB_GO;				
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,compare); 
			}
			else	
			{
				LB_BACK;
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,-compare);
			}
			break;
		case 4:
			if(Speed >= 0)
			{		
				RB_GO;				
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,compare); 
			}
			else	
			{
				RB_BACK;
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,-compare);
			}
			break;
	}
}


