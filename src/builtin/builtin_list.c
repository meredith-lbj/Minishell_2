/*
** EPITECH PROJECT, 2021
** builtin_list
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

my_env_t *builtin_list(my_env_t *my_env, char *command)
{
    char *fixed = fix_space(command);
    char **exe = get_commands(fixed);
    int space = space_count(fixed);

    if (my_strcmp(exe[0], "cd") == 0)
        return (exec_cd(my_env, exe, space));
    if (my_strcmp(exe[0], "setenv") == 0)
        return (exec_setenv(my_env, exe, space));
    if (my_strcmp(exe[0], "unsetenv") == 0)
        return (exec_unsetenv(my_env, exe, space));
    if (my_strcmp("env", fixed) == 0)
        return (print_env(my_env));
    if (my_strcmp(exe[0], "exit") == 0)
        return (exec_exit(my_env, command, fixed));
    if (my_strcmp("--helper", fixed) == 0)
        return (print_helper(my_env));
    return (exec_command(my_env, exe, fixed));
}
