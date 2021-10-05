#include "game.h"

/*
 * @param labyrinth lab : the labyrinth to display
 */
void display_labyrinth(labyrinth* lab) {
    printf("\n\n\nLabyrinthe %s \n", lab->name);
    for (int i = 0; i < lab->height; ++i) {
        for (int j = 0; j < lab->width; ++j) {
            switch (lab->labyrinth[i][j]) {
                case 0:
                    printf("%s  %s",WHTB, reset);
                    break;
                case -1:
                    printf("%s  %s", GRNB, reset);
                    break;
                case -2:
                    printf("%s  %s", REDB, reset);
                    break;
                default:
                    //printf("%2d", lab->labyrinth[i][j]);
                    printf("%s  %s", BLKB, reset);
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * @param labyrinth lab : the lab to init
 */
void init(labyrinth* lab, int height, int width){
    lab->height = height;
    lab->width = width;
    lab->labyrinth = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++)
        lab->labyrinth[i] = (int*)malloc(width * sizeof(int));
    int val = 1;
    for(int i = 0; i < height/2;++i) {
        for(int j =0; j < width/2;++j) {
            lab->labyrinth[i*2+1][j*2+1] = val;
            ++val;
        }
    }
    lab->labyrinth[0][1]=-1;
    lab->labyrinth[height-1][width-2]=-2;
}


void replace(labyrinth *lab, int target, int val) {
    for (int i = 0; i < lab->height; ++i) {
        for (int j = 0; j < lab->width; ++j) {
            if(lab->labyrinth[i][j] == target)
                lab->labyrinth[i][j] = val;
        }
    }
}

int apply_val(labyrinth *lab, int val, int x, int y, direction direction) {
    int temp;
    switch (direction) {
        case UP:
            if(x>2) {
                temp = lab->labyrinth[x-2][y];
                if(temp != val) {
                    lab->labyrinth[x - 1][y] = val;
                    replace(lab, temp, val);
                    return 1;
                }
            }
            break;
        case RIGHT:
            if(y < lab->width - 2) {
                temp = lab->labyrinth[x][y+2];
                if(temp != val) {
                    lab->labyrinth[x][y+1]=val;
                    replace(lab, temp, val);
                    return 1;
                }
            }
            break;
        case DOWN:
            if(x < lab->height - 2) {
                temp = lab->labyrinth[x+2][y];
                if(temp != val) {
                    lab->labyrinth[x+1][y]=val;
                    replace(lab, temp, val);
                    return 1;
                }
            }
            break;
        case LEFT:
            if(y>2) {
                temp = lab->labyrinth[x][y-2];
                if(temp != val) {
                    lab->labyrinth[x][y-1]=val;
                    replace(lab, temp, val);
                    return 1;
                }

            }
            break;
    }
    return 0;
}

int random_odd_in_ange(int min, int max) {
    return (int)(rand() % (max - min - 1) / 2) * 2 + min + 1;
}

/*
 * @param labyrinth lab : the lab variable in which we generate the lab
 * @param debug : 1 = yes 0 = no;
 */
void generate_labyrinth(labyrinth *lab, int height, int width) {
    srand(time(NULL ));
    init(lab, height, width);
    int t = 0;
    while(t<((height/2)*(width/2)-1)) {
        int x = random_odd_in_ange(0,height);
        int y = random_odd_in_ange(0, width);
        int val_case = lab->labyrinth[x][y];
        int direction = rand()%4;
        int result = apply_val(lab, val_case, x, y, direction);
        /*
         * if(debug == 1) {
            printf("------------------iteration-----------------\n");
            printf("x = %d ; y = %d ; direction = %d\n",x,y,direction);
            printf("success (1=yes;0=no)= %d\n", result);
            display_labyrinth(lab);
        }
         */
        if(result == 1) {
            t++;
        }

    }
}

int play(labyrinth *lab) {

}
