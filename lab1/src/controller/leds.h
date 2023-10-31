#ifndef LEDS_H
#define LEDS_H

#include <gpio.h>
#include <stm32.h>
#include "../types.h"

#define RED_LED_GPIO GPIOA
#define GREEN_LED_GPIO GPIOA
#define BLUE_LED_GPIO GPIOB
#define GREEN2_LED_GPIO GPIOA
#define RED_LED_PIN 6
#define GREEN_LED_PIN 7
#define BLUE_LED_PIN 0
#define GREEN2_LED_PIN 5

#define RedLEDon() \
RED_LED_GPIO->BSRR = 1 << (RED_LED_PIN + 16)
#define RedLEDoff() \
RED_LED_GPIO->BSRR = 1 << RED_LED_PIN

#define GreenLEDon() \
GREEN_LED_GPIO->BSRR = 1 << (GREEN_LED_PIN + 16)
#define GreenLEDoff() \
GREEN_LED_GPIO->BSRR = 1 << GREEN_LED_PIN

#define BlueLEDon() \
BLUE_LED_GPIO->BSRR = 1 << (BLUE_LED_PIN + 16)
#define BlueLEDoff() \
BLUE_LED_GPIO->BSRR = 1 << BLUE_LED_PIN

#define Green2LEDon() \
GREEN2_LED_GPIO->BSRR = 1 << GREEN2_LED_PIN
#define Green2LEDoff() \
GREEN2_LED_GPIO->BSRR = 1 << (GREEN2_LED_PIN + 16)

typedef struct {
	bool red;
	bool green;
	bool blue;
	bool green2;
} led_state;

void init_leds(led_state* l);

void on_red(led_state* l);
void off_red(led_state* l);
void toggle_red(led_state* l);

void on_blue(led_state* l);
void off_blue(led_state* l);
void toggle_blue(led_state* l);

void on_green(led_state* l);
void off_green(led_state* l);
void toggle_green(led_state* l);

void on_green2(led_state* l);
void off_green2(led_state* l);
void toggle_green2(led_state* l);

#endif // LEDS_H
