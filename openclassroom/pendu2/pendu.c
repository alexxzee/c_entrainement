// Libs natives
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Mes libs
#include "functions.h"

int main(){

  // Tableau des mots
  char words[20][TAILLE_MAX] = { {0} };
  char mot_secret[TAILLE_MAX] = {0};
  int nb_word = 0;
  int nb_coups = 10;

  char chaine_secret[20] = {0};
  char letter = 0;
  int places_letter[20] = {0};
  int result_game = 0;

  nb_word = get_dictionnaire("pendu2/dictionnaire.txt", words);
  sanitize_words(words);
  set_random_word( words, mot_secret, &nb_word );
  init_secret_chain( strlen( mot_secret ), chaine_secret );


  printf("\n Bienvenue dans le pendu ! \n\n");
  printf("Il vous reste %d coups\n", nb_coups);
  printf("Quel est le mot secret ? %s\n", chaine_secret);
  printf("%s\n", mot_secret);

  for( int i = 0; i < 20; i++ ){

    check_end_game(&nb_coups, chaine_secret, &result_game);
    if( result_game != 0 ){
      if( result_game == 1 )printf("Vous n'avez plus de coups, perdu ...");
      if( result_game == 2 )printf("Vous avez reussi en %d coups ! Gagne !", i);
      break;
    }
    letter = lireCaractere();
    place_letter(mot_secret, letter, places_letter, &nb_coups);
    modify_secret_chain( mot_secret, places_letter, chaine_secret );
    printf("Il vous reste %d coups\n", nb_coups);
    printf("Quel est le mot secret ? %s\n", chaine_secret);
  }


  return 0;
}