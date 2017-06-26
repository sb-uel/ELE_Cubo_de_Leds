#ifndef __cubo_h
#define __cubo_h

// Pinos do Cubo
// Vcc, data_bit, CLK, demux(2), demux(1), demux(0), ENABLE, GND.
#define CUBO_DATABIT	0x01		//0b0000_0001
#define CUBO_DEMUX		0x0E		//0b0000_1110
#define CUBO_CLK		0x10		//0b0001_0000
#define CUBO_ENABLE		0x20		//0b0010_0000
#define CUBO_STATE1		0x40		//0b0100_0000
#define CUBO_STATE2		0x80		//0b1000_0000

//---O clock CLK vai ser controlado por um timer (TIM, Systick, RTC)
//---Os 3bits do demux vao selecionar a camada (8 camadas)  e devem ser incrementados (0 a 7) a
//cada 64 ciclos de clock
//---O DataBit contem o dado do estado atual (serao 512 estados) e deve ser atualizado do vetor
//cubo_layer a cada ciclo de clock
//---O Enable vai permitir a o plot da camada toda, e devera ser acionado apenas por um pulso de
//clock a cada 64 ciclos de clock

struct cubo_reg {
	unsigned char databit	: 1;
	unsigned char demux		: 3;
	unsigned char clk		: 1;
	unsigned char enable	: 1;
};

typedef struct cubo_reg cubo_r;

void atualiza_camada(cubo_r *cubo, uint8_t cubo_linha, uint8_t *nlinha, uint8_t *nbit);
// atualiza_camada (&cubo, cubo_linha(nlinha), &nlinha, &nbit);

#endif //__cubo_h
