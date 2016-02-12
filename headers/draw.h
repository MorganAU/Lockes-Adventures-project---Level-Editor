//LAD - SDL 2.0
//Level Editor v.0.9
//draw.h

#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED


#include "defs.h"


void draw_drawWindow(char *title);
void draw_drawRenderer(void);
void draw_cleanWindowAndRenderer(void);
void draw_drawEditor(void);
void draw_closeGraphics(void);
SDL_Window *draw_getGraphicsScreen(void);
SDL_Renderer *draw_getGraphicsRenderer(void);
SDL_Texture *draw_getGraphicsEditorBackground(void);
SDL_Texture *draw_getGraphicsInterface(void);
void draw_setGraphicsTexture(int texture, char *path);


/* Backgrounds editor coordinates */
#define BACKGROUND_X_DEST 5
#define BACKGROUND_Y_DEST 93


/* Menu Bar coordinates */
#define MENUBAR_X_SRC 0
#define MENUBAR_Y_SRC 0

#define MENUBAR_X_DEST 0
#define MENUBAR_Y_DEST 0

#define MENUBAR_W 211
#define MENUBAR_H 23


#endif // DRAW_H_INCLUDED
