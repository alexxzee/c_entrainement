typedef struct Element Element;
typedef struct Liste Liste;

struct Element{
  int nombre;
  Element *suivant;
};

struct Liste{
  int nbElements;
  Element *premier;
};

Liste *initialisation();
Element *insertion( Liste *liste, int nvNombre );
void suppression( Liste *liste );
void afficherListe( Liste *liste );
void insertion_milieu( Liste *liste, int nvNombre, Element *precedent );

// Créer une liste et un élement puis place l'élément en premier dans la liste
Liste *initialisation(){
  Liste *liste = malloc( sizeof( *liste ) );
  Element *element = malloc( sizeof( *element ) );

  if( liste == NULL || element == NULL ) exit( EXIT_FAILURE );

  element->nombre = 0;
  element->suivant = NULL;

  liste->premier = element;
  liste->nbElements = 0;

  return liste;
}



// Affiche tous les éléments de la liste en commenceant par le premier
void afficherListe( Liste *liste ){
  if( liste == NULL ) exit( EXIT_FAILURE );

  Element *actuel = liste->premier;

  while( actuel != NULL ){
    printf( "%d -> ", actuel->nombre );

    // On incrémente actuel, au suivant car
    // au bout de la liste on trouve un NULL
    // Donc, le NULL arrêtera la boucle
    actuel = actuel->suivant;
  }

  printf( "NULL\n" );
}

// Créer un nouvel élement et l'insert en premier dans la liste fournie.
Element *insertion( Liste *liste, int nvNombre ){
  // Création d'un nouvel élement
  Element *nouveau = malloc( sizeof( *nouveau ) );
  if( liste == NULL || nouveau == NULL ) exit( EXIT_FAILURE );

  nouveau->nombre = nvNombre;

  // Insertion de l'élément au milieu de la liste
  nouveau->suivant = liste->premier;
  liste->premier = nouveau;

  liste->nbElements++;

  return nouveau;
}

void insertion_milieu( Liste *liste, int nvNombre, Element *precedent ){

  Element *nouveau = malloc( sizeof( *nouveau ) );
  if( liste == NULL || nouveau == NULL || precedent == NULL ) exit( EXIT_FAILURE );

  nouveau->nombre = nvNombre;

  nouveau->suivant = precedent->suivant;
  precedent->suivant = nouveau;

  liste->nbElements++;
}



void suppression_milieu( Liste *liste, Element *precedent, Element *aSupprimer ){

  if( liste == NULL || aSupprimer == NULL ) exit( EXIT_FAILURE );
  if( aSupprimer == liste->premier ){
    printf( "Vous souhaitez supprimer le premier élément \n Veuillez utiliser la fonction suppression." );
    exit( EXIT_FAILURE );
  }
  precedent->suivant = aSupprimer->suivant;
  free( aSupprimer );

  liste->nbElements--;
}

// Supprime un élément
void suppression( Liste *liste ){
  if( liste == NULL || liste->premier == NULL ) exit( EXIT_FAILURE );

    Element *aSupprimer = liste->premier;
    liste->premier = liste->premier->suivant;
    free( aSupprimer );
    liste->nbElements--;
}

void destruction_liste( Liste *liste ){
  while( liste->premier != NULL ) suppression( liste );
  liste->nbElements = 0;
  printf("Tout est supprimer");
}

