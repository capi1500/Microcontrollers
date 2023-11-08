#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "../periphery/periphery.h"

void interrupts_init(void);

void interrupt_periphery_setup(Periphery* periphery);

#endif // INTERRUPTS_H