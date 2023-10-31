#ifndef CYCLIC_BUFER_H
#define CYCLIC_BUFER_H

#include "../types.h"

#define CYCLIC_BUFFER_SIZE 512

typedef struct {
	char buffer[CYCLIC_BUFFER_SIZE];
	unsigned read_pointer;
	unsigned write_pointer;
	unsigned size;
} cyclic_buffer;

void init_cyclic_buffer(cyclic_buffer* b);

void cyclic_buffer_add_string(cyclic_buffer* b, const char* c);
bool cyclic_buffer_can_read_char(cyclic_buffer* b);
char cyclic_buffer_read_char(cyclic_buffer* b);

#endif // CYCLIC_BUFER_H
