#include "interrupts.h"

typedef struct {
    bool enabled;
    int32_t irq;
    uint8_t pin_begin;
    uint8_t pin_end;
} PeripheryInterruptConfig;

#define PERIPHERY_CONFIG_COUNT 7
static PeripheryInterruptConfig periphery_config[PERIPHERY_CONFIG_COUNT];

typedef struct {
	bool enabled;
	int32_t irq;
	Timer* timer;
} TimerInterruptConfig;

#define TIMER_CONFIG_COUNT 4
static TimerInterruptConfig timer_config[TIMER_CONFIG_COUNT];

void init_periphery_config(PeripheryInterruptConfig* c, int32_t irq, uint8_t pin_begin, uint8_t pin_end) {
	c->irq = irq;
	c->pin_begin = pin_begin;
	c->pin_end = pin_end;
	c->enabled = false;
}

void init_timer_config(TimerInterruptConfig* c, Timer* timer, int32_t irq) {
	c->irq = irq;
	c->timer = timer;
	c->enabled = false;
}

void interrupts_init(void) {
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	
	init_periphery_config(&periphery_config[0], EXTI0_IRQn, 0, 0);
	init_periphery_config(&periphery_config[1], EXTI1_IRQn, 1, 1);
	init_periphery_config(&periphery_config[2], EXTI2_IRQn, 2, 2);
	init_periphery_config(&periphery_config[3], EXTI3_IRQn, 3, 3);
	init_periphery_config(&periphery_config[4], EXTI4_IRQn, 4, 4);
	init_periphery_config(&periphery_config[5], EXTI9_5_IRQn, 5, 9);
	init_periphery_config(&periphery_config[6], EXTI15_10_IRQn, 10, 15);
	
	init_timer_config(&timer_config[0], TIM2, TIM2_IRQn);
	init_timer_config(&timer_config[1], TIM3, TIM3_IRQn);
	init_timer_config(&timer_config[2], TIM4, TIM4_IRQn);
	init_timer_config(&timer_config[3], TIM5, TIM5_IRQn);
}

void periphery_interrupts_setup(Periphery* periphery, EXTITrigger_TypeDef trigger) {
	GPIOinConfigure(
			periphery->GPIO,
			periphery->pin,
			periphery->enabled_state ? GPIO_PuPd_UP : GPIO_PuPd_DOWN,
			EXTI_Mode_Interrupt,
			trigger);
	
	EXTI->PR = (1 << periphery->pin);
	
	periphery_interrupts_enable(periphery);
}

void periphery_interrupts_enable(Periphery* periphery) {
	for (int i = 0; i < PERIPHERY_CONFIG_COUNT; i++) {
		if (periphery_config[i].pin_begin <= periphery->pin && periphery->pin <= periphery_config[i].pin_end) {
			if (!periphery_config[i].enabled) {
				periphery_config[i].enabled = true;
				NVIC_EnableIRQ(periphery_config[i].irq);
			}
			break;
		}
	}
}

void periphery_interrupts_disable(Periphery* periphery) {
	for (int i = 0; i < PERIPHERY_CONFIG_COUNT; i++) {
		if (periphery_config[i].pin_begin <= periphery->pin && periphery->pin <= periphery_config[i].pin_end) {
			if (periphery_config[i].enabled) {
				periphery_config[i].enabled = false;
				NVIC_DisableIRQ(periphery_config[i].irq);
			}
			break;
		}
	}
}

void timer_interrupts_enable(Timer* timer) {
	for (int i = 0; i < TIMER_CONFIG_COUNT; i++) {
		if (timer_config[i].timer == timer) {
			if (!timer_config[i].enabled) {
				timer_config[i].enabled = true;
				NVIC_EnableIRQ(timer_config[i].irq);
			}
			break;
		}
	}
}

void timer_interrupts_disable(Timer* timer) {
	for (int i = 0; i < TIMER_CONFIG_COUNT; i++) {
		if (timer_config[i].timer == timer) {
			if (timer_config[i].enabled) {
				timer_config[i].enabled = false;
				NVIC_DisableIRQ(timer_config[i].irq);
			}
			break;
		}
	}
}
