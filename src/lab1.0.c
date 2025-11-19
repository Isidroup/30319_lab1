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
 * @date Last modified: 2025/07/24 20:36:24
 */

#include <stdint.h>        /**< Definiciones de tipos enteros con tamaño específico */

#include "HAL_FM4_gpio.h" /**< Funciones para acceso a pines GPIO del microcontrolador */
#include "FM4_leds_sw.h"  /**< Funciones para manejo de LEDs y pulsadores de la placa */


/**
 * @brief Implementa un retardo por software
 *
 * @details Esta función crea un retardo bloqueante mediante un bucle vacío.
 * El tiempo de espera depende de la frecuencia del procesador donde se ejecute.
 * El factor 100 está calibrado para el hardware específico.
A *
 * @param ms Tiempo de espera en milisegundos
 *
 * @warning Esta función es bloqueante y consumirá CPU durante toda la espera
 */
void custom_delay(uint32_t ms) {
    volatile uint32_t delay_counter = 0;
    uint32_t target = ms * 100;

    while(delay_counter < target) {
        delay_counter = delay_counter + 1;
    }
}


/**
 * @brief Función principal del programa
 *
 * @details Esta función inicializa los pines GPIO necesarios y ejecuta un bucle
 * infinito que hace parpadear el LED azul y alterna el estado del pin P7D.
 * El ciclo de parpadeo tiene un periodo de aproximadamente 1 segundo
 * (500ms encendido, 500ms apagado).
 *
 * @return int Código de retorno (nunca se alcanza debido al bucle infinito)
 *
 * @note La secuencia realizada es:
 *       1. Configurar P7D como salida
 *       2. Inicializar LEDs y pulsadores
 *       3. Entrar en bucle infinito de parpadeo
 */
int main(void) {
    /* Configuración del pin P7D como salida digital */
    GPIO_ChannelMode(P7D, GPIO_OUTPUT)

    /* Inicialización de todos los LEDs y pulsadores */
    LedsSwInit();

    /* Bucle infinito */
    while (1) {
        /* Encender LED azul y establecer P7D en alto */
        LedON(LED_AZUL);
        GPIO_ChannelWrite(P7D, GPIO_HIGH);
        custom_delay(500);  /* Esperar 500ms */

        /* Apagar LED azul y establecer P7D en bajo */
        LedOFF(LED_AZUL);
        GPIO_ChannelWrite(P7D, GPIO_LOW);
        custom_delay(500);  /* Esperar 500ms */

    }
}
