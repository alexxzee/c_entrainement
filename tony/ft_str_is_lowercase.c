#include <unistd.h>
#include <stdio.h>

// 0 : Non
int is_minuscule( int letter ){
    return ( letter >= 97 && letter <= 122 );
}

int ft_str_is_lowercase( char *str){
    int result = 1;
    int i = 0;
    while( str[i] != '\0' ){
        if( !is_minuscule(str[i]) ) result = 0;
        i++;
    }
    return result;
}


int main(){
    char str[200] = "az";
    int result = 0;
    result = ft_str_is_lowercase(str);

    printf("%d\n", result);


    return 0;
}