#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <gpio.h>
#include <stm32.h>
#include "../types.h"
#include "../periphery/periphery.h"

void interrupts_init();

void interrupt_periphery_setup(Periphery* periphery);

#endif // INTERRUPTS_H