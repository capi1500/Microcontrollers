#include <stdbool.h>
#include "timer.h"
#include "../interrupts/interrupts.h"

#define TIMER_FREQUENCY 16000000

void timer_force_update(Timer* timer) {
	timer->EGR = TIM_EGR_UG;
}

void timer_init(Timer* timer, TimerConfig config) {
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	
	switch (config.counting_direction) {
		case COUNTING_UP:
			timer->CR1 = 0;
			break;
		case COUNTING_DOWN:
			timer->CR1 = TIM_CR1_DIR;
			break;
		case COUNTING_BOTH:
			timer->CR1 = TIM_CR1_CMS_0 | TIM_CR1_CMS_1;
			break;
	}
	
	timer_update(timer, config, true);
}

void timer_update(Timer* timer, TimerConfig config, bool force) {
	timer->CR1 |= TIM_CR1_UDIS;
	timer->PSC = (TIMER_FREQUENCY / config.updates_per_second) - 1;
	timer->ARR = config.count_limit;
	timer->CR1 &= ~TIM_CR1_UDIS;
	if (force) {
		timer_force_update(timer);
	}
}

void timer_start(Timer* timer) {
	timer->CR1 |= TIM_CR1_CEN;
}

void timer_stop(Timer* timer) {
	timer->CR1 &= ~TIM_CR1_CEN;
}

void timer_enable_interrupts(Timer* timer) {
	timer->SR = ~(TIM_SR_UIF);
	timer->DIER = TIM_DIER_UIE;
	timer_interrupts_enable(timer);
}

void timer_set_value(Timer* timer, unsigned value) {
	timer_force_update(timer);
	timer->CNT = value;
}
