typedef struct Element Element;
typedef struct Pile Pile;

struct Element{
  int nombre;
  Element *suivant;
};

struct Pile{
  int nbElements;
  Element *premier;
};

void empiler( Pile *pile, int nvNombre );
int depiler( Pile *pile );
void afficherPile(Pile *pile);
Pile *initialiser();

// Créer une pile et un élement puis place l'élément en premier dans la pile
Pile *initialiser(){
  Pile *pile = malloc( sizeof( *pile ) );
  Element *element = malloc( sizeof( *element ) );

  if( pile == NULL || element == NULL ) exit( EXIT_FAILURE );

  element->nombre = 0;
  element->suivant = NULL;

  pile->premier = element;
  pile->nbElements = 0;

  return pile;
}

void empiler(Pile *pile, int nvNombre){
  Element *nouveau = malloc( sizeof( *nouveau ) );

  if( pile == NULL || nouveau == NULL ) exit( EXIT_FAILURE );

  nouveau->nombre = nvNombre;
  nouveau->suivant = pile->premier;
  pile->premier = nouveau;
}

int depiler( Pile *pile ){
  if( pile == NULL ) exit( EXIT_FAILURE );

  int nombreDepile = 0;
  Element *elementDepile = pile->premier;

  if( pile == NULL || pile->premier == NULL ) exit( EXIT_FAILURE );

  nombreDepile = elementDepile->nombre;
  pile->premier = elementDepile->suivant;
  free(elementDepile);
  return nombreDepile;
}

void afficherPile(Pile *pile){
  if( pile == NULL ) exit( EXIT_FAILURE );

  Element *actuel = pile->premier;

  while( actuel != NULL ) {
    printf("%d\n", actuel->nombre);
    actuel = actuel->suivant;
  }

  printf("\n");
}