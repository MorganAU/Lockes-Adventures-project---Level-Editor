//LAD - SDL 2.0
//Level Editor v.0.9
//input.c

#include "input.h"


void getInput(void)
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
        }
    }

}



































