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

// 0 : Non
int is_letter( int caractere ){
    return ( is_minuscule(caractere) || is_majuscule(caractere) );
}

// 0 : Non
int is_number( int caractere ){
    return ( caractere >= 48 && caractere <= 57 );
}



int ft_str_is_numeric( char *str){
    int result = 1;
    int i = 0;
    while( str[i] != '\0' ){
        if( !is_number(str[i]) ) result = 0;
        i++;
    }
    return result;
}


int main(){
    char str[200] = "az5";
    int result = 0;
    result = ft_str_is_numeric(str);

    printf("%d\n", result);


    return 0;
}