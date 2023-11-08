#ifndef QUEUE_BUFFER_H
#define QUEUE_BUFFER_H

#include <stdint.h>
#include "../types.h"

#define QUEUE_BUFFER_SIZE 512

typedef struct {
	char buf[2][QUEUE_BUFFER_SIZE + 1];
	uint32_t size[2];
	uint8_t current;
} QueueBuffer;

void init_queue_buffer(QueueBuffer* queue_buffer);
void queue_buffer_add(QueueBuffer* queue_buffer, const char* str);
// returned string will not change unless queue_buffer_get is called again
const char* queue_buffer_get(QueueBuffer* queue_buffer);
uint32_t queue_buffer_size(QueueBuffer* queue_buffer);

#endif // QUEUE_BUFFER_H
