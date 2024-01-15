#ifndef DISPLAY_H
#define DISPLAY_H

#include "../logic/calculator.h"

void display_init(void);

void display_clear(void);
void display_draw(Calculator* calculator);

#endif // DISPLAY_H
