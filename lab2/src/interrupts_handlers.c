#include <gpio.h>

#include "interrupts_handlers.h"
#include "periphery/periphery.h"
#include "periphery/leds.h"
#include "periphery/buttons.h"
#include "controller/dma.h"
#include "data/queue_buffer.h"
#include "commands.h"

static QueueBuffer buffer;

void init_interrupt_handlers() {
	init_queue_buffer(&buffer);
}

// Resets QueueBuffer buffer and starts sending string
void send_dma_usart2() {
	dma_start_send_usart2(queue_buffer_get(&buffer));
}

void try_handle_debug(Periphery* periphery, Periphery* led, bool value) {
	if (EXTI->PR & periphery->mask) {
		periphery_set(led, value);
		EXTI->PR = periphery->mask;
	}
}

void try_handle(Button button) {
	Periphery* periphery = &get_buttons()[button];
	if (EXTI->PR & periphery->mask) {
		queue_buffer_add(&buffer, button_get_message(button));
		if (dma_can_start_send_usart2()) {
			send_dma_usart2();
		}
		EXTI->PR = periphery->mask;
	}
}

void EXTI0_IRQHandler(void) {
	try_handle(BUTTON_USER);
}

void EXTI3_IRQHandler(void) {
	try_handle(BUTTON_LEFT);
}

void EXTI4_IRQHandler(void) {
	try_handle(BUTTON_RIGHT);
}

void EXTI9_5_IRQHandler(void) {
	try_handle(BUTTON_UP);
	try_handle(BUTTON_DOWN);
}

void EXTI15_10_IRQHandler(void) {
	try_handle(BUTTON_MODE);
	try_handle(BUTTON_FIRE);
}

void DMA1_Stream6_IRQHandler() {
	/* Odczytaj zgłoszone przerwania DMA1. */
	uint32_t isr = DMA1->HISR;
	if (isr & DMA_HISR_TCIF6) {
		DMA1->HIFCR = DMA_HIFCR_CTCIF6;

		if (queue_buffer_size(&buffer) > 0) {
			send_dma_usart2();
		}
	}
}

void DMA1_Stream5_IRQHandler() {
	/* Odczytaj zgłoszone przerwania DMA1. */
	uint32_t isr = DMA1->HISR;
	if (isr & DMA_HISR_TCIF5) {
		/* Obsłuż zakończenie transferu
		w strumieniu 5. */
		DMA1->HIFCR = DMA_HIFCR_CTCIF5;
		/* ... */
		/* Ponownie uaktywnij odbieranie. */
		/* ... */
	}
}