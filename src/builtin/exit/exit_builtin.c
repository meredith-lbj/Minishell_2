/*
** EPITECH PROJECT, 2021
** exit
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

void free_exit(char *fixed, my_env_t *my_env)
{
    free(fixed);
    free_list(my_env);
}

int exit_builtin(char *fixed, my_env_t *my_env)
{
    int i = 0;
    char **exe = get_commands(fixed);

    for (i = 0 ; exe[i] != NULL ; i++);
    if (i > 2)
        return (1);
    if (i == 2) {
        if (my_str_isnum(exe[1]) == 0) {
            free_exit(fixed, my_env);
            exit(my_getnbr(exe[1]) % 256);
        }
        return (1);
    }
    if (i == 1) {
        free_exit(fixed, my_env);
        exit(0);
    }
    return (1);
}
