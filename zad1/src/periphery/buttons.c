#include "buttons.h"
#include "../interrupts/interrupts.h"

static Periphery buttons[BUTTONS_COUNT];

Periphery* get_buttons(void) {
	return buttons;
}

void init_buttons(void) {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN;
	
	periphery_init(&buttons[BUTTON_LEFT], GPIOB, 3, false);
	periphery_init(&buttons[BUTTON_RIGHT], GPIOB, 4, false);
	periphery_init(&buttons[BUTTON_UP], GPIOB, 5, false);
	periphery_init(&buttons[BUTTON_DOWN], GPIOB, 6, false);
	periphery_init(&buttons[BUTTON_FIRE], GPIOB, 10, false);
	periphery_init(&buttons[BUTTON_MODE], GPIOA, 0, true);
	periphery_init(&buttons[BUTTON_USER], GPIOC, 13, false);
	
	for (int i = 0; i < BUTTONS_COUNT; i++) {
		interrupt_periphery_setup(&get_buttons()[i]);
	}
}
