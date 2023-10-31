#ifndef BUTTONS_H
#define BUTTONS_H

#include <gpio.h>
#include <stm32.h>
#include "../types.h"

#define LEFT_BTN_GPIO GPIOB
#define LEFT_BTN_PIN 3
#define RIGHT_BTN_GPIO GPIOB
#define RIGHT_BTN_PIN 4
#define UP_BTN_GPIO GPIOB
#define UP_BTN_PIN 5
#define DOWN_BTN_GPIO GPIOB
#define DOWN_BTN_PIN 6
#define FIRE_BTN_GPIO GPIOB
#define FIRE_BTN_PIN 10

#define MODE_BTN_GPIO GPIOA
#define MODE_BTN_PIN 0

#define USER_BTN_GPIO GPIOC
#define USER_BTN_PIN 13

#define LEFT_BTN_PRESSED() \
(((LEFT_BTN_GPIO->IDR >> LEFT_BTN_PIN) & 1) == 0)
#define RIGHT_BTN_PRESSED() \
(((RIGHT_BTN_GPIO->IDR >> RIGHT_BTN_PIN) & 1) == 0)
#define UP_BTN_PRESSED() \
(((UP_BTN_GPIO->IDR >> UP_BTN_PIN) & 1) == 0)
#define DOWN_BTN_PRESSED() \
(((DOWN_BTN_GPIO->IDR >> DOWN_BTN_PIN) & 1) == 0)
#define FIRE_BTN_PRESSED() \
(((FIRE_BTN_GPIO->IDR >> FIRE_BTN_PIN) & 1) == 0)

#define MODE_BTN_PRESSED() \
(((MODE_BTN_GPIO->IDR >> MODE_BTN_PIN) & 1) == 1)

#define USER_BTN_PRESSED() \
(((USER_BTN_GPIO->IDR >> USER_BTN_PIN) & 1) == 0)


typedef struct {
	bool left;
	bool right;
	bool up;
	bool down;
	bool fire;
	bool user;
	bool mode;
} buttons_state;

void init_buttons(buttons_state* buttons);

bool left_changed(buttons_state* buttons);
bool right_changed(buttons_state* buttons);
bool up_changed(buttons_state* buttons);
bool down_changed(buttons_state* buttons);
bool fire_changed(buttons_state* buttons);
bool user_changed(buttons_state* buttons);
bool mode_changed(buttons_state* buttons);

#endif // BUTTONS_H
