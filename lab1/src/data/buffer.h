#ifndef BUFFER_H
#define BUFFER_H

#include "../types.h"

#define BUFFER_SIZE 3

typedef struct {
	char buffer[BUFFER_SIZE];
	unsigned size;
} buffer;

void init_buffer(buffer* b);

void buffer_add_char(buffer* b, char c);
// bool buffer_can_read_char(buffer* b);
// char buffer_read_char(buffer* b);
// void buffer_try_read_command(buffer* b, const char* cmd);

#endif // BUFFER_H
