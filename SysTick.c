#include "SysTick.h"

volatile uint32_t uwTick=0;
extern uint32_t SystemCoreClock;

// Inicia o SysTick e configura sua interrup��o para 1 ms
// A cada 1 ms o contador universal uwTick ser� atualizado
// pela rotina de interrup��o SysTick_Handler()
void SysTick_Init (void) {
	// Inicia o SysTick dar reload a cada 1 ms
	SysTick_Config(SystemCoreClock / 1000);
	// Configura prioridade de grupo 4, ou seja, 3 bits de preemp��o e 1 bit de sub-prioridade
	NVIC_SetPriorityGrouping(0x4);
	// 3 bits para preemp��o (xxx0) e 1 bit de sub-prioridade (000x),
	// pois a prioridade de grupo foi configurada como 4
	// Ver tab.7.6 do livro ARM Cortex - 3a ed - Yiu
	NVIC_SetPriority(SysTick_IRQn, 0x0); // Maior prioridade poss�vel
	// Liga a baga�a
	//NVIC_EnableIRQ(SysTick_IRQn);
}

// Fun��o Get_Tick();
// Retorna um contador universal uwTick de 32bits
// Este contador � incrementado a cada 1 ms
// Serve para gerar uma base de tempo para as aplica��es
uint32_t Get_Tick (void) {
	return uwTick;
}

void DelayTick_Start (uint32_t *Timer_x, uint32_t Time_ms) {
	*Timer_x = Time_ms + Get_Tick();
}

DelayTick_State DelayTick (uint32_t *Timer_x) {
	if ( ( (int32_t)(Get_Tick() - *Timer_x) ) >= 0 ) {
		return _Tick_is_Up;
	}
	else {
		return _Tick_is_Counting;
	}
}

void Sq_Wave(GPIO_TypeDef* porta, uint16_t pino, uint32_t* timer_alvo, uint32_t tempo, cubo_r *cubo) {
	if (_Tick_is_Up == DelayTick(timer_alvo)) {
		DelayTick_Start(timer_alvo, tempo);
		cubo->clk = GPIO_ReadOutputDataBit(porta,pino)^1;
		GPIO_WriteBit(porta, pino, cubo->clk);
	}
}


