#include <delay.h>
#include "calculator.h"
#include "display.h"

Calculator calculator;

int main() {
	calculator_init(&calculator);
	display_init();
	
	calculator.state = Result;
	calculator.operator = Divide;
	calculator.num1 = 15;
	calculator.num2 = 3;
	calculator.result = 5;
	
	display_draw(&calculator);
}
