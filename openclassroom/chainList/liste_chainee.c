#include <stdlib.h>
#include <stdio.h>
#include "liste_chainee.h"



int main(){
  Liste *maListe = initialisation();

  Element *element3 = insertion(maListe, 4);
  Element *element2 = insertion( maListe, 15 );
  Element *element1 = insertion( maListe, 8 );
  // suppression( maListe );
  // suppression_milieu( maListe, element2, element3 );
  insertion( maListe, 5 );
  printf("%d\n", maListe->nbElements);
  afficherListe( maListe );

  return 0;
}
