#include <gpio.h>
#include <stm32.h>
#include <string.h>

#include "controller/base.h"
#include "controller/usart2.h"
#include "controller/leds.h"
#include "controller/buttons.h"

#include "data/buffer.h"
#include "data/cyclic_buffer.h"
#include "commands.h"

bool str_eq(const char* s1, const char* s2, unsigned n) {
	return strncmp(s1, s2, n) == 0;
}

void try_do_command(led_state* leds, buffer* reader) {
	if (reader->size < 3) {
		return;
	} // reader->size == 3
	const char* cmd = reader->buffer;
	if (str_eq(cmd, red_on, 3)) {
		on_red(leds);
	} else if (str_eq(cmd, red_off, 3)) {
		off_red(leds);
	} else if (str_eq(cmd, red_toggle, 3)) {
		toggle_red(leds);
	} 
	else if (str_eq(cmd, blue_on, 3)) {
		on_blue(leds);
	} else if (str_eq(cmd, blue_off, 3)) {
		off_blue(leds);
	} else if (str_eq(cmd, blue_toggle, 3)) {
		toggle_blue(leds);
	} 
	else if (str_eq(cmd, green_on, 3)) {
		on_green(leds);
	} else if (str_eq(cmd, green_off, 3)) {
		off_green(leds);
	} else if (str_eq(cmd, green_toggle, 3)) {
		toggle_green(leds);
	} 
	else if (str_eq(cmd, green2_on, 3)) {
		on_green2(leds);
	} else if (str_eq(cmd, green2_off, 3)) {
		off_green2(leds);
	} else if (str_eq(cmd, green2_toggle, 3)) {
		toggle_green2(leds);
	}
	else {
		reader->buffer[0] = reader->buffer[1];
		reader->buffer[1] = reader->buffer[2];
		reader->size = 2;
		return;
	}
	reader->size = 0;
}

void check_button_state(buttons_state* buttons, cyclic_buffer* writer) {
	if (left_changed(buttons)) {
		if (buttons->left) {
			cyclic_buffer_add_string(writer, left_pressed);
		} else {
			cyclic_buffer_add_string(writer, left_released);
		}
	}
	if (right_changed(buttons)) {
		if (buttons->right) {
			cyclic_buffer_add_string(writer, right_pressed);
		} else {
			cyclic_buffer_add_string(writer, right_released);
		}
	}
	if (up_changed(buttons)) {
		if (buttons->up) {
			cyclic_buffer_add_string(writer, up_pressed);
		} else {
			cyclic_buffer_add_string(writer, up_released);
		}
	}
	if (down_changed(buttons)) {
		if (buttons->down) {
			cyclic_buffer_add_string(writer, down_pressed);
		} else {
			cyclic_buffer_add_string(writer, down_released);
		}
	}
	if (fire_changed(buttons)) {
		if (buttons->fire) {
			cyclic_buffer_add_string(writer, fire_pressed);
		} else {
			cyclic_buffer_add_string(writer, fire_released);
		}
	}
	if (user_changed(buttons)) {
		if (buttons->user) {
			cyclic_buffer_add_string(writer, user_pressed);
		} else {
			cyclic_buffer_add_string(writer, user_released);
		}
	}
	if (mode_changed(buttons)) {
		if (buttons->mode) {
			cyclic_buffer_add_string(writer, mode_pressed);
		} else {
			cyclic_buffer_add_string(writer, mode_released);
		}
	}
}

int main() {
	led_state leds;
	buttons_state buttons;
	
	init_leds(&leds);
	init_buttons(&buttons);
	init_usart2();
	start_usart2();
	
	cyclic_buffer writer;
	buffer reader;
	
	init_buffer(&reader);
	init_cyclic_buffer(&writer);
	
	for(;;) {
		if (can_read()) { // adds at most 1 char into the buffer
			char c = read_char();
			buffer_add_char(&reader, c);
		}
		try_do_command(&leds, &reader); // if buffer.size == 3, removes at least 1, at most 3 chars
		check_button_state(&buttons, &writer);
		if (cyclic_buffer_can_read_char(&writer) && can_write()) {
			char c = cyclic_buffer_read_char(&writer);
			send_char(c);
		}
	}
}
