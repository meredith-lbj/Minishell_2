/*
** EPITECH PROJECT, 2021
** check_access
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

int check_access(my_env_t *my_env, char *find)
{
    char *way = NULL;

    way = get_way(my_env, find);
    if (way == NULL)
        return (1);
    if (access(way, F_OK) == 0 && access(way, X_OK) == 0) {
        free(way);
        return (0);
    }
    else {
        free(way);
        return (1);
    }
    return (0);
}
