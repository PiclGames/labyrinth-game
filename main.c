#include "game.h"
#include "menu.h"
#include <stdlib.h>

//----------------------MAIN------------------
int main()
{
    labyrinth *lab = malloc(sizeof(labyrinth));
    generate_labyrinth(lab, 11, 25);
    display_labyrinth(lab);

    //start_menu();
}
