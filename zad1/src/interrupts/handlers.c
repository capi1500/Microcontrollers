#include <gpio.h>
#include <lcd.h>

#include "handlers.h"
#include "../periphery/periphery.h"
#include "../periphery/keyboard.h"
#include "../periphery/buttons.h"
#include "interrupts.h"

void interrupt_handlers_init(void) {

}

void try_handle(Periphery* periphery) {
	if (EXTI->PR & periphery->mask) {
		LCDputcharWrap('X');
		LCDputcharWrap('0' + periphery->pin);
		LCDputcharWrap(';');
		
		interrupt_disable_periphery_interrupts(periphery);
		
		EXTI->PR = periphery->mask;
		
		for (KeyboardColumn i = COLUMN_1; i < COLUMN_COUNT; i++) {
			periphery_set(&get_keyboard_columns()[i], true);
		}
		
		// zero CNT licznika
		// uruchomienie TIMx
	}
}

// przerwania dla licznika TIMx

void EXTI9_5_IRQHandler(void) {
	for (KeyboardRow i = ROW_1; i < ROW_COUNT; i++) {
		try_handle(&get_keyboard_rows()[i]);
	}
}
