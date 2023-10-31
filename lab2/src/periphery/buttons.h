#ifndef BUTTONS_H
#define BUTTONS_H

#include <gpio.h>
#include <stm32.h>
#include "../types.h"
#include "periphery.h"

typedef enum {
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_FIRE,
	BUTTON_USER,
	BUTTON_MODE,
	BUTTONS_COUNT
} Button;

Periphery* get_buttons();

void init_buttons();

#endif // BUTTONS_H
