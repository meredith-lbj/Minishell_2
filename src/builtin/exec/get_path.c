/*
** EPITECH PROJECT, 2021
** get_path
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

int limit_count(char const *path_var)
{
    int count = 0;
    int i = 0;

    while (path_var[i] != '\0') {
        if (path_var[i] == ':') {
            count++;
        }
        i++;
    }
    return (count);
}

void fill_path(char ***path, char const *path_var)
{
    int x = 0;
    int y = 0;

    for (int i = 0 ; path_var[i] != '\0' ; i++) {
        if (path_var[i] == ':') {
            (*path)[x][y] = '\0';
            i++;
            x++;
            y = 0;
        }
        (*path)[x][y] = path_var[i];
        y++;
    }
}

char **alloc_way(char const *path_var, char **path, int limit)
{
    int x = 0;
    int word = 0;

    path = malloc(sizeof(char*) * (limit + 2));
    path[limit + 1] = NULL;
    for (int i = 0 ; path_var[i] != '\0' ; i++) {
        word++;
        if (path_var[i] == ':') {
            path[x] = malloc(sizeof(char) * (word + 1));
            path[x][word] = '\0';
            x++;
            word = 0;
        }
    }
    path[x] = malloc(sizeof(char) * (word + 1));
    path[x][word] = '\0';
    fill_path(&path, path_var);
    return (path);
}

char **get_path(my_env_t *my_env)
{
    char *path_var = NULL;
    char **path = NULL;
    int limit;

    path_var = get_way(my_env, "PATH");
    if (path_var == NULL)
        return (NULL);
    limit = limit_count(path_var);
    path = alloc_way(path_var, path, limit);
    free(path_var);
    return (path);
}
