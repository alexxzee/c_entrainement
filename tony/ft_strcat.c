#include <unistd.h>
#include <stdio.h>

int count( char *str ){
    int i = 0;
    while( str[i] != '\0' ) i++;
    return i;
}

char *ft_strcat( char *dest, char *src ){
    int size_src = count( src );
    int size_dest = count( dest );
    int i = 0;
    while( size_src >= 0 ){

        dest[size_dest] = src[i];

        size_src--;
        size_dest++;
        i++;
    }
    return src;
}


int main(){
    char src[200] = "phrase provenant de source";
    char dest[200] = "test";
    ft_strcat( dest, src );
    printf("%s\n", dest);
    return 0;
}