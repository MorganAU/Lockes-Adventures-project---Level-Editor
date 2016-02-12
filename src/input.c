//LAD - SDL 2.0
//Level Editor v.0.9
//input.c

#include "input.h"

#include "draw.h"
#include "management.h"

void input_windowResize(SDL_Event event);


void input_getInput(void)
{
    SDL_Event event;

    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
        case SDL_QUIT:
            exit(EXIT_SUCCESS);
            break;

        case SDL_WINDOWEVENT:
            input_windowResize(event);
            break;

        }

    }
}



void input_windowResize(SDL_Event event)
{
    if(event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
    {
        management_setManagementScreenWidth(event.window.data1);
        management_setManagementScreenHeight(event.window.data2);
    }

    if(event.window.event == SDL_WINDOWEVENT_RESIZED)
        SDL_SetWindowSize(draw_getGraphicsScreen(),
                          management_getManagementScreenWidth(),
                          management_getManagementScreenHeight());

}


































