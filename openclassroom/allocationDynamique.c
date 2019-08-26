#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct Coordonnees Coordonnees;
struct Coordonnees{
  int x;
  // int y;
};


void main(){
  int nbFriends = 0;
  int *oldFriends = NULL;


  printf("Combien avez-vous d'amis ?");
  scanf("%d", &nbFriends);

  // S'il n'y a pas d'amis on arrète le programme
  if( nbFriends < 1 ) exit(0);

  // Création du tableau en fonction du nombre d'amis
  oldFriends = malloc( nbFriends * sizeof(int) );

  // On vérifie que malloc à trouver un espace mémoire assez grand
  if( oldFriends == NULL ) exit(0);

  for( int i = 0; i < nbFriends; i++ ){
    printf("Quel age à l'ami numéro %d\n", i + 1);
    scanf("%d", &oldFriends[i]);
  }

  printf("\n Vos amis ont les ages suivants: \n");

  for (int i = 0; i < nbFriends; i++){
    printf("Amis numéro %d: %d ans \n", i + 1, oldFriends[i]);
  }
  
  free(oldFriends);
}
