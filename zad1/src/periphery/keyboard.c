#include "keyboard.h"
#include "../interrupts/interrupts.h"
#include "../logic/input.h"

static Periphery columns[4];
static Periphery rows[4];

#define COUNT_TO_REACH_FIRST 3
#define COUNT_TO_REACH_MAX 32
#define COUNT_TO_REACH_MIN 4

typedef struct {
	bool first;
	bool can_repeat;
	unsigned count;
	unsigned count_to_reach;
} KeyboardButtonRepeat;

KeyboardButtonRepeat buttons[4][4];

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
	
	periphery_init(&rows[ROW_1], GPIOC, 6, false);
	periphery_init(&rows[ROW_2], GPIOC, 7, false);
	periphery_init(&rows[ROW_3], GPIOC, 8, false);
	periphery_init(&rows[ROW_4], GPIOC, 9, false);
	
	for (KeyboardColumn i = COLUMN_1; i < COLUMN_COUNT; i++) {
		periphery_set(&columns[i], false);
		for (KeyboardRow j = ROW_1; j < ROW_COUNT; j++) {
			buttons[i][j].first = true;
			buttons[i][j].count = 0;
			buttons[i][j].count_to_reach = COUNT_TO_REACH_FIRST;
			buttons[i][j].can_repeat = (i <= COLUMN_3 && j <= ROW_3) || (i == COLUMN_2 && j == ROW_4);
		}
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
		GPIOinConfigure(
				rows[i].GPIO,
				rows[i].pin,
				GPIO_PuPd_UP,
				EXTI_Mode_Interrupt,
				EXTI_Trigger_Falling);
		periphery_interrupts_enable(&rows[i]);
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
		// Włączenie kolumnie
		periphery_set(&columns[i], false);
		bool rows_values[4];
		// Odczyt wartości rzędów
		for (KeyboardRow j = ROW_1; j < ROW_COUNT; j++) {
			rows_values[j] = periphery_read_state(&rows[j]);
		}
		// Wyłączenie kolumny
		periphery_set(&columns[i], true);
		
		for (KeyboardRow j = ROW_1; j < ROW_COUNT; j++) {
			// Obsługa przytrzymania przycisku
			if (rows_values[j]) {
				anything_pressed = true;
				
				buttons[i][j].count++;
				if (buttons[i][j].count >= buttons[i][j].count_to_reach && (buttons[i][j].first || buttons[i][j].can_repeat)) {
					buttons[i][j].count = 0;
					if (buttons[i][j].first) {
						buttons[i][j].first = false;
						buttons[i][j].count_to_reach = COUNT_TO_REACH_MAX;
					} else {
						buttons[i][j].count_to_reach /= 2;
						if (buttons[i][j].count_to_reach < COUNT_TO_REACH_MIN) {
							buttons[i][j].count_to_reach = COUNT_TO_REACH_MIN;
						}
					}
					
					input_add_event(input_map_row_column(i, j));
				}
			} else {
				buttons[i][j].first = true;
				buttons[i][j].count = 0;
				buttons[i][j].count_to_reach = COUNT_TO_REACH_FIRST;
			}
		}
	}
	return anything_pressed;
}
