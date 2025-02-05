# Temporizador de um disparo (One Shot)

## Atividade:

Com o emprego da função add_alarm_in_ms(), presente na
ferramenta Pico SDK, projete um sistema de temporização
para o acionamento de LEDs, que atua a partir do clique em um
botão (pushbutton). 

## Nesta prática, foram simulados os seguintes componentes:

1) Microcontrolador Raspberry Pi Pico W.
2) 03 LEDs (azul, vermelho e verde).
3) 03 Resistores de 330 Ω.
4) Botão (Pushbutton).

## Requisitos: 

1) Caso o usuário clique no botão (pushbutton), os três LEDs serão
ligados (todos em nível alto). A partir da primeira rotina de
atraso, ocorrerá uma mudança de estado para dois LEDs
ligados e, em seguida, apenas um.
2) O temporizador do alarme deve ser ajustado para um atraso de
3 segundos (3.000ms), entre os estados de acionamento dos
LEDs.
3) A mudança de estado dos LEDs deve ser implementa em
funções de call-back do temporizador, turn_off_callback().
4) O botão só pode alterar o estado dos LEDs quando o último LED
for desligado. Deste modo, durante a execução das rotinas de
temporização, o botão não pode iniciar uma nova chamada da
função call-back.
5) Com o emprego da Ferramenta Educacional BitDogLab, faça
um experimento com o código deste exercício utilizando o LED
RGB – GPIOs 11, 12 e 13 e o Botão A, GPIO 05.
6) Opcional: Implementar uma rotina em software para atenuação
do efeito bouncing no botão (software debounce).

## Tecnologias utilizadas:

1. Visual Studio Code;
2. Linguagem C;
3. Git e Github;
4. Wokwi.

## Simulação Wokwi Web: https://wokwi.com/projects/422011458237044737
