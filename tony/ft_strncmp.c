#include <unistd.h>
#include <stdio.h>

int compare( char *chaine, unsigned int n ){
    int somme = 0;
    int i = 0;
    while( n != 0 ){
        somme += chaine[i];
        i++;
        n--;
    }
    return i;
}

int ft_strncmp( char *s1, char *s2, unsigned int n){

    int count_s1 = compare(s1, n );
    int count_s2 = compare( s2, n );

    if( count_s1 < count_s2 ) return -1;
    else if( count_s1 == count_s2 ) return 0;
    else return 1;

}

int main(){
    char s1[50] = "test";
    char s2[50] = "test";
    int n = 3;
    int result = 0;

    result = ft_strncmp(s1, s2, n);

    printf("%d\n", result);

    return 0;
}