#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "../periphery/periphery.h"
#include "../timer/timer.h"

// Włączenie taktowania przerwań EXTI
// Konfiguracja struktur pomocniczych dla przerwań
void interrupts_init(void);

// Włącz obsługę przerwań dla periphery
void periphery_interrupts_enable(Periphery* periphery);
// Wyłącz obsługę przerwań dla periphery
void periphery_interrupts_disable(Periphery* periphery);

// Włącz obsługę przerwań dla licznika
void timer_interrupts_enable(Timer* timer);

#endif // INTERRUPTS_H
