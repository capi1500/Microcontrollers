#include "leds.h"

void init_leds(led_state* l) {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN;
	
    __NOP();

	off_red(l);
	off_blue(l);
	off_green(l);
	off_green2(l);

    GPIOoutConfigure(RED_LED_GPIO,
        RED_LED_PIN,
        GPIO_OType_PP,
        GPIO_Low_Speed,
        GPIO_PuPd_NOPULL);
    GPIOoutConfigure(GREEN_LED_GPIO,
        GREEN_LED_PIN,
        GPIO_OType_PP,
        GPIO_Low_Speed,
        GPIO_PuPd_NOPULL);
    GPIOoutConfigure(BLUE_LED_GPIO,
        BLUE_LED_PIN,
        GPIO_OType_PP,
        GPIO_Low_Speed,
        GPIO_PuPd_NOPULL);
    GPIOoutConfigure(GREEN2_LED_GPIO,
        GREEN2_LED_PIN,
        GPIO_OType_PP,
        GPIO_Low_Speed,
        GPIO_PuPd_NOPULL);
}

void on_red(led_state* l) {
	l->red = true;
	RedLEDon();
}
void off_red(led_state* l) {
	l->red = false;
	RedLEDoff();
}
void toggle_red(led_state* l) {
	if (l->red) {
		off_red(l);
	} else {
		on_red(l);
	}
}

void on_blue(led_state* l) {
	l->blue = true;
	BlueLEDon();
}
void off_blue(led_state* l) {
	l->blue = false;
	BlueLEDoff();
}
void toggle_blue(led_state* l) {
	if (l->blue) {
		off_blue(l);
	} else {
		on_blue(l);
	}
}

void on_green(led_state* l) {
	l->green = true;
	GreenLEDon();
}
void off_green(led_state* l) {
	l->green = false;
	GreenLEDoff();
}
void toggle_green(led_state* l) {
	if (l->green) {
		off_green(l);
	} else {
		on_green(l);
	}
}

void on_green2(led_state* l) {
	l->green2 = true;
	Green2LEDon();
}
void off_green2(led_state* l) {
	l->green2 = false;
	Green2LEDoff();
}
void toggle_green2(led_state* l) {
	if (l->green2) {
		off_green2(l);
	} else {
		on_green2(l);
	}
}
