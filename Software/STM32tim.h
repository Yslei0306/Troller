#ifndef __STM32TIM_H_
#define __STM32TIM_H_

#include "stm32f1xx_hal.h"


uint32_t Get_sys_time_ms(void);

float Get_sys_time_s(void);
void TIM_count_100KHz(void);
uint32_t Get_sys_time_us(void);
#endif
