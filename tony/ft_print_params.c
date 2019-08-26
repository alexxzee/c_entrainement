#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

void ft_putchar( char c ){
    write( 1, &c, 1 );
}

int count( char *str ){
    int i = 0;
    while( str[i] != '\0' ) i++;
    return i;
}

void display_arg( char *arg ){
    int size_arg = count( arg );
    int i = 0;
    while( size_arg >= 0 ){
        ft_putchar(arg[i]);
        size_arg--;
        i++;
    }
}

int main( int argc, char* argv[] ){
    int i = 1;  
    while( i < argc ){
        display_arg( argv[i] );
        i++;
    }
    return 0;
}