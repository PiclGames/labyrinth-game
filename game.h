#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ansi_color_codes.h"

#ifndef MINI_PROJET_GAME_H


//---------------direction-----------------
typedef enum direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
}direction;

//--------------struct of the labyrinth----
typedef struct labyrinth{
    int height, width;
    int **labyrinth;
    char name[45];
}labyrinth;



//-------------fonctions-------------------

/*
 * @param labyrinth lab : the labyrinth to display
 */
void display_labyrinth(labyrinth* lab);

/*
 * @param labyrinth lab : the lab to init
 */
void init(labyrinth* lab, int height, int width);


void replace(labyrinth *lab, int target, int val);

int apply_val(labyrinth *lab, int val, int x, int y, direction direction);

int randomOddInRange(int min, int max);

/*
 * @param labyrinth lab : the lab variable in which we generate the lab
 * @param debug : 1 = yes 0 = no;
 */
void generate_labyrinth(labyrinth *lab, int height, int width);


int play(labyrinth *lab);


#define MINI_PROJET_GAME_H

#endif //MINI_PROJET_GAME_H
