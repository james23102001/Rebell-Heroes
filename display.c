#include "includes.h"
const int BOX_Y[] = {90, 120, 150, 180, 210};


///Le premier écran, ne sert qu'à afficher le logo du jeu avec la notice "Tapez sur un bouton pour continuer"
int display_main(){

int continuer=1;
SDL_Surface *bg = NULL;
SDL_Event event;
SDL_Rect pos;
SDL_Color couleurRouge = {255,0,0};
pos.x=0;
pos.y=0;

bg = IMG_Load("background_main.png");
texte = TTF_RenderText_Blended(police, "Press a key to continue...", couleurRouge);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(bg, NULL, ecran, &pos);

pos.x=200;
pos.y=100;
//Ce sera certainement mieux si ca clignote, non?
SDL_BlitSurface(texte, NULL, ecran, &pos);
SDL_Flip(ecran);

while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {

            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                SDL_FreeSurface(bg);
                return true;
                break;

            default:
                break;
        }

    }

    SDL_FreeSurface(bg);

    return false;
}

///L'écran de choix des options. retourne 1 si le joueur veut commencer en mode histoire, 2 en combat libre et 3 pour quitter.
int display_choice(){

int continuer=1;
//SDL_Surface *bg = NULL;
SDL_Event event;
SDL_Rect pos;
SDL_Color couleurRouge = {255,0,0}, couleurNoire = {0,0,0};
pos.x=0;
pos.y=0;

char options[3][20] = {
"Un héros",
"Combat libre",
"Quitter",
};

int indice = 0;
int limite = 2;

//bg = SDL_LoadBMP("background_main.bmp");
texte = TTF_RenderText_Shaded(police, options[indice], couleurRouge,  couleurNoire);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
//SDL_BlitSurface(bg, NULL, ecran, &pos);

pos.x=200;
pos.y=100;
//Ce sera certainement mieux si ca clignote, non?
SDL_BlitSurface(texte, NULL, ecran, &pos);
SDL_Flip(ecran);

while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {

            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){

            //Je l'utiliserai plus tard ppour revenir à l'écran d'acceuil
            case SDLK_ESCAPE:
                return act_back;

            case SDLK_DOWN:
                    if (indice != limite)
                        indice +=1;
                    break;

            case SDLK_UP:
                    if (indice != 0)
                        indice -=1;
                    break;

            case SDLK_RETURN:
                switch(indice){
                case 0:
                    return act_histoire;
                    break;
                case 1:
                    return act_combat;
                    break;
                case 2:
                    return act_quitter;
                    break;
                }

            default:
                break;

                }
                break;

            default:
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        texte = TTF_RenderText_Shaded(police, options[indice], couleurRouge,  couleurNoire);
        SDL_BlitSurface(texte, NULL, ecran, &pos);
        SDL_Flip(ecran);

    }

//    SDL_FreeSurface(bg);

    return false;

}

int display_story(){

int continuer=1;
SDL_Surface *bg = NULL;
SDL_Event event;
SDL_Rect pos;
SDL_Color couleurRouge = {255,0,0}, couleurBlanche = {255,255,255};

char story[10][MAX] = {
    "Avec les autres prisonniers sur place, James déclenche une émeute et s'enfuit.",
    "Il se fait subitement aborder par une personne qu'il connait ... Riley.",
    "Inquiet, James essaie de s'enfuir.",
    "Mais il se fait rattraper par Riley.",
    "A présent, le combat est inévitable",
    "Il faudra se battre",
    "Si il veut rester libre",
    "Ready? Fight!",
    "",
    ""
};

int indice = 0;

bg = SDL_LoadBMP("storyBg.bmp");
//texte = TTF_RenderText_Shaded(police_texte, story[indice], couleurRouge,  couleurNoire);
//SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(bg, NULL, ecran, &pos_start);

pos.x=BOX_X;
pos.y=BOX_Y[0];

int i, start=0, stop = 5;

//Ce sera certainement mieux si ca clignote, non?
//SDL_BlitSurface(texte, NULL, ecran, &pos);
SDL_Flip(ecran);

while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {

            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){

            //Je l'utiliserai plus tard ppour revenir à l'écran d'acceuil
            case SDLK_ESCAPE:
                return act_back;

            case SDLK_DOWN:
                    if (start < stop)
                        start +=1;
                    break;

            case SDLK_UP:
                    if (start > 0)
                        start -=1;
                    break;

            case SDLK_RETURN:
                return true;
                break;

            default:
                break;

                }
                break;

            default:
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(bg, NULL, ecran, &pos_start);

        indice = start;
        for (i=0; i<5; i++){

            if(start == stop+1)
                break;

            texte = TTF_RenderText_Shaded(police_texte, story[indice], couleurRouge,  couleurBlanche);
            pos.y = BOX_Y[i];
            SDL_BlitSurface(texte, NULL, ecran, &pos);
            indice++;

        }

        SDL_Flip(ecran);

}
return false;
}


