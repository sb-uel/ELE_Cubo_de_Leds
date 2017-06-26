#include "stm32f10x_it.h"

extern volatile uint32_t uwTick;

void SysTick_Handler(void){
	++uwTick;
}
