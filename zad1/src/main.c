#include <delay.h>
#include "calculator.h"
#include "display.h"

Calculator calculator;

int main() {
	calculator_init(&calculator);
	display_init();
}
