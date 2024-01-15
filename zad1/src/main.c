#include <delay.h>
#include "logic/calculator.h"
#include "periphery/display.h"
#include "periphery/keyboard.h"
#include "interrupts/interrupts.h"
#include "interrupts/handlers.h"

Calculator calculator;

int main() {
	interrupts_init();
	
	display_init();
	keyboard_init();
	calculator_init(&calculator);
	
	interrupt_handlers_init();
	
	while(true) {
		if (input_get_event_count() > 0) {
			Input input = input_get_event();
			
			calculator_process_input(&calculator, input);
			display_draw(&calculator);
		}
		Delay(40000); // 10ms
	}
}
