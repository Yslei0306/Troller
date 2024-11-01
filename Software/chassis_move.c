#include "chassis_move.h"
#include "motor.h"
#include "Global.h"
#include "pid.h"
#include "MPU_Updata.h"
//�ڲ�����
void SetMotorCurrent(void);
void SetMotorSpeed(void);
void limitSpeed(float speeds[], uint8_t numWheels,uint8_t MAX_SPEED);

//����
pid_t mpu6050_set;
float mpu6050_yaw_set = 0;

/*
���ܣ����̿��Ƴ�ʼ������
*/
void chassis_move_init(void)//��ʼ��
{
	Global.wheel_speed[0] = 0;
	Global.wheel_speed[1] = 0;
	Global.wheel_speed[2] = 0;
	Global.wheel_speed[3] = 0;
	
//	Global.control_mode = MPU6050;
	
	pid_set(&mpu6050_set,1,0,0,100,100);
}
/*
���ܣ����̿���
*/
void chassis_set_speed(void)
{
	//�趨ֵ
	if(Global.control_mode == BLUETOOTH)
	{
		Global.set.y = Global.input.y;
		Global.set.x = Global.input.x;
		Global.set.r = Global.input.r;
		
		mpu6050_yaw_set = IMU_data.angle.yaw;
	}
	else if(Global.control_mode == MPU6050)
	{		
		mpu6050_yaw_set += Global.input.r/200;
		
		Global.set.y = Global.input.y;
		Global.set.r = pid_cal(&mpu6050_set,IMU_data.angle.yaw,mpu6050_yaw_set);//�������ǵ��趨ֵ
	}
	
//	if(Global.set.y < 50 && Global.set.y > -50)
//	{
//		Global.set.x = 0;
//	}
//	else if(Global.set.x < 50 && Global.set.x > -50)
//	{
//		Global.set.y = 0;
//	}
	
	SetMotorSpeed();//��������ת��
	limitSpeed(Global.wheel_speed, 4,100);
	
	SetMotorCurrent();//����������
}	
/*
���ܣ���������ת�٣���ĳһ����ת������ֵ�����������ʱ������������������ת�ٴﵽ��Ӱ������˶������Ч��
�βκ��壺
	speeds[]�����ݽ����Ĵ�������ת�ٵ�����
	numWheels�����ӵ�����
	MAX_SPEED�����Ƶ��������ת��
*/
void limitSpeed(float speeds[], uint8_t numWheels,uint8_t MAX_SPEED) 
{  
    int maxSpeedWheelIndex = -1;  
    int maxSpeed = 0;  
  
    // �ҵ�ת����������  
    for (int i = 0; i < numWheels; i++) 
	{  
        if (speeds[i] > maxSpeed) 
		{  
            maxSpeed = speeds[i];  
            maxSpeedWheelIndex = i;  
        }  
    }  
  
    // ���ת���������ӳ���100���������ٶȲ�������������  
    if (maxSpeed > MAX_SPEED) 
	{  
        speeds[maxSpeedWheelIndex] = MAX_SPEED;  
  
        // �����������  
        float ratio = (float)MAX_SPEED / maxSpeed;  
  
        // �����������������ӵ��ٶ�  
        for (int i = 0; i < numWheels; i++) 
		{  
            if (i != maxSpeedWheelIndex) 
			{  
                speeds[i] = (int)(speeds[i] * ratio);  
            }  
        }  
    }  
}  
/*
���ܣ��˶����㣬��ȫ������ת��Ϊ���ӵ�ת��
*/
void SetMotorSpeed(void)
{
	Global.wheel_speed[0] = - Global.set.x + Global.set.y - Global.set.r;//��ǰ
	Global.wheel_speed[1] = + Global.set.x + Global.set.y + Global.set.r;//��ǰ	
	Global.wheel_speed[2] = - Global.set.x + Global.set.y + Global.set.r;//���
	Global.wheel_speed[3] = + Global.set.x + Global.set.y - Global.set.r;//�Һ�
}
/*
���ܣ�������������ת�ٸ�ֵ������������˶�
*/
void SetMotorCurrent(void)
{
	Motor_SetCurrent(1,Global.wheel_speed[0]);
	Motor_SetCurrent(2,Global.wheel_speed[1]);
	Motor_SetCurrent(3,Global.wheel_speed[2]);
	Motor_SetCurrent(4,Global.wheel_speed[3]);
}


