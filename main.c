#include "stm32f10x_conf.h"
#include "stm32f10x.h"
#include "cubo.h"
#include "conf_GPIO.h"

int main(void){
	cubo_r cubo = {0};
	uint8_t cubo_linha[8] = {0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81};
	uint8_t nlinha = 0;
	uint8_t nbit = 0;
	uint32_t timer = 0;
	SysTick_Init();
	GPIO_Inicia();
    while(1){
    	Sq_Wave(GPIO_Cubo, Pin_Clk, &timer, 1000, &cubo);
    	//GPIO_WriteBit(GPIO_Cubo, Pin_DataBit, cubo);
    	atualiza_camada(&cubo, cubo_linha[nlinha], &nlinha, &nbit);
    }
    return 0;
}
