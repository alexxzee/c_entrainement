#include <unistd.h>
#include <stdio.h>

// Valeur de retour
// Toute la chaine est trouvée ? :
// 0 : echec
// 1 : succé
int capture( char *str, int i, char *to_find ){
    int iteration = i;
    int j = 0;
    while( to_find[j] != '\0' ){
        if( str[iteration] == to_find[j] ){
            iteration++;
        } else return 0;
        j++;
    }
    return i;
}

char *ft_strstr( char *str, char *to_find){

    int success = 0;
    int i = 0;
    int j = 0;
    while( str[i] != '\0' ){

        if( str[i] == to_find[j] ){
            success = capture( str, i, to_find );
        }
        i++; 
    }

    return str + success;
}

int main(){
    char str[50] = "hello world";
    char to_find[50] = "ello";
    char *result = 0;


    result = ft_strstr(str, to_find);

    printf("%s\n", result);

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