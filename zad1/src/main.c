#include <delay.h>
#include <lcd.h>
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
	
	int row = 5;
	while(true) {
		if (input_get_event_count() > 0) {
			Input input = input_get_event();
			
			calculator_process_input(&calculator, input);
			display_draw(&calculator);
			
			LCDgoto(row, 0);
			LCDputchar('I');
			LCDputchar('0' + (input / 10));
			LCDputchar('0' + (input % 10));
			row++;
			if (row == 10) {
				row = 5;
			}
		}
		Delay(40000); // 10ms
	}
}
