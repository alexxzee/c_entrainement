#include <unistd.h>

void ft_putchar( char c ){
    write( 1, &c, 1 );
}

// Converti un chiffre en unicode lisible
int convert_num(int n){
    return ( n <= 9 && n >= 0 ) ? n + 48 : 0;
}

void ft_putnbr( int nb ){
    ft_putchar(convert_num( nb ));
}

int main(){
    
    ft_putnbr( 5 );
    return 0;
}

