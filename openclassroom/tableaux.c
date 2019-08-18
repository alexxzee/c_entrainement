
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int somme(int tableau[], int tailleTableau);
int moyenne( int tableau[], int tailleTableau );
void copie( int tableau[], int copie[], int tailleTableau );
void maximumTableau( int tableau[], int tailleTableau, int valeurMax );
void ordonnerTableau( int tableau[], int tailleTableau );
void intervertir(int tableau[], int i_current);

    int main(void)
{

    int tableau[4] = {10, 2, 5, 4};
    int copieTableau[4] = {0};
    int length = sizeof(tableau) / sizeof(int);

    // int result = somme( tableau, 4 );
    // int result = moyenne( tableau, 4 );
    // printf("%d\n", result);
    
    // copie( tableau, copieTableau, 4  );
    // maximumTableau( tableau, 4, 5 );
    ordonnerTableau( tableau, length );

    
    for( int i = 0; i < length; i++ ){
        printf("%d\n", tableau[i]);
    }
    

}

void ordonnerTableau( int tableau[], int tailleTableau ){

    for( int j = 0; j < tailleTableau - 1; j++ ){
        for( int i = 0; i < tailleTableau; i++ ){
            if( tableau[ i + 1 ] < tableau[i] ) intervertir( tableau, i );
        }
    }

}

void intervertir( int tableau[], int i_current ){
    int i_next = i_current + 1;
    int variable_intermediaire = 0;

    variable_intermediaire = tableau[i_current];
    tableau[i_current] = tableau[i_next];
    tableau[i_next] = variable_intermediaire;

}

void maximumTableau(int tableau[], int tailleTableau, int valeurMax){
    for( int i = 0; i < tailleTableau; i++ ){
        if(tableau[i] > valeurMax) tableau[i] = 0;
    }
}

void copie( int tableau[], int copieTableau[], int tailleTableau ){
    
    int i = 0;

    for( i = 0; i < tailleTableau; i++ ){
        copieTableau[i] = tableau[i];
    }

    for( int i = 0; i < 4; i++ ){
        printf( "%d\n", copieTableau[i] );
    }
}

int moyenne( int tableau[], int tailleTableau ){
    int i = 0;
    int result = 0;
    int result_somme = 0;

    return somme(tableau, tailleTableau) / tailleTableau;
}

int somme(int tableau[], int tailleTableau){
    int i = 0;
    int result = 0;
    for( i = 0; i < tailleTableau; i++ ){
        result += tableau[i];
    }
    return result;
}
