/*
** EPITECH PROJECT, 2018
** proto
** File description:
** proto
*/

#ifndef BSQ_H_
#define BSQ_H_

typedef struct bsq_list
{
    char **map;
    int **map2;
    int save_x;
    int save_y;
    int size;
} bsq_list_t;

char *get_file(char *filepath);
int check_error_map(char *map, int nb);
void do_bsq(bsq_list_t *bsq);
void find_max_square(bsq_list_t *bsq);
void fill_square(bsq_list_t *bsq);
void fill_int(bsq_list_t *bsq, int j, int i);
void my_free(bsq_list_t bsq, char *map);

#endif /* !BSQ_H_ */
