/*
** EPITECH PROJECT, 2021
** get_binary
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

int get_len(char **path)
{
    int len = 0;

    for (int y = 0 ; path[y] != NULL ; y++) {
        len++;
    }
    return (len);
}

char *parse_command2(char *command, char *find)
{
    int j = 0;
    int k = 0;

    while (command[j] != ' ') {
        j++;
    }
    find = malloc(sizeof(char) * (j + 1));
    find[j] = '\0';
    while (k < j) {
        find[k] = command[k];
        k++;
    }
    return (find);
}

char *parse_command(int space, char *command, char *find)
{
    if (space != 0) {
        find = parse_command2(command, find);
    }
    else {
        find = my_strdup(find, command);
    }
    return (find);
}

char **get_binary(char **path, char *command)
{
    int path_len = 0;
    int space = space_count(command);
    int len = get_len(path);
    char *find = NULL;
    char **new_path = NULL;

    new_path = malloc(sizeof(char *) * (len + 1));
    new_path[len] = NULL;
    find = parse_command(space, command, find);
    for (int i = 0 ; path[i] != NULL ; i++) {
        path_len = my_strlen(find) + my_strlen(path[i]) + 2;
        new_path[i] = malloc(sizeof(char) * (path_len));
        new_path[i] = my_strcpy(new_path[i], path[i]);
        new_path[i] = my_strcat(new_path[i], "/");
        new_path[i] = my_strcat(new_path[i], find);
    }
    free(find);
    free(path);
    return (new_path);
}
