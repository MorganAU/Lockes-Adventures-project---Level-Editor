//LAD - SDL 2.0
//Level Editor v.0.9
//structs.h

#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED


typedef struct Graphics
{
    SDL_Window *screen;
	SDL_Renderer *renderer;

	SDL_Texture *editorBackground, *interface;


} Graphics;


typedef struct Management
{
    /* Windows size */
	int screenHeight, screenWidth;

} Management;


typedef struct Font
{
    /* Font size used by the program */
    TTF_Font *font8;

} Font;


#endif // STRUCTS_H_INCLUDED
