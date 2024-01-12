#include <stdbool.h>
#include "display.h"

void display_init(void) {
	LCDconfigure();
}

void display_number(int num) {
	bool negative = num < 0;
	int i;
	for (i = 10; num != 0; i--, num /= 10) {
		LCDgoto(0, i);
		LCDputchar('0' + num % 10);
	}
	if (negative) {
		LCDgoto(0, i);
		LCDputchar('-');
	}
}

void display_draw(Calculator* calculator) {
	switch (calculator->state) {
		case FirstNumber:
			display_number(calculator->num1);
			break;
		case SecondNumber:
			display_number(calculator->num2);
			LCDgoto(0, 0);
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
			break;
		case Result:
			display_number(calculator->num1);
			LCDgoto(0, 0);
			LCDputchar('=');
			break;
	}
}
