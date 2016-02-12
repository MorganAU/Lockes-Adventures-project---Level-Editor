//LAD - SDL 2.0
//Level Editor v.0.9
//init.c

#include "init.h"

#include "draw.h"
#include "font.h"
#include "management.h"


void init_init(char *title)
{
    management_setManagementScreenWidth(WINDOW_MINIMUM_SIZE);
    management_setManagementScreenHeight(WINDOW_MINIMUM_SIZE);

    /* Initialize SDL Video */
    draw_drawWindow(title);

    SDL_SetWindowMinimumSize(draw_getGraphicsScreen(),
                             WINDOW_MINIMUM_SIZE,
                             WINDOW_MINIMUM_SIZE);

    draw_drawRenderer();

    if(draw_getGraphicsScreen() == NULL || draw_getGraphicsRenderer() == NULL)
    {
        printf("Couldn't initialize %d x %d screen mode: %s\n",
               management_getManagementScreenWidth(),
               management_getManagementScreenHeight(),
               SDL_GetError());

        exit(EXIT_FAILURE);
    }

    /* Initialize images flag */
    int imgFlags = IMG_INIT_PNG;

    if(!(IMG_Init(imgFlags)&imgFlags))
    {
        printf( "Couldn't initialize SDL Image: %s\n", IMG_GetError() );
        exit(EXIT_FAILURE);
    }

    /* Initialize SDL_TTF */
    if(TTF_Init() < 0)
    {
        printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    /* Load the font */
    font_loadFont(PATH_FONT_GENBASB);


}



void init_cleanup(void)
{
    /* Clean graphics */
    draw_closeGraphics();
    draw_cleanWindowAndRenderer();

    /* Close fonts */
    font_closeFont();

    /* Quitte la SDL */
    SDL_Quit();

}