///L'écran de choix des options. retourne 1 si le joueur veut commencer en mode histoire, 2 en combat libre et 3 pour quitter.
int display_chars(){

int continuer=1;
SDL_Surface *bg = NULL;
SDL_Event event;
SDL_Rect pos;
SDL_Color couleurRouge = {255,0,0}, couleurNoire = {0,0,0};
pos.x=0;
pos.y=0;

char options[9][20] = {
"James",
"Riley",
"Desdemona",
"Eok",
"Tenebra",
"Estra",
"Kicop_Uw",
"Hades",
"Loupito"
};
char images[9][20] = {
"1.jpg",
"2.jpg",
"1.jpg",
"2.jpg",
"1.jpg",
"2.jpg",
"1.jpg",
"2.jpg",
"1.jpg",
};

int indice = 0;
int limite = 8;

//bg = SDL_LoadBMP("background_main.bmp");
texte = TTF_RenderText_Shaded(police, options[indice], couleurRouge,  couleurNoire);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
//SDL_BlitSurface(bg, NULL, ecran, &pos);

pos.x=200;
pos.y=100;
//Ce sera certainement mieux si ca clignote, non?
SDL_BlitSurface(texte, NULL, ecran, &pos);
SDL_Flip(ecran);

while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {

            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){

            //Je l'utiliserai plus tard ppour revenir à l'écran d'acceuil
            case SDLK_ESCAPE:
                return act_back;

            case SDLK_DOWN:
                    if (indice != limite)
                        indice +=1;
                    break;

            case SDLK_UP:
                    if (indice != 0)
                        indice -=1;
                    break;

            case SDLK_RETURN:
                SDL_FreeSurface(bg);
                return indice;
                break;

            default:
                break;

                }
                break;

            default:
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        texte = TTF_RenderText_Shaded(police, options[indice], couleurRouge,  couleurNoire);
        bg = IMG_Load(images[indice]);
        SDL_BlitSurface(bg, NULL, ecran, &pos_start);
        SDL_BlitSurface(texte, NULL, ecran, &pos);
        SDL_Flip(ecran);

    }

    SDL_FreeSurface(bg);

    return false;

}

int display_battle(){

int continuer=1;
//SDL_Surface *bg = NULL;
SDL_Surface *hero, *foe = {NULL};
SDL_Event event;
SDL_Rect pos;
//SDL_Color couleurRouge = {255,0,0}, couleurNoire = {0,0,0};
pos.x=0;
pos.y=0;
/*
char options[9][20] = {
"James",
"Riley",
"Desdemona",
"Eok",
"Tenebra",
"Estra",
"Kicop_Uw",
"Hades",
"Loupito"
};
char images[9][20] = {
"1.jpg",
"2.jpg",
"1.jpg",
"2.jpg",
"1.jpg",
"2.jpg",
"1.jpg",
"2.jpg",
"1.jpg",
};

int indice = 0;
int limite = 8;
*/
//bg = SDL_LoadBMP("background_main.bmp");
//texte = TTF_RenderText_Shaded(police, options[indice], couleurRouge,  couleurNoire);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
//SDL_BlitSurface(bg, NULL, ecran, &pos);

hero = IMG_Load("1.jpg");
//foe = IMG_Load("2.png");

int sol = 450;

pos.x=  400 - hero->w ; // + foe ->w
pos.y= sol - hero->h ; // - foe -> h

//Ce sera certainement mieux si ca clignote, non?
//SDL_BlitSurface(texte, NULL, ecran, &pos);
SDL_Flip(ecran);

while (continuer)
    {

        SDL_PollEvent(&event);

        switch(event.type)
        {

            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){

        case SDLK_LEFT:
                hero = IMG_Load("2.png");
                if(pos.x >= 0)
                    pos.x -= 20;
                break;

            case SDLK_RIGHT:
                hero = IMG_Load("1.jpg");
                if(pos.x <= 1000-hero->w)
                    pos.x += 20;
                break;

            case SDLK_RETURN:
                break;

            default:
                break;

                }
                break;

            default:
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        //texte = TTF_RenderText_Shaded(police, options[indice], couleurRouge,  couleurNoire);
        //bg = IMG_Load(images[indice]);
        SDL_BlitSurface(hero, NULL, ecran, &pos);
        //SDL_BlitSurface(texte, NULL, ecran, &pos);
        SDL_Flip(ecran);

    }

    //SDL_FreeSurface(bg);
    SDL_FreeSurface(hero);
    SDL_FreeSurface(foe);

    return false;

}
