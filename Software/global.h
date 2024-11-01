/**
 * @file global.h
 * @author 
 * @brief 全局状态机
 * @version 0.1
 * @date 
 *
 * @copyright 
 *
 */
#include "stdint.h"
 
#define __GLOBAL_H__
#ifdef __GLOBAL_H__

struct GlobalStatus_t
{
//    float max_x, max_y, max_r;//底盘最大分速度	
//	float max_pitch,max_yaw,max_gripper;
	float wheel_speed[4];//轮子转速

	 enum control_mode_e//夹爪
    {
        BLUETOOTH  = 0,//开
        MPU6050,
    } control_mode;	
    struct
    {
		float x, y, r; // 底盘移动
		float pitch,yaw,gripper;//机械臂	+夹爪	
    } input;
	 struct
    {
		float x, y, r; // 底盘移动
		float pitch,yaw,gripper;//机械臂	+夹爪	
    }set;

};

extern struct GlobalStatus_t Global;


#endif
// end of file

