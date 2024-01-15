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

bool periphery_read_state(Periphery* periphery) {
	periphery->state = ((periphery->GPIO->IDR >> periphery->pin) & 1) == (periphery->enabled_state ? 1 : 0);
	return periphery->state;
}
