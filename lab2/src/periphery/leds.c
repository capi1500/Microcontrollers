#include "leds.h"

static Periphery leds[LEDS_COUNT];

Periphery* get_leds() {
	return leds;
}

void init_leds() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN;
	
	__NOP();
	
	periphery_init(&leds[LED_RED], GPIOA, 6, true);
	periphery_init(&leds[LED_GREEN], GPIOA, 7, true);
	periphery_init(&leds[LED_BLUE], GPIOB, 0, true);
	periphery_init(&leds[LED_GREEN2], GPIOA, 5, false);
	
	for (int i = 0; i < LEDS_COUNT; i++) {
		periphery_set(&leds[i], false);
		GPIOoutConfigure(leds[i].GPIO,
						 leds[i].pin,
						 GPIO_OType_PP,
						 GPIO_Low_Speed,
						 GPIO_PuPd_NOPULL);
	}
}
