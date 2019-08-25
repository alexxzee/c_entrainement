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

int ft_str_is_printable( char *str){
    int result = 1;
    int i = 0;
    while( str[i] != '\0' ){
        if( !is_letter(str[i]) && !is_number(str[i]) && !is_special_caractere(str[i]) && !is_space(str[i]) ) result = 0;
        i++;
    }
    return result;
}


int main(){
    char str[200] = "A";
    int result = 0;
    result = ft_str_is_printable(str);
    printf("%d\n", result);
    return 0;
}