/**
INIT.C

Juste deux fonctions : Une pour charger le jeu, et une pour quitter le jeu.
*/
#include "includes.h"

//Les variables globales du programme. je mets les pointeurs là pour ne pas oublier de les vider de la mémoire à la fin. C'est important qu'elles pointent toutes vers NULL.
SDL_Surface *ecran = NULL, *menu = NULL, *texte=NULL;
TTF_Font *police, *police_texte = {NULL};
SDL_Rect pos_start;
Mix_Music *musique = NULL;
int ecranActuel;

///La fonction initSurfaces...
void initSurfaces(){

pos_start.x = 0;
pos_start.y = 0;

//Initialisant SDL_VIDEO
SDL_Init(SDL_INIT_VIDEO);

//SDL_WM_SetIcon(SDL_LoadBMP("caisse.bmp"), NULL);
ecran = SDL_SetVideoMode(1000, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

//menu = SDL_LoadBMP("menu.bmp");
//Le titre
SDL_WM_SetCaption("Rebells Heroes", NULL);

//Lancement de MIX
if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)== -1)
    {
        fprintf(stderr, "%s", Mix_GetError());
    }

//Lancement de TTF
TTF_Init();

//Initialisation de la police
police = TTF_OpenFont("kid.otf",50);
police_texte = TTF_OpenFont("kid.otf",14);

//Initialisation de la musique
musique= Mix_LoadMUS("music.mid");

ecranActuel=ecranAcceuil;
initChars();
}


///Fonction pour libérer totalement la mémoire.
void destroyAll(){

//Libération de MIX
Mix_FreeMusic(musique);
Mix_CloseAudio();

//DE TTF
TTF_CloseFont(police);
TTF_Quit();

//Et de SDL
SDL_FreeSurface(menu);
SDL_FreeSurface(texte);

//Quitter
SDL_Quit();
}
