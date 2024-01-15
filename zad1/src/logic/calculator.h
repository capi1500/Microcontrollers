#pragma once

#include "input.h"

typedef enum {
	Plus,
	Minus,
	Multiply,
	Divide,
	None
} Operator;

typedef enum {
	FirstNumber,
	SecondNumber,
	Result
} State;

typedef struct {
	int num1;
	int num2;
	int result;
	Operator operator;
	State state;
} Calculator;

void calculator_init(Calculator* calculator);
void calculator_process_input(Calculator* calculator, Input input);
