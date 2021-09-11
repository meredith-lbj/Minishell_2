/*
** EPITECH PROJECT, 2021
** get_way
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

char *get_way(my_env_t *my_env, char *find)
{
    char *way = NULL;
    my_env_t *ptr = my_env;

    while (ptr != NULL) {
        if (my_strcmp(ptr->name, find) == 0) {
            way = my_strdup(way, ptr->value);
            return (way);
        }
        ptr = ptr->next;
    }
    return (way);
}
