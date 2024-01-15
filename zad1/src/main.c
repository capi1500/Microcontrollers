#include <delay.h>
#include "logic/calculator.h"
#include "periphery/display.h"
#include "periphery/keyboard.h"
#include "interrupts/interrupts.h"
#include "interrupts/handlers.h"
#include "timer/timer.h"

Calculator calculator;

int main() {
	interrupt_handlers_init();
	interrupts_init();
	
	TimerConfig timer_config;
	timer_config.updates_per_second = 1000;
	timer_config.count_limit = 10;
	timer_config.counting_direction = COUNTING_UP;
	timer_init(TIM3, timer_config);
	timer_enable_interrupts(TIM3);
	
	display_init();
	keyboard_init();
	calculator_init(&calculator);
	
	while(true) {
		__NOP();
	}
}
