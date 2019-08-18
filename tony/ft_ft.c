#include <unistd.h>

void ft_ft( int *nbr ){
    *nbr = 42;
}

int main(){

    int nbr = 5;
    ft_ft( &nbr );
    return 0;
}

