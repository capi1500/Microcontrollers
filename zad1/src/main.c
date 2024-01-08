#include <lcd.h>
#include <delay.h>
#include "calculator.h"

Calculator calculator;

int main() {
	calculator_init(&calculator);
	
	LCDconfigure();

	LCDgoto(0, 8);
	LCDputchar('+');
}
