#include <stdbool.h>
#include <fonts.h>
#include <lcd.h>
#include "display.h"

#define COLUMN_COUNT 16

void display_init(void) {
	LCDconfigure(&font8x16);
}

void display_number(long long num, int row) {
	if (num_out_of_bounds(num)) {
		LCDgoto(row, COLUMN_COUNT - 13);
		LCDputchar('O');
		LCDputchar('U');
		LCDputchar('T');
		LCDputchar(' ');
		LCDputchar('O');
		LCDputchar('F');
		LCDputchar(' ');
		LCDputchar('B');
		LCDputchar('O');
		LCDputchar('U');
		LCDputchar('N');
		LCDputchar('D');
		LCDputchar('S');
		return;
	}
	if (num == 0) {
		LCDgoto(row, COLUMN_COUNT - 1);
		LCDputchar('0' + num % 10);
		return;
	}
	bool negative = num < 0;
	if (negative) {
		num *= -1;
	}
	int i;
	for (i = COLUMN_COUNT - 1; num != 0; i--, num /= 10) {
		LCDgoto(row, i);
		LCDputchar('0' + num % 10);
	}
	if (negative) {
		LCDgoto(row, i);
		LCDputchar('-');
	}
}

void display_clear(void) {
	LCDclear();
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
