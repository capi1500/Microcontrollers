#include "queue_buffer.h"

#include <string.h>

void init_queue_buffer(QueueBuffer* queue_buffer) {
	queue_buffer->size[0] = 0;
	queue_buffer->current = 0;
	memset(queue_buffer->buf[0], 0, QUEUE_BUFFER_SIZE + 1);
}

void queue_buffer_add(QueueBuffer* queue_buffer, const char* str) {
	size_t n = strlen(str);
	if (queue_buffer->size[queue_buffer->current] + n > QUEUE_BUFFER_SIZE) {
		return; // ERROR
	}
	strncpy(queue_buffer->buf[queue_buffer->current] + queue_buffer->size[queue_buffer->current], str, n + 1);
	queue_buffer->size[queue_buffer->current] += n;
}

// returned string will not change unless queue_buffer_get is called again
const char* queue_buffer_get(QueueBuffer* queue_buffer) {
	const char* ret = queue_buffer->buf[queue_buffer->current];
	queue_buffer->current = (1 - queue_buffer->current);
	memset(queue_buffer->buf[queue_buffer->current], 0, QUEUE_BUFFER_SIZE + 1);
	queue_buffer->size[queue_buffer->current] = 0;
	return ret;
}

uint32_t queue_buffer_size(QueueBuffer* queue_buffer) {
	return queue_buffer->size[queue_buffer->current];
}