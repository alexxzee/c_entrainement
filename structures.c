#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Coordonnees
{
    int x;
    int y;
};

void initialiserCoordonnees( struct Coordonnees*);

// struct Personne
// {
//     char prenom[100];
//     char nom[100];
//     int age;
// };




void main(){
    struct Coordonnees monPoint;

    initialiserCoordonnees( &monPoint );

    printf("%d\n", monPoint.x);


    // Exemple : //////////////////////////

    // struct Coordonnees
    // {
    //     int x;
    //     int y;
    // };

    // Coordonnees monPoint;
    // Coordonnees *pointeur = &monPoint;

    // monPoint.x = 10;  // On travaille sur une variable, on utilise le "point"
    // pointeur->x = 10; // On travaille sur un pointeur, on utilise la flèche

    // return 0;
}

void initialiserCoordonnees( struct Coordonnees* point ){
    point->x = 0;
    point->y = 0;
}

