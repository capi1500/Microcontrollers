#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "../periphery/periphery.h"

void interrupts_init(void);

void interrupt_periphery_setup(Periphery* periphery, EXTITrigger_TypeDef trigger);
void interrupt_enable_periphery_interrupts(Periphery* periphery);
void interrupt_disable_periphery_interrupts(Periphery* periphery);

#endif // INTERRUPTS_H
