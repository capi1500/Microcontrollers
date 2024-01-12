#ifndef _LCD_H
#define _LCD_H 1

#include "fonts.h"

void LCDconfigure(const font_t* font);
void LCDclear(void);
void LCDgoto(int textLine, int charPos);
void LCDputchar(char c);
void LCDputcharWrap(char c);

#endif
