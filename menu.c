#include "menu.h"

void save(labyrinth* lab) {
    FILE *outfile;
    char *file_name = lab->name;

    strcat(file_name, ".cfg");
    outfile = fopen(file_name, "w+");
    if(outfile==NULL) {
        printf("Erreur lors de l'ouverture/création du fichier\n");
        return ;
    }
    if((fwrite (&lab, sizeof(labyrinth), 1, outfile))!=0) {
        printf("Labyrinthe créé, sauvegardé et chargé\n\n\n");
    } else {
        printf("Erreur lors de la sauvegarde\n\n\n");
    }
    fclose(outfile);
}


labyrinth* create_labyrinth() {
    int height = 0;
    int width = 0;
    do {
        printf("Veuillez entrer la hauteur, puis la largeur du labyrinthe (Elles doivent être impaires)\n");
        printf("Hauteur :");
        scanf("%d", &height);
        printf("Largeur :");
        scanf("%d", &width);
    } while (!(height%2==1 && width%2 == 1));

    labyrinth *lab = malloc(sizeof(labyrinth));

    printf("Quel sera le nom de ce labyrinthe (45characters max) ?");
    scanf("%s", lab->name);

    generate_labyrinth(lab, height, width);
    display_labyrinth(lab);
    save(lab);
    return lab;
}

labyrinth *load_lab() {
    char file_name[45];
    FILE *infile;
    labyrinth *lab;

    printf("Quel est le nom du labyrithe que vous souhaitez charger (sans l'extension) ?\n");
    scanf("%s", file_name);
    strcat(file_name,".cfg");

    infile = fopen(file_name, "r+");
    if(infile==NULL) {
        printf("Erreur lors de l'ouverture du fichier %s , il n'existe pas\n", file_name);
        return NULL;
    }
    if((fread(&lab, sizeof(labyrinth), 1, infile))!=0) {
        printf("Sauvegarde chargée avec succès! Le voici :\n");
        //display_labyrinth(lab);
        fclose(infile);
        return lab;
    } else {
        printf("Erreur lors de la lecture du contenu de la sauvegarde \n");
        fclose(infile);
        return NULL;
    }

}

void start_menu() {
    int state = 1;
    while(state) {
        printf("Que souhaitez-vous faire ?\n 1. Créer un labyrinthe\n 2. Charger un labyrinthe\n 3. Jouer\n 4. Quitter\n");
        int choice = 0;
        do {
            printf("Le choix doit être entre  1 et 4 !");
            scanf("%d", &choice);
        } while(choice > 4 || choice < 1);

        labyrinth *charged_lab;

        if(choice == 4) {
            state = 0;
        }
        if(choice == 1) {
            charged_lab = create_labyrinth();
            state = 1;
        }
        if(choice == 2) {
            charged_lab = load_lab();
            state = 1;
        }
        if(choice == 3) {
            int callback = play(charged_lab);
            state = 1;
        }
    }



}



