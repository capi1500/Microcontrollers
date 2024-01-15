#include <fonts.h>
#include <lcd.h>
#include "display.h"

#define COLUMN_COUNT 16

#define MIN_NUMBER (-2147483648ll)
#define MAX_NUMBER 2147483647ll

void display_init(void) {
	LCDconfigure(&font8x16);
}

void display_number(long long num, int column) {
	if (num < MIN_NUMBER || num > MAX_NUMBER) {
		LCDgoto(column, COLUMN_COUNT - 13);
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
