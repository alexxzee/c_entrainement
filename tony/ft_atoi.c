#include <unistd.h>
#include <stdio.h>

// Converti un chiffre en unicode lisible
int convert_num(int str){
    return (int)str - 48;
}

int construct_number( int number, int str ){
    number *= 10;
    number += convert_num(str);
    return number;
}

int is_number( int str ){
    return ( str >= 48 && str >= 57 ) ? 0 : 1;
}

int is_negatif_sign( int str ){
    return ( str == 45 ) ? 0 : 1;
}



int ft_atoi( char *str ){
    int nbr = 0;
    int i = 0;
    while( str[i] != '\0' ){
        // Si c'est un signe moins
        if( is_number( str[i] ) && is_negatif_sign( str[i] ) != 0 ){
            nbr = construct_number( nbr, str[i] );
        }
        else nbr = 0; // Ne construit que le dernier nombre
        // printf("nbr x 10: %d\n", is_number( 'a' ));
        i++;
    }

    // On réinitialise l'itérateur
    i = 0;
    while( str[i] != '\0' ){
        if( is_negatif_sign( str[i] ) ) {
            nbr = ( -nbr );
        }
        i++;
    }

    
    return nbr; 
}

int main(){
    char str[] = "-33";
    int number = 0;
    number = ft_atoi(str);

    printf("%d\n", number);

    return 0;
}

// FONCTIONNEMENT:

// On créer une dizaine avec un 0
// On converti le second chiffre rencontré en int
// Pour ça, on convertie le code ascii puis on lui enleve 48 (c'est la valeur de 0 en ascii)
// On obtiend le chiffre
// On passe à la dizaine suivante et on fait la meme opération
// Cette opération n'agit que sur la dizaine voulu

// La fonction renvoi un mauvais résulat lorsque la chaine
// - comporte un signe moins
// - comporte 2 nombres séparé par n'imorte quel caractère
// il faudrai reconstruire la chaine puis construire le nombre