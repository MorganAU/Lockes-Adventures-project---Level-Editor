//LAD - SDL 2.0
//Level Editor v.0.9
//management.c

#include "management.h"

static Management management;


void management_delay(unsigned int frameLimit)
{
    /* Gestion des 60 fps */
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
        return;

    if (frameLimit > ticks + 16)
        SDL_Delay(16);
    else
        SDL_Delay(frameLimit - ticks);

}



///////***** ACCESSORS *****///////
int management_getManagementScreenHeight(void)
{
    return management.screenHeight;

}



int management_getManagementScreenWidth(void)
{
    return management.screenWidth;

}



///////***** MUTATORS *****///////
void management_setManagementScreenWidth(int width)
{
    management.screenWidth = width;

}



void management_setManagementScreenHeight(int height)
{
    management.screenHeight = height;

}























