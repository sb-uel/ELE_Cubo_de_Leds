
#ifndef __conf_GPIO
#define __conf_GPIO

// defines
#define _ON 0
#define _OFF 1

#define GPIO_Cubo 			GPIOC
#define RCC_APB2Periph_Cubo	RCC_APB2Periph_GPIOC
#define Pin_DataBit	((uint16_t)0x0001)	//GPIO_Pin_0		0b0000_0000_0000_0001
#define Pin_Demux	((uint16_t)0x000E)	//GPIO_Pin_1_2_3	0b0000_0000_0000_1110
#define Pin_Clk		((uint16_t)0x0010)	//GPIO_Pin_4		0b0000_0000_0001_0000
#define Pin_Enable	((uint16_t)0x0020)	//GPIO_Pin_5		0b0000_0000_0010_0000

// Protótipos de função

void GPIO_Inicia(void);

#endif




