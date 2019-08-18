#include <unistd.h>
#include <stdio.h>

void ft_putchar( char c ){
    write( 1, &c, 1 );
}

void ft_putstr( char *str ){
    int i = -1;
    while( i++ <= 6 ){
        ft_putchar( str[i] );
    }
}

int main(){
    char str[6] = "chaine";
    ft_putstr(str);
    return 0;
}

