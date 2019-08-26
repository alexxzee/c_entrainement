#include <unistd.h>
#include <stdio.h>

char *ft_strcpy( char *dest, char *src ){
    int i = 0;
    while( src[i] != '\0' ){
        dest[i] = src[i];
        i++;
    }
    return dest;
}

int main(){

    char src[50] = "source";
    char dest[50] = "";

    ft_strcpy(dest, src);

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