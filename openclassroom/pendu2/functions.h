#define TAILLE_MAX 50

char lireCaractere(){
  char caractere = 0;

  // Lecture du premier caractère
  caractere = getchar();

  // Mise en majuscule de la lettre
  caractere = toupper(caractere);

  while (getchar() != '\n');
  return caractere;
}

int longueurChaine( char *chaine ){
  int longueur = 0;
  do{
    longueur++;
  }while( chaine[longueur] != '\n' );

  return longueur;
}

void sanitize_words( char words[20][50] ){

  for (int i = 0; i < 20; i++ )
    for( int j = 0; j < strlen( words[i] ); j++ )
      if( words[i][j] == '\n' ) words[i][j] = 0;
}

void sanitize_word( char word[50] ){

  // for (int i = 0; i < 20; i++ )
    for( int j = 0; j < strlen( word ); j++ )
      if( word[j] == '\n' ) word[j] = 0;
}

// Renvoi le nombre deligne
int get_dictionnaire( char *path, char words[20][50] ){
    // Déclaration de la variable destinée pour le dictionnaire
  FILE *dictionnaire = NULL;

  // Ouverture du fichier en mode lecture seule
  dictionnaire = fopen(path, "r");

  // Vérification du bon déroulement de l'ouverture de fichier.
  if (dictionnaire == NULL){
    printf("Impossible d'ouvrire le dictionnaire.");
    exit(0);
  }

  // Déclaration du nombre de ligne
  int nb_line = 0;
  // char words[20][TAILLE_MAX];
  char word[TAILLE_MAX] = {0};

  // Parcours de chaque ligne
  while ( fgets(word, TAILLE_MAX, dictionnaire) != NULL ){    
    strcpy(words[nb_line], word);
    nb_line++;
  }
  fclose(dictionnaire);
  return nb_line;
}

int get_num_random( int min, int max ){
  srand(time(NULL));
  return (rand() % (max - min + 1)) + min;
}

void set_random_word( char words[20][TAILLE_MAX], char mot_secret[20], int *nb_word ){
  int random = get_num_random(0, *nb_word);
  strcpy( mot_secret, words[random] );
};

void init_secret_chain( int nb_caractere, char chaine_secret[20] ){
  for( int i = 0; i < nb_caractere; i++ ){
    strcat( chaine_secret, "*" );
  }
}


// Pour places_letter :
// 0 Pas de lettre
// 1 Une lettre mais pas bon
// 2 Une lettre et la bonne
// Pour result_letter :
// 0 Pour une mauvaise réponse
// 1 Pour une bonne
void place_letter(char mot_secret[], char letter, int places_letter[], int *nb_coups)
{
  int result_letter = 0;

  for( int i = 0; i < strlen(mot_secret); i++ ){

    if( places_letter[i] != 2 ){ // Si la lettre en cours est déjà bonne, on saute.
      if( letter == mot_secret[i] ){
        places_letter[i] = 2;
        result_letter = 1;
      }
      else if( letter != mot_secret[i] ) {
        places_letter[i] = 1;
        if(result_letter != 1 ) result_letter = 0;
      } 
    }
  }
  if( result_letter == 0 ) *nb_coups = *nb_coups - 1;
}

// Pour result_game:
// 1 : Perdu : Plus assez de vie
// 2: Gagner : Plus de caractère à trouver
void check_end_game( int *nb_coups, char chaine_secret[], int *result_game ){
  for( int i = 0; i < strlen(chaine_secret); i++ ){
    // Si le caractère est une étoile
    if( chaine_secret[i] == 42 ){
      *result_game = 0;
      break;
    }
    else *result_game = 2;
  }
  if( *nb_coups == 0 ) *result_game = 1;
}

void modify_secret_chain(char mot_secret[], int places_letter[], char chaine_secret[]){

  for( int j = 0; j < strlen(chaine_secret); j++ ) chaine_secret[j] = 0;

  for( int i = 0; i < 20; i++ ){
    if( places_letter[i] == 2 ) chaine_secret[i] = mot_secret[i];
    else if( places_letter[i] == 1 ) strcat(chaine_secret, "*");
    else chaine_secret[i] = 0;
  }
}
