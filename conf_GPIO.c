#include "conf_GPIO.h"
#include "stm32f10x_conf.h"

void GPIO_Inicia(void) {
	// Liga os clocks da GPIOC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_Cubo, ENABLE);

	GPIO_InitTypeDef GPIO_Type;

//	GPcoisas.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPcoisas.GPIO_Speed = GPIO_Speed_50MHz;
//	GPcoisas.GPIO_Pin = PINO_PB_PV;
//
//	GPIO_Init(GPIO_PB_PV, &GPcoisas); // Configura PA0 como pino de entrada

	GPIO_Type.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_Type.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Type.GPIO_Pin = Pin_DataBit|Pin_Demux0|Pin_Demux1|Pin_Demux2|Pin_Clk|Pin_Enable;

	GPIO_Init(GPIO_Cubo, &GPIO_Type); // Configura PC12 como pino de sa�da OD
	GPIO_Write(GPIO_Cubo, 0x00);
	GPIO_Write(GPIO_Cubo, 0x00);
	GPIO_Write(GPIO_Cubo, 0x00);
	GPIO_Write(GPIO_Cubo, 0x00);
	GPIO_Write(GPIO_Cubo, 0x00);
	GPIO_Write(GPIO_Cubo, 0x00);
	GPIO_Write(GPIO_Cubo, 0x00);
	GPIO_Write(GPIO_Cubo, 0x00);
}
