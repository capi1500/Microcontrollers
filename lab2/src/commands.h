#ifndef COMMANDS_H
#define COMMANDS_H

#include "periphery/buttons.h"

void init_button_messages();
const char* button_get_message(Button button);

#endif // COMMANDS_H