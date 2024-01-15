#include "periphery.h"
#include "delay.h"

void periphery_init(Periphery* periphery, GPIO_TypeDef* GPIO, uint8_t pin, bool enabled_state) {
    periphery->GPIO = GPIO;
    periphery->pin = pin;
    periphery->mask = (1 << pin);
    periphery->enabled_state = enabled_state;
    periphery->state = false;
}

void periphery_set(Periphery* periphery, bool value) {
    // 1 && 0
    // 0 && 1
    if (periphery->enabled_state ^ value)
        periphery->GPIO->BSRR = 1 << periphery->pin;
    // 1 && 1
    // 0 && 0
    else
        periphery->GPIO->BSRR = 1 << (periphery->pin + 16);
    periphery->state = value;
}

void periphery_toggle(Periphery* periphery) {
    periphery_set(periphery, !periphery->state);
}

bool periphery_read_state(Periphery* periphery) {
	periphery->state = ((periphery->GPIO->IDR >> periphery->pin) & 1) == (periphery->enabled_state ? 1 : 0);
	return periphery->state;
}

bool periphery_is_on(Periphery* periphery) {
    return periphery->state;
}

void periphery_is_on_with_repeat(Periphery* periphery, fn_void handle) {
	int t = 40000; // 10ms
	int count = 0;
	int timeout = 50; // 500ms
	if (periphery_is_on(periphery)) {
		Delay(t);
		while (periphery_is_on(periphery)) {
			handle();
			count = 0;
			while (periphery_is_on(periphery) && (count < timeout)) {
				Delay(t);
				count++;
			}
			timeout /= 2;
		}
	}
}

bool periphery_read_state_is_changed(Periphery* periphery) {
    bool previous = periphery->state;
    periphery->state = periphery_is_on(periphery);
    return periphery->state != previous;
}