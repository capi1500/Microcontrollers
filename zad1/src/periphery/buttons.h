#ifndef BUTTONS_H
#define BUTTONS_H

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

Periphery* get_buttons(void);

void init_buttons(void);

#endif // BUTTONS_H
