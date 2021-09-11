/*
** EPITECH PROJECT, 2021
** free_list
** File description:
** No file there, just an epitech header example
*/

#include <stdlib.h>
#include "mysh.h"

void free_list(my_env_t *my_env)
{
    my_env_t *ptr;

    ptr = my_env;
    while (ptr != NULL) {
        ptr = ptr->next;
        free(my_env->name);
        free(my_env->value);
        free(my_env);
        my_env = ptr;
    }
}
