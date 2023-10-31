#include <string.h>
#include "cyclic_buffer.h"

void init_cyclic_buffer(cyclic_buffer* b) {
	memset(b->buffer, 0, CYCLIC_BUFFER_SIZE);
	b->read_pointer = 0;
	b->write_pointer = 0;
	b->size = 0;
}

void cyclic_buffer_add_string(cyclic_buffer* b, const char* c) {
	unsigned n = strlen(c);
	for (int i = 0; i < n; i++) {
		b->buffer[b->write_pointer] = c[i];
		b->size++;
		b->write_pointer = (b->write_pointer + 1) % CYCLIC_BUFFER_SIZE;
	}
}

bool cyclic_buffer_can_read_char(cyclic_buffer* b) {
	return b->size > 0;
}

char cyclic_buffer_read_char(cyclic_buffer* b) {
	char c = b->buffer[b->read_pointer];
	b->size--;
	b->read_pointer = (b->read_pointer + 1) % CYCLIC_BUFFER_SIZE;
	return c;
}
