#ifndef __SysTick
#define __SysTick

#include "stm32f10x_conf.h"
#include "cubo.h"

typedef enum
{
	_Tick_is_Counting = 0,
	_Tick_is_Up
}DelayTick_State;


void SysTick_Init (void);
uint32_t Get_Tick (void);
void DelayTick_Start (uint32_t *Timer_x, uint32_t Time_ms);
DelayTick_State DelayTick (uint32_t *Timer_x);
void Sq_Wave(GPIO_TypeDef* porta, uint16_t pino, uint32_t* timer_alvo, uint32_t tempo, cubo_r *cubo);

#endif
