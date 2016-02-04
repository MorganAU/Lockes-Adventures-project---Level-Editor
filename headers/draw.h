//LAD - SDL 2.0
//Level Editor v.0.9
//draw.h

#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED


#include "defs.h"

extern void draw_drawWindow(char *title);
extern void draw_drawRenderer(void);
extern void draw_cleanWindowAndRenderer(void);
extern void draw_drawEditor(void);
extern void draw_closeGraphics(void);
extern SDL_Window *draw_getGraphicsScreen(void);
extern SDL_Renderer *draw_getGraphicsRenderer(void);
extern SDL_Texture *draw_getGraphicsEditorBackground(void);
extern void draw_setGraphicsTexture(int texture, char *path);


/* Backgrounds coordinates + outline */
#define BACKGROUND_X_DEST 5
#define BACKGROUND_Y_DEST 93



#endif // DRAW_H_INCLUDED
