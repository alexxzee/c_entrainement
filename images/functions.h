#include <SDL/SDL.h>

void pause(){
  int continuer = 1;
  SDL_Event event;
  while (continuer){
    SDL_WaitEvent(&event);
    switch (event.type){
    case SDL_QUIT:
      continuer = 0;
    }
  }
}

SDL_Surface * pixel(SDL_Surface *ecran, int iteration){
  // Déclaration de la variable
  SDL_Surface *rectangle = NULL;

  // Création de la surface
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 1, 1, 32, 0, 0, 0, 0);

  // Création de la couleur
  Uint32 color = SDL_MapRGB(ecran->format, iteration, iteration, iteration);

  // Colorisation de la surface avec la couleur
  SDL_FillRect(rectangle, NULL, color);
  return rectangle;
}


void display_pixel( SDL_Surface *ecran, int iteration, int positionY ){
  SDL_Surface *current_pixel = pixel(ecran, positionY);
  SDL_Rect position;
  position.x = iteration;
  position.y = positionY;
  SDL_BlitSurface(current_pixel, NULL, ecran, &position);
  SDL_FreeSurface(current_pixel);
}

void line( SDL_Surface *ecran, int largeur_ecran, int positionY ){
  for (int iteration = 0; iteration < largeur_ecran; iteration++){
    display_pixel(ecran, iteration, positionY);
  }
}

void line_inverse( SDL_Surface *ecran, int largeur_ecran, int positionY ){
  for (int iteration = 0; iteration < largeur_ecran; iteration++){
    display_pixel(ecran, iteration, positionY);
  }
}
