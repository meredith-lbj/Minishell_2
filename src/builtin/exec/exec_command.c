/*
** EPITECH PROJECT, 2021
** exec_command
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

my_env_t *exec_path(my_env_t *my_env, char **exe, char *fixed)
{
    int x = 0;
    char **path = get_path(my_env);
    struct stat file_stat;
    int fd = stat(exe[0], &file_stat);

    path = get_binary(path, fixed);
    for (x = 0; path[x] != NULL && fd == -1 ; x++)
        fd = stat(path[x], &file_stat);
    if (fd == 0) {
        free_chaine(exe);
        exe = swap_way(path, x - 1, fixed);
        if (file_stat.st_mode & S_IXUSR && file_stat.st_mode & S_IFREG) {
            execut(my_env, exe);
            return (my_env);
        }
    }
    command_not_found(exe[0]);
    free_chaine(path);
    return (my_env);
}

my_env_t *path_is_valid(my_env_t *my_env, char **exe, char *fixed)
{
    char **path = get_path(my_env);

    if (path == NULL)
        command_not_found(exe[0]);
    else
        return (exec_path(my_env, exe, fixed));
    return (my_env);
}

my_env_t *command_is_valid(my_env_t *my_env, char **exe)
{
    execut(my_env, exe);
    free_chaine(exe);
    return (my_env);
}

my_env_t *exec_command(my_env_t *my_env, char **exe, char *fixed)
{
    int fd = 0;
    int size = my_strlen(fixed);
    struct stat file_stat;

    fd = stat(exe[0], &file_stat);
    if (fd == -1)
        return (path_is_valid(my_env, exe, fixed));
    else if (fd == 0)
        return (command_is_valid(my_env, exe));
    command_not_found(exe[0]);
    return (my_env);
}
