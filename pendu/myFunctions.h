#define TAILLE_MAX 1000

char lireCaractere()
{
  char caractere = 0;

  // Lecture du premier caractère
  caractere = getchar();

  // Mise en majuscule de la lettre
  caractere = toupper(caractere);

  //
  while (getchar() != '\n')
    ;

  return caractere;
}

int longueurChaine(const char *chaine)
{

  int nbCaractere = 0;
  char caractereActuel = 0;

  while (caractereActuel != '\n')
  {
    caractereActuel = chaine[nbCaractere];
    nbCaractere++;
  }

  return nbCaractere;
}

int random_int(int min, int max){
  srand(time(NULL)); // A mettre au début du main()
  return (rand() % (max - min + 1)) + min;
}
