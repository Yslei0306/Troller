#include "chassis_move.h"
#include "motor.h"
#include "Global.h"
#include "pid.h"
#include "MPU_Updata.h"
//内部调用
void SetMotorCurrent(void);
void SetMotorSpeed(void);
void limitSpeed(float speeds[], uint8_t numWheels,uint8_t MAX_SPEED);

//定义
pid_t mpu6050_set;
float mpu6050_yaw_set = 0;

/*
功能：底盘控制初始化函数
*/
void chassis_move_init(void)//初始化
{
	Global.wheel_speed[0] = 0;
	Global.wheel_speed[1] = 0;
	Global.wheel_speed[2] = 0;
	Global.wheel_speed[3] = 0;
	
//	Global.control_mode = MPU6050;
	
	pid_set(&mpu6050_set,1,0,0,100,100);
}
/*
功能：底盘控制
*/
void chassis_set_speed(void)
{
	//设定值
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
		Global.set.r = pid_cal(&mpu6050_set,IMU_data.angle.yaw,mpu6050_yaw_set);//给陀螺仪的设定值
	}
	
//	if(Global.set.y < 50 && Global.set.y > -50)
//	{
//		Global.set.x = 0;
//	}
//	else if(Global.set.x < 50 && Global.set.x > -50)
//	{
//		Global.set.y = 0;
//	}
	
	SetMotorSpeed();//计算轮子转速
	limitSpeed(Global.wheel_speed, 4,100);
	
	SetMotorCurrent();//设置马达电流
}	
/*
功能：控制轮子转速，当某一轮子转速设置值超过最大限制时，降低其他轮子设置转速达到不影响底盘运动结算的效果
形参含义：
	speeds[]：传递进来的储存轮子转速的数组
	numWheels：轮子的数量
	MAX_SPEED：限制的轮子最大转速
*/
void limitSpeed(float speeds[], uint8_t numWheels,uint8_t MAX_SPEED) 
{  
    int maxSpeedWheelIndex = -1;  
    int maxSpeed = 0;  
  
    // 找到转速最快的轮子  
    for (int i = 0; i < numWheels; i++) 
	{  
        if (speeds[i] > maxSpeed) 
		{  
            maxSpeed = speeds[i];  
            maxSpeedWheelIndex = i;  
        }  
    }  
  
    // 如果转速最快的轮子超过100，限制其速度并调整其他轮子  
    if (maxSpeed > MAX_SPEED) 
	{  
        speeds[maxSpeedWheelIndex] = MAX_SPEED;  
  
        // 计算比例因子  
        float ratio = (float)MAX_SPEED / maxSpeed;  
  
        // 按比例调整其他轮子的速度  
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
功能：运动解算，将全局坐标转换为轮子的转动
*/
void SetMotorSpeed(void)
{
	Global.wheel_speed[0] = - Global.set.x + Global.set.y - Global.set.r;//左前
	Global.wheel_speed[1] = + Global.set.x + Global.set.y + Global.set.r;//右前	
	Global.wheel_speed[2] = - Global.set.x + Global.set.y + Global.set.r;//左后
	Global.wheel_speed[3] = + Global.set.x + Global.set.y - Global.set.r;//右后
}
/*
功能：将计算后的轮子转速赋值给电机来控制运动
*/
void SetMotorCurrent(void)
{
	Motor_SetCurrent(1,Global.wheel_speed[0]);
	Motor_SetCurrent(2,Global.wheel_speed[1]);
	Motor_SetCurrent(3,Global.wheel_speed[2]);
	Motor_SetCurrent(4,Global.wheel_speed[3]);
}


