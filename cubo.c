#include "stm32f10x_conf.h"
#include "cubo.h"

void atualiza_camada(cubo_r *cubo, uint8_t cubo_linha, uint8_t *nlinha, uint8_t *nbit){
// 	cubo->demux = *nlinha;
	cubo->databit=cubo_linha&(1<<(*nbit));
	uint8_t demux=cubo->demux;
	if(cubo->enable) cubo->enable = 0;
	if (7 == *nbit){
		*nbit = 0;
		if(7 == *nlinha){
			*nlinha = 0;
			cubo->enable = 1;
			if(7 == demux){
				demux = 0;

			}
			else{
				demux ++;
			}
		}
		else	(*nlinha)++;
	}
	else (*nbit)++;
	cubo->demux=demux;
}
