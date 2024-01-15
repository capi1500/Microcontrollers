#include <delay.h>
#include "logic/calculator.h"
#include "periphery/display.h"
#include "periphery/keyboard.h"
#include "interrupts/interrupts.h"
#include "interrupts/handlers.h"
#include "timer/timer.h"
#include "periphery/buttons.h"

Calculator calculator;

int main() {
	display_init();
	
	interrupt_handlers_init();
	calculator_init(&calculator);
	interrupts_init();
	
	keyboard_init();
	
	// Skonfiguruj TIMx, aby zgłaszał przerwanie w regularnych
	// odstępach czasu, np. co 10 ms, ale nie włączaj licznika
//	timer_init(TIM1);
	
	while(true) {
		__NOP();
	}
}
