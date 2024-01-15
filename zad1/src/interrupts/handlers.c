#include <gpio.h>
#include <lcd.h>

#include "handlers.h"
#include "../periphery/periphery.h"
#include "../periphery/keyboard.h"
#include "interrupts.h"

void interrupt_handlers_init(void) {}

void try_handle(Periphery* periphery) {
	if (EXTI->PR & periphery->mask) {
		LCDputcharWrap('X');
		LCDputcharWrap('0' + periphery->pin);
		LCDputcharWrap(';');
		
		periphery_interrupts_disable(periphery);
		
		EXTI->PR = periphery->mask;
		
		for (KeyboardColumn i = COLUMN_1; i < COLUMN_COUNT; i++) {
			periphery_set(&get_keyboard_columns()[i], true);
		}
		
		// zero CNT licznika
		// uruchomienie TIMx
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
		LCDputcharWrap('T');
		LCDputcharWrap('1');
		LCDputcharWrap(';');
		// TODO
	}
	if (it_status & TIM_SR_CC1IF) {
		TIM3->SR = ~TIM_SR_CC1IF;
		LCDputcharWrap('T');
		LCDputcharWrap('2');
		LCDputcharWrap(';');
		// TODO
	}
}