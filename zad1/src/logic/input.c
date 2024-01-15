#include "input.h"

#define INPUT_QUEUE_MAX_SIZE 500

static unsigned input_queue_size = 0;
static unsigned input_queue_read_pointer = 0;
static unsigned input_queue_write_pointer = 0;

static Input input_queue[INPUT_QUEUE_MAX_SIZE];

unsigned input_get_event_count(void) {
	return input_queue_size;
}

Input input_get_event(void) {
	unsigned to_return = input_queue_read_pointer;
	if (input_queue_size != 0) {
		input_queue_size--;
		input_queue_read_pointer++;
		if (input_queue_read_pointer == INPUT_QUEUE_MAX_SIZE) {
			input_queue_read_pointer = 0;
		}
	}
	return input_queue[to_return];
}

void input_add_event(Input input) {
	input_queue[input_queue_write_pointer] = input;
	input_queue_size++;
	input_queue_write_pointer++;
	if (input_queue_write_pointer == INPUT_QUEUE_MAX_SIZE) {
		input_queue_write_pointer = 0;
	}
}
