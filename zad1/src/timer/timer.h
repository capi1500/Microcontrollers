#ifndef TIMER_H
#define TIMER_H

#include <stm32.h>

typedef enum {
	COUNTING_UP,
	COUNTING_DOWN,
	COUNTING_BOTH
} TimerCountingDirection;

typedef TIM_TypeDef Timer;

typedef struct {
	TimerCountingDirection counting_direction;
	unsigned updates_per_second;
	unsigned count_limit;
} TimerConfig;

// Inicjalizacja licznika zgodnie z konfiguracja [config]
void timer_init(Timer* timer, TimerConfig config);
// Aktualizacja wskaźnika zgodnie z konfiguracja [config]
void timer_update(Timer* timer, TimerConfig config, bool force);

// Uruchomienie licznika
void timer_start(Timer* timer);
// Zatrzymanie licznika
void timer_stop(Timer* timer);
// Uruchomienie przerwań licznika
void timer_enable_interrupts(Timer* timer);

// Ustawienie wartości licznika
void timer_set_value(Timer* timer, unsigned value);

#endif // TIMER_H
