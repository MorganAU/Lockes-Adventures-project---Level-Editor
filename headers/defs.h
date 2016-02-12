//LAD - SDL 2.0
//Level Editor v.0.9
//defs.h

#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>


/* Add SDL2 libs */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h >


/* Add structures */
#include "structs.h"


/* Font path */
 #define PATH_FONT_GENBASB "ressources/font/PIXEARG_.ttf"


/* Graphics resources path */
#define PATH_GRAPHICS_EDITOR_BACKGROUND "ressources/graphics/editor/editor_background.png"
#define PATH_GRAPHICS_INTERFACE "ressources/graphics/editor/interface.png"


/* List of texture */
#define TEXTURE_EDITOR_BACKGROUND 1
#define TEXTURE_INTERFACE 2


/* List of setColor */
#define COLOR_NONE -1
#define WHITE 0
#define BLACK 1


#endif // DEFS_H_INCLUDED
