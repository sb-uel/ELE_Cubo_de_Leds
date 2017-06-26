
#ifndef __conf_GPIO
#define __conf_GPIO

// defines
#define _ON 0
#define _OFF 1

#define GPIO_Cubo 			GPIOC
#define RCC_APB2Periph_Cubo	RCC_APB2Periph_GPIOC
#define Pin_DataBit	GPIO_Pin_0		//0b0000_0000_0000_0001
#define Pin_Demux0	GPIO_Pin_1		//0b0000_0000_0000_0010
#define Pin_Demux1	GPIO_Pin_2		//0b0000_0000_0000_0100
#define Pin_Demux2	GPIO_Pin_3		//0b0000_0000_0000_1000
#define Pin_Clk		GPIO_Pin_4		//0b0000_0000_0001_0000
#define Pin_Enable	GPIO_Pin_5		//0b0000_0000_0010_0000

// Protótipos de função

void GPIO_Inicia(void);

#endif




