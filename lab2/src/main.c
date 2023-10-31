#include <gpio.h>

#include "controller/usart2.h"
#include "controller/dma.h"
#include "controller/interrupts.h"

#include "periphery/buttons.h"
#include "periphery/leds.h"
#include "interrupts_handlers.h"
#include "commands.h"


int main() {
	init_interrupt_handlers();
	init_button_messages();

	interrupts_init();

	init_buttons();
	init_leds();
	init_usart2();
	init_dma();
	
	for (int i = 0; i < BUTTONS_COUNT; i++) {
		interrupt_periphery_setup(&get_buttons()[i]);
	}

	dma_set_stream_6_usart2();

	start_usart2();
	dma_start_stream_6();

	while(true) {
		__NOP();
	}
}
