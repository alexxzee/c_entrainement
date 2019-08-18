#include <unistd.h>
#include <stdio.h>

char *ft_strrev( char *str ){
    char chaine[100] = {0};
    int nb_letter = 0;
    int i = 0;

    // Calcul du nombre de lettre
    while( str[i] != '\0' ){
        nb_letter++;
        i++;
    }

    // On echange les lettres dans une variable intermédiaire
    i = 0;
    while( nb_letter > 0 ){
        chaine[i] = str[nb_letter - 1];
        i++;
        nb_letter--;
    }

    // On réatribut les nouvelles valeur à la chaine de départ
    i = 0;
    while( chaine[i] != '\0' ){
        str[i] = chaine[i];
        i++;
    }

    return str;
}

int main(){
    char str[100] = "chaine";
    ft_strrev(str);

    return 0;
}