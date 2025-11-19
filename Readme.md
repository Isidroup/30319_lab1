# Laboratorio 1: Introducción a la Programación de Microcontroladores

## Introducción

Este laboratorio introduce los conceptos fundamentales de la programación de
microcontroladores utilizando la placa de desarrollo Cypress FM4.
A través de ejercicios prácticos, los estudiantes aprenderán a manipular pines
GPIO, controlar LEDs, leer pulsadores y crear efectos visuales básicos.

## Objetivos

- Familiarizarse con el entorno de desarrollo para microcontroladores Cypress FM4
- Comprender la arquitectura de capas HAL (Hardware Abstraction Layer) y BSP (Board Support Package)
- Aprender a configurar y controlar pines GPIO como entradas y salidas digitales
- Implementar control básico de LEDs y lectura de pulsadores
- Crear efectos visuales utilizando técnicas de modulación por ancho de pulso (PWM) por software
- Desarrollar aplicaciones interactivas que respondan a la entrada del usuario

## Contenido del Laboratorio

### Ejercicio 1.0: LED Intermitente Básico
- Configuración básica de GPIO
- Control simple de encendido/apagado de LED
- Implementación de retardos por software
- Sincronización de múltiples salidas

### Ejercicio 1.1: LED RGB con Efecto de Respiración
- Control avanzado de LEDs RGB
- Implementación de PWM por software
- Creación de efectos de respiración suaves
- Manejo de entrada de usuario mediante pulsadores
- Ciclado entre diferentes colores

## Estructura del Proyecto

```bash
lab1/
  ├── build_keil    # Proyecto de Keil uVision5
  ├── hal/          # Hardware Abstraction Layer
  │    ├── include/ # Archivos de cabecera HAL
  │    └── src/     # Implementación HAL
  ├── bsp/          # Board Support Package
  │    ├── include/ # Archivos de cabecera BSP
  │    └── src/     # Implementación BSP
  └── src/          # Código de aplicación
       ├── lab1.0.c # Ejercicio básico
       └── lab1.1.c # Ejercicio avanzado
```


## Conceptos Clave

- **GPIO (General Purpose Input/Output)**: Configuración y control de pines digitales
- **PWM por Software**: Generación de señales PWM mediante código
- **Polling**: Técnica de lectura continua de entradas
- **Debouncing**: Eliminación de rebotes en pulsadores
- **Estado estático**: Uso de variables estáticas para mantener estado entre llamadas

## Requisitos Previos

- Conocimientos básicos de programación en C
- Comprensión de sistemas digitales y electrónica básica
- Familiaridad con conceptos de temporización en sistemas embebidos

Este laboratorio proporciona una base sólida para el desarrollo de aplicaciones más complejas en microcontroladores y sienta las bases para los laboratorios
