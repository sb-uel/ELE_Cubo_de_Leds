# **ELE_Cubo_de_Leds**
> O *Hardware* está pronto, mas a biblioteca *cubo.h* ainda está em desenvolvimento.

## Descrição Geral
O projeto se consiste em um cubo de leds de dimensões 8x8x8 preparado como periférico para usar com um microcontrolador genérico.
Os sinais de entrada são:
* DataBit (1bit) - Contém o dado binário a ser exibido em um LED.
* Demux   (3bits) - Controla a linha a partir de um Demultiplixeador de 3x8.
* CLK     (1bit) - O clock de controle, em 30kHz para varredura.
* Enable  (1bit) - Bit de Enable dos chips para habilitar a visualização.
Além dos pinos de alimentação, com GND e VCC = 5V (Tecnologia TTL), totalizando em 8 pinos para o *hardware* de controle do cubo.

## *Hardware*

O hardware consiste em um demux 3x8( 74HC138N) que seleciona as camadas do cubo e 8 74HC164( Shift Register) em cascata que envia o dado para a camada selecionada a cada ciclo de clock, ao todo serão 64 ciclos de clock por camada. Como as saídas do demux8 são barradas foi usado 2 74LS14( porta NOT) para inverter a saída e enviar para 8 transistores 2N3904 que controlam as camadas.

## Biblioteca *cubo.h*
* struct  cubo_reg é um bit field para conter os sinais de controle do cubo.
* *void atualiza_camada* é uma função para atualizar uma camada completa para cada ciclo do clock de controle.
A função atualiza cada bit em um ciclo de clock, até varrer toda uma linha, e depois varre cada linha até completar uma camada de 64 bits. Ao final do 64o bit, atualiza o enable para acionar a camada toda.
