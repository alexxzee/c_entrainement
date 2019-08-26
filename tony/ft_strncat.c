#include <unistd.h>
#include <stdio.h>

int count( char *str ){
    int i = 0;
    while( str[i] != '\0' ) i++;
    return i;
}

char *ft_strncat( char *dest, char *src, int nb ){
    int size_dest = count( dest );
    int i = 0;
    while( nb >= 0 ){

        dest[size_dest] = src[i];

        nb--;
        size_dest++;
        i++;
    }
    return src;
}


int main(){
    char src[200] = "phrase provenant de source";
    char dest[200] = "test";
    ft_strncat(dest, src, 2);
    printf("%s\n", dest);
    return 0;
}