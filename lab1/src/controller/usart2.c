#include "usart2.h"

void init_usart2() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	
	GPIOafConfigure(GPIOA,
		2,
		GPIO_OType_PP,
		GPIO_Fast_Speed,
		GPIO_PuPd_NOPULL,
		GPIO_AF_USART2);
		
	GPIOafConfigure(GPIOA,
		3,
		GPIO_OType_PP,
		GPIO_Fast_Speed,
		GPIO_PuPd_UP,
		GPIO_AF_USART2);
	
	USART2->CR1 = USART_Mode_Rx_Tx |
		USART_WordLength_8b |
		USART_Parity_No;
	
	USART2->CR2 = USART_StopBits_1;
	
	USART2->CR3 = USART_FlowControl_None;
	
	USART2->BRR = (PCLK1_HZ + (BAUD / 2U)) / BAUD;
}

void start_usart2() {
	USART2->CR1 |= USART_Enable;
}

bool can_read() {
	return USART2->SR & USART_SR_RXNE;
}

bool can_write() {
	return USART2->SR & USART_SR_TXE;
}

char read_char() {
	return USART2->DR;
}

void send_char(char c) {
	USART2->DR = c;
}
