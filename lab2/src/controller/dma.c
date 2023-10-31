#include <string.h>
#include "dma.h"

void init_dma() {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_DMA1EN;
}

void dma_set_stream_6_usart2() {
    DMA1_Stream6->CR = 4U << 25 |
        DMA_SxCR_PL_1 |
        DMA_SxCR_MINC |
        DMA_SxCR_DIR_0 |
        DMA_SxCR_TCIE;
    
    DMA1_Stream6->PAR = (uint32_t)&USART2->DR;
}

void dma_set_stream_5_usart2() {
    DMA1_Stream5->CR = 4U << 25 |
        DMA_SxCR_PL_1 |
        DMA_SxCR_MINC |
        DMA_SxCR_TCIE;
    
    DMA1_Stream5->PAR = (uint32_t)&USART2->DR;
}

void dma_start_stream_6() {
    DMA1->HIFCR = DMA_HIFCR_CTCIF6;
    NVIC_EnableIRQ(DMA1_Stream6_IRQn);
}

void dma_start_stream_5() {
	DMA1->HIFCR = DMA_HIFCR_CTCIF5;
	NVIC_EnableIRQ(DMA1_Stream5_IRQn);
}

void dma_start_send_usart2(const char* buff) {
    DMA1_Stream6->M0AR = (uint32_t)buff;
    DMA1_Stream6->NDTR = strlen(buff);
    DMA1_Stream6->CR |= DMA_SxCR_EN;
}

void dma_start_receiver_usart2(char* buff) {
    DMA1_Stream5->M0AR = (uint32_t)buff;
    DMA1_Stream5->NDTR = 1;
    DMA1_Stream5->CR |= DMA_SxCR_EN;
}

bool dma_can_start_send_usart2() {
	return (DMA1_Stream6->CR & DMA_SxCR_EN) == 0 &&
	       (DMA1->HISR & DMA_HISR_TCIF6) == 0;
}