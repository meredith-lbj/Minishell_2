/*
** EPITECH PROJECT, 2021
** cd_builtin
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

my_env_t *go_home(my_env_t *my_env)
{
    char str[100];
    char *home = NULL;
    char *oldpwd = NULL;

    oldpwd = get_way(my_env, "PWD");
    home = get_way(my_env, "HOME");
    chdir(home);
    my_env = setenv_builtin(my_env, "OLDPWD", oldpwd);
    my_env = setenv_builtin(my_env, "PWD", home);
    free(oldpwd);
    free(home);
    return (my_env);
}

my_env_t *cd_builtin(my_env_t *my_env, char *commands)
{
    if (my_strcmp(commands, "cd") == 0) {
        return (go_home(my_env));
    }
    if (my_strcmp(commands, "-") == 0) {
        return (prev_directory(my_env, commands));
    }
    if (check_start(commands, "..") == 0) {
        return (change_dir(my_env, commands));
    }
    if (access(commands, F_OK) == 0 && access(commands, X_OK) == 0) {
        return (change_dir2(my_env, commands));
    }
    if (access(commands, F_OK) == 0 && access(commands, X_OK) == -1) {
        return (check_dir_perms(my_env, commands));
    }
    not_directory(commands);
    return (my_env);
}
