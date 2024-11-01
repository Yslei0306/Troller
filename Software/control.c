#include "global.h"
#include "bluetooth.h"
#include "Motor.h"
#include "chassis_move.h"
#include "control.h"

#include "MPU_Updata.h"
#include "inv_mpu.h"
#include "limit.h"

#include "STM32tim.h"

uint32_t Time_delay_press_USART2_RX_BUF = 0;

uint8_t max_x, max_y, max_r;//���������ٶ�	
uint8_t max_pitch,max_yaw,max_gripper,min_pitch,min_yaw,min_gripper;
/*
���ܣ�ȫ�����ݳ�ʼ������
*/
void Global_init(void)
{
//����	
	Global.input.x = 0;
	Global.input.y = 0;
	Global.input.r = 0;
	
//��е��
	Global.input.pitch = 0;//��ʼλ��
	Global.input.yaw = 0;
	Global.input.gripper = 0;
	
	max_pitch = 180;
	max_yaw = 180;
	max_gripper = 40;
	min_pitch = 0;
	min_yaw = 0;
	min_gripper = 0;
//����ģʽ	
	Global.control_mode = BLUETOOTH;		
}

/*
����ʾ�⣺
	
		Yǰ��
		*
		*
		*
		*
		**********X	����			      
	  R��ת

���ܣ�ң�������ƺ���
*/
int i,j;

void control_tack(void)
{
	if(USART2_RX_BUF[0]==0xA5)
	{
		if(USART2_RX_BUF[1]!=0||USART2_RX_BUF[2]!=0)
		{
			Global.input.y = data_limit((USART2_RX_BUF[1] - 50) * 2,max_y,-max_y);
			Global.input.x = data_limit((USART2_RX_BUF[2] - 50) * 2,max_r,-max_r);
			
			Global.input.r = data_limit((USART2_RX_BUF[6] - 50) * 2,max_r,-max_r);
		}
		else
		{
			Global.input.y = 0;
			Global.input.r = 0;
		}

		//��е��
		if(USART2_RX_BUF[3] == 1)
		{
			if (Get_sys_time_ms() - Time_delay_press_USART2_RX_BUF > 50)
			{
				i--;
				Global.input.pitch = data_limit(i,max_pitch,-max_pitch);
				Time_delay_press_USART2_RX_BUF = Get_sys_time_ms();
			}
		}
		else if(USART2_RX_BUF[3] == 2)
		{
			if (Get_sys_time_ms() - Time_delay_press_USART2_RX_BUF > 50)
			{
				i++;
				Global.input.pitch = data_limit(i,max_pitch,-max_pitch);
				Time_delay_press_USART2_RX_BUF = Get_sys_time_ms();
			}
		}
		else if(USART2_RX_BUF[3] == 3)
		{
			if (Get_sys_time_ms() - Time_delay_press_USART2_RX_BUF > 50)
			{
				j++;
				Global.input.yaw = data_limit(j,max_yaw,-max_yaw);
				Time_delay_press_USART2_RX_BUF = Get_sys_time_ms();
			}
			
		}
		else if(USART2_RX_BUF[3] == 4)
		{
			if (Get_sys_time_ms() - Time_delay_press_USART2_RX_BUF > 50)
			{
				j--;
				Global.input.yaw = data_limit(j,max_yaw,-max_yaw);
				Time_delay_press_USART2_RX_BUF = Get_sys_time_ms();
			}
		}
		//��צ
		 Global.input.gripper = USART2_RX_BUF[4] * 2;
		//���Ʒ�ʽ
		if(USART2_RX_BUF[5])
		{
			Global.control_mode = BLUETOOTH;
			max_y = 50;
			max_x = 50;
			max_r = 50;

		}
		else
		{
			max_y = 100;
			max_x = 100;
			max_r = 100;
			if(mpu_dmp_get_data(&IMU_data.angle.pitch, &IMU_data.angle.roll, &IMU_data.angle.yaw))
			{
			}
			else
				Global.control_mode = MPU6050;
		}
	}
	
	mpu6050_updata();//���������ݸ���

}

