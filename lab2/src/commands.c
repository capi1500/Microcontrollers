#include "commands.h"
#include "periphery/buttons.h"

const char* left_pressed = "LEFT PRESSED\r\n";
const char* left_released = "LEFT RELEASED\r\n";
const char* right_pressed = "RIGHT PRESSED\r\n";
const char* right_released = "RIGHT RELEASED\r\n";
const char* up_pressed = "UP PRESSED\r\n";
const char* up_released = "UP RELEASED\r\n";
const char* down_pressed = "DOWN PRESSED\r\n";
const char* down_released = "DOWN RELEASED\r\n";

const char* fire_pressed = "FIRE PRESSED\r\n";
const char* fire_released = "FIRE RELEASED\r\n";
const char* user_pressed = "USER PRESSED\r\n";
const char* user_released = "USER RELEASED\r\n";
const char* mode_pressed = "MODE PRESSED\r\n";
const char* mode_released = "MODE RELEASED\r\n";

typedef struct {
	const char* message[2];
} ButtonMessages;

static ButtonMessages button_messages[BUTTONS_COUNT];

void init_message(Button button, const char* pressed, const char* released) {
	button_messages[button].message[0] = released;
	button_messages[button].message[1] = pressed;
}

void init_button_messages(void) {
	init_message(BUTTON_LEFT, left_pressed, left_released);
	init_message(BUTTON_RIGHT, right_pressed, right_released);
	init_message(BUTTON_UP, up_pressed, up_released);
	init_message(BUTTON_DOWN, down_pressed, down_released);
	init_message(BUTTON_FIRE, fire_pressed, fire_released);
	init_message(BUTTON_USER, user_pressed, user_released);
	init_message(BUTTON_MODE, mode_pressed, mode_released);
}

const char* button_get_message(Button button) {
	Periphery* periphery = &get_buttons()[button];
	return button_messages[button].message[periphery_is_on(periphery) ? 1 : 0];
}