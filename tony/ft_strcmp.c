#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare( char *chaine ){
    int somme = 0;
    int i = 0;
    while( chaine[i] != '\0' ){
        somme += chaine[i];
        i++;
    } 
    return i;
}

int ft_strcmp( char *s1, char *s2){

    int count_s1 = compare(s1);
    int count_s2 = compare( s2 );
    
    if( count_s1 < count_s2 ) return -1;
    else if( count_s1 == count_s2 ) return 0;
    else return 1;

}

int main(){
    char s1[50] = "test";
    char s2[50] = "tesa";
    int result = 0;

    result = ft_strcmp(s1, s2);

    printf("%d\n", result);

    return 0;
}

// FONCTIONNEMENT:

// On créer une dizaine avec un 0
// On converti le second chiffre rencontré en int
// Pour ça, on convertie le code ascii puis on lui enleve 48 (c'est la valeur de 0 en ascii)
// On obtiend le chiffre
// On passe à la dizaine suivante et on fait la meme opération
// Cette opération n'agit que sur la dizaine voulu

// La fonction renvoi un mauvais résulat lorsque la chaine
// - comporte un signe moins
// - comporte 2 nombres séparé par n'imorte quel caractère
// il faudrai reconstruire la chaine puis construire le nombre