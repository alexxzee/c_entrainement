#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>

void pause()

{

  int continuer = 1;

  SDL_Event event;

  while (continuer)

  {

    SDL_WaitEvent(&event);

    switch (event.type)

    {

    case SDL_QUIT:

      continuer = 0;
    }
  }
}

int main(int argc, char *argv[])

{

  SDL_Surface *ecran = NULL, *rectangle = NULL;
  SDL_Rect position;

  if( SDL_Init(SDL_INIT_VIDEO) == -1 ){ // Démarrage de la SDL (ici : chargement du système vidéo)
   fprintf(stderr, "Erreur d'initialisation de la SDL: %s\n", SDL_GetError());
   exit( EXIT_FAILURE );
  }

  ecran = SDL_SetVideoMode( 1024, 768, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF );

  if( ecran == NULL ){
    fprintf( stderr, "Impossible de charger le mode vidéo: %s\n", SDL_GetError() );
    exit( EXIT_FAILURE );
  }

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
  SDL_WM_SetCaption( "Ma fenêtre", NULL );


  // Couleur écran:
  Uint32 bleuVert = SDL_MapRGB( ecran->format, 17, 206, 112 );
  SDL_FillRect( ecran, NULL, bleuVert );


  // Position du rectangle
  position.x = ( 1024 / 2 ) - ( 220 / 2 );
  position.y = ( 768 / 2 ) - ( 180 / 2 );

  // On colorie le rectangle
  Uint32 blanc = SDL_MapRGB(ecran->format, 255, 255, 255);
  SDL_FillRect( rectangle, NULL, blanc );

  // On place le rectangle en le Blittant sur l'écran principal
  SDL_BlitSurface( rectangle, NULL, ecran, &position );

  SDL_Flip(ecran);

  pause();

  SDL_FreeSurface( rectangle );
  SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).

  return EXIT_SUCCESS;
}
