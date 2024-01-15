#include "keyboard.h"
#include "../interrupts/interrupts.h"
#include "../logic/input.h"

static Periphery columns[4];
static Periphery rows[4];

Periphery* get_keyboard_columns(void) {
	return columns;
}

Periphery* get_keyboard_rows(void) {
	return rows;
}

void keyboard_init(void) {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

	periphery_init(&columns[COLUMN_1], GPIOC, 0, false);
	periphery_init(&columns[COLUMN_2], GPIOC, 1, false);
	periphery_init(&columns[COLUMN_3], GPIOC, 2, false);
	periphery_init(&columns[COLUMN_4], GPIOC, 3, false);
	
	periphery_init(&rows[ROW_1], GPIOC, 6, true);
	periphery_init(&rows[ROW_2], GPIOC, 7, true);
	periphery_init(&rows[ROW_3], GPIOC, 8, true);
	periphery_init(&rows[ROW_4], GPIOC, 9, true);
	
	for (KeyboardColumn i = COLUMN_1; i < COLUMN_COUNT; i++) {
		periphery_set(&columns[i], false);
	}
	for (KeyboardColumn i = COLUMN_1; i < COLUMN_COUNT; i++) {
		GPIOoutConfigure(
				columns[i].GPIO,
				columns[i].pin,
				GPIO_OType_PP,
				GPIO_Low_Speed,
				GPIO_PuPd_NOPULL);
	}
	for (KeyboardRow i = ROW_1; i < ROW_COUNT; i++) {
		periphery_interrupts_setup(&rows[i], EXTI_Trigger_Falling);
	}
}

Input input_map_row_column(KeyboardColumn column, KeyboardRow row) {
	if (column == COLUMN_4) {
		return 10 + row;
	}
	if (row <= ROW_3) {
		return 1 + row * 3 + column;
	}
	if (column == COLUMN_1) {
		return OpClear;
	} else if (column == COLUMN_2) {
		return Num0;
	} else
		return OpResult;
}

bool keyboard_scan_columns(void) {
	bool anything_pressed = false;
	for (KeyboardColumn i = COLUMN_1; i < COLUMN_COUNT; i++) {
		periphery_set(&columns[i], false);
		bool rows_values[4];
		for (KeyboardRow j = ROW_1; j < ROW_COUNT; j++) {
			rows_values[j] = periphery_read_state(&rows[j]); // TODO: tak, czy powinno być zmienione na is_on??
		}
		periphery_set(&columns[i], true);
		for (KeyboardRow j = ROW_1; j < ROW_COUNT; j++) {
			if (rows_values[j]) {
				anything_pressed = true;
				// TODO: sprawdzić, czy jest to przytrzymanie
				input_add_event(input_map_row_column(i, j));
				break;
			}
		}
	}
	return anything_pressed;
}
