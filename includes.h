#ifndef INCLUDES_H
#define INCLUDES_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "../C_upgrade/C_upgrade.h"
#include "characters.h"
#include "init.h"
#include "constantes.h"
#include "display.h"

extern SDL_Surface  *ecran;
extern SDL_Surface *menu;
extern SDL_Surface *texte;
extern TTF_Font *police;
extern TTF_Font *police_texte;
extern SDL_Rect pos_start;
extern Mix_Music *musique;
extern int ecranActuel;

#endif // INCLUDES
