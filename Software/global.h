/**
 * @file global.h
 * @author 
 * @brief ȫ��״̬��
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
//    float max_x, max_y, max_r;//���������ٶ�	
//	float max_pitch,max_yaw,max_gripper;
	float wheel_speed[4];//����ת��

	 enum control_mode_e//��צ
    {
        BLUETOOTH  = 0,//��
        MPU6050,
    } control_mode;	
    struct
    {
		float x, y, r; // �����ƶ�
		float pitch,yaw,gripper;//��е��	+��צ	
    } input;
	 struct
    {
		float x, y, r; // �����ƶ�
		float pitch,yaw,gripper;//��е��	+��צ	
    }set;

};

extern struct GlobalStatus_t Global;


#endif
// end of file

