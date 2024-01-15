#include <gpio.h>

#include "handlers.h"
#include "../periphery/periphery.h"
#include "../periphery/keyboard.h"
#include "interrupts.h"

void interrupt_handlers_init(void) {
	TimerConfig timer_config;
	timer_config.updates_per_second = 1000;
	timer_config.count_limit = 10;
	timer_config.counting_direction = COUNTING_UP;
	timer_init(TIM3, timer_config);
	timer_enable_interrupts(TIM3);
}

void try_handle(Periphery* periphery) {
	if (EXTI->PR & periphery->mask) {
		periphery_interrupts_disable(periphery);

		EXTI->PR = periphery->mask;

		for (KeyboardColumn i = COLUMN_1; i < COLUMN_COUNT; i++) {
			periphery_set(&get_keyboard_columns()[i], true);
		}

		timer_set_value(TIM3, 0);
		timer_start(TIM3);
	}
}

void EXTI9_5_IRQHandler(void) {
	for (KeyboardRow i = ROW_1; i < ROW_COUNT; i++) {
		try_handle(&get_keyboard_rows()[i]);
	}
}

void TIM3_IRQHandler(void) {
	uint32_t it_status = TIM3->SR & TIM3->DIER;
	if (it_status & TIM_SR_UIF) {
		TIM3->SR = ~TIM_SR_UIF;
		if (!keyboard_scan_columns()) {
			timer_stop(TIM3);
			for (KeyboardColumn i = COLUMN_1; i < COLUMN_COUNT; i++) {
				periphery_set(&get_keyboard_columns()[i], false);
			}
			for (KeyboardRow i = ROW_1; i < ROW_COUNT; i++) {
				periphery_interrupts_enable(&get_keyboard_rows()[i]);
			}
		}
	}
	if (it_status & TIM_SR_CC1IF) {
		TIM3->SR = ~TIM_SR_CC1IF;
	}
}