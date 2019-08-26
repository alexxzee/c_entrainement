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

int is_number( int caractere ){
    return ( caractere >= 48 && caractere <= 57 );
}

int convert_num( int number ){
    return number - 48;
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

int ft_rev_params( int argc, char *argv[] ){
    int i = (argc - 1); 
    while( i > 0 ){
        display_arg(argv[i]);
        i--;
    }
    return 0;
}

int ft_print_params( int argc, char *argv[] ){
    int i = 1;  
    while( i < argc ){
        display_arg( argv[i] );
        i++;
    }
    return 0;
}

// Converti le premier argument en chiffre
int arg_to_num( int argc, char *argv[]  ){
    if (argc == 2 && is_number(*argv[1])){
        return convert_num(*argv[1]);
    } else return 0;
}


// void draw_line(  int height, int width ){
//     int i = width;

//     while( i < height - 1 - ){
//         i++;
//     }

//     while( i >= 0 ){
//         write( 1, "*", 1 );
//         i--;
//     }
// }

void draw_door( int door, int size, int j ){
    if( door ){ // Si la porte doit être dessinée

        int size_door = (size % 2 == 0 ? size - 1 : size);
        int i = 0;

        while( i < size_door ){
            if( j == 28 ){
                write( 1, "|", 1 );
                i++;
            }
        }
    }
}

void draw_stage( int height, int width, int space, int door, int size ){
    int i = 0;
    while (i < height){

        int j = - space;
        while( j < height - 1 - i ){
            write( 1, " ", 1 );
            j++;
        }
        j += height + 1 - i; // Décallage
        write( 1, "/", 1 );
        while( j < width ){
            
            draw_door( door, size, j );

            write( 1, "*", 1 );
            j++;
        }
        write( 1, "\\", 1 );
        write( 1, "\n", 1 );
        i++;
    }
}

int line_width( int i ){
    if( i == 0 ) return 7;
    return line_width( i - 1 ) + 2 * ( 1 + ( 3 + i ) + ( ( i % 2 ) + ( i / 2 ) ) );
}

void sastantua( int size ){
    int i = 0;
    
    int height = 0;
    int width = 0;
    int door = 0;
    int space;


    while( i < size ){
        
        space = ( line_width( size - 1 ) - line_width( i ) ) / 2;
        height = i + 3;
        width = line_width(i);
        if( i == size - 1 ) door = 1;
        draw_stage( height, width, space, door, size );
        i++;
    }

}

int main( int argc, char *argv[] ){



    int num = 0;
    
    num = arg_to_num( argc, argv );
    sastantua( num );


    return 0;
}