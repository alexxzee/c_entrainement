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



void main(){

  int good_places[20] = {0};
  int lifes = 10;

  struct Display messages;
  init_display( &messages );

  set_random_word(motSecret);
  int size_word = longueurChaine(motSecret);
  int caractere = 0;
  int caractere_to_reveal;
  set_chaine_to_find(size_word, chaine_secret, good_places, motSecret);

  printf("%s\n", messages.welcome);
  



  display( &messages );
  caractere = lireCaractere();
  check_letter( motSecret, caractere, good_places );

  // for (int place_letter = 0; place_letter < longueurChaine(motSecret); place_letter++){
  //   printf("%d\n", good_places[place_letter]);
  // }
  set_chaine_to_find(size_word, chaine_secret, good_places, motSecret);
}
