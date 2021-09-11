/*
** EPITECH PROJECT, 2021
** check_var
** File description:
** No file there, just ane epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

int check_var(my_env_t *my_env, char *name)
{
    my_env_t *ptr = my_env;

    while (ptr != NULL) {
        if (my_strcmp(ptr->name, name) == 0) {
            return (0);
        }
        ptr = ptr->next;
    }
    return (1);
}
