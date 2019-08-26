#include <unistd.h>
#include <stdio.h>

// 0 : Non
int is_majuscule( int letter ){
    return ( letter >= 65 && letter <= 90 );
}


// 0 : Non
int is_minuscule( int letter ){
    return ( letter >= 97 && letter <= 122 );
}

int is_space( int letter_before ){
    return ( letter_before == 32 );
}

int is_special_caractere( int caractere ){
    if( 
        (caractere >= 58 && caractere <= 64) ||
        (caractere >= 33 && caractere <= 47) ||
        (caractere >= 91 && caractere <= 96) ||
        (caractere >= 123 && caractere <= 126)
    ) return 0;
    else return 1;
}

// 0 : Non
int is_letter( int caractere ){
    return ( is_minuscule(caractere) || is_majuscule(caractere) );
}

// 0 : Non
int is_number( int caractere ){
    return ( caractere >= 48 && caractere <= 57 );
}




int is_first_letter( char *str, int iteration ){
    int letter_before = str[(iteration - 1)];
    // printf("letter_before: %c -- est une lettre ? %d\n", letter_before, is_letter(letter_before));

    return (
        // Le caractère précédent n'est pas une lettre
        // Et le caractere en cours est une lettre
        // Le caractère en cour n'est pas un chiffre
        (is_letter(letter_before) == 0 && is_letter(str[iteration]) && is_number(letter_before) == 0)

        // Ou alors :

        // Le caractere en cours est une lettre
        // l'itération est la première
        // Le caractère en cour n'est pas un chiffre
        || (is_letter(letter_before) == 0 && iteration == 0 && is_number(letter_before) == 0));
}

int min_to_maj( int letter ){
    return letter - 32;
}

char *ft_strcapitalize( char *str){

    int result = 0;
    int i = 0;
    while( str[i] != '\0' ){

        result = is_first_letter( str, i );

        if( result && !is_majuscule(str[i]) ){
            str[i] = min_to_maj( str[i] );
        }

        i++;
    }
    return 0;
}


int main(){
    char str[200] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

    ft_strcapitalize(str);

    printf("%s\n", str);


    return 0;
}