#include "calculator.h"
#include "../periphery/display.h"

void append_number(long long* num, int digit) {
	*num = (*num * 10) + digit;
}

bool num_out_of_bounds(long long n) {
	return n < MIN_NUMBER || n > MAX_NUMBER;
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
	if (num_out_of_bounds(a) || num_out_of_bounds(b)) {
		return MAX_NUMBER + 1;
	}
	switch (calculator->operator) {
		case Plus:
			return a + b;
		case Minus:
			return a - b;
		case Multiply:
			return a * b;
		case Divide:
			return b == 0 ? (MAX_NUMBER + 1) : a / b;
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
				display_clear();
				display_draw(calculator);
				break;
			case Result:
				calculator->num1 = calculator->result;
				calculator->num2 = 0;
				calculator->result = 0;
				calculator->operator = operator;
				calculator->state = SecondNumber;
				display_clear();
				display_draw(calculator);
				break;
		}
	} else if (input == OpResult) {
		switch (calculator->state) {
			case FirstNumber:
				calculator->result = calculator->num1;
				calculator->operator = None;
				calculator->state = Result;
				break;
			case SecondNumber:
				calculator->result = calculate(calculator);
				calculator->state = Result;
				break;
			case Result:
				calculator->num1 = calculator->result;
				calculator->num2 = 0;
				calculator->result = 0;
				calculator->operator = None;
				calculator->state = FirstNumber;
				display_clear();
				display_draw(calculator);
				break;
		}
	} else if (input == OpClear) {
		calculator_init(calculator);
	}
}
