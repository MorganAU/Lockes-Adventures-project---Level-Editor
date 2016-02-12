//LAD - SDL 2.0
//Level Editor v.0.9
//draw.c

#include "draw.h"

#include "init.h"
#include "font.h"
#include "loadResources.h"
#include "management.h"

void draw_drawInterface(void);
void draw_drawImage(SDL_Texture *image, int x, int y);
void draw_drawTilePlus(SDL_Texture *texture, int destX, int destY, int srcX, int srcY, int w, int h);

static Graphics graphics;


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
        draw_drawTilePlus(graphics.editorBackground,
                          0, 0,
                          0, 0,
                          management_getManagementScreenWidth(), management_getManagementScreenHeight());

}



/* Change the width depending on the size */
int draw_resizeTexture(int textureSize, int screenSize)
{
    /* '1' is the beginning or ending of menu bar */
    int i = screenSize / (textureSize - 1);

    if(screenSize % (textureSize - 1) > 0)
        i++;



    return i;

}



void draw_drawTextureWithLoop(SDL_Texture *texture, int width, int height)
{
        int numberLoop = draw_resizeTexture(width, management_getManagementScreenWidth());
        int temp = 0;

        for(int i = 0 ; i < numberLoop ; i++)
        {
            int xSrc = i == 0 ? 0
                       : i == numberLoop - 1 ? width - (management_getManagementScreenWidth() - temp)
                       : 1;


            int w = (i > 0 && i < numberLoop - 1) ? 2
                    : 1;

            draw_drawTilePlus(texture, temp, 0, xSrc, 0, width - w, height);

            temp += width - w;
        }

}



void draw_drawMenuBar(void)
{
    draw_drawTextureWithLoop(graphics.interface, MENUBAR_W, MENUBAR_H);

    font_writeMenuBarText();

}



void draw_drawInterface(void)
{
    if(graphics.interface == NULL)
        loadResources_loadEditorInterface();
    else
    {
        draw_drawMenuBar();

    }

}



void draw_drawEditor(void)
{
    draw_drawEditorBackground();
    draw_drawInterface();

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

    if (graphics.interface != NULL)
    {
        SDL_DestroyTexture(graphics.interface);
        graphics.interface = NULL;
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



SDL_Texture *draw_getGraphicsInterface(void)
{
    return graphics.interface;

}



///////***** MUTATORS *****///////
void draw_setGraphicsTexture(int texture, char *path)
{
    if(texture == TEXTURE_EDITOR_BACKGROUND)
        graphics.editorBackground = loadResources_loadGraphics(path);
    else if(texture == TEXTURE_INTERFACE)
        graphics.interface = loadResources_loadGraphics(path);

}



























