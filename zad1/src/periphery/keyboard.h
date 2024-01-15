#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "periphery.h"

typedef enum {
	COLUMN_1,
	COLUMN_2,
	COLUMN_3,
	COLUMN_4,
	COLUMN_COUNT
} KeyboardColumn;

typedef enum {
	ROW_1,
	ROW_2,
	ROW_3,
	ROW_4,
	ROW_COUNT
} KeyboardRow;

Periphery* get_keyboard_columns(void);
Periphery* get_keyboard_rows(void);

bool keyboard_scan_columns(void);

void keyboard_init(void);

#endif // KEYBOARD_H
