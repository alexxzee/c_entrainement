#define TAILLE_MAX 1000

char motSecret[TAILLE_MAX] = "";
char chaine_secret[TAILLE_MAX] = "";

struct Display{
  char welcome[200];
  char question_secret[200];
  char question_letter[200];
};

char lireCaractere(){
  char caractere = 0;

  // Lecture du premier caractère
  caractere = getchar();

  // Mise en majuscule de la lettre
  caractere = toupper(caractere);

  while (getchar() != '\n');
  return caractere;
}

int longueurChaine(const char *chaine){

  int nbCaractere = 0;
  char caractereActuel = 0;

  while (caractereActuel != '\n'){
    caractereActuel = chaine[nbCaractere];
    nbCaractere++;
  }
  nbCaractere--;
  return nbCaractere;
}

int get_random( int min, int max ){
  srand(time(NULL));
  return (rand() % (max - min + 1)) + min;
}

void set_random_word(char *word){
  // Déclaration de la variable destinée pour le dictionnaire
  FILE *dictionnaire = NULL;

  // Ouverture du fichier en mode lecture seule
  dictionnaire = fopen("pendu/dictionnaire.txt", "r");

  // Vérification du bon déroulement de l'ouverture de fichier.
  if (dictionnaire == NULL){
    printf("Impossible d'ouvrire le dictionnaire.");
    exit(0);
  }

  // Déclaration du nombre de ligne
  int nb_line = 0;
  char words[20][TAILLE_MAX];

  // Parcours de chaque ligne
  while (fgets(word, TAILLE_MAX, dictionnaire) != NULL){
    strcpy(words[nb_line], word);
    // Incrémentation du nombre de ligne
    nb_line++;
  }

  fclose(dictionnaire);
  int random = get_random(0, nb_line - 1);
  strcpy(word, words[random]);
}

void set_chaine_to_find(int size_word, char *chaine_secret, int *good_places, char *motSecret)
{
  char star[] = "*";
  
  char letter[1] = "";
  

  for (int i = 0; i < size_word; i++){
    letter[0] = motSecret[i];

    // On réinitialise le caractère
    chaine_secret[i] = 0;

    // Si c'est la bonne lettre on la révèle
    if( good_places[i] == 1 ) strcat( chaine_secret, letter );

    // Sinon, on y met une étoile à la place
    else if( good_places[i] == 0 ) strcat( chaine_secret, star );

    // if (i == strlen( chaine_secret )) printf("Dernier caractère: %c\n",  )
  }
  printf("%s\n", chaine_secret);
}

// Renvoi les bonnes et mauvaises positions de la lettre entré par l'utilisateur
void check_letter( char *motSecret, int caractere, int *good_places ){
  for (int place_letter = 0; place_letter < longueurChaine(motSecret); place_letter++){
      good_places[place_letter] = (caractere == motSecret[place_letter]);
  }
}

void init_display( struct Display *messages ){
  strcpy( messages->welcome, "Bienvenue dans le pendu !");
  strcpy( messages->question_secret, "Quel est le mot secret: ");
  strcpy( messages->question_letter, "Proposez une lettre: ");
}

void display(struct Display *messages){
  printf("%s", messages->question_secret);
  printf("%s", motSecret);
  printf("%s\n", chaine_secret);
  printf("%s\n", messages->question_letter);
}
