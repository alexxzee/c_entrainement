#include <unistd.h>
#include <stdio.h>

// 0 : Non
int is_majuscule( int letter ){
    return ( letter >= 65 && letter <= 90 );
}

int ft_str_is_uppercase( char *str){
    int result = 1;
    int i = 0;
    while( str[i] != '\0' ){
        if( !is_majuscule(str[i]) ) result = 0;
        i++;
    }
    return result;
}


int main(){
    char str[200] = "A";
    int result = 0;
    result = ft_str_is_uppercase(str);
    printf("%d\n", result);
    return 0;
}