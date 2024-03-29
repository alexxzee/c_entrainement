#include <stdio.h>
#include <unistd.h>

int ft_putchar(char c){
    write(1, &c, 1);

    return (0);
}


int is_number( int caractere ){
    return ( caractere >= 48 && caractere <= 57 );
}

int convert_num( int number ){
    return number - 48;
}
// Converti le premier argument en chiffre
int arg_to_num( int argc, char *argv[]  ){
    if (argc == 2 && is_number(*argv[1])){
        return convert_num(*argv[1]);
    } else return 0;
}

void ft_put_line(int space, int length)
{
    int i;

    i = 0;
    while (i++ < space)
        ft_putchar(' ');
    i = 0;
    ft_putchar('/');
    while (i++ < length) ft_putchar('*');
    ft_putchar('\\');
    ft_putchar('\n');
}

void ft_put_line_door(int space, int length, int door_size)
{
    int i;
    int y;

    i = 0;
    y = door_size;
    while (i++ < space) ft_putchar(' ');

    i = 0;

    ft_putchar('/');

    while (i++ < length) ft_putchar('*');
    i = 0;
    while (y--){
        if (
            y == 1 
            && door_size / 2 == space 
            && door_size > 3
        ) ft_putchar('$');
        else ft_putchar('|');
    }
    while (i++ < length) ft_putchar('*');
    ft_putchar('\\');
    ft_putchar('\n');
}

void ft_put_sastantua(int length_total, int size, int start_door){
    int current_floor;
    int current_line;
    int length;
    int shift;
    int space;

    current_floor = 0;
    length = -1;
    shift = 2;
    while (current_floor++ < size){
        current_line = 1;
        while (current_line++ <= (current_floor + 2)){
            length += 1;
            space = ((length_total / 2) - length - 1);
            if (current_floor == size && current_line > (size + 3) - start_door)
                ft_put_line_door(space, length - (start_door / 2), start_door);
            else ft_put_line(space, (length * 2) + 1);
        }
        if (current_floor % 2 && current_floor > 1) shift++;
        length += shift;
    }
}

void sastantua(int size)
{
    int current_floor;
    int current_line;
    int length;
    int shift;
    int start_door;

    current_floor = 0;
    length = -1;
    shift = 2;
    while (current_floor++ < size)
    {
        current_line = 1;
        while (current_line++ <= (current_floor + 2))
            length += 1;
        if (current_floor % 2 && current_floor > 1)
            shift++;
        length += shift;
    }
    start_door = size - 1;
    if (size % 2)
        start_door++;
    ft_put_sastantua(((length - shift) * 2) + 3, size, start_door);
}

int main(int argc, char *argv[]){
    int num = 0;

    num = arg_to_num(argc, argv);
    sastantua(num);

    return 0;
}