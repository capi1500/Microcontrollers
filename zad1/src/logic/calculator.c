#include "calculator.h"
#include "../periphery/display.h"

void append_number(long long* num, int digit) {
	*num = (*num * 10) + digit;
}

void calculator_init(Calculator* calculator) {
	calculator->num1 = 0;
	calculator->num2 = 0;
	calculator->result = 0;
	calculator->operator = None;
	calculator->state = FirstNumber;
	display_clear();
	display_draw(calculator);
}

long long calculate(Calculator* calculator) {
	long long a = calculator->num1;
	long long b = calculator->num2;
	switch (calculator->operator) {
		case Plus:
			return a + b;
		case Minus:
			return a - b;
		case Multiply:
			return a * b;
		case Divide:
			return b == 0 ? 0 : a / b;
		default:
			return 0;
	}
}

void calculator_process_input(Calculator* calculator, Input input) {
	if (input <= Num9) {
		switch (calculator->state) {
			case FirstNumber:
				append_number(&calculator->num1, input);
				break;
			case SecondNumber:
				append_number(&calculator->num2, input);
				break;
			case Result:
				calculator_init(calculator); // does reset
				append_number(&calculator->num1, input);
				break;
		}
	} else if (input <= OpDiv) {
		Operator operator = input - OpPlus;
		switch (calculator->state) {
			case FirstNumber:
				calculator->operator = operator;
				calculator->state = SecondNumber;
				break;
			case SecondNumber:
				calculator->num1 = calculate(calculator);
				calculator->num2 = 0;
				calculator->operator = operator;
				break;
			case Result:
				calculator->operator = operator;
				calculator->state = SecondNumber;
				break;
		}
	} else if (input == OpResult) {
		switch (calculator->state) {
			case SecondNumber:
				calculator->result = calculate(calculator);
				calculator->state = Result;
				break;
			default:
				break;
		}
		calculator->operator = None;
		calculator->state = Result;
	} else if (input == OpClear) {
		calculator_init(calculator);
	}
}
