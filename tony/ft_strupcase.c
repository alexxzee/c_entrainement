#include <unistd.h>
#include <stdio.h>

int is_minuscule( int letter ){
    return ( letter >= 97 && letter <= 122 );
}

char *ft_strupcase( char *str){

    int i = 0;
    while( str[i] != '\0' ){
        if( is_minuscule(str[i]) == 1 ) str[i] = (str[i] - 32);
        i++;
    }
    return 0;
}

int main(){
    char str[50] = "test";

    ft_strupcase(str);

    printf("%s\n", str);

    return 0;
}