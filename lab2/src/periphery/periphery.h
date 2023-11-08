#ifndef PERIPHERY_H
#define PERIPHERY_H

#include <gpio.h>
#include "../types.h"

typedef struct {
    GPIO_TypeDef* GPIO;
    uint8_t pin;
    uint32_t mask;
    bool enabled_state;

    bool state;
} Periphery;

void periphery_init(Periphery* periphery, GPIO_TypeDef* GPIO, uint8_t pin, bool enabled_state);

void periphery_set(Periphery* periphery, bool value);
void periphery_toggle(Periphery* periphery);

bool periphery_is_on(Periphery* periphery);
bool periphery_is_off(Periphery* periphery);

bool periphery_read_state(Periphery* periphery);
bool periphery_read_state_is_changed(Periphery* periphery);

#endif //PERIPHERY_H
