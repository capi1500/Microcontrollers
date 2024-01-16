#ifndef PERIPHERY_H
#define PERIPHERY_H

#include <gpio.h>
#include <stdbool.h>

typedef struct {
    GPIO_TypeDef* GPIO;
    uint8_t pin;
    uint32_t mask;
    bool enabled_state;

    bool state;
} Periphery;

// Inicjalizacja struktury wyprowadzenia
void periphery_init(Periphery* periphery, GPIO_TypeDef* GPIO, uint8_t pin, bool enabled_state);

// Ustawienie stanu na wyprowadzeniu
void periphery_set(Periphery* periphery, bool value);

// Odczyt stanu z wyprowadzenia
bool periphery_read_state(Periphery* periphery);

#endif //PERIPHERY_H
