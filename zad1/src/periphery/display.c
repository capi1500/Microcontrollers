#include <stdbool.h>
#include <fonts.h>
#include "display.h"

#define COLUMN_COUNT 16

void display_init(void) {
	LCDconfigure(&font8x16);
}

void display_number(int num, int column) {
	if (num == 0) {
		LCDgoto(column, COLUMN_COUNT - 1);
		LCDputchar('0' + num % 10);
		return;
	}
	bool negative = num < 0;
	int i;
	for (i = COLUMN_COUNT - 1; num != 0; i--, num /= 10) {
		LCDgoto(column, i);
		LCDputchar('0' + num % 10);
	}
	if (negative) {
		LCDgoto(column, i);
		LCDputchar('-');
	}
}

void display_draw(Calculator* calculator) {
	display_number(calculator->num1, 0);
	if (calculator->state == FirstNumber) {
		return;
	}
	LCDgoto(1, 0);
	switch (calculator->operator) {
		case Plus:
			LCDputchar('+');
			break;
		case Minus:
			LCDputchar('-');
			break;
		case Multiply:
			LCDputchar('*');
			break;
		case Divide:
			LCDputchar('/');
			break;
		case None:
			break;
	}
	display_number(calculator->num2, 1);
	if (calculator->state == SecondNumber) {
		return;
	}
	LCDgoto(2, 0);
	LCDputchar('=');
	display_number(calculator->result, 2);
}
