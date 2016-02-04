//Locke's Adventures Project - SDL 2.0
//Level Editor v.0.9
//main.c

#include "defs.h"

#include "draw.h"
#include "init.h"
#include "input.h"
#include "loadResources.h"
#include "management.h"


int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

   	/* Initializing the SDL */
	init("Level Editor");

    /* Load resources */
    loadResources_loadEditor();


	/* Call cleanup function at the end of program */
    atexit(cleanup);

    unsigned int frameLimit = 16;
    int go = 1;

	/* Main loop */
	while(go)
	{
	    getInput();

	    /* Display */
	    draw_drawEditor();

		/* 60 fps management (1000ms/60 = 16.6 -> 16 */
        management_delay(frameLimit);
		frameLimit = SDL_GetTicks() + 16;

	}

	/* Exit */
	exit(EXIT_SUCCESS);

}

