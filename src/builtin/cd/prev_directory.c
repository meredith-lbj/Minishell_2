/*
** EPITECH PROJECT, 2021
** prev_directory
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

my_env_t *swap_pwd_oldpwd(my_env_t *my_env)
{
    char str[100];
    char *new_pwd = NULL;
    char *oldpwd = NULL;

    oldpwd = get_way(my_env, "OLDPWD");
    new_pwd = get_way(my_env, "PWD");
    chdir(oldpwd);
    my_env = setenv_builtin(my_env, "OLDPWD", new_pwd);
    my_env = setenv_builtin(my_env, "PWD", oldpwd);
    free(oldpwd);
    free(new_pwd);
    return (my_env);
}

void error_cd(my_env_t *my_env, char *commands)
{
    if (get_way(my_env, "OLDPWD") == NULL)
        not_directory(NULL);
    else
        not_directory(commands);
}

my_env_t *prev_directory(my_env_t *my_env, char *commands)
{
    if (check_access(my_env, "OLDPWD") == 0) {
        my_env = swap_pwd_oldpwd(my_env);
    }
    else {
        error_cd(my_env, commands);
    }
    return (my_env);
}
