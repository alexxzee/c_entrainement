#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>






int get_nombre( int difficulty ){
    const int MIN = 0, MAX = difficulty;
    srand(time(NULL));
    int nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

    return nombreMystere;
}

char *ecart( int nbPlayer, int nbMystere ){
    if( nbPlayer < nbMystere ) return "petit";
    else return "grand";
}

int difficulty(){
    int difficulty = 1;
    printf( "Choisissez votre difficulte: \n 1 = entre 1 et 100 \n 2 = entre 1 et 1000 \n 3 = entre 1 et 10000 \n" );
    scanf( "%d", &difficulty );
    return difficulty;
}

int partie(){

    int compteur = 0;
    int nbPlayer = 0;
    char result[10] = "";
    int nbMystere = get_nombre( difficulty() );

    while( true ){

        printf("Saisissez un nombre: \n");
        scanf("%d", &nbPlayer);
        if (nbPlayer == nbMystere) break;
        compteur += 1;
        printf("Perdu, le nombre est trop: %s\n", ecart(nbPlayer, nbMystere));
    }
    printf("Bravo, vous avez trouve le nombre mystere en %d coups \n", compteur);
    return compteur;
}

int main( void ){

    int jouer = 1;
    while( jouer == 1 ){
        partie();
        printf("Refaire une partie ?\n [1] Pour oui \n [2] Pour non \n ");
        scanf("%d", &jouer);
    }
    
}
