/*
 * TimeBase.c
 *
 *  Created on: Mar 14, 2024
 *      Author: jingzhan96
 */


#include "TimeBase.h"
#include "Led.h"
#include "stm32l0xx_ll_tim.h"

void TimeBaseStartIT(void)
{
	LL_TIM_EnableCounter(TIM21);
	LL_TIM_EnableIT_UPDATE(TIM21);
}
