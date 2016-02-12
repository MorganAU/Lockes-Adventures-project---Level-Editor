//LAD - SDL 2.0
//Level Editor v.0.9
//loadResources.c

#include "loadResources.h"

#include "draw.h"


SDL_Texture *loadResources_loadGraphics(char *name)
{
    /* Load pictures with SDL Image in SDL_Surface */
    SDL_Surface *loadedImage = IMG_Load(name);
    SDL_Texture *texture = NULL;

    if(loadedImage != NULL)
    {
        /* Type conversion image -> texture */
        texture = SDL_CreateTextureFromSurface(draw_getGraphicsRenderer(), loadedImage);

        SDL_FreeSurface(loadedImage);
        loadedImage = NULL;
    }
    else
        printf("Can't load ! SDL_Error :  %s\n", SDL_GetError());

    return texture;

}



void loadResources_loadEditorBackground(void)
{
    draw_setGraphicsTexture(TEXTURE_EDITOR_BACKGROUND, PATH_GRAPHICS_EDITOR_BACKGROUND);

    if(draw_getGraphicsEditorBackground() == NULL)
    {
        printf("SDL_Texture graphics.editorBackground is <null> -> loadRessources.c -> l.33 !\n");
        exit(EXIT_FAILURE);
    }

}



void loadResources_loadEditorInterface(void)
{
    draw_setGraphicsTexture(TEXTURE_INTERFACE, PATH_GRAPHICS_INTERFACE);

    if(draw_getGraphicsInterface() == NULL)
    {
        printf("SDL_Texture graphics.interface is <null> -> loadRessources.c -> l.47 !\n");
        exit(EXIT_FAILURE);
    }

}






















