#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define TAILLE_MAX 500

void readFile(char fileName){
  FILE *fichier = NULL;
  char chaine[TAILLE_MAX] = "";
  fichier = fopen(fileName, "r+");
  if( fichier != NULL ){
      while (fgets(chaine, TAILLE_MAX, fichier) != NULL ){
        printf("%s", chaine);
      }
      fclose(fichier);
    } else printf("Impossible d'ouvrir le fichier.");
}

void main(){
    
    int age = 20;
    char myFile[] = "test.txt";

    readFile( myFile );
}
