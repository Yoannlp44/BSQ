/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include "bsq.h"

void fill_square(bsq_list_t *bsq)
{
    if (bsq->size == 1)
        bsq->map[bsq->save_x][bsq->save_y] = 'x';
    for (int cmpt = 0; cmpt < bsq->size; cmpt++){
        for (int cmpt2 = 0; cmpt2 < bsq->size; cmpt2++)
            bsq->map[bsq->save_x - cmpt][bsq->save_y - cmpt2] = 'x';
    }
}

void save_pos(bsq_list_t *bsq, int i, int j)
{
    if (bsq->map2[i][j] > bsq->size) {
        bsq->size = bsq->map2[i][j];
        bsq->save_x = i;
        bsq->save_y = j;
    }
}

void find_max_square(bsq_list_t *bsq)
{
    int i = 0;
    int j = 0;

    for (; bsq->map2[i]; i++){
        for (; bsq->map2[i][j] != -1; j++)
            save_pos(bsq, i, j);
        j = 0;
    }
}

int change_nbr(int j, int i, bsq_list_t *bsq)
{
    int tmp = bsq->map2[i][j - 1];

    if (bsq->map2[i][j] == 0)
        return (0);
    if (tmp >= bsq->map2[i - 1][j - 1])
        tmp = bsq->map2[i - 1][j - 1];
    if (tmp >= bsq->map2[i - 1][j])
        tmp = bsq->map2[i - 1][j];
    bsq->map2[i][j] = tmp + 1;
    return (0);
}

void do_bsq(bsq_list_t *bsq)
{
    int i = 1;
    int j = 1;

    for (; bsq->map2[i]; i++){
        for (; bsq->map2[i][j] != -1; j++)
            change_nbr(j, i, bsq);
        j = 1;
    }
}
