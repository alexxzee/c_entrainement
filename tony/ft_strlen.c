#include <unistd.h>
#include <stdio.h>

int ft_strlen( char *str ){
    int nb_letter = 0;

    int i = -1;
    while( i++ <= 100 ){
        // Intervals des lettres Majuscules ou Minuscule
        if( str[i] >= 65 && str[i] >= 90 || str[i] >= 97 && str[i] >= 122 ){
            nb_letter++;
        }
    }
    return nb_letter;
}

int main(){
    char str[100] = "chaine";
    int nb_letter = 0;
    nb_letter = ft_strlen( str );
    printf("%d\n", nb_letter);
    return 0;
}