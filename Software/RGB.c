#include "RGB.h"
#include "WS2812.h"

void RGB_Init(void)
{


}
void set_RGB(void)
{
	WS28xx.SetALLColor_RGB (255,0,0);//�����ɫ
    WS28xx.show ();
    HAL_Delay (200);
    WS28xx.SetALLColor_RGB (0,255,0);//������ɫ
    WS28xx.show ();
    HAL_Delay (200);
    WS28xx.SetALLColor_RGB (0,0,255);//������ɫ
    WS28xx.show ();
    HAL_Delay (200);	
    WS28xx.SetALLColor_RGB (0,0,0);  //����Ϩ��
    WS28xx.show ();
	WS28xx.SetPixelColor_RGB(0,0,0,255);//��һ��������
	WS28xx.show ();
	HAL_Delay (200);		
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(1,0,0,255);//�ڶ������̵� 	
	WS28xx.show ();
	HAL_Delay (200);	
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(2,0,0,255);//������������ 	
	WS28xx.show ();
	HAL_Delay (200);
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(2,0,0,255);//���ĸ������� 	
	WS28xx.show ();
	HAL_Delay (200);
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(4,0,0,255);//����������� 	
	WS28xx.show ();
	HAL_Delay (200);			
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(5,0,0,255);//������������ 	
	WS28xx.show ();
	HAL_Delay (200);	
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(6,0,0,255);//���߸������� 	
	WS28xx.show ();
	HAL_Delay (200);	
	WS28xx.SetALLColor_RGB (0,0,0);
	WS28xx.SetPixelColor_RGB(7,0,0,255);//�ڰ˸������� 	
	WS28xx.show ();
	HAL_Delay (200);		


}

