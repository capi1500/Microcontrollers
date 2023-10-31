#include "buttons.h"

static Periphery buttons[BUTTONS_COUNT];

Periphery* get_buttons() {
	return buttons;
}

void init_buttons() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN;
	
	periphery_init(&buttons[BUTTON_LEFT], GPIOB, 3, false);
	periphery_init(&buttons[BUTTON_RIGHT], GPIOB, 4, false);
	periphery_init(&buttons[BUTTON_UP], GPIOB, 5, false);
	periphery_init(&buttons[BUTTON_DOWN], GPIOB, 6, false);
	periphery_init(&buttons[BUTTON_FIRE], GPIOB, 10, false);
	periphery_init(&buttons[BUTTON_USER], GPIOA, 0, false);
	periphery_init(&buttons[BUTTON_MODE], GPIOC, 13, true);
}
