/*
** EPITECH PROJECT, 2021
** exec_builtin
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>
#include <unistd.h>

my_env_t *exec_exit(my_env_t *my_env, char *command, char *fixed)
{
    free(command);
    if (exit_builtin(fixed, my_env) == 1) {
        command_not_found(fixed);
        free(fixed);
        return (my_env);
    }
    return (my_env);
}

my_env_t *exec_unsetenv(my_env_t *my_env, char **exe, int space)
{
    if (space == 0) {
        write(2, "unsetenv: Too few arguments.\n", 29);
    }
    if (space == 1) {
        my_env = unsetenv_builtin(my_env, exe[1]);
    }
    if (space > 1) {
        for (int u = 1 ; exe[u] != NULL ; u++) {
            my_env = unsetenv_builtin(my_env, exe[u]);
        }
    }
    free_chaine(exe);
    return (my_env);
}

my_env_t *exec_setenv(my_env_t *my_env, char **exe, int space)
{
    if (space == 0) {
        print_env(my_env);
    }
    if (space == 1) {
        my_env = setenv_builtin(my_env, exe[1], NULL);
    }
    if (space == 2) {
        my_env = setenv_builtin(my_env, exe[1], exe[2]);
    }
    if (space > 2) {
        write(2, "setenv: Too many arguments.\n", 28);
    }
    free_chaine(exe);
    return (my_env);
}

my_env_t *exec_cd(my_env_t *my_env, char **exe, int space)
{
    if (space == 0) {
        my_env = cd_builtin(my_env, exe[0]);
    }
    else {
        my_env = cd_builtin(my_env, exe[1]);
    }
    return (my_env);
}
