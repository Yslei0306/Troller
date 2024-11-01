#include "RGB.h"
#include "WS2812.h"

void RGB_Init(void)
{


}
void set_RGB(void)
{
	WS28xx.SetALLColor_RGB (255,0,0);//整体红色
    WS28xx.show ();
    HAL_Delay (200);
    WS28xx.SetALLColor_RGB (0,255,0);//整体绿色
    WS28xx.show ();
    HAL_Delay (200);
    WS28xx.SetALLColor_RGB (0,0,255);//整体蓝色
    WS28xx.show ();
    HAL_Delay (200);	
    WS28xx.SetALLColor_RGB (0,0,0);  //集体熄灭
    WS28xx.show ();
	WS28xx.SetPixelColor_RGB(0,0,0,255);//第一个亮蓝灯
	WS28xx.show ();
	HAL_Delay (200);		
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(1,0,0,255);//第二个亮绿灯 	
	WS28xx.show ();
	HAL_Delay (200);	
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(2,0,0,255);//第三个亮蓝灯 	
	WS28xx.show ();
	HAL_Delay (200);
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(2,0,0,255);//第四个亮蓝灯 	
	WS28xx.show ();
	HAL_Delay (200);
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(4,0,0,255);//第五个亮蓝灯 	
	WS28xx.show ();
	HAL_Delay (200);			
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(5,0,0,255);//第六个亮蓝灯 	
	WS28xx.show ();
	HAL_Delay (200);	
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(6,0,0,255);//第七个亮蓝灯 	
	WS28xx.show ();
	HAL_Delay (200);	
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(7,0,0,255);//第八个亮蓝灯 	
	WS28xx.show ();
	HAL_Delay (200);		


}

