#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "functions.h"



int main(int argc, char *argv[]){

  SDL_Surface *ecran = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
  { // Démarrage de la SDL (ici : chargement du système vidéo)
    fprintf(stderr, "Erreur d'initialisation de la SDL: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  ecran = SDL_SetVideoMode(1024, 256, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);

  if (ecran == NULL){
    fprintf(stderr, "Impossible de charger le mode vidéo: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_WM_SetCaption("Fenêtre", NULL);



  // for( int i = 0; i < 256; i++ ) line( ecran, 1024, i );
  for( int i = 255; i > 0; i-- ) line_inverse( ecran, 1024, i );
  

  SDL_Flip(ecran);

  pause();

  SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).

  return EXIT_SUCCESS;
}
