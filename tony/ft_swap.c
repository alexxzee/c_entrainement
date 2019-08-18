#include <unistd.h>
#include <stdio.h>

void ft_swap( int *a, int *b ){
    int intermediaire = 0;
    intermediaire = *a;
    *a = *b;
    *b = intermediaire;
}

int main(){

    int nb1 = 5;
    int nb2 = 8;
    ft_swap(&nb1, &nb2);
    return 0;
}

