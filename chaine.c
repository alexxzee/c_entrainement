#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])

{

    /* On crée une chaîne "chaine" qui contient un peu de texte

    et une copie (vide) de taille 100 pour être sûr d'avoir la place

    pour la copie */

    char chaine[50] = "Texte", copie[100] = {0}, chaine2[] = "encore du text";

    strcat( chaine, chaine2 );
    strcpy(copie, chaine); // On copie "chaine" dans "copie"

    // Si tout s'est bien passé, la copie devrait être identique à chaine

    printf("chaine vaut : %s\n", chaine);

    // printf("copie vaut : %s\n", copie);

    return 0;
}