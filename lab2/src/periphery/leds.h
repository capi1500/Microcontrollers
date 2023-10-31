#ifndef LEDS_H
#define LEDS_H

#include <gpio.h>
#include <stm32.h>
#include "../types.h"
#include "periphery.h"

enum {
    LED_RED,
    LED_GREEN,
    LED_BLUE,
    LED_GREEN2,
    LEDS_COUNT
};

Periphery* get_leds();

void init_leds();

#endif // LEDS_H
