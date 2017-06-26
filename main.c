#include "stm32f10x_conf.h"
#include "stm32f10x.h"
#include "cubo.h"
#include "conf_GPIO.h"
#include "SysTick.h"
#include "stm32f10x_it.h"

cubo_r cubo = { 0 };
uint8_t cubo_linha[8] = {0xFF,0xFF,0,0,0,0,0,0};
uint8_t nlinha = 0;
uint8_t nbit = 0;
uint32_t timer = 0;
uint8_t clkant = 0;
uint8_t clkatu = 0;

int main(void) {
	GPIO_Inicia();
	SysTick_Init();
	while (1) {
		clkant = clkatu;
		clkatu = cubo.clk;
		if (_Tick_is_Up == DelayTick(&timer)) {
			DelayTick_Start(&timer,1);
			cubo.clk = !(cubo.clk);
			GPIO_WriteBit(GPIO_Cubo, Pin_Clk, cubo.clk);
		}

		if (clkatu == 1 && clkant == 0) {
			atualiza_camada(&cubo, cubo_linha[nlinha], &nlinha, &nbit);
			GPIO_WriteBit(GPIO_Cubo, Pin_DataBit, cubo.databit);
			GPIO_WriteBit(GPIO_Cubo, Pin_Enable, !cubo.enable);
			GPIO_WriteBit(GPIO_Cubo, Pin_Demux0, cubo.demux&0x1);
			GPIO_WriteBit(GPIO_Cubo, Pin_Demux1, cubo.demux&0x2);
			GPIO_WriteBit(GPIO_Cubo, Pin_Demux2, cubo.demux&0x4);
		}

	}
	return 0;
}
