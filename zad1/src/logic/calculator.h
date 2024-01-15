#ifndef CALCULATOR_H
#define CALCULATOR_H

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
	long long num1;
	long long num2;
	long long result;
	Operator operator;
	State state;
} Calculator;

void calculator_init(Calculator* calculator);
void calculator_process_input(Calculator* calculator, Input input);

#endif // CALCULATOR_H
