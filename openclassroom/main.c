
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int somme(int tableau[], int tailTableau);

    

int main(void){

    int tableau[4] = {1, 2, 2, 2};
    int result = somme( tableau, 4 );
    printf("%d\n", result);

}

int somme(int tableau[], int tailleTableau){
    int i = 0;
    int result = 0;
    for( i = 0; i < tailleTableau; i++ ){
        result += tableau[i];
    }
    return result;
}
