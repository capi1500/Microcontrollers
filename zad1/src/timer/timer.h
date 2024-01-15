#pragma once

#include <stm32.h>

typedef enum {
	COUNTING_UP,
	COUNTING_DOWN,
	COUNTING_BOTH
} TimerCountingDirection;

typedef TIM_TypeDef Timer;

typedef struct {
	TimerCountingDirection counting_direction;
	unsigned updates_per_second;
	unsigned count_limit;
} TimerConfig;

void timer_init(Timer* timer, TimerConfig config);
void timer_update(Timer* timer, TimerConfig config, bool force);

void timer_start(Timer* timer);
void timer_enable_interrupts(Timer* timer);

unsigned timer_get_value(Timer* timer);
void timer_set_value(Timer* timer, unsigned value);