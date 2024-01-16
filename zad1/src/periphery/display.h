#ifndef DISPLAY_H
#define DISPLAY_H

#include "../logic/calculator.h"

// Konfiguracja wyświetlacza
void display_init(void);

// Wyczysczenie wyświetlacza
void display_clear(void);
// Narysowanie kalkulatora
void display_draw(Calculator* calculator);

#endif // DISPLAY_H
