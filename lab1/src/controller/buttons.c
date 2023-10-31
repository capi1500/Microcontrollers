#include "buttons.h"

void init_buttons(buttons_state* buttons) {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN;
	
	buttons->left = false;
	buttons->right = false;
	buttons->up = false;
	buttons->down = false;
	buttons->fire = false;
	buttons->user = false;
	buttons->mode = false;
}

bool left_changed(buttons_state* buttons) {
	bool current = LEFT_BTN_PRESSED();
	bool previous = buttons->left;
	buttons->left = current;
	return current != previous;
}

bool right_changed(buttons_state* buttons) {
	bool current = RIGHT_BTN_PRESSED();
	bool previous = buttons->right;
	buttons->right = current;
	return current != previous;
}

bool up_changed(buttons_state* buttons) {
	bool current = UP_BTN_PRESSED();
	bool previous = buttons->up;
	buttons->up = current;
	return current != previous;
}

bool down_changed(buttons_state* buttons) {
	bool current = DOWN_BTN_PRESSED();
	bool previous = buttons->down;
	buttons->down = current;
	return current != previous;
}

bool fire_changed(buttons_state* buttons) {
	bool current = FIRE_BTN_PRESSED();
	bool previous = buttons->fire;
	buttons->fire = current;
	return current != previous;
}

bool user_changed(buttons_state* buttons) {
	bool current = USER_BTN_PRESSED();
	bool previous = buttons->user;
	buttons->user = current;
	return current != previous;
}

bool mode_changed(buttons_state* buttons) {
	bool current = MODE_BTN_PRESSED();
	bool previous = buttons->mode;
	buttons->mode = current;
	return current != previous;
}
