#include <string.h>

#include "buffer.h"

void init_buffer(buffer* b) {
	memset(b->buffer, 0, BUFFER_SIZE);
	b->size = 0;
}

void buffer_add_char(buffer* b, char c) {
	if (b->size >= BUFFER_SIZE) {
		return; // ERROR - ignore c
	}
	b->buffer[b->size] = c;
	b->size++;
}

// bool buffer_can_read_char(buffer* b) {
// 	return b->size > 0;
// }

// char buffer_read_char(buffer* b) {
// 	char c = b->buffer[b->size];
// 	b->size--;
// 	return c;	
// }

// bool buffer_try_read_command(buffer* b, const char* cmd) {
// 	unsigned len = strlen(cmd);
// 	if (b->size < len) {
// 		return false;
// 	}
// 	if (strcmp(b->buffer + size - len, cmd, len) != 0) {
// 		return false;
// 	}
// 	b->size -= len;
// 	return true;
// }
