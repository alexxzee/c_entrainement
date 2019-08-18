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

int main(){
    ft_putchar( 'a' );
    return 0;
}