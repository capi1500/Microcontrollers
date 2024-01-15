#pragma once

#include <stm32.h>

typedef enum {
	COUNTING_UP,
	COUNTING_DOWN,
	COUNTING_BOTH
} TimerCountingDirection;

typedef struct {
	TIM_TypeDef* timer;
} Timer;

void timer_init(
		Timer* timer,
		TIM_TypeDef* timer_ptr,
		TimerCountingDirection counting_direction);
