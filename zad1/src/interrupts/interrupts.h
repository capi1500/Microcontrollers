#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "../periphery/periphery.h"
#include "../timer/timer.h"

void interrupts_init(void);

void periphery_interrupts_setup(Periphery* periphery, EXTITrigger_TypeDef trigger);
void periphery_interrupts_enable(Periphery* periphery);
void periphery_interrupts_disable(Periphery* periphery);

void timer_interrupts_enable(Timer* timer);
void timer_interrupts_disable(Timer* timer);

#endif // INTERRUPTS_H
