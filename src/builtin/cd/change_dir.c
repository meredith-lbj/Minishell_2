/*
** EPITECH PROJECT, 2021
** change_dir
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

my_env_t *change_pdirectory(my_env_t *my_env)
{
    char str[100];
    char *oldpwd = NULL;

    oldpwd = get_way(my_env, "PWD");
    my_env = setenv_builtin(my_env, "OLDPWD", oldpwd);
    my_env = setenv_builtin(my_env, "PWD", getcwd(str, 100));
    free(oldpwd);
    return (my_env);
}

my_env_t *change_dir2(my_env_t *my_env, char *commands)
{
    struct stat file_stat;

    stat(commands, &file_stat);
    if (S_ISDIR(file_stat.st_mode)) {
        chdir(commands);
        my_env = change_pdirectory(my_env);
    }
    else {
        not_directory(commands);
    }
    return (my_env);
}

my_env_t *change_dir(my_env_t *my_env, char *commands)
{
    if (access(commands, F_OK) == 0 && access(commands, X_OK) == 0) {
        chdir(commands);
        my_env = change_pdirectory(my_env);
    }
    else {
        not_directory(commands);
    }
    return (my_env);
}
