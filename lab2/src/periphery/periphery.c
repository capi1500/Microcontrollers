#include "periphery.h"

void periphery_init(Periphery* periphery, GPIO_TypeDef* GPIO, uint8_t pin, bool enabled_state) {
    periphery->GPIO = GPIO;
    periphery->pin = pin;
    periphery->mask = (1 << pin);
    periphery->enabled_state = enabled_state;
    periphery->state = false;
}

void periphery_set(Periphery* periphery, bool value) {
    // 1 && 0
    // 0 && 1
    if (periphery->enabled_state ^ value)
        periphery->GPIO->BSRR = 1 << periphery->pin;
    // 1 && 1
    // 0 && 0
    else
        periphery->GPIO->BSRR = 1 << (periphery->pin + 16);
    periphery->state = value;
}

void periphery_toggle(Periphery* periphery) {
    periphery_set(periphery, !periphery->state);
}

bool periphery_is_on(Periphery* periphery) {
    return ((periphery->GPIO->IDR >> periphery->pin) & 1) == (periphery->enabled_state ? 1 : 0);
}

bool periphery_is_off(Periphery* periphery) {
    return !periphery_is_on(periphery);
}

bool periphery_changed(Periphery* periphery) {
    bool previous = periphery->state;
    periphery->state = periphery_is_on(periphery);
    return periphery->state != previous;
}