/**
 * @file lab1.0.c
 * @brief Programa de demostración para el laboratorio 1 - LED intermitente
 *
 * @details Este programa implementa una aplicación básica que hace parpadear
 * el LED azul de la placa FM4 y alterna el estado del pin P7D en sincronía.
 * Utiliza retardos por software para establecer la temporización.
 *
 * @author Universidad de Zaragoza
 * @date Created on: 2025/07/14
 * @date Last modified: 2025/07/24 10:52:46
 */

#include <stdint.h> /**< Definiciones de tipos enteros con tamaño específico */

#include "FM4_leds_sw.h" /**< Funciones para manejo de LEDs y pulsadores  */
#include "HAL_FM4_gpio.h" /**< Funciones para acceso a pines GPIO del uP */



#define TOP (0x03FF)

void breath_rgb(const rgb_color_t color) {
    static uint32_t time_counter = 0;
    static uint16_t pwm_counter = 0;

    time_counter++;
    uint16_t sawtooth = (time_counter >> 10) & TOP;
    uint16_t triangle = (sawtooth < (TOP >> 1)) ? sawtooth : (TOP - sawtooth);
    uint16_t brightness = triangle >> 2;

    LedRGB((brightness >= pwm_counter) ? color : OFF);

    pwm_counter = (pwm_counter + 1) & TOP;
}

/**
 * @brief Función principal del programa
 *
 * @details Esta función implementa un sistema de control de LED RGB con efecto
 *          de respiración que permite cambiar entre diferentes colores usando
 *          el pulsador SW2. El LED muestra un efecto de respiración continuo
 *          que se puede ciclar entre 7 colores diferentes.
 *
 * @return int Código de retorno (nunca se alcanza debido al bucle infinito)
 *
 * @note La secuencia realizada es:
 *       1. Inicializar LEDs y pulsadores
 *       2. Establecer color inicial (AZUL)
 *       3. Bucle infinito:
 *          - Mostrar efecto de respiración con el color actual
 *          - Detectar pulsación de SW2 para cambiar color
 *          - Ciclar entre: AZUL -> CIAN -> BLANCO -> VERDE -> MAGENTA ->
 *                          -> ROJO -> AMARILLO -> AZUL
 *       4. Esperar a que se libere el pulsador antes del siguiente cambio
 */
int main(void) {

    /* Inicialización de todos los LEDs y pulsadores */
    LedsSwInit();

    static rgb_color_t led_color = BLUE;  // Color inicial del LED RGB

    /* Bucle infinito de control del LED RGB */
    while (1) {
        /* Aplicar efecto de respiración con el color actual */
        breath_rgb(led_color);

        /* Detectar pulsación del botón SW2 para cambiar color */
        if (Sw2Read() == 1) {
            while(Sw2Read() == 1);  // Esperar a que se libere el pulsador

            /* Cambiar al siguiente color en la secuencia */
            switch (led_color)
            {
                case BLUE:
                    led_color = CYAN;     // AZUL -> CIAN
                case CYAN:
                    led_color = WHITE;    // CIAN -> BLANCO
                case WHITE:
                    led_color = GREEN;    // BLANCO -> VERDE
                case GREEN:
                    led_color = MAGENTA;  // VERDE -> MAGENTA
                case MAGENTA:
                    led_color = RED;      // MAGENTA -> ROJO
                case RED:
                    led_color = YELLOW;   // ROJO -> AMARILLO
                case YELLOW:
                    led_color = BLUE;     // AMARILLO -> AZUL (reinicia el ciclo)
                default:
                    led_color = OFF;     // Valor por defecto en caso de error
            }
        }
    }
}
