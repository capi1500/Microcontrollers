#ifndef INPUT_H
#define INPUT_H

typedef enum {
	Num0 = 0,
	Num1,
	Num2,
	Num3,
	Num4,
	Num5,
	Num6,
	Num7,
	Num8,
	Num9,
	OpPlus = 10,
	OpMinus,
	OpMul,
	OpDiv,
	OpResult = 14,
	OpClear = 15,
	OpNone
} Input;

// Pobranie liczby oczekujących zdarzeń
unsigned input_get_event_count(void);
// Pobranie pierwszego oczekującego zdarzenia
Input input_get_event(void);

// Dodanie nowego zdarzenia
void input_add_event(Input input);

#endif // INPUT_H
