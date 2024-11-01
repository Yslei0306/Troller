/**
 * @author Koala
 * @brief robot arm init program
 * @version 0.1
 * @date 2024-10-1
 * @copyright The code copyright belongs to Koala(Shunlei Yu 2337248447@qq.com)
 */
#include "robot_arm.h"
#include "Servo.h"
#include "Global.h"


void robot_arm_init(void)
{

}
void robot_arm_set(void)
{
	ServoCtrl(1,Global.input.pitch);
	ServoCtrl(2,Global.input.yaw);
	ServoCtrl(3,Global.input.gripper);
}	

