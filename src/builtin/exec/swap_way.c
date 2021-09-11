/*
** EPITECH PROJECT, 2021
** swap_way
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

char **swap_way(char **path, int pos, char *command)
{
    int space = space_count(command);
    char **divide = get_commands(command);
    char **new_path = NULL;

    new_path = malloc(sizeof(char *) * (space + 2));
    new_path[space + 1] = NULL;
    new_path[0] = my_strdup(new_path[0], path[pos]);
    for (int i = 1 ; divide[i] != NULL ; i++) {
        new_path[i] = my_strdup(new_path[i], divide[i]);
    }
    return (new_path);
}
