#include "interrupts.h"

typedef struct {
    bool enabled;
    int32_t irq;
    uint8_t pin_begin;
    uint8_t pin_end;
} Config;

#define CONFIG_COUNT 7

static Config config[CONFIG_COUNT];

void init_config(Config* c, int32_t irq, uint8_t pin_begin, uint8_t pin_end) {
	c->irq = irq;
	c->pin_begin = pin_begin;
	c->pin_end = pin_end;
	c->enabled = false;
}

void interrupts_init() {
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	init_config(&config[0], EXTI0_IRQn, 0, 0);
	init_config(&config[1], EXTI1_IRQn, 1, 1);
	init_config(&config[2], EXTI2_IRQn, 2, 2);
	init_config(&config[3], EXTI3_IRQn, 3, 3);
	init_config(&config[4], EXTI4_IRQn, 4, 4);
	init_config(&config[5], EXTI9_5_IRQn, 5, 9);
	init_config(&config[6], EXTI15_10_IRQn, 10, 15);
}

void interrupt_periphery_setup(Periphery* periphery) {
	uint8_t pin = periphery->pin;
	GPIOinConfigure(
			periphery->GPIO,
			pin,
			periphery->enabled_state ? GPIO_PuPd_UP : GPIO_PuPd_DOWN,
			EXTI_Mode_Interrupt,
			EXTI_Trigger_Rising_Falling);
	
	EXTI->PR = (1 << pin);
	
	for (int i = 0; i < CONFIG_COUNT; i++) {
		if (config[i].pin_begin <= pin && pin <= config[i].pin_end && !config[i].enabled) {
			NVIC_EnableIRQ(config[i].irq);
			config[i].enabled = true;
			break;
		}
	}
}
