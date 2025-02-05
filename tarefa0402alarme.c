#include "pico/stdlib.h"
#include <stdio.h>

// Definição dos pinos dos LEDs e do botão
#define LED_BLUE 11     // LED azul no pino 11
#define LED_RED 12      // LED vermelho no pino 12
#define LED_GREEN 13    // LED verde no pino 13
#define BUTTON 5        // Botão no pino 5
#define DEBOUNCE_DELAY 50 // debounce 50 milissegundos

// Estados dos LEDs
typedef enum {
    ALL_ON,
    TWO_ON,
    ONE_ON,
    ALL_OFF
} LedState;

// Variável global para armazenar o estado atual dos LEDs
LedState current_led_state = ALL_OFF;

// Função de callback do temporizador
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    switch (current_led_state) {
        case ALL_ON:
            current_led_state = TWO_ON;
            gpio_put(LED_BLUE, 0); // Desliga o LED azul
            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            break;
        case TWO_ON:
            current_led_state = ONE_ON;
            gpio_put(LED_RED, 0); // Desliga o LED vermelho
            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            break;
        case ONE_ON:
            current_led_state = ALL_OFF;
            gpio_put(LED_GREEN, 0); // Desliga o LED verde
            break;
        default:
            break;
    }
    return 0;
}

int main() {
    // Inicializa a comunicação serial (para debug)
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Configura o pino do botão como entrada
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    // Loop principal
    while (true) {
        if (gpio_get(BUTTON) == 0) {
            if (gpio_get(BUTTON) == 0 && current_led_state == ALL_OFF) {
                // Liga todos os LEDs
                gpio_put(LED_BLUE, 1);
                gpio_put(LED_RED, 1);
                gpio_put(LED_GREEN, 1);
                current_led_state = ALL_ON;

                // Inicia o temporizador para desligamento
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }
    }

    return 0;
}