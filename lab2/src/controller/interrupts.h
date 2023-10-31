#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <gpio.h>
#include <stm32.h>
#include "../types.h"
#include "../periphery/periphery.h"

void interrupts_init();

void interrupt_periphery_setup(Periphery* periphery);

typedef uint32_t irq_level_t;

irq_level_t interrupt_pause();
void interrupt_resume(irq_level_t level);

#endif // INTERRUPTS_H