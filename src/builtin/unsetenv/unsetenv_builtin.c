/*
** EPITECH PROJECT, 2021
** unsetenv_builtin
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>
#include <unistd.h>

my_env_t *delete_var(my_env_t *my_env, char *name)
{
    my_env_t *delete = my_env;
    my_env_t *ptr = my_env;

    while (delete != NULL) {
        if (my_strcmp(name, delete->name) == 0) {
            ptr->next = delete->next;
            free(delete->name);
            if (delete->value != NULL) {
                free(delete->value);
            }
            free(delete);
            delete = ptr;
            return (my_env);
        }
        ptr = delete;
        delete = delete->next;
    }
    return (my_env);
}

my_env_t *unsetenv_builtin(my_env_t *my_env, char *name)
{
    if (find_my_chr(name, '*') == 1) {
        my_env = delete_var(my_env, name);
    }
    return (my_env);
}
