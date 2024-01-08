#include <lcd.h>
#include <delay.h>

int main() {
	LCDconfigure();	

	LCDgoto(0, 8);
	LCDputchar('+');
}
