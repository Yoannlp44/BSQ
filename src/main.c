/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stddef.h>
#include "my.h"
#include <stdlib.h>
#include "bsq.h"

int change_map(char **map, int size_of_pointer_move, int nb)
{
    while (**map != '\n' && **map){
        (*map)++;
        size_of_pointer_move++;
    }
    (*map)++;
    if ((**map != 'o' && **map != '.') || nb == 0)
        exit(84);
    return (size_of_pointer_move);
}

void re_init_map(char **map, int size_of_pointer_move)
{
    while (size_of_pointer_move != 0){
        (*map)--;
        size_of_pointer_move--;
    }
    (*map)--;
}

bsq_list_t init_struct(bsq_list_t bsq)
{
    bsq.map = NULL;
    bsq.save_x = 0;
    bsq.save_y = 0;
    bsq.size = 0;
    bsq.map2 = 0;
    return (bsq);
}

bsq_list_t init_int(bsq_list_t bsq, int nb)
{
    int i = 0;
    int j = 0;

    bsq.map2 = malloc(sizeof(int *) * (nb + 1));
    for (; bsq.map[0][i]; i++);
    for (j = 0; nb > 0; nb--, j++)
        bsq.map2[j] = malloc(sizeof(int) * (i+ 1));
    for (j = 0; bsq.map[j]; j++){
        for (i = 0; bsq.map[j][i]; i++)
            fill_int(&bsq, j, i);
        bsq.map2[j][i] = -1;
    }
    return (bsq);
}

int main(int ac, char **av)
{
    char *map = NULL;
    int nb = 0;
    int size_of_pointer_move = 0;
    bsq_list_t bsq;

    (void)ac;
    bsq = init_struct(bsq);
    map = get_file(av[1]);
    nb = my_getnbr(map);
    size_of_pointer_move = change_map(&map, size_of_pointer_move, nb);
    if (check_error_map(map, nb) != 0)
        return (84);
    bsq.map = my_str_to_word_array(map);
    bsq = init_int(bsq, nb);
    do_bsq(&bsq);
    find_max_square(&bsq);
    fill_square(&bsq);
    my_show_word_array(bsq.map);
    re_init_map(&map, size_of_pointer_move);
    my_free(bsq, map);
    return (0);
}