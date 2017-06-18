#include "stm32f10x_conf.h"
#include "cubo.h"

void atualiza_camada(cubo_r *cubo, uint8_t cubo_linha, uint8_t *nlinha, uint8_t *nbit){
	if(cubo->enable) cubo->enable = 0; 
 	cubo->demux = *nlinha;
	
	if (7 == *nbit){
		*nbit = 0;
		if(7 == *nlinha){
			*nlinha = 0;
			cubo->enable = 1;
		}
		else	(*nlinha)++;
	}
	else (*nbit)++;
}
