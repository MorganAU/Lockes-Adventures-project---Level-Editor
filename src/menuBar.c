//LAD - SDL 2.0
//Level Editor v.0.9
//menuBar.c

#include "menuBar.h"

#include "font.h"

void menuBar_menuFile(void)
{
    font_writeString("File",
                     MENUBAR_FILE_TEXT_START_X, MENUBAR_FILE_TEXT_START_Y,
                     BLACK, COLOR_NONE,
                     font_getFontSize(13));

}




























