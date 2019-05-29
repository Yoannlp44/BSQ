/*
** EPITECH PROJECT, 2018
** error
** File description:
** error check
*/

#include "my.h"

int check_chararacters(char *map)
{
    int i = 0;

    while (map[i]){
        if (map[i] != '.' && map[i] != 'o' && map[i] != '\n')
            return (84);
        i++;
    }
    return (0);
}

int compare_size_map(char *map, int nb)
{
    int i = 0;
    int nb_line = 0;

    while (map[i]){
        if (map[i] == '\n')
            nb_line++;
        i++;
    }
    if (nb_line != nb)
        return (84);
    return (0);
}

int compare_size_of_lines(char *map, int nb)
{
    int size_line = 0;
    int i = 0;

    while (map[i] != '\n'){
        size_line++;
        i++;
    }
    while (map[i])
        i++;
    if (nb * (size_line + 1) != i)
        return (84);
    return (0);
}

int check_error_map(char *map, int nb)
{
    if (compare_size_map(map, nb) != 0) {
        my_putstr("Wrong size of first number\n");
        return (84);
    }
    if (compare_size_of_lines(map, nb) != 0) {
        my_putstr("One or several lines are not identical\n");
        return (84);
    }
    if (check_chararacters(map) != 0) {
        my_putstr("Only '.' and 'o' are allowed\n");
        return (84);
    }
    return (0);
}
