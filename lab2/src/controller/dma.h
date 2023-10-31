#ifndef DMA_H
#define DMA_H

#include <gpio.h>
#include <stm32.h>
#include "../types.h"

void init_dma();

void dma_set_stream_6_usart2();
void dma_set_stream_5_usart2();

void dma_start_stream_6();
void dma_start_stream_5();

void dma_start_send_usart2(const char* buff);
void dma_start_receiver_usart2(char* buff);

bool dma_can_start_send_usart2();

#endif // DMA_H
