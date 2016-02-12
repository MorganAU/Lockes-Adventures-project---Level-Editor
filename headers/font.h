//LAD - SDL 2.0
//Level Editor v.0.9
//font.h

#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED


#include "defs.h"


void font_loadFont(char *name);
void font_closeFont(void);
void font_writeString(char *text, int x, int y, int rgbaFore, int rgbaBack,
                      TTF_Font *fontSize);
void font_writeMenuBarText(void);
TTF_Font *font_getFontSize(int size);


#endif // FONT_H_INCLUDED
