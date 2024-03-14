/*
 * Led.c
 *
 *  Created on: Mar 14, 2024
 *      Author: jingzhan96
 */

#include "Led.h"
#include "stm32l0xx_ll_tim.h"

typedef struct
{
	int current_v;
	int increment_v;
} Led_info;

static Led_info info = {.current_v = 0, .increment_v = 1};

// démarrer le timer
void LedStart(void)
{
	LL_TIM_EnableCounter(TIM2);
	LL_TIM_CC_EnableChannel(TIM2,LL_TIM_CHANNEL_CH1);
}

//Configure le rapport cyclique de la pwm entre 0 et 255
void LedSetValue(uint8_t value)
{
	LL_TIM_OC_SetCompareCH1(TIM2,(uint32_t)value);
	info.current_v = value;
}

// À chaque appel, cette fonction incrémente la luminosité de la LED
// Arrivé à la valeur maximale, chaque appel décrémente la LED
void LedPulse(void)
{
	info.current_v += info.increment_v;
	if(info.current_v == 255) info.increment_v = -1;
	else if (info.current_v == 0) info.increment_v = 1;
	LedSetValue(info.current_v);
}
