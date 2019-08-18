void ft_print_alphabet(int c);
void ft_putchar( char c );
void ft_print_number( void );
void ft_is_negative( int n );
void ft_print_comb( void );
int convert_num( int n );

void ft_print_comb(){
    int first = 47;
    int second;
    int third;

    while( first++ <= 57 ){
        second = first;
        while( second++ <= 57 ){
            third = second;
            while( third++ < 57 ){
                ft_putchar( first );
                ft_putchar( second );
                ft_putchar( third );
                ft_putchar( ' ' );
            }
        }
    }
}



// Converti un chiffre en unicode lisible
int convert_num(int n){
    return ( n <= 9 && n >= 0 ) ? n + 48 : 0;
}

void ft_is_negative( int n ){
    char result = ( n <= 0 ) ? 'N' : 'P';
    write( 1, &result, 1 );
}

void ft_print_number( void ){
    int i = 48;
    while( i <= 57 ) ft_print_alphabet( i++ );
}

void ft_print_alphabet(int c){
    while( c <= 122 ) ft_putchar( c++ );
}

void ft_putchar( char c ){
    write( 1, &c, 1 );
}