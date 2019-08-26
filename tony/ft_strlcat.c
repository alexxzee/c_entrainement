#include <unistd.h>
#include <stdio.h>

int count( char *str ){
    int i = 0;
    while( str[i] != '\0' ) i++;
    return i;
}

char *ft_strlcat( char *dest, char *src, int nb ){
    int size_dest = count( dest );
    int size_src = count( src );
    int size_beffer_dest = sizeof(dest);
    int i = 0;

    if( (size_dest + size_src) > size_beffer_dest ) return "\0";

    while( nb >= 0 ){

        dest[i] = src[i];

        size_dest++;
        i++;
        nb--;
    }
    return src;
}

int main(){
    char src[200] = "phrase provenant de source";
    char dest[5] = "test";
    char *result = 0;
    result = ft_strlcat(dest, src, 2);
    printf("%s\n", dest);
    printf("result: %d\n", *result);
    return 0;
}