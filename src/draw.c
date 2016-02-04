//LAD - SDL 2.0
//Level Editor v.0.9
//draw.c

#include "draw.h"

#include "loadResources.h"
#include "management.h"

void draw_drawInterface(void);
void draw_drawImage(SDL_Texture *image, int x, int y);
void draw_drawTilePlus(SDL_Texture *texture, int destX, int destY, int srcX, int srcY, int w, int h);

Graphics graphics;


void draw_drawWindow(char *title)
{
    graphics.screen = SDL_CreateWindow(title,
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       management_getManagementScreenWidth(),
                                       management_getManagementScreenHeight(),
                                       SDL_WINDOW_RESIZABLE);

}



void draw_drawRenderer(void)
{
    graphics.renderer = SDL_CreateRenderer(graphics.screen, -1, SDL_RENDERER_PRESENTVSYNC);

}



void draw_cleanWindowAndRenderer(void)
{
    SDL_DestroyRenderer(graphics.renderer);
    graphics.renderer = NULL;

    SDL_DestroyWindow(graphics.screen);
    graphics.screen = NULL;

}



void draw_drawEditorBackground(void)
{
    if(graphics.editorBackground == NULL)
        loadResources_loadEditorBackground();
    else
        /* Affiche la fenêtre de mapping */
        draw_drawImage(graphics.editorBackground, 0, 0);

}



void draw_drawEditor(void)
{
    draw_drawEditorBackground();

    SDL_RenderPresent(graphics.renderer);

    /* For processor */
    SDL_Delay(1);



}



void draw_drawImage(SDL_Texture *image, int x, int y)
{
    SDL_Rect dest;

    /* Règle le rectangle à dessiner selon la taille de l'image source */

    dest.x = x;
    dest.y = y;

    /* Dessine l'image entière sur l'écran aux coordonnées x et y */
    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(graphics.renderer, image, NULL, &dest);

}



/* Draw a whole picture or part */
void draw_drawTilePlus(SDL_Texture *texture, int destX, int destY, int srcX, int srcY, int w, int h)
{
    /* Dest */
    SDL_Rect dest;

    dest.x = destX;
    dest.y = destY;
    dest.w = w;
    dest.h = h;

    /* Source */
    SDL_Rect src;

    src.x = srcX;
    src.y = srcY;
    src.w = w;
    src.h = h;

    SDL_RenderCopy(graphics.renderer, texture, &src, &dest);

}




void draw_closeGraphics(void)
{
    if (graphics.editorBackground != NULL)
    {
        SDL_DestroyTexture(graphics.editorBackground);
        graphics.editorBackground = NULL;
    }

}



///////***** ACCESSORS *****///////
SDL_Window *draw_getGraphicsScreen(void)
{
    return graphics.screen;

}



SDL_Renderer *draw_getGraphicsRenderer(void)
{
    return graphics.renderer;

}



SDL_Texture *draw_getGraphicsEditorBackground(void)
{
    return graphics.editorBackground;

}



///////***** MUTATORS *****///////
void draw_setGraphicsTexture(int texture, char *path)
{
    if(texture == TEXTURE_EDITOR_BACKGROUND)
    graphics.editorBackground = loadResources_loadGraphics(path);

}



























