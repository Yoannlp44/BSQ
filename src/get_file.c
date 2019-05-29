/*
** EPITECH PROJECT, 2018
** get file
** File description:
** get file
*/

#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "bsq.h"

void my_free(bsq_list_t bsq, char *map)
{
    for (int i = 0; bsq.map[i]; i++){
        free(bsq.map[i]);
        free(bsq.map2[i]);
    }
    free(bsq.map);
    free(bsq.map2);
    free(map);
}

void fill_int(bsq_list_t *bsq, int j, int i)
{
    if (bsq->map[j][i] == '.')
        bsq->map2[j][i] = 1;
    else
        bsq->map2[j][i] = 0;
}

char *get_file(char *filepath)
{
    int fd = 0;
    char *buffer = NULL;
    struct stat sb;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("Can't open the file\n");
        exit(84);
    }
    stat(filepath, &sb);
    if (sb.st_size < 1)
        exit(84);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    read(fd, buffer, sb.st_size);
    buffer[sb.st_size] = '\0';
    return (buffer);
}
