#include "includes.h"

///La fonction principale
int main(int argc, char *argv[])
{
    //Au d�but, tout initialiser
    initSurfaces();

    int buffer = 0;


    //if(display_main()) buffer = display_choice();

    //if(buffer == act_histoire) display_story();
    //display_chars();
    display_battle();

    //Puis, d�clarer les variables locales
    //SDL_Color CouleurRouge = {255,0,0};

    //Boucle principale. C'est ici qu'il faut g�rer les commandes.
    //Je pense que pour chaque �cran il faudra une boucle diff�rente.

    destroyAll();

    return EXIT_SUCCESS;
}
