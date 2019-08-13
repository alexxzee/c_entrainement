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
  int* memoireAllouee = NULL;
  int variable = 1;
  // memoireAllouee = malloc(sizeof(int));
  memoireAllouee = malloc(variable);
 
   if( memoireAllouee == NULL ) {exit(0);}

   printf("%d", memoireAllouee);
}
