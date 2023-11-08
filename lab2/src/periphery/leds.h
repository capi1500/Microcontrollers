#ifndef LEDS_H
#define LEDS_H

#include "../types.h"
#include "periphery.h"

enum {
    LED_RED,
    LED_GREEN,
    LED_BLUE,
    LED_GREEN2,
    LEDS_COUNT
};

Periphery* get_leds(void);

void init_leds(void);

#endif // LEDS_H
