//LAD - SDL 2.0
//Level Editor v.0.9
//init.c

#include "init.h"

#include "draw.h"
#include "management.h"


void init(char *title)
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


}



void cleanup(void)
{
    draw_closeGraphics();

    draw_cleanWindowAndRenderer();

    /* Quitte la SDL */
    SDL_Quit();

}























