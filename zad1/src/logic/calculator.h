#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdbool.h>
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

#define MIN_NUMBER (-2147483648ll)
#define MAX_NUMBER 2147483647ll

// Czy liczba jest poza obsługiwanym zakresem
bool num_out_of_bounds(long long n);

// Inicjalizacja logiki kalkulatora
void calculator_init(Calculator* calculator);
// Obsługa zdarzenia wejścia
void calculator_process_input(Calculator* calculator, Input input);

#endif // CALCULATOR_H
