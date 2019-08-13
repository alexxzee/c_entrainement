// char myChar[20] = "variable";
// char myChar2[20] = "variable2";
// words[0] = myChar;
// words[1] = myChar2;
// printf("%s\n", words[0]);


// Libs natives
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Mes libs
#include "myFunctions.h"

char motSecret[TAILLE_MAX] = "";
// char motSecret[] = "MARRON";



char sanitize( char *chaine ){
  int longueur = longueurChaine( chaine );
  char nouvelleChaine[TAILLE_MAX];

  for( int i = 0; i <= longueur; i++ ){
    if( chaine[i] == '\n' ) chaine[i] = "";
    nouvelleChaine[i] = chaine[i];
  }
  chaine = "";
  chaine = nouvelleChaine;
  printf("%s\n", chaine);
}


char get_random_word(){
  // Déclaration de la variable destinée pour le dictionnaire
  FILE* dictionnaire = NULL;

  // Ouverture du fichier en mode lecture seule
  dictionnaire = fopen("pendu/dictionnaire.txt", "r");

  // Vérification du bon déroulement de l'ouverture de fichier.
  if( dictionnaire == NULL ){
    printf("Impossible d'ouvrire le dictionnaire.");
    exit(0);
  }

  // Déclaration du nombre de ligne
  int nb_line = 0;
  char *words[20];

  // Parcours de chaque ligne
  while( fgets( motSecret, TAILLE_MAX, dictionnaire) != NULL ){

    sanitize( motSecret );
    

    words[nb_line] = motSecret;
    // Incrémentation du nombre de ligne
    nb_line++;
  }
  fclose( dictionnaire );


  // char *word[TAILLE_MAX];
  int random = 0;
  random = random_int(0, nb_line);

  // printf( "Mot: %s", words[5] );
}

void main(){
  char motSecret = get_random_word();
  // char maLettre = lireCaractere();
  // printf("%c", maLettre);
}
