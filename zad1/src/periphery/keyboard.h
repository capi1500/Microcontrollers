#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "periphery.h"

typedef enum {
	COLUMN_1, // output - GPIOC 0
	COLUMN_2, // output - GPIOC 1
	COLUMN_3, // output - GPIOC 2
	COLUMN_4, // output - GPIOC 3
	COLUMN_COUNT
} KeyboardColumn;

typedef enum {
	ROW_1, // input - GPIOC 6
	ROW_2, // input - GPIOC 7
	ROW_3, // input - GPIOC 8
	ROW_4, // input - GPIOC 9
	ROW_COUNT
} KeyboardRow;

// Pobranie listy periphery kolumn klawiatury
Periphery* get_keyboard_columns(void);
// Pobranie listy periphery rzędów klawiatury
Periphery* get_keyboard_rows(void);

// Skanowanie klawiatury w poszukiwaniu nowych zmian
bool keyboard_scan_columns(void);

// Inicjalizacja wyprowadzeń związanych z klawiaturą
// Inicjalizacja struktur pomocniczych klawiatury
void keyboard_init(void);

#endif // KEYBOARD_H
