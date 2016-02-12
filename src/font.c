//LAD - SDL 2.0
//Level Editor v.0.9
//font.c

#include "font.h"

#include "draw.h"
#include "menuBar.h"

void font_colorNumber(SDL_Color *color, int rgba);
void font_setColor(SDL_Color *color, int r, int g, int b, int a);
void font_convertText(SDL_Surface *surface, int x, int y);

static Font font;


void font_loadFont(char *name)
{
    /* Use SDL_TTF to load the font at the specified size */
    font.font8 = TTF_OpenFont(name, 8);

    if(font.font8 == NULL)
    {
        printf("Failed to open Font %s: %s\n", name, TTF_GetError());
        exit(EXIT_FAILURE);
    }

}



void font_closeFont(void)
{
    /* Close the font once we're done with it */
    if(font.font8 != NULL)
        TTF_CloseFont(font.font8);

}



/* Wrote the text to coordinates x and y with a foreground  and background color.
   If no background color rgbaBack = -1 */
void font_writeString(char *text, int x, int y, int rgbaFore, int rgbaBack,
                      TTF_Font *fontSize)
{
    SDL_Surface *surface, *surfaceOption = NULL; /* To write the text */
    SDL_Color foregroundColor, backgroundColor;
    TTF_Font *fontChoosen;


    /* Couleur du texte RGBA */
    font_colorNumber(&foregroundColor, rgbaFore);

    if(rgbaBack >= 0)
        font_colorNumber(&backgroundColor, rgbaBack);

    fontChoosen = fontSize;
    fontSize = NULL;

    /* On utilise SDL_TTF pour générer une SDL_Surface à partir d'une chaîne de caractères (string) */
    surface = TTF_RenderUTF8_Blended(fontChoosen, text, foregroundColor);

    if(rgbaBack >= 0)
        surfaceOption = TTF_RenderUTF8_Blended(fontChoosen, text, backgroundColor);

    fontChoosen = NULL;

    if(surface != NULL)
        font_convertText(surface, x, y);

    if(surfaceOption != NULL && rgbaBack >= 0)
        font_convertText(surfaceOption, x + 1, y + 1);

    surface = surfaceOption = NULL;

}



void font_colorNumber(SDL_Color *color, int rgba)
{
    if(rgba == BLACK)
        font_setColor(color, 0, 0, 0, 255);
    else if(rgba == WHITE)
        font_setColor(color, 255, 255, 255, 255);

}



void font_setColor(SDL_Color *color, int r, int g, int b, int a)
{
    color->r = r;
    color->g = g;
    color->b = b;
    color->a = a;

}



void font_convertText(SDL_Surface *surface, int x, int y)
{
    SDL_Texture *texture;
    SDL_Rect dest;

    texture = SDL_CreateTextureFromSurface(draw_getGraphicsRenderer(), surface);

    SDL_FreeSurface(surface);
    surface = NULL;

    dest.x = x;
    dest.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(draw_getGraphicsRenderer(), texture, NULL, &dest);

    SDL_DestroyTexture(texture);

}



void font_writeMenuBarText(void)
{
    menuBar_menuFile();

}



///////***** ACCESSORS *****///////
TTF_Font *font_getFontSize(int size)
{
        return font.font8;

}
















