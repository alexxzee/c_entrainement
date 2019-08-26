#include <unistd.h>
#include <stdio.h>

int is_majuscule( int letter ){
    return ( letter >= 65 && letter <= 90 );
}

char *ft_strlowcase( char *str){

    int i = 0;
    while( str[i] != '\0' ){
        if( is_majuscule(str[i]) == 1 ) str[i] = (str[i] + 32);
        i++;
    }
    return 0;
}

int main(){
    char str[50] = "TEST";

    ft_strlowcase(str);

    printf("%s\n", str);

    return 0;
}